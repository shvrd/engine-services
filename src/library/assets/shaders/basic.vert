#version 330 core

layout(location = 0) in vec3 _vertexPosition;
layout(location = 1) in vec4 _vertexColor;
layout(location = 2) in vec2 _vertexUV;

out vec4 vertexColor;
out vec2 vertexUV;

void main() {
    gl_Position.xyz = _vertexPosition;
    gl_Position.w = 1.0;

    vertexColor = _vertexColor;
    vertexUV = _vertexUV;
}