#pragma once

#include "ParticleComponent.h"

class CAccelerationComponent :
	public CParticleComponent
{
public:
	CAccelerationComponent(void);
	CAccelerationComponent(vec3 acceleration);
	~CAccelerationComponent(void);

	virtual void Update(CParticle* particle, float dt);



private:
	vec3* m_acceleration;
};

