#version 330 core

out vec4 color;

in vec4 fragmentColor;
in vec2 fragmentUV;

void main() {
    color = fragmentColor.rgba;
}
