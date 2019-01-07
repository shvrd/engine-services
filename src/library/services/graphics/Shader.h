//
// Created by thekatze on 07/01/2019.
//

#ifndef ENGINITO_SHADER_H
#define ENGINITO_SHADER_H
class Shader {
public:
    Shader() = default;
    virtual ~Shader() = default;

    virtual void bind() = 0;

    virtual void setVertexShader(const std::string& filePath) = 0;
    virtual void setFragmentShader(const std::string& filePath) = 0;
};
#endif //ENGINITO_SHADER_H
