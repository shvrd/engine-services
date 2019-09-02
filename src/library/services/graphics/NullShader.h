//
// Created by thekatze on 07/01/2019.
//

#ifndef ENGINITO_NULLSHADER_H
#define ENGINITO_NULLSHADER_H
class NullShader : public Shader {
public:
    NullShader() = default;
    ~NullShader() override = default;

    void bind() override {}
    void unbind() override {}

    void setVertexShader(const std::string& filePath) override {}
    void setFragmentShader(const std::string& filePath) override {}

    void finalize() override {}
    void reload() override {}

    void addAttribute(const std::string& attributeName) override {}

    void use() override {}
    void endUse() override {}
};
#endif //ENGINITO_NULLSHADER_H
