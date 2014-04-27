#pragma once
class ParticleComponent;
#include <vector>

struct Particle
{

};

class CParticleEmitter
{


public:
	CParticleEmitter(void);
	~CParticleEmitter(void);

	void Update(float gameTime);

private:
	std::vector<ParticleComponent *> components;
};

