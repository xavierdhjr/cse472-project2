#pragma once
#include "particlecomponent.h"

class CAlphaComponent :
	public CParticleComponent
{
public:
	CAlphaComponent(void);
	~CAlphaComponent(void);

	virtual void Update(CParticle* particle, float dt);
};

