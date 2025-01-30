#pragma once
#include <string>
#include "texture.h"

class SandTexture : public Texture{
public:
	SandTexture() {
		diffusePath = "textures/Sand_008_Texture/Sand_008_basecolor.png";
		roughnessPath = "textures/Sand_008_Texture/Sand_008_roughness.png";
		normalPath = "textures/Sand_008_Texture/Sand_008_normal.png";
	}
};