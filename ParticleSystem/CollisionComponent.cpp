#include "StdAfx.h"
#include "CollisionComponent.h"
#include "ParticleEmitter.h"

CCollisionComponent::CCollisionComponent(void) : CParticleComponent()
{
	m_groundHeight = 0;
	m_impulse = vec3(0,0,0);
	m_impact = false;
}

CCollisionComponent::CCollisionComponent(float GroundHeight)
{
	m_groundHeight = GroundHeight;
	m_impulse = vec3(0,0,0);
	m_impact = false;
}

CCollisionComponent::~CCollisionComponent(void)
{
}

void CCollisionComponent::Update(CParticle* particle, float dt)
{
	//if((*particle).velocity.y < -15)
	//{
		if((*particle).position.y < m_groundHeight - 0.5  && (*particle).velocity.y < -1)
		{
			(*particle).position.y = m_groundHeight;
			// add impulse
			(*particle).velocity *= -0.5;
			//= (-((*particle).velocity*10);
		}
		else //if((*particle).position.y <= m_groundHeight + 0.5 && (*particle).velocity.y >= -1)
		{
			//(*particle).velocity.y = 0;
		}
	//}

	/*if(m_impact)
	{
		// impulse negative velocity
		(*particle).position += m_impulse;

		// lerp impulse to 0
		m_impulse /= 1.1;

		if(pow(sqrt(m_impulse.x*m_impulse.x +m_impulse.y*m_impulse.y),2) < 0.01)
		{
			m_impulse *= 0;
			m_impact = false;
		}
	}*/

}
