#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/glm.hpp>

class OBJLoader {
public:
	static bool loadOBJ(
		const std::string& path,
		std::vector<glm::vec3>& out_vertices,
		std::vector<glm::vec2>& out_uvs,
		std::vector<glm::vec3>& out_normals
	);
};
#endif