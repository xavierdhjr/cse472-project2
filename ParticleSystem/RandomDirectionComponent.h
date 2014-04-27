#pragma once
#include "particlecomponent.h"
class CRandomDirectionComponent :
	public CParticleComponent
{
public:
	CRandomDirectionComponent(void);
	~CRandomDirectionComponent(void);

	virtual void Update(CParticle* particle, float dt);
};

