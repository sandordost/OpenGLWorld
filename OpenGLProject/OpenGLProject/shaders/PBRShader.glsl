#version 460 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;
in mat3 TBN;

struct Material {
    sampler2D diffuse;   
    sampler2D roughness; 
    sampler2D normal;
    float shininess;
    float smoothness;
    float normalStrength;
};  

uniform Material material;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;
uniform bool useNormalMap;
uniform float lightStrength; // Nieuwe uniform voor lichtsterkte

void main() {
    // **Ambient lighting**
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * texture(material.diffuse, TexCoord).rgb;

    // **Normal mapping**
    vec3 norm;
    if (useNormalMap) {
        // Sample de normal map en transformeer naar [-1, 1] bereik
        vec3 sampledNormal = texture(material.normal, TexCoord).rgb;
        sampledNormal = normalize(sampledNormal * 2.0 - 1.0);

        // Pas normalStrength toe en combineer met de oorspronkelijke normal richting
        norm = normalize(mix(Normal, TBN * sampledNormal, material.normalStrength));
    } else {
        norm = normalize(Normal);
    }

    // **Diffuse lighting**
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = lightStrength * diff * texture(material.diffuse, TexCoord).rgb;  // Pas de lichtsterkte toe

    // **Specular lighting**
    float rough = texture(material.roughness, TexCoord).r;
    float specularStrength = (1.0 - rough) * (1.0 - material.smoothness);

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), max(8.0, material.shininess * (1.0 - rough)));

    vec3 specular = lightStrength * specularStrength * spec * lightColor;  // Pas de lichtsterkte toe

    // **Combineer de resultaten**
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}
