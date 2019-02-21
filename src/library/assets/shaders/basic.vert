#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec4 vertexColor;
layout(location = 2) in vec2 vertexUV;

out vec4 fragmentColor;
out vec2 fragmentUV;

void main() {
    gl_Position.xyz = vertexPosition;
    gl_Position.w = 1.0;

    fragmentColor = vertexColor;
    fragmentUV = vertexUV;
}