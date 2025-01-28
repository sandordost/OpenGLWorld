#version 460 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

struct Material {
    sampler2D diffuse;   
    sampler2D roughness; 
    float shininess;
};  

uniform Material material;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main() {
    // Ambient lighting
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * texture(material.diffuse, TexCoord).rgb;

    // Diffuse lighting
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * texture(material.diffuse, TexCoord).rgb;

    // Specular lighting (Fixed)
    float rough = texture(material.roughness, TexCoord).r;
    float specularStrength = 1.0 - rough; // Minder reflectie bij hogere roughness

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    
    // ✅ Voeg condition toe om glitches te voorkomen
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), max(8.0, material.shininess * (1.0 - rough)));

    vec3 specular = specularStrength * spec * lightColor;

    // Combineer verlichting
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}
