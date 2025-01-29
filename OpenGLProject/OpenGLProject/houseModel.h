#pragma once
#include "model.h"
#include "cubeMesh.h"
#include "squareMesh.h"
#include "pyramidMesh.h"

class HouseModel : public Model {
public:
    HouseModel() {
        auto base = std::make_shared<CubeMesh>(DefaultMaterial());
        auto roof = std::make_shared<PyramidMesh>(DefaultMaterial());
        auto door = std::make_shared<CubeMesh>(DefaultMaterial());
        auto window = std::make_shared<SquareMesh>(DefaultMaterial());

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
