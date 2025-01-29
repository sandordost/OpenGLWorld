#pragma once
#include "Mesh.h"
#include "defaultMaterial.h"

class SquareMesh : public Mesh {
public:
    SquareMesh(const Material& _material) 
    : Mesh(_material){
        std::vector<float> vertices = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f,

            -0.5f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f
        };

        std::vector<float> normals = {
             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f,

             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f
        };

        std::vector<float> texCoords = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 1.0f
        };

        SetupMesh(vertices, normals, texCoords, _material);
    }
};
