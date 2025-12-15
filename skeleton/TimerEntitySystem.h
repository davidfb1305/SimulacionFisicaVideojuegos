#pragma once
#include "EntitySystem.h"
class TimerEntitySystem : public EntitySystem
{
private:
protected:
	float _genTime;
	float _actTime;
public:
	TimerEntitySystem(EntityManager* em,float genTime);
	~TimerEntitySystem();
	virtual bool update(double t) override;
};

