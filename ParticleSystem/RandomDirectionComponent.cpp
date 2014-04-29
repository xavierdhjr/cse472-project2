#include "StdAfx.h"
#include "RandomDirectionComponent.h"
#include <cmath>
#include <cstdlib>


CRandomDirectionComponent::CRandomDirectionComponent(void)
{
}
CRandomDirectionComponent::CRandomDirectionComponent(vec3 randMin, vec3 randMax)
{
	m_randMin = randMin;
	m_randMax = randMax;
}

CRandomDirectionComponent::~CRandomDirectionComponent(void)
{
}

void CRandomDirectionComponent::Update(CParticle* particle, float dt)
{
	if(particle->age >= 0)
	{
		float x = randFloat(m_randMax.x, m_randMin.x);
		float y = randFloat(m_randMax.y, m_randMin.y);
		float z = randFloat(m_randMax.z, m_randMin.z);
		particle->velocity == vec3(x, y, z);
	}
}