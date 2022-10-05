#pragma once

#include "Organism.h"

class World;

class Plant : public Organism
{
public:
	Plant(int x, int y);
	void action(World *world) override;
	void collision(Organism *organism, World* world) override;
	virtual bool isForceSuplement();
};

