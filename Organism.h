#pragma once
#include <string>
#include <random>

class World;

class Organism
{
public:
	Organism(int x, int y);
	virtual void action(World *world) = 0;
	virtual void collision(Organism* organism, World* world) = 0;
	virtual void draw() = 0;
	virtual std::string getName() const = 0;
	int getForce();
	int getAge();
	int getInitiative();
	int getX();
	int getY();
	void setXY(int x, int y);
	virtual void kill();
	bool isAlive();
	bool hasBaby();
	int getBabyCount();
	bool multiply(World* world);
	void setForce(int force);
	void setAge(int age);
	void setAlive(bool alive);
	void setBabyCount(int count);
protected:
	int getRandomNumber(int a, int b);
	int randomPoint(int point, int max);
	int force = 0;
	int initiative = 0;
	int x, y;
	int age = 1;
	bool alive = true;
	int baby = 0;
};

