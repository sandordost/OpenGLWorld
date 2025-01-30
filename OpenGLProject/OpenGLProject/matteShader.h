#pragma once

#include "Shader.h"

class MatteShader : public Shader {
public:
	MatteShader() : Shader("shaders/vertexShader.glsl", "shaders/matteShader.glsl") {}
};