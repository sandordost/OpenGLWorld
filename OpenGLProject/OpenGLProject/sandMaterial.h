#pragma once
#include <string>
#include "material.h"
#include "sandTexture.h"

class SandMaterial : public Material {
public:
	SandMaterial() : Material(SandTexture(), 0.0f, 0.9f) {}
};