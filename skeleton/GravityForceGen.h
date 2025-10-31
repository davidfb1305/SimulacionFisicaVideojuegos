#pragma once
#include "ForceGenerator.h"
class GravityForceGen : public ForceGenerator
{
private:
protected:
public:
	GravityForceGen();
	~GravityForceGen();
	bool checkAddForce(Entity* p) override;
	bool removeForceGenerator(Entity* p) override;
};

