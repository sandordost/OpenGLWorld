#pragma once
#include "mesh.h"
#include "defaultMaterial.h"
#include "material.h"

class TriangleMesh : public Mesh {
public:
	TriangleMesh(const Material& _material) 
	: Mesh(_material){
		std::vector<float> vertices = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		std::vector<float> normals = {
			 0.0f,  0.0f,  1.0f,
			 0.0f,  0.0f,  1.0f,
			 0.0f,  0.0f,  1.0f
		};

		std::vector<float> texCoords = {
			0.0f, 0.0f,
			1.0f, 0.0f,
			0.5f, 1.0f
		};

		SetupMesh(vertices, normals, texCoords, _material);
	}
};
