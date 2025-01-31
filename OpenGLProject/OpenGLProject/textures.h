#pragma once

#include <string>
#include "texture.h"

class SandTexture : public Texture {
public:
	SandTexture() {
		diffusePath = "textures/Sand_008_Texture/Sand_008_basecolor.png";
		roughnessPath = "textures/Sand_008_Texture/Sand_008_roughness.png";
		normalPath = "textures/Sand_008_Texture/Sand_008_normal.png";
	}
};

class AsphaltTexture : public Texture {
public:
	AsphaltTexture() {
		diffusePath = "textures/asphalt/asphalt_color.png";
		roughnessPath = "textures/asphalt/asphalt_roughness.png";
		normalPath = "textures/asphalt/asphalt_normal.png";
	}
};

class PavementTexture : public Texture {
public:
	PavementTexture() {
		diffusePath = "textures/pavement/pavement_color.png";
		roughnessPath = "textures/pavement/pavement_roughness.png";
		normalPath = "textures/pavement/pavement_normal.png";
	}
};

class GrassTexture : public Texture {
public:
	GrassTexture() {
		diffusePath = "textures/grass/grass_color.png";
		roughnessPath = "textures/grass/grass_roughness.png";
		normalPath = "textures/grass/grass_normal.png";
	}
};

class BrickTexture : public Texture {
public:
	BrickTexture() {
		diffusePath = "textures/bricks/bricks_color.png";
		roughnessPath = "textures/bricks/bricks_roughness.png";
		normalPath = "textures/bricks/bricks_normal.png";
	}
};

class GlassTexture : public Texture {
public:
	GlassTexture() {
		diffusePath = "textures/glass/glass_color.png";
		roughnessPath = "textures/glass/glass_roughness.png";
		normalPath = "textures/glass/glass_normal.png";
	}
};

class RoofTexture : public Texture {
public:
	RoofTexture() {
		diffusePath = "textures/roof/roof_color.png";
		roughnessPath = "textures/roof/roof_roughness.png";
		normalPath = "textures/roof/roof_normal.png";
	}
};