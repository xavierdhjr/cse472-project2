#pragma once
#include "particlecomponent.h"

class CAlphaComponent :
	public CParticleComponent
{
public:
	CAlphaComponent(void);
	~CAlphaComponent(void);

	virtual void Update(Particle* particle, float dt);
};

