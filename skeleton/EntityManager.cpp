#include "EntityManager.h"
#include "Particle.h"
#include "PlayerEntity.h"
#include "Bullet.h"
EntityManager::EntityManager(physx::PxPhysics* gP)
{
	entityList = std::list<Entity*>();
	gPhysics = gP;
}

EntityManager::~EntityManager()
{
	ReleaseEntities();
}



Entity* EntityManager::createSphere(const Vector3& transform, double r, const Vector4& color, const float& mat1, const float& mat2, const float& mat3)
{
	Entity* aux = new Entity();
	aux->mGeo = new physx::PxSphereGeometry(r);
	aux->mtrans = new physx::PxTransform(transform);
	aux->mshape = CreateShape(*aux->mGeo, gPhysics->createMaterial(mat1,mat2,mat3));
	aux->mItem = new RenderItem(aux->mshape, aux->mtrans, color);
	RegisterRenderItem(aux->mItem);
	entityList.push_back(aux);
	return aux;
}
Entity* EntityManager::createParticle(const Vector3& transform, const Vector3& v, const Vector3& a, double d,int mt, double r, int rc, int rct, Vector3 maxdis, const Vector4& color, const float& mat1, const float& mat2, const float& mat3)
{
	Particle* aux = new Particle(transform,v,a,d, mt,rc,rct,maxdis);
	aux->mGeo = new physx::PxSphereGeometry(r);
	aux->mtrans = new physx::PxTransform(transform);
	aux->mshape = CreateShape(*aux->mGeo, gPhysics->createMaterial(mat1, mat2, mat3));
	aux->mItem = new RenderItem(aux->mshape, aux->mtrans, color);
	RegisterRenderItem(aux->mItem);
	entityList.push_back(aux);
	aux->setLastPos(transform);
	return aux;
}
Entity* EntityManager::createMassParticle(const Vector3& transform, const Vector3& v, const Vector3& vr, double ms, const Vector3& a, double d, int mt, double r, int rc, int rct, Vector3 maxdis, const Vector4& color, const float& mat1, const float& mat2, const float& mat3)
{
	Particle* aux = new Particle(transform,v,a,d,mt,rc,rct,maxdis);
	aux->setMass(ms);
		//Particle(transform,v,vr,ms,a,d,mt,rc,rct,maxdis);
	aux->mGeo = new physx::PxSphereGeometry(r);
	aux->mtrans = new physx::PxTransform(transform);
	aux->mshape = CreateShape(*aux->mGeo, gPhysics->createMaterial(mat1, mat2, mat3));
	aux->mItem = new RenderItem(aux->mshape, aux->mtrans, color);
	RegisterRenderItem(aux->mItem);
	entityList.push_back(aux);
	aux->setLastPos(transform);
	return aux;
}
Entity* EntityManager::createBullet(const Vector3& transform, const Vector3& v, const Vector3& a, double d, int mt, double r, int rc, int rct, Vector3 maxdis, const Vector4& color, const float& mat1, const float& mat2, const float& mat3, const physx::PxVec3& vrreal, double m, const physx::PxVec3& g)
{
	Bullet* aux = new Bullet(transform,v,vrreal,a,d,mt,m,g);
	aux->mGeo = new physx::PxSphereGeometry(r);
	aux->mtrans = new physx::PxTransform(transform);
	aux->mshape = CreateShape(*aux->mGeo, gPhysics->createMaterial(mat1, mat2, mat3));
	aux->mItem = new RenderItem(aux->mshape, aux->mtrans, color);
	RegisterRenderItem(aux->mItem);
	entityList.push_back(aux);
	aux->setLastPos(transform);
	return aux;
}
PlayerEntity* EntityManager::createPlayer(const Vector3 initPos,double size, physx::PxPhysics* gP)
{
	PlayerEntity* aux = new PlayerEntity(initPos, gP,this);
	aux->mGeo = new physx::PxSphereGeometry(size);
	aux->mtrans = new physx::PxTransform(initPos);
	aux->mshape = CreateShape(*aux->mGeo, gPhysics->createMaterial(1.0, 1.0, 1.0));
	aux->mItem = new RenderItem(aux->mshape, aux->mtrans, Vector4(1.0, 1.0, 1.0, 1.0));
	RegisterRenderItem(aux->mItem);
	entityList.push_back(aux);
	return aux;
}
const std::list<Entity*>& EntityManager::getEntityList()
{
	return entityList;
}
void EntityManager::createAxes()
{
	createSphere();
	createSphere(Vector3(10, 0, 0), 1, Vector4(1, 0, 0, 1));
	createSphere(Vector3(0, 10, 0), 1, Vector4(0, 1, 0, 1));
	createSphere(Vector3(0, 0, 10), 1, Vector4(0, 0, 1, 1));
}
void EntityManager::ReleaseEntities()
{
	for (auto a : entityList) {
		entityListToRemove.push_back(a);
	}
	for (auto a : entityListToRemove) {
		delete a;
	}
	entityList.clear();
}

void EntityManager::addEntity(Entity* e)
{
	entityList.push_back(e);
}

void EntityManager::updateEntities(double t)
{
	for (auto a : entityList) { 
		if (!a->update(t)) entityListToRemove.push_back(a);
	}
	for (auto a : entityListToRemove) {
		entityList.remove(a);
		delete a;
	}
	entityListToRemove.clear();
}
