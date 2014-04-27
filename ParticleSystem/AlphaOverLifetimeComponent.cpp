#include "StdAfx.h"
#include "AlphaOverLifetimeComponent.h"


CAlphaOverLifetimeComponent::CAlphaOverLifetimeComponent(void)
{
}


CAlphaOverLifetimeComponent::~CAlphaOverLifetimeComponent(void)
{
}

void CAlphaOverLifetimeComponent::Update(CParticle* particle, float dt)
{
	particle->color.a = 1 - particle->age / particle->lifetime;
}