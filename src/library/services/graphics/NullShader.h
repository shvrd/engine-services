//
// Created by thekatze on 07/01/2019.
//

#ifndef SHVRD_NULLSHADER_H
#define SHVRD_NULLSHADER_H
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

    int getUniformLocation(const std::string& uniformName) override { return 0; }
};
#endif //SHVRD_NULLSHADER_H
