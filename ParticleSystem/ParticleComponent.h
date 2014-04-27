#pragma once
#include "ParticleEmitter.h"

class CParticleComponent
{
public:
	CParticleComponent(void);
	~CParticleComponent(void);

	void Update(float gameTime, Particle particle);
};

