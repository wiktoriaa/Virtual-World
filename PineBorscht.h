#pragma once

#include "Plant.h"
#include <string>

class World;

class PineBorscht : public Plant
{
public:
	PineBorscht(int x, int y);
	void draw() override;
	std::string getName() const override;
	void action(World* world) override;
};

