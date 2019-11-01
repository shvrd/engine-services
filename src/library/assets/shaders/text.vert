#version 330 core

in vec4 coord;

out vec2 texCoord;

uniform mat4 projection;

void main(void) {
    gl_Position = projection * vec4(coord.xy, 0, 1);
    texCoord = coord.zw;
}
