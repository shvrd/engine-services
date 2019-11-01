#version 330 core

in vec2 texCoord;

uniform sampler2D image;
uniform vec4 color;

out vec4 outColor;

void main(void) {
    outColor = vec4(1, 1, 1, texture2D(image, texCoord).r) * color;
}
