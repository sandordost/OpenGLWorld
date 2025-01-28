#pragma once
#include "textureLoader.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint TextureLoader::LoadTexture(const char* path)
{
    std::cout << "🔍 Laden van texture: " << path << std::endl;

    GLuint textureID;
    glGenTextures(1, &textureID); // Genereer een texture ID
    glBindTexture(GL_TEXTURE_2D, textureID); // Bind de texture

    // Stel standaard texture parameters in
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(true); // Zorg ervoor dat de afbeelding correct wordt geladen

    int width, height, nrChannels;
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data) {
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB; // Bepaal het formaat van de afbeelding
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D); // Genereer mipmaps
        std::cout << "✅ Texture geladen: " << path << " (" << width << "x" << height << ", " << nrChannels << " kanalen)" << std::endl;
    }
    else {
        std::cerr << "❌ Fout: Kan texture niet laden: " << path << std::endl;
    }

    stbi_image_free(data); // Vrij geheugen van de geladen afbeelding
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind de texture

    return textureID;
}
