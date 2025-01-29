#pragma once
#include "model.h"
#include "objLoader.h"

class AirPlaneModel : public Model {
public:
	AirPlaneModel() {

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;

		OBJLoader::loadOBJ("C:\\GitHub\\OpenGLWorld\\OpenGLProject\\OpenGLProject\\meshes\\PlayerCharacter.obj", vertices, uvs, normals);

		std::vector<float> verticesFloat;
		std::vector<float> normalsFloat;
		std::vector<float> uvsFloat;

		for (size_t i = 0; i < vertices.size(); i++) {
			verticesFloat.push_back(vertices[i].x);
			verticesFloat.push_back(vertices[i].y);
			verticesFloat.push_back(vertices[i].z);
		}

		for (size_t i = 0; i < normals.size(); i++) {
			normalsFloat.push_back(normals[i].x);
			normalsFloat.push_back(normals[i].y);
			normalsFloat.push_back(normals[i].z);
		}

		for (size_t i = 0; i < uvs.size(); i++) {
			uvsFloat.push_back(uvs[i].x);
			uvsFloat.push_back(uvs[i].y);
		}

		auto mesh = std::make_shared<Mesh>();
		mesh->SetupMesh(verticesFloat, normalsFloat, uvsFloat, DefaultMaterial());

		AddMesh(mesh);
	}
};