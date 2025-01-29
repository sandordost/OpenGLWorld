#pragma once
#include "model.h"
#include "objectLoader.h"

class AirPlaneModel : public Model {
public:
	AirPlaneModel() {
		std::vector<Mesh> loadedMeshes = ObjectLoader::LoadOBJ("meshes/PlayerCharacter.obj");

		for (auto& mesh : loadedMeshes) {
			AddMesh(std::make_shared<Mesh>(mesh));
		}
	}
};