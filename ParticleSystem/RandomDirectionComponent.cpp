#include "StdAfx.h"
#include "RandomDirectionComponent.h"
#include <cmath>
#include <cstdlib>


CRandomDirectionComponent::CRandomDirectionComponent(void)
{
}


CRandomDirectionComponent::~CRandomDirectionComponent(void)
{
}

void CRandomDirectionComponent::Update(CParticle* particle, float dt)
{
	if(particle->age == 0)
	{
		particle->velocity = vec3(rand() % 50 - 25, rand() % 50 - 25, 0);
	}
}