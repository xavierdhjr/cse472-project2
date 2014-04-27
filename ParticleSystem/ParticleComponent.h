#pragma once
#include "ParticleEmitter.h"
#include <gl/GL.h>

class CParticleComponent
{
public:
	CParticleComponent(void);
	~CParticleComponent(void);
	virtual void Update(Particle* particle, float dt) = 0;
};

