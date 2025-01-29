#include "objectLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "defaultMaterial.h"

std::vector<Mesh> ObjectLoader::LoadOBJ(const std::string& filePath) {
    std::vector<Mesh> meshes;
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;

    std::vector<float> vertices;
    std::vector<float> meshNormals;
    std::vector<float> meshTexCoords;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "❌ Kon het OBJ-bestand niet openen: " << filePath << std::endl;
        return meshes;
    }

    std::cout << "📂 Laden van OBJ-bestand: " << filePath << std::endl;


    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v") {
            glm::vec3 position{};
            iss >> position.x >> position.y >> position.z;
            positions.push_back(position);
        }
        else if (type == "vt") {
            glm::vec2 texCoord{};
            iss >> texCoord.x >> texCoord.y;
            texCoords.push_back(texCoord);
        }
        else if (type == "vn") {
            glm::vec3 normal{};
            iss >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
        }
        else if (type == "f") {
            std::string vertexData;
            int vertexCount = 0;

            while (iss >> vertexData) {
                vertexCount++;
                std::istringstream viss(vertexData);
                std::string v, vt, vn;

                std::getline(viss, v, '/');
                std::getline(viss, vt, '/');
                std::getline(viss, vn, '/');

                int vi = std::stoi(v) - 1;
                int vti = vt.empty() ? -1 : std::stoi(vt) - 1;
                int vni = vn.empty() ? -1 : std::stoi(vn) - 1;

                // Posities toevoegen
                vertices.push_back(positions[vi].x);
                vertices.push_back(positions[vi].y);
                vertices.push_back(positions[vi].z);

                // Texture Coördinaten (UV)
                if (vti >= 0 && vti < texCoords.size()) {
                    meshTexCoords.push_back(texCoords[vti].x);
                    meshTexCoords.push_back(1.0f - texCoords[vti].y); // Y-coord fixen (flippen)
                }
                else {
                    meshTexCoords.push_back(0.5f);
                    meshTexCoords.push_back(0.5f);
                }

                // Normals
                if (vni >= 0 && vni < normals.size()) {
                    meshNormals.push_back(normals[vni].x);
                    meshNormals.push_back(normals[vni].y);
                    meshNormals.push_back(normals[vni].z);
                }
                else {
                    meshNormals.push_back(0.0f);
                    meshNormals.push_back(0.0f);
                    meshNormals.push_back(1.0f); // Default normal omhoog gericht
                }
            }

            // Controleer of het een quad is (4 vertices ipv 3)
            if (vertexCount == 4) {
                // De eerste driehoek was al toegevoegd (0, 1, 2)
                // We moeten nog (2, 3, 0) toevoegen om een quad te maken
                for (int i = 0; i < 3; i++) {
                    vertices.push_back(vertices[(vertices.size() - 12) + i]); // Vertex 2
                    vertices.push_back(vertices[(vertices.size() - 6) + i]);  // Vertex 3
                    vertices.push_back(vertices[(vertices.size() - 18) + i]); // Vertex 0

                    meshTexCoords.push_back(meshTexCoords[(meshTexCoords.size() - 8) + i]);
                    meshTexCoords.push_back(meshTexCoords[(meshTexCoords.size() - 4) + i]);

                    meshNormals.push_back(meshNormals[(meshNormals.size() - 12) + i]);
                    meshNormals.push_back(meshNormals[(meshNormals.size() - 6) + i]);
                    meshNormals.push_back(meshNormals[(meshNormals.size() - 18) + i]);
                }
            }
        }
    }

    std::cout << "DEBUG: Vertices geladen (" << vertices.size() / 3 << "):\n";
    for (size_t i = 0; i < vertices.size(); i += 3) {
        std::cout << "Vertex " << i / 3 << ": (" << vertices[i] << ", "
            << vertices[i + 1] << ", " << vertices[i + 2] << ")\n";
    }

    file.close();

    // Debug Output
    std::cout << "✅ OBJ Geladen: " << filePath << "\n"
        << "   🔹 Posities: " << positions.size() << "\n"
        << "   🔹 UV Coördinaten: " << texCoords.size() << "\n"
        << "   🔹 Normals: " << normals.size() << "\n"
        << "   🔹 Totaal Vertices: " << vertices.size() / 3 << std::endl;

    // Maak een nieuwe mesh aan met de ingeladen data
    if (!vertices.empty()) {
        meshes.emplace_back();
        meshes.back().SetupMesh(vertices, meshNormals, meshTexCoords, DefaultMaterial());
    }

    return meshes;
}
