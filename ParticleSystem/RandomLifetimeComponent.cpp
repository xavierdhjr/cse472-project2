#include "StdAfx.h"
#include "RandomLifetimeComponent.h"

CRandomLifetimeComponent::CRandomLifetimeComponent(float randMin, float randMax)
{
	m_randMin = randMin;
	m_randMax = randMax;
}

CRandomLifetimeComponent::CRandomLifetimeComponent(void)
{
}


CRandomLifetimeComponent::~CRandomLifetimeComponent(void)
{
}

void CRandomLifetimeComponent::Update(CParticle* particle, float dt)
{
	if(particle->age == 0)
	{
		particle->lifetime = randFloat(m_randMin, m_randMax);
	}
}