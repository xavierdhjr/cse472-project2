#include "StdAfx.h"
#include "RotationComponent.h"
#include "ParticleEmitter.h"

CRotationComponent::CRotationComponent(void) : CParticleComponent()
{
	m_angularVelocity = 0;
}

CRotationComponent::CRotationComponent(float angularVelocity)
{
	m_angularVelocity = angularVelocity;
}

CRotationComponent::~CRotationComponent(void)
{
}

void CRotationComponent::Update(CParticle* particle, float dt)
{
	(*particle).rotation += m_angularVelocity*dt;
	(*particle).rotation = fmod((*particle).rotation,2.f*3.1415f);
}
