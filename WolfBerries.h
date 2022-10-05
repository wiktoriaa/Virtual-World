#pragma once

#include "Plant.h"
#include <string>

class WolfBerries : public Plant
{
public:
	WolfBerries(int x, int y);
	void draw() override;
	std::string getName() const override;
};

