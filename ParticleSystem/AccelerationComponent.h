#pragma once
#include "particlecomponent.h"

class CAccelerationComponent :
	public CParticleComponent
{
public:
	CAccelerationComponent(void);
	~CAccelerationComponent(void);

	virtual void Update(CParticle* particle, float dt);
};

