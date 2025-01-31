#pragma once
#include "scene.h"
#include "materials.h"
#include <memory>

#include <glm/gtx/rotate_vector.hpp>
#include "houseObject.h"
#include "lantern.h"

class MainScene : public Scene {
public:
	MainScene() : Scene() {
		
		// Grass
		auto grass = std::make_shared<SceneObject>();
		auto grassMaterial = std::make_shared<GrassMaterial>();
		CreateGrass(grass, 20, 20, grassMaterial);
		grass->Translate(glm::vec3(-20.0f, 0.0f, 20.0f));

		// Road
		auto road = std::make_shared<SceneObject>();
		auto roadMaterial = std::make_shared<PavementMaterial>();
		CreateRoadLoop(road, 40, roadMaterial);
		road->Translate(glm::vec3(8.0f, 0.001f, 8.0f));

		// House 1
		auto house1 = std::make_shared<HouseObject>();
		house1->Scale(glm::vec3(2.0f, 2.0f, 2.0f));
		house1->Translate(glm::vec3(1.0f, 0.5f, 1.0f));
		house1->Rotate(180, glm::vec3(0.0f, 1.0f, 0.0f));

		// Small Latern
		auto latern = std::make_shared<LanternObject>();
		latern->Translate(glm::vec3(1.2f, 0.0f, 500.0f));


		// Add objects to scene
		AddObject(grass);
		AddObject(road);
		AddObject(house1);
		AddObject(latern);
	}

	void Update() override {

	}

private:
	void CreateRoadLoop(const std::shared_ptr<SceneObject>& roadObject, int numberOfSegments, const std::shared_ptr<Material>& roadMaterial) {
		glm::vec3 currentPosition(0.0f, 0.001f, 0.0f);
		glm::vec3 direction(0.0f, 1.0f, 0.0f);
		float segmentLength = 2.0f;

		for (int i = 0; i < numberOfSegments; i++) {
			auto roadMesh = std::make_shared<SquareMesh>(roadMaterial);
			roadMesh->Rotate(90.0f, glm::vec3(-1.0f, 0.0f, 0.0f));
			roadMesh->Scale(glm::vec3(2.0f, 2.0f, 1.0f));
			roadMesh->Translate(currentPosition);
			roadObject->AddMesh(roadMesh);

			currentPosition += direction * (segmentLength / 2);

			if ((i + 1) % 8 == 0) {
				direction = glm::rotateZ(direction, glm::radians(90.0f));
			}
		}
	};

	void CreateGrass(const std::shared_ptr<SceneObject>& grassObject, int segmentsX, int segmentsY, const std::shared_ptr<Material>& grassMaterial) {
		glm::vec3 basePosition(0.0f, -0.01f, 0.0f);
		float segmentSize = 2.0f; // Elk grasvlak is 10x10 units groot

		for (int x = 0; x < segmentsX; x++) {
			for (int y = 0; y < segmentsY; y++) {
				// Maak een nieuw mesh aan voor elk segment
				auto grassMesh = std::make_shared<SquareMesh>(grassMaterial);
				grassMesh->Rotate(90.0f, glm::vec3(-1.0f, 0.0f, 0.0f));
				grassMesh->Scale(glm::vec3(segmentSize, segmentSize, 1.0f));

				// Bereken de wereldpositie van het segment
				glm::vec3 position = basePosition + glm::vec3(x * segmentSize / 2, y * segmentSize / 2, 0.0f);
				grassMesh->Translate(position);

				// Voeg het mesh toe aan het `SceneObject`
				grassObject->AddMesh(grassMesh);
			}
		}
	};
};