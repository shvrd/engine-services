//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_OPENGLGRAPHICS_H
#define ENGINITO_OPENGLGRAPHICS_H

#include <GL/glew.h>
#include <GL/gl.h>
#include "../Graphics.h"

class OpenGLGraphics : public Graphics {
    GLuint m_textVertexArrayObject, m_textVertexBufferObject;

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
    std::shared_ptr<Sprite> createSprite(Vector2f location, Vector2f dimensions) override;

    void bindShader(std::shared_ptr<Shader> shader) override;

    void drawText(const std::string& text, Vector2f location) override;
};


#endif //ENGINITO_OPENGLGRAPHICS_H
