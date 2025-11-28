#pragma once
#include "core.hpp"
#include <list>
#include "Entity.h"
#include <random>
class Generator
{
	private:

	protected:
		int _maxEntities;
		bool active = true;
		int generateProb;
		Vector3 pos;
		std::list<Entity*> entityList;
		std::list<ForceGenerator*> forceList;
	public:
		Generator(int _max = 200);
		~Generator();
		bool isActive();
		void setmForceList(std::list<ForceGenerator*> fl);
		void addForceGen(ForceGenerator* f);
		void setActive(bool b);
		void updateOriginPos(Vector3 v);
		virtual void generate() = 0;
};

