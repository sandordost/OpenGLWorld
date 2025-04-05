#pragma once
#include "sceneObject.h"
#include "cubeMesh.h"
#include "squareMesh.h"
#include "pyramidMesh.h"
#include "animation.h"
#include "materials.h"
#include "triangleMesh.h"

class HouseObject : public SceneObject {
public:
    HouseObject() : SceneObject() {
		auto sandMaterial = std::make_shared<SandMaterial>();
		auto brickMaterial = std::make_shared<BrickMaterial>();
		auto glassMaterial = std::make_shared<GlassMaterial>();
		auto roofMaterial = std::make_shared<RoofMaterial>();

        auto base = std::make_shared<CubeMesh>(brickMaterial);
        auto roof = std::make_shared<PyramidMesh>(roofMaterial);
        auto door = std::make_shared<CubeMesh>(sandMaterial);
        auto window = std::make_shared<SquareMesh>(glassMaterial);
		auto frontPoarch = std::make_shared<TriangleMesh>(roofMaterial);

        roof->Scale(glm::vec3(1.35f, 0.7f, 1.35f));
        roof->Translate(glm::vec3(0.0f, 1, 0.0f));

        door->Scale(glm::vec3(0.3f, 0.7f, 0.1f));
        door->Translate(glm::vec3(0.0f, -0.3f, -4.8f));

        window->Scale(glm::vec3(0.3f, 0.3f, 1.0f));
        window->Translate(glm::vec3(0.3f, 0.2f, 0.51f));

        frontPoarch->Scale(glm::vec3(1.0f, 1.5f, 1.5f));
        frontPoarch->Rotate(-90, glm::vec3(1.0f, 0.0f, 0.0f));
        frontPoarch->Translate(glm::vec3(0.0f, 0.65f, -0.331f));

        AddMesh(base);
        AddMesh(roof);
        AddMesh(door);
        AddMesh(window);
		AddMesh(frontPoarch);
    }
};
