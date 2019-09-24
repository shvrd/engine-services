//
// Created by thekatze on 25/12/2018.
//

#ifndef ENGINITO_OPENGLGRAPHICS_H
#define ENGINITO_OPENGLGRAPHICS_H

#include <GL/glew.h>
#include <GL/gl.h>
#include "../Graphics.h"

class OpenGLGraphics : public Graphics {
    GLuint m_vertexArrayObject, m_vertexBufferObject;
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
    std::shared_ptr<Sprite> createSprite(Vector2 location, Vector2 dimensions) override;


    void bindShader(const std::shared_ptr<Shader> shader) override;
};


#endif //ENGINITO_OPENGLGRAPHICS_H
