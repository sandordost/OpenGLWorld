#pragma once
#include "mesh.h"

class CubeMesh : public Mesh {
public:
	CubeMesh(const std::shared_ptr<Material>& _material)
		: Mesh(_material) {
		std::vector<float> vertices = {
			// Voorvlak (+Z)
			-0.5f, -0.5f,  0.5f,
			0.5f, -0.5f,  0.5f,
			0.5f,  0.5f,  0.5f,

			0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,
			-0.5f, -0.5f,  0.5f,

			// Bovenkant (+Y)
			-0.5f,  0.5f,  0.5f,
			0.5f,  0.5f,  0.5f,
			0.5f,  0.5f, -0.5f,

			0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f,  0.5f,

			// Rechterzijvlak (+X)
			0.5f, -0.5f, -0.5f,
			0.5f,  0.5f, -0.5f,
			0.5f,  0.5f,  0.5f,

			0.5f,  0.5f,  0.5f,
			0.5f, -0.5f,  0.5f,
			0.5f, -0.5f, -0.5f,

			// Achtervlak (-Z)
			-0.5f, -0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f,
			0.5f,  0.5f, -0.5f,

			0.5f,  0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,

			// Linkerzijvlak (-X)
			-0.5f,  0.5f,  0.5f,
			-0.5f,  0.5f,  -0.5f,
			-0.5f, -0.5f,  -0.5f,

			-0.5f, -0.5f, -0.5f,
			-0.5f, -0.5f,  0.5f,
			-0.5f,  0.5f,  0.5f,

			// Onderkant (-Y)
			0.5f, -0.5f,  -0.5f,
			-0.5f, -0.5f, 0.5f,
			-0.5f, -0.5f,  -0.5f,

			-0.5f, -0.5f,  0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f, -0.5f,  0.5f,
		};

		std::vector<float> normals = {
			// Voorvlak (+Z)
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,

			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,
			0.0f,  0.0f,  1.0f,

			// Bovenkant (+Y)
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,

			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,
			0.0f,  1.0f,  0.0f,

			// Rechterzijvlak (+X)
			1.0f,  0.0f,  0.0f,
			1.0f,  0.0f,  0.0f,
			1.0f,  0.0f,  0.0f,

			1.0f,  0.0f,  0.0f,
			1.0f,  0.0f,  0.0f,
			1.0f,  0.0f,  0.0f,

			// Achtervlak (-Z)
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,

			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,
			0.0f,  0.0f, -1.0f,

			// Linkerzijvlak (-X)
			-1.0f,  0.0f,  0.0f,
			-1.0f,  0.0f,  0.0f,
			-1.0f,  0.0f,  0.0f,

			-1.0f,  0.0f,  0.0f,
			-1.0f,  0.0f,  0.0f,
			-1.0f,  0.0f,  0.0f,

			// Onderkant (-Y)
			0.0f, -1.0f,  0.0f,
			0.0f, -1.0f,  0.0f,
			0.0f, -1.0f,  0.0f,

			0.0f, -1.0f,  0.0f,
			0.0f, -1.0f,  0.0f,
			0.0f, -1.0f,  0.0f
		};

		std::vector<float> texCoords = {
			0.0f, 0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
			1.0f, 1.0f,  0.0f, 1.0f,  0.0f, 0.0f,

			0.0f, 0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
			1.0f, 1.0f,  0.0f, 1.0f,  0.0f, 0.0f,

			0.0f, 0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
			1.0f, 1.0f,  0.0f, 1.0f,  0.0f, 0.0f,

			0.0f, 0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
			1.0f, 1.0f,  0.0f, 1.0f,  0.0f, 0.0f,

			0.0f, 0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
			1.0f, 1.0f,  0.0f, 1.0f,  0.0f, 0.0f,

			0.0f, 0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
			1.0f, 1.0f,  0.0f, 1.0f,  0.0f, 0.0f,
		};

		SetupMesh(vertices, normals, texCoords);
	}
};
