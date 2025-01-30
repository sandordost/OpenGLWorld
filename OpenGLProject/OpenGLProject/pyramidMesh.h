#pragma once
#include "mesh.h"

class PyramidMesh : public Mesh {
public:
	PyramidMesh(const std::shared_ptr<Material>& _material) 
	: Mesh(_material) {
		std::vector<float> vertices = {
			// Voorvlak
			-0.5f, -0.5f,  0.5f,
			0.5f, -0.5f,  0.5f,
			0.0f,  0.5f,  0.0f,
			// Rechterzijvlak
			0.5f, -0.5f,  0.5f,
			0.5f, -0.5f, -0.5f,
			0.0f,  0.5f,  0.0f,
			// Achtervlak
			0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			0.0f,  0.5f,  0.0f,
			// Linkerzijvlak
			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f,  0.5f,
			0.0f,  0.5f,  0.0f,
			// Ondervlak
			0.5f, -0.5f, -0.5f,
			0.5f, -0.5f,  0.5f,
			-0.5f, -0.5f,  0.5f,

			-0.5f, -0.5f,  0.5f,
			-0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
		};
		std::vector<float> normals = {
			// Voorvlak
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			// Rechterzijvlak
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			// Achtervlak
			0.0f, 0.0f, -1.0f,
			0.0f, 0.0f, -1.0f,
			0.0f, 0.0f, -1.0f,
			// Linkerzijvlak
			-1.0f, 0.0f, 0.0f,
			-1.0f, 0.0f, 0.0f,
			-1.0f, 0.0f, 0.0f,
			// Ondervlak
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,

			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
		};
		std::vector<float> texCoords = {
			// Voorvlak
			0.0f, 0.0f,
			1.0f, 0.0f,
			0.5f, 1.0f,
			// Rechterzijvlak
			0.0f, 0.0f,
			1.0f, 0.0f,
			0.5f, 1.0f,
			// Achtervlak
			0.0f, 0.0f,
			1.0f, 0.0f,
			0.5f, 1.0f,
			// Linkerzijvlak
			0.0f, 0.0f,
			1.0f, 0.0f,
			0.5f, 1.0f,
			// Ondervlak
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,

			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,
		};
		SetupMesh(vertices, normals, texCoords);
	}
};