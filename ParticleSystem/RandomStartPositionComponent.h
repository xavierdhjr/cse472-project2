#pragma once
#include "particlecomponent.h"
class CRandomStartPositionComponent :
	public CParticleComponent
{
public:
	CRandomStartPositionComponent(void);
	CRandomStartPositionComponent(vec3 max, vec3 min);
	~CRandomStartPositionComponent(void);

	virtual void Update(CParticle* particle, float dt);
private:
	vec3 m_randMax;
	vec3 m_randMin;
};

