#pragma once
#include "ParticleEmitter.h"

using namespace glm;

class CParticleComponent
{
public:
	CParticleComponent(void);
	~CParticleComponent(void);

	virtual void Update(CParticle* particle, float dt) = 0;

	float randFloat(float HI, float LO)
	{
		return LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
	}
};

