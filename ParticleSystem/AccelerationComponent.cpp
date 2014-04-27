#include "StdAfx.h"
#include "AccelerationComponent.h"
#include "ParticleEmitter.h"

CAccelerationComponent::CAccelerationComponent(void) : CParticleComponent()
{
	m_acceleration = new vec3(0,0,0);
}

CAccelerationComponent::CAccelerationComponent(vec3 acceleration)
{
	m_acceleration = new vec3(acceleration);
}

CAccelerationComponent::~CAccelerationComponent(void)
{
}

void CAccelerationComponent::Update(CParticle* particle, float dt)
{
	(*particle).velocity = (*particle).velocity + *m_acceleration;
}
