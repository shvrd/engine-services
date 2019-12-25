//
// Created by thekatze on 25/12/2018.
//

#ifndef SHVRD_OPENGLGRAPHICS_H
#define SHVRD_OPENGLGRAPHICS_H

#include <GL/glew.h>
#include <GL/gl.h>
#include "../Graphics.h"

class OpenGLGraphics : public Graphics {
    GLuint m_spriteVertexArrayObject, m_spriteVertexBufferObject;
    GLuint m_textVertexArrayObject, m_textVertexBufferObject;
    GLuint m_rectVertexArrayObject, m_rectVertexBufferObject;

public:
    OpenGLGraphics();
    ~OpenGLGraphics() override = default;

    void clear() override;
    void setClearColor(Color color) override;

    void initialize(int windowWidth, int windowHeight) override;

    void setViewport(int width, int height) override;

    std::shared_ptr<Texture> loadTexture(const std::string& filePath) override;

    void useTexture(std::shared_ptr<Texture> texture) override;

    std::shared_ptr<Shader> createShader() override;

    void bindShader(std::shared_ptr<Shader> shader) override;

    void drawText(const std::string& text, Vector2f location) override;

    void drawToRect(Vector2f location, Vector2f dimensions) override;

    void drawSprite(const std::shared_ptr<Sprite>& sprite) override;
};


#endif //SHVRD_OPENGLGRAPHICS_H
