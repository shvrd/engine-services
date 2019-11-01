#version 330 core

out vec4 color;

in vec4 fragmentColor;
in vec2 fragmentUV;

uniform sampler2D image;

void main() {
    vec4 textureColor = texture(image, fragmentUV);

    color = textureColor * fragmentColor.rgba;
}
