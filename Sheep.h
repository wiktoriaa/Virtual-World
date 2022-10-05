#pragma once

#include "Animal.h"
#include <string>

class Sheep : public Animal
{
public:
	Sheep(int x, int y);
	void draw() override;
	std::string getName() const override;
	bool isReflectedAttack(Organism* attacker) override;
};


