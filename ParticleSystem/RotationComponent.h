#pragma once

#include "ParticleComponent.h"

class CRotationComponent :
	public CParticleComponent
{
public:
	CRotationComponent(void);
	CRotationComponent(float rotation, float angularVelocity = 0);
    ~CRotationComponent(void);

	virtual void Update(CParticle* particle, float dt);



private:
	float m_rotation;
	float m_angularVelocity;
};

