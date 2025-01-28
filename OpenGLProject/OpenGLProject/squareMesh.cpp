#include "squareMesh.h"

SquareMesh::SquareMesh() {
    std::vector<float> vertices = {
        // Positie (3D)
        -0.5f, -0.5f, 0.0f,  // Linksonder
         0.5f, -0.5f, 0.0f,  // Rechtsonder
        -0.5f,  0.5f, 0.0f,  // Linksboven

        -0.5f,  0.5f, 0.0f,  // Linksboven
         0.5f, -0.5f, 0.0f,  // Rechtsonder
         0.5f,  0.5f, 0.0f   // Rechtsboven
    };

    std::vector<float> normals = {
         0.0f,  0.0f,  1.0f,   
         0.0f,  0.0f,  1.0f,   
         0.0f,  0.0f,  1.0f,

         0.0f,  0.0f,  1.0f,   
         0.0f,  0.0f,  1.0f,   
         0.0f,  0.0f,  1.0f
    };

    SetupMesh(vertices, normals);
}