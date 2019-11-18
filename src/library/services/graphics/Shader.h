//
// Created by thekatze on 07/01/2019.
//

#ifndef ENGINITO_SHADER_H
#define ENGINITO_SHADER_H
class Shader {
public:
    Shader()
    : m_isFinalized(false)
    , m_attributes(0) {}

    virtual ~Shader() = default;

    virtual void bind() = 0;
    virtual void unbind() = 0;

    virtual void setVertexShader(const std::string& filePath) = 0;
    virtual void setFragmentShader(const std::string& filePath) = 0;

    virtual void finalize() = 0;
    virtual void reload() = 0;

    virtual void addAttribute(const std::string& attributeName) = 0;

    virtual void use() = 0;
    virtual void endUse() = 0;

    // TODO: This might be graphics-api-dependent, check if okay.
    virtual int getUniformLocation(const std::string& uniformName) = 0;

protected:
    bool m_isFinalized;
    unsigned int m_attributes;
};
#endif //ENGINITO_SHADER_H
