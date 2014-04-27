#pragma once
struct CParticle;

class CParticleComponent
{
public:
	CParticleComponent(void);
	~CParticleComponent(void);
	virtual void Update(CParticle* particle, float dt) = 0;
};

