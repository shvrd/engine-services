//
// Created by thekatze on 25/12/2018.
//

#include <sstream>

#include "OpenGLGraphics.h"
#include "../../../log/Logger.h"
#include "GLSLShader.h"
#include "../../../types/Vertex.h"
#include "OpenGLSprite.h"
#include "util/ImageLoader.h"

OpenGLGraphics::OpenGLGraphics()
    : m_textVertexArrayObject(0)
    , m_textVertexBufferObject(0) {

}

void OpenGLGraphics::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLGraphics::setClearColor(Color color) {
    glClearColor(color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
}

void GLAPIENTRY
MessageCallback(GLenum source,
                GLenum type,
                GLuint id,
                GLenum severity,
                GLsizei length,
                const GLchar *message,
                const void *userParam) {
    std::stringstream log;

    if (type == 33361) {
        return;
    }

    log << message << " | Type: 0x" << type;

    if (severity == GL_DEBUG_TYPE_ERROR) {
        Logger::error(log.str());
    } else {
        Logger::info(log.str());
    }
}

void OpenGLGraphics::initialize(int windowWidth, int windowHeight) {
    glewExperimental = GL_TRUE;
    GLenum initStatus = glewInit();

    if(initStatus != GLEW_OK) {
        Logger::error((char*)glewGetErrorString(initStatus));

        Logger::critical("GLEW/GL could not be initialized", -5);
    }

    Logger::info(std::string("OpenGL Version: ") + (char*)(glGetString(GL_VERSION)));

#ifdef BUILD_DEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, nullptr);
#endif

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(1, &m_textVertexArrayObject);

    glBindVertexArray(m_textVertexArrayObject);

    glGenBuffers(1, &m_textVertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, m_textVertexBufferObject);
    // Vertex Attribute ID 0: Position
    glVertexAttribPointer((GLuint) 0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));

    // Vertex Attribute ID 1: Color
    glVertexAttribPointer((GLuint) 1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*) offsetof(Vertex, color));

    // Vertex Attribute ID 2: UV Map
    glVertexAttribPointer((GLuint) 2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, uv));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m_freeType.initialize();

    auto textShader = createShader();

    textShader->setVertexShader("../../../src/library/assets/shaders/text.vert");
    textShader->setFragmentShader("../../../src/library/assets/shaders/text.frag");

    textShader->addAttribute("vertexPosition");
    textShader->addAttribute("vertexColor");
    textShader->addAttribute("vertexUV");

    textShader->finalize();

    m_freeType.setTextShader(textShader);
    m_freeType.useFont("../../../src/library/assets/fonts/OpenSans-Regular.ttf");

    Logger::info("Setting up Camera");

    m_camera = std::make_shared<Camera>(Vector2f(static_cast<float>(windowWidth), static_cast<float>(windowHeight)));

    setViewport(windowWidth, windowHeight);
}

std::shared_ptr<Texture> OpenGLGraphics::loadTexture(const std::string &filePath) {
    // If texture is already cached, return it.
    if (auto texture = m_textures.get(filePath)) {
        Logger::info("Loaded texture from cache: " + filePath);
        return texture;
    }

    Logger::info("Loading texture for the first time: " + filePath);

    auto texture = ImageLoader::loadFromPNG(filePath);

    m_textures.add(filePath, texture);

    return texture;
}

std::shared_ptr<Shader> OpenGLGraphics::createShader() {
    return std::make_shared<GLSLShader>();
}

std::shared_ptr<Sprite> OpenGLGraphics::createSprite(Vector2f location, Vector2f dimensions) {
    return std::make_shared<OpenGLSprite>(location, dimensions);
}

void OpenGLGraphics::setViewport(int width, int height) {
    glViewport(0, 0, width, height);
    m_camera->setScreenDimensions({static_cast<float>(width), static_cast<float>(height)});

    // TODO: Validate this behaviour
    m_camera->setLocation({static_cast<float>(-width) / 2, static_cast<float>(-height) / 2});
}

void OpenGLGraphics::useTexture(std::shared_ptr<Texture> texture) {
    if (!texture || !texture->id) {
        Logger::error("Given texture has not been properly loaded");

        return;
    }

    glActiveTexture(GL_TEXTURE0);

    glUniform1i(m_currentShader->getUniformLocation("image"), 0);
    glBindTexture(GL_TEXTURE_2D, texture->id);
}

void OpenGLGraphics::bindShader(const std::shared_ptr<Shader> shader) {
    Graphics::bindShader(shader);

    glUniformMatrix4fv(m_currentShader->getUniformLocation("projection"), 1, GL_FALSE, &(m_camera->getCameraMatrix()[0][0]));
}

void OpenGLGraphics::drawText(const std::string &text, Vector2f location) {
    auto textShader = m_freeType.getTextShader();

    bindShader(textShader);
    Vector2f cursor = location;

    // Bind vertex array object
    glBindVertexArray(m_textVertexArrayObject);

    // Bind vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, m_textVertexBufferObject);

    textShader->use();

    for (auto iterator = text.begin(); iterator < text.end(); ++iterator) {
        auto letter = m_freeType.getLetter(*iterator);

        if (!letter->textureId) {
            std::shared_ptr<Texture> tex = ImageLoader::loadFromGrayscaleCharArray(letter->bitmap.buffer, letter->bitmap.width, letter->bitmap.height);
            letter->textureId = tex->id;
            m_freeType.cache(letter);
        }

        useTexture(std::make_shared<Texture>(Texture{.id = letter->textureId, .width = 0, .height = 0}));

        Vector2f letterPos = {cursor.x + letter->offset.x, -cursor.y - letter->offset.y};

        Vertex vertices[4];

        // top left, top right, bottom left, bottom right
        vertices[0] = Vertex{{letterPos.x,  -letterPos.y, 0.f}, Colors::WHITE, {0, 0}};
        vertices[1] = Vertex{{letterPos.x + letter->bitmap.width,  -letterPos.y, 0.f}, Colors::WHITE, {1, 0}};
        vertices[2] = Vertex{{letterPos.x, -letterPos.y - letter->bitmap.height, 0.f}, Colors::WHITE, {0, 1}};
        vertices[3] = Vertex{{letterPos.x + letter->bitmap.width, -letterPos.y - letter->bitmap.height, 0.f}, Colors::WHITE, {1, 1}};

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        cursor = {cursor.x + (letter->advance.x >> 6), cursor.y + (letter->advance.y >> 6)};
    }

    textShader->endUse();

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}
