#version 330 core

out vec3 color;

in vec3 fragmentColor;
in vec2 fragmentUV;

void main() {
    color = fragmentColor;
}