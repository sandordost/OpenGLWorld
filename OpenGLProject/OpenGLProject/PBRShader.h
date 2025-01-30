#pragma once

#include "Shader.h"

class PBRShader : public Shader {
public:
	PBRShader() : Shader("shaders/vertexShader.glsl", "shaders/PBRShader.glsl") {}
};