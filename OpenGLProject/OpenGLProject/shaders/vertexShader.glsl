#version 460 core

layout (location = 0) in vec3 aPos;       // Vertex positie
layout (location = 1) in vec3 aNormal;    // Normale vector
layout (location = 2) in vec2 aTexCoord; // Texture-co�rdinaten

out vec3 FragPos;   // Fragment positie
out vec3 Normal;    // Normaalvector
out vec2 TexCoord;  // UV-co�rdinaten

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    FragPos = vec3(model * vec4(aPos, 1.0));            // Wereldco�rdinaten
    Normal = mat3(transpose(inverse(model))) * aNormal; // Normale vector transformeren
    TexCoord = aTexCoord;                               // UV-co�rdinaten doorgeven

    gl_Position = projection * view * vec4(FragPos, 1.0);
}