#pragma once

#include "Plant.h"
#include <string>

class Guarana : public Plant
{
public:
	Guarana(int x, int y);
	void draw() override;
	std::string getName() const override;
	bool isForceSuplement() override;
};

