#pragma once
#include <string>
#include "sandTexture.h"
#include "pbrMaterial.h"

class SandMaterial : public PBRMaterial {
public:
	SandMaterial() : PBRMaterial(SandTexture()) {
		shininess = 20.0f;
		smoothness = 0.2f;
	}
};