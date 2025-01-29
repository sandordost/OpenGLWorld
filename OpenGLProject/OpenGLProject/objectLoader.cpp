#include "objectLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "defaultMaterial.h"

std::vector<Mesh> ObjectLoader::LoadOBJ(const std::string& filePath)
{
    std::vector<Mesh> meshes;
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;
    std::vector<float> vertices;
    std::vector<float> meshNormals;
    std::vector<float> meshTexCoords;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Couldn't open obj file: " << filePath << std::endl;
        return meshes;
    }

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
            for (int i = 0; i < 3; i++) {
                iss >> vertexData;
                std::istringstream viss(vertexData);
                std::string v, vt, vn;

                std::getline(viss, v, '/');
                std::getline(viss, vt, '/');
                std::getline(viss, vn, '/');

                int vi = std::stoi(v) - 1;
                int vti = vt.empty() ? -1 : std::stoi(vt) - 1;
                int vni = vn.empty() ? -1 : std::stoi(vn) - 1;

                vertices.push_back(positions[vi].x);
                vertices.push_back(positions[vi].y);
                vertices.push_back(positions[vi].z);

                if (vti >= 0) {
                    meshTexCoords.push_back(texCoords[vti].x);
                    meshTexCoords.push_back(texCoords[vti].y);
                }
                else {
                    meshTexCoords.push_back(0.0f);
                    meshTexCoords.push_back(0.0f);
                }

                if (vni >= 0) {
                    meshNormals.push_back(normals[vni].x);
                    meshNormals.push_back(normals[vni].y);
                    meshNormals.push_back(normals[vni].z);
                }
                else {
                    meshNormals.push_back(0.0f);
                    meshNormals.push_back(0.0f);
                    meshNormals.push_back(0.0f);
                }
            }
        }
    }

    file.close();

    if (!vertices.empty()) {
        meshes.emplace_back();
        meshes.back().SetupMesh(vertices, meshNormals, meshTexCoords, DefaultMaterial());
        std::cout << "Loaded obj:" << filePath << " with " << vertices.size() / 3 << " vertices.\n";
    }

    return meshes;
}
