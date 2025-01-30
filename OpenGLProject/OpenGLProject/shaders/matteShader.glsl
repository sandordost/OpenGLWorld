#version 460 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

struct Material {
    sampler2D diffuse;
};

uniform Material material;
uniform vec3 lightPos;
uniform vec3 lightColor;

void main() {
    // Simpele diffuse belichting zonder specular highlights
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    // Alleen diffuse en ambient licht
    vec3 ambient = 0.3 * texture(material.diffuse, TexCoord).rgb;
    vec3 diffuse = diff * texture(material.diffuse, TexCoord).rgb;
    vec3 result = ambient + diffuse;

    FragColor = vec4(result, 1.0);
}
