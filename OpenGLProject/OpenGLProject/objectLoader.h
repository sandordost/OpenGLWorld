#pragma once
#include <vector>
#include "mesh.h"

class ObjectLoader
{
public:
	static std::vector<Mesh> LoadOBJ(const std::string& filePath);
};

