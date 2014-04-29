#pragma once
#include "particlecomponent.h"
class CRandomDirectionComponent :
	public CParticleComponent
{
public:
	CRandomDirectionComponent(void);
	CRandomDirectionComponent(vec3 randMin, vec3 randMax);
	~CRandomDirectionComponent(void);

	virtual void Update(CParticle* particle, float dt);
private:
	vec3 m_randMin;
	vec3 m_randMax;
};

