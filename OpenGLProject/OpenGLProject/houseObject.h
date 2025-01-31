#pragma once
#include "sceneObject.h"
#include "cubeMesh.h"
#include "squareMesh.h"
#include "pyramidMesh.h"
#include "animation.h"
#include "materials.h"

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

        roof->Scale(glm::vec3(1.35f, 0.7f, 1.35f));
        roof->Translate(glm::vec3(0.0f, 1, 0.0f));

        door->Scale(glm::vec3(0.3f, 0.6f, 0.1f));
        door->Translate(glm::vec3(0.0f, -0.2f, 0.51f));

        window->Scale(glm::vec3(0.3f, 0.3f, 1.0f));
        window->Translate(glm::vec3(0.3f, 0.2f, 0.51f));

        AddMesh(base);
        AddMesh(roof);
        AddMesh(door);
        AddMesh(window);

    }
};
