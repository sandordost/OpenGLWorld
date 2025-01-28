#include "CubeMesh.h"

CubeMesh::CubeMesh() {
    // Vertex data voor een kubus (36 vertices, 12 driehoeken)
    std::vector<float> vertices = {
		// Voorvlak
		-0.5f, -0.5f,  0.5f, // Linksonder
		0.5f, -0.5f,  0.5f, // Rechtsonder
		0.5f,  0.5f,  0.5f, // Rechtsboven

		0.5f,  0.5f,  0.5f, // Rechtsboven
		-0.5f,  0.5f,  0.5f, // Linksboven
		-0.5f, -0.5f,  0.5f, // Linksonder

		// Achtervlak
		-0.5f, -0.5f, -0.5f, // Linksonder
		0.5f, -0.5f, -0.5f, // Rechtsonder
		0.5f,  0.5f, -0.5f, // Rechtsboven

		0.5f,  0.5f, -0.5f, // Rechtsboven
		-0.5f,  0.5f, -0.5f, // Linksboven
		-0.5f, -0.5f, -0.5f, // Linksonder

		// Linkerzijvlak
		-0.5f,  0.5f,  0.5f, // Rechtsboven
		-0.5f,  0.5f, -0.5f, // Rechtsboven
		-0.5f, -0.5f, -0.5f, // Linksonder

		-0.5f, -0.5f, -0.5f, // Linksonder
		-0.5f, -0.5f,  0.5f, // Linksonder
		-0.5f,  0.5f,  0.5f, // Rechtsboven

		// Rechterzijvlak
		0.5f,  0.5f,  0.5f, // Rechtsboven
		0.5f,  0.5f, -0.5f, // Rechtsboven
		0.5f, -0.5f, -0.5f, // Linksonder

		0.5f, -0.5f, -0.5f, // Linksonder
		0.5f, -0.5f,  0.5f, // Linksonder
		0.5f,  0.5f,  0.5f, // Rechtsboven

		// Bovenkant
		-0.5f,  0.5f,  0.5f, // Linksonder
		0.5f,  0.5f,  0.5f, // Rechtsonder
		0.5f,  0.5f, -0.5f, // Rechtsboven

		0.5f,  0.5f, -0.5f, // Rechtsboven
		-0.5f,  0.5f, -0.5f, // Linksboven
		-0.5f,  0.5f,  0.5f, // Linksonder

		// Onderkant
		-0.5f, -0.5f,  0.5f, // Linksonder
		0.5f, -0.5f,  0.5f, // Rechtsonder
		0.5f, -0.5f, -0.5f, // Rechtsboven

		0.5f, -0.5f, -0.5f, // Rechtsboven
		-0.5f, -0.5f, -0.5f, // Linksboven
		-0.5f, -0.5f,  0.5f, // Linksonder
    };

	std::vector<float> normals = {
		// Voorvlak
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		// Achtervlak
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		// Linkerzijvlak
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,

		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,

		// Rechterzijvlak
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		// Bovenkant
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		// Onderkant
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,

		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f
	};

    SetupMesh(vertices, normals);
}
