#pragma once

#include "ParticleComponent.h"

class CCollisionComponent :
	public CParticleComponent
{
public:
	CCollisionComponent(void);
	CCollisionComponent(float groundHeight);
	~CCollisionComponent(void);

	virtual void Update(CParticle* particle, float dt);



private:
	float m_groundHeight;
	vec3 m_impulse;
	vec3 m_prevVelocity;
	bool m_impact;
};

