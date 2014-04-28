#include "StdAfx.h"
#include "RotationComponent.h"
#include "ParticleEmitter.h"

CRotationComponent::CRotationComponent(void) : CParticleComponent()
{
	m_rotation = 0;
	m_angularVelocity = 0;
}

CRotationComponent::CRotationComponent(float rotation, float angularVelocity)
{
	m_rotation = rotation;
	m_angularVelocity = angularVelocity;
}

CRotationComponent::~CRotationComponent(void)
{
}

void CRotationComponent::Update(CParticle* particle, float dt)
{
	m_rotation += fmod(m_angularVelocity*dt,2.f*3.1415f);
	(*particle).rotation = m_rotation;
}
