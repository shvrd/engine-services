#version 330 core

out vec4 color;

in vec4 vertexColor;
in vec2 vertexUV;

void main() {
    color = vertexColor;
}