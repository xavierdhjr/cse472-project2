#include "StdAfx.h"
#include "SpiralComponent.h"
#include "ParticleEmitter.h"

CSpiralComponent::CSpiralComponent(void)
{
	m_period = 2.0f;
	m_center = new vec3(0, -1, 0);
	m_primaryaxis = 1;
	m_radius = 1.;
	m_angle = 0.;
	m_time = 0.0;
	m_lifetime = 2.0;
}

CSpiralComponent::CSpiralComponent(float period, vec3 center, float radius, float lifetime)
{
	m_period = period;
	m_center = new vec3(center);
	float components[3] = {abs(center.x), abs(center.y), abs(center.z)};
	float max = 0;
	m_primaryaxis = 0;
	for (int i=0; i<3; i++)
	{
		if (components[i] > max)
		{
			max = components[i];
			m_primaryaxis = i;
		}
	}
	m_radius = radius;
	m_angle = 0.;
	m_time = 0.0;
	m_lifetime = 2.0;
}


CSpiralComponent::~CSpiralComponent(void)
{
}

void CSpiralComponent::Update(CParticle* particle, float dt)
{
	(*particle).velocity = *(new vec3(0., 0., 0.));
	m_time += dt;
	if (m_time > m_lifetime)
		m_time = 0.;
	m_angle += dt * m_period * TWOPI;
	if (m_angle > TWOPI)
		m_angle -= TWOPI;
	vec3 * rotation_component;
	if (m_primaryaxis == 0)
	{
		rotation_component = new vec3(0., m_radius * cos(m_angle), m_radius * sin(m_angle));
	} else if (m_primaryaxis == 1)
	{
		rotation_component = new vec3(m_radius * cos(m_angle), 0., m_radius * sin(m_angle));
	} else 
	{
		rotation_component = new vec3(m_radius * cos(m_angle), m_radius * sin(m_angle), 0.);
	}
	(*particle).position = (*m_center) * m_time + *rotation_component;
}