#pragma once
#include "ParticleEmitter.h"

using namespace glm;

class CParticleComponent
{
public:
	CParticleComponent(void);
	~CParticleComponent(void);

	virtual void Update(CParticle* particle, float dt) = 0;
};

