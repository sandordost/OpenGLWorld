#pragma once
#include "material.h"

class DefaultMaterial : public Material {
public:
    DefaultMaterial() : Material("", "", 0.0f, 0.2f) {}
};
