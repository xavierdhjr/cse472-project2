#pragma once
#include "particlecomponent.h"
class CColorChangeComponent :
	public CParticleComponent
{
public:
	CColorChangeComponent(void);
	CColorChangeComponent(vec4 from, vec4 to, float period);
	~CColorChangeComponent(void);

	virtual void Update(CParticle* particle, float dt);

private:
	float m_time;
	vec4 m_from;
	vec4 m_to;
	float m_period;
};

