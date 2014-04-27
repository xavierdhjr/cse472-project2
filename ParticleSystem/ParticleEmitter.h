#pragma once
#include "ParticleComponent.h"
#include <vector>

struct CParticle
{

};

class CParticleEmitter
{


public:
	CParticleEmitter(void);
	~CParticleEmitter(void);

	void Update(float gameTime);

private:
	std::vector<CParticleComponent *> m_components;
	std::vector<CParticle *> m_particles;
};

