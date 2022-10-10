#include "InputGenerator.h"
#include <cstdlib>

InputGenerator::InputGenerator() {
	iterator = 0;
}

glm::vec3 InputGenerator::getNextInput(){
	glm::vec3 temp = glm::vec3((rand() % 50) - 25, (rand() % 50) - 25, (rand() % 50) - 25);
	pastInputs[iterator] = temp;
	iterator++;
	if (iterator == 10) {
		iterator = 0;
	}
	return temp;
}
