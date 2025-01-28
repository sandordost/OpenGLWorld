#pragma once
#include <vector>
#include <glad/glad.h>

class Mesh {
public:
    Mesh();
    virtual ~Mesh();

    void SetupMesh(const std::vector<float>& vertices, const std::vector<float>& normals);

    void Draw() const;

protected:
    GLuint VAO, VBO, NBO;
    size_t verticesCount;
};
