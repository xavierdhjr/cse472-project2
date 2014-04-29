#pragma once
#include "particlecomponent.h"
class CRandomLifetimeComponent :
	public CParticleComponent
{
public:
	CRandomLifetimeComponent(float randMin, float randMax);
	CRandomLifetimeComponent(void);
	~CRandomLifetimeComponent(void);

	virtual void Update(CParticle* particle, float dt);
private:
	float m_randMin;
	float m_randMax;
};

