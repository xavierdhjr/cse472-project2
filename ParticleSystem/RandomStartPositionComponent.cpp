#include "StdAfx.h"
#include "RandomStartPositionComponent.h"


CRandomStartPositionComponent::CRandomStartPositionComponent(void)
{
	m_randMax = vec3(2.5f, 0.1f, 0.f);
	m_randMin = vec3(-2.5f, 0.f, 0.f);
}

CRandomStartPositionComponent::CRandomStartPositionComponent(vec3 max, vec3 min)
{
	m_randMax = max;
	m_randMin = min;
}


CRandomStartPositionComponent::~CRandomStartPositionComponent(void)
{
}

void CRandomStartPositionComponent::Update(CParticle* particle, float dt)
{
	if(particle->age == 0)
	{
		float x = randFloat(m_randMax.x,m_randMin.x);
		float y = randFloat(m_randMax.y,m_randMin.y);
		float z = randFloat(m_randMax.z,m_randMin.z);
		particle->position = vec3(x,y,z);
	}
}