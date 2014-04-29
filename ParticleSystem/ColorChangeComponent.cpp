#include "StdAfx.h"
#include "ColorChangeComponent.h"


CColorChangeComponent::CColorChangeComponent(void)
{
	m_from = vec4(1., 0., 0., 1.);
	m_to = vec4(0., 0., 1., 1.);
	m_period = 0.5f;
	m_time = 0.0f;
}

CColorChangeComponent::CColorChangeComponent(vec4 from, vec4 to, float period)
{
	m_from = from;
	m_to = to;
	m_period = period;
	m_time = 0.0f;
}

CColorChangeComponent::~CColorChangeComponent(void)
{
}

void CColorChangeComponent::Update(CParticle* particle, float dt)
{
	m_time += dt;
	if (m_time >= m_period) 
		m_time = 0.0f;
	particle->color.a = m_from.a + (m_time / m_period) *(m_to.a - m_from.a);
	particle->color.r = m_from.r + (m_time / m_period) *(m_to.r - m_from.r);
	particle->color.a = m_from.g + (m_time / m_period) *(m_to.g - m_from.g);
	particle->color.a = m_from.b + (m_time / m_period) *(m_to.b - m_from.b);
}