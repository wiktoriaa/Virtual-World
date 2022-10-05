#pragma once

#include "Plant.h"
#include <string>

class Grass : public Plant
{
public:
	Grass(int x, int y);
	void draw() override;
	std::string getName() const override;
};

