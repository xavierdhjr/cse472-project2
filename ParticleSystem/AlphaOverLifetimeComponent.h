#pragma once
#include "particlecomponent.h"
class CAlphaOverLifetimeComponent :
	public CParticleComponent
{
public:
	CAlphaOverLifetimeComponent(void);
	~CAlphaOverLifetimeComponent(void);

	
	virtual void Update(CParticle* particle, float dt);
};

