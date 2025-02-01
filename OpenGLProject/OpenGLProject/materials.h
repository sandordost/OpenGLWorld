#pragma once
#include <string>
#include "textures.h"
#include "pbrMaterial.h"
#include "matteMaterial.h"

class SandMaterial : public PBRMaterial {
public:
	SandMaterial() : PBRMaterial(SandTexture()) {
		shininess = 20.0f;
		smoothness = 0.2f;
	}
};

class AsphaltMaterial : public PBRMaterial {
public:
	AsphaltMaterial() : PBRMaterial(AsphaltTexture()) {
		shininess = 20.0f;
		smoothness = 0.6f;
	}
};

class PavementMaterial : public PBRMaterial {
public:
	PavementMaterial() : PBRMaterial(PavementTexture()) {
		shininess = 20.0f;
		smoothness = 0.2f;
	}
};

class GrassMaterial : public PBRMaterial {
public:
	GrassMaterial() : PBRMaterial(GrassTexture()) {
		shininess = 20.0f;
		smoothness = 0.9f;
	}
};

class BrickMaterial : public PBRMaterial {
public:
	BrickMaterial() : PBRMaterial(BrickTexture()) {
		shininess = 0.0f;
		smoothness = 0.9f;
		normalStrength = 1.2f;
	}
};

class GlassMaterial : public PBRMaterial {
public:
	GlassMaterial() : PBRMaterial(GlassTexture()) {
		shininess = 5.0f;
		smoothness = 0.05f;
	}
};

class RoofMaterial : public PBRMaterial {
public:
	RoofMaterial() : PBRMaterial(RoofTexture()) {
		shininess = 12.0f;
		smoothness = 0.5f;
	}
};

class CarMaterial : public MatteMaterial {
public:
	CarMaterial() : MatteMaterial(80, 80, 80, 255) {
	}
};