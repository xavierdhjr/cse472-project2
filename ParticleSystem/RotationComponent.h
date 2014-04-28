#pragma once

#include "ParticleComponent.h"

class CRotationComponent :
	public CParticleComponent
{
public:
	CRotationComponent(void);
	CRotationComponent(float angularVelocity);
    ~CRotationComponent(void);

	virtual void Update(CParticle* particle, float dt);



private:
	float m_angularVelocity;
};

