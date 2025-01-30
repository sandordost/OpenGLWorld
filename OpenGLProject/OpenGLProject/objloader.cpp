#include "objLoader.h"

bool OBJLoader::loadOBJ(
    const std::string& path,
    std::vector<glm::vec3>& out_vertices,
    std::vector<glm::vec2>& out_uvs,
    std::vector<glm::vec3>& out_normals
) {
    std::cout << "Laden van OBJ-bestand: " << path << std::endl;

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Fout: Kan OBJ-bestand niet openen: " << path << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v") {
            glm::vec3 vertex;
            ss >> vertex.x >> vertex.y >> vertex.z;
            temp_vertices.push_back(vertex);
        }
        else if (type == "vt") {
            glm::vec2 uv;
            ss >> uv.x >> uv.y;
            uv.y = 1.0f - uv.y; // OBJ-formaat heeft soms omgekeerde UV's
            temp_uvs.push_back(uv);
        }
        else if (type == "vn") {
            glm::vec3 normal;
            ss >> normal.x >> normal.y >> normal.z;
            temp_normals.push_back(glm::normalize(normal));
        }
        else if (type == "f") {
            std::string vertexData;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

            for (int i = 0; i < 3; i++) {
                ss >> vertexData;
                std::istringstream viss(vertexData);
                std::string v, vt, vn;

                std::getline(viss, v, '/');
                std::getline(viss, vt, '/');
                std::getline(viss, vn, '/');

                vertexIndex[i] = std::stoi(v) - 1;
                uvIndex[i] = vt.empty() ? -1 : std::stoi(vt) - 1;
                normalIndex[i] = vn.empty() ? -1 : std::stoi(vn) - 1;
            }

            for (int i = 0; i < 3; i++) {
                out_vertices.push_back(temp_vertices[vertexIndex[i]]);
                out_uvs.push_back(uvIndex[i] >= 0 ? temp_uvs[uvIndex[i]] : glm::vec2(0.0f));
                out_normals.push_back(normalIndex[i] >= 0 ? temp_normals[normalIndex[i]] : glm::vec3(0.0f, 0.0f, 1.0f));
            }
        }
    }

    file.close();

    std::cout << "OBJ-bestand geladen: " << path << std::endl;
    std::cout << "   Vertices: " << out_vertices.size() << ", UVs: " << out_uvs.size() << ", Normals: " << out_normals.size() << std::endl;

    return true;
}
