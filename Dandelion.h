#pragma once

#include "Plant.h"
#include <string>

class Dandelion : public Plant
{
public:
	Dandelion(int x, int y);
	void draw() override;
	std::string getName() const override;
	void action(World* world) override;
};

