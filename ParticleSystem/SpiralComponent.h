#pragma once
#include "ParticleComponent.h"

#define TWOPI (2. * 3.1415962)

class CSpiralComponent :
	public CParticleComponent
{
public:
	CSpiralComponent(void);
	CSpiralComponent(float period, vec3 center, float radius, float lifetime);
	~CSpiralComponent(void);

	virtual void Update(CParticle* particle, float dt);

private:
	vec3 * m_center;
	float m_period;
	int m_primaryaxis;
	float m_radius;
	float m_angle;
	float m_time;
	float m_lifetime;
};

