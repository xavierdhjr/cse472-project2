#pragma once
struct CParticle;
#include <gl/GL.h>

class CParticleComponent
{
public:
	CParticleComponent(void);
	~CParticleComponent(void);

	virtual void Update(CParticle* particle, float dt) = 0;
};

