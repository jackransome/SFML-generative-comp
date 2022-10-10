#pragma once
#include <glm/glm.hpp>

class InputGenerator {
public:
	InputGenerator();
	glm::vec3 getNextInput();
private:
	glm::vec3 pastInputs[10];
	int iterator;
};