#version 330 core

out vec4 color;

in vec4 fragmentColor;
in vec2 fragmentUV;

uniform sampler2D image;

void main() {
    color = vec4(fragmentColor.rgb, texture(image, fragmentUV).r * fragmentColor.a);
}
