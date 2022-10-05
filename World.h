#pragma once
#include "Organism.h"
#include <vector>

class World
{
public:
	World();
	~World();
	void createBoard(int x, int y);
	void drawWorld();
	void round();
	int getX();
	int getY();
	Organism* getOrganism(int x, int y);
	void addOrganism(std::string name, int x, int y);
	void moveOrganism(Organism* organism, int x, int y, int newX, int newY);
	void removeFromBoard(Organism* organism);
	void addToBoard(Organism* organism);
	void killIfAnimal(Organism* organism);
	void saveWorld();
	bool loadWorldFromFile();
private:
	std::vector<std::vector<Organism*>> board;
	std::vector<Organism*> organismList;
	void sortOrganisms();
	int x = 0, y = 0;
};

class ComparatorByForceAge {
public:
	bool operator() (Organism* a, Organism* b) {
		if (a->getInitiative() > b->getInitiative()) return true;
		else if (a->getInitiative() == b->getInitiative() && a->getAge() > b->getAge()) return true;
		return false;
		
		//return ((a->getForce() < b->getForce()) || (a->getForce() == b->getForce() && a->getAge() < b->getAge()));
	}
};

