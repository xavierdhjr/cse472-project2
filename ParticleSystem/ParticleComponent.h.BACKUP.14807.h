#pragma once
#include "ParticleEmitter.h"

class CParticleComponent
{
public:
	CParticleComponent(void);
	~CParticleComponent(void);
<<<<<<< HEAD
	virtual void Update(Particle* particle, float dt) = 0;
=======

	void Update(float gameTime, Particle particle);
>>>>>>> d446d8b08098494bf5e0fceb8f951e662e73fb2b
};

