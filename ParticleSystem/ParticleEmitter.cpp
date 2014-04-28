#include "StdAfx.h"
#include <vector>
#include <math.h>
#include "ParticleEmitter.h"
#include "ParticleComponent.h"

using namespace std;

//
//        Name : Quad()
// Description : Inline function for drawing 
//               a quadralateral.
//
inline void Quad(GLdouble *v1, GLdouble *v2, GLdouble *v3, GLdouble *v4)
{
    glBegin(GL_QUADS);
    glVertex3dv(v1);
    glVertex3dv(v2);
    glVertex3dv(v3);
    glVertex3dv(v4);
    glEnd();
}

CParticleEmitter::CParticleEmitter(vec3 startPosition, float emissionRate, float lifetime, float size, vec3 initialVelocity, bool randomStartDirection)
{
	m_startPosition = startPosition;
	m_emissionRate = emissionRate;
	m_timer = 0;
	m_lifetime = lifetime;
	m_size = size;

	m_type = CParticleEmitter::Point;
}

CParticleEmitter::CParticleEmitter(vec3 startPosition, float radius, float emissionRate, float lifetime, float size, vec3 initialVelocity, bool randomStartDirection)
{
	m_startPosition = startPosition;
	m_emissionRate = emissionRate;
	m_timer = 0;
	m_lifetime = lifetime;
	m_size = size;

	m_type = CParticleEmitter::Sphere;
	m_radius = radius;
}

CParticleEmitter::CParticleEmitter(vec3 startPosition, float height, float width, float emissionRate, float lifetime, float size, vec3 initialVelocity, bool randomStartDirection)
{
	m_startPosition = startPosition;
	m_emissionRate = emissionRate;
	m_timer = 0;
	m_lifetime = lifetime;
	m_size = size;

	m_type = CParticleEmitter::Box;
	m_height = height;
	m_width = width;
}

CParticleEmitter::CParticleEmitter(void)
{

}


CParticleEmitter::~CParticleEmitter(void)
{
}

void CParticleEmitter::DrawParticle(std::vector<CParticle *>::iterator it, float gameTime)
{
	for(std::vector<CParticleComponent *>::iterator itc = m_components.begin(); itc != m_components.end(); ++itc) 
	{
		(*itc)->Update(*it, gameTime);
	}

	CParticle* p = *it;

	// update particle position based on velocity
	(*it)->position = (*it)->position + (*it)->velocity * gameTime;

	// draw particle
	GLdouble a[] = {(*it)->position.x - (*it)->size, (*it)->position.y + (*it)->size, (*it)->position.z};
	GLdouble b[] = {(*it)->position.x + (*it)->size, (*it)->position.y + (*it)->size, (*it)->position.z};
	GLdouble c[] = {(*it)->position.x - (*it)->size, (*it)->position.y - (*it)->size, (*it)->position.z};
	GLdouble d[] = {(*it)->position.x + (*it)->size, (*it)->position.y - (*it)->size, (*it)->position.z};

	glColor4f(p->color.r,p->color.g,p->color.b, p->color.a);
	Quad(a,c,d,b);
}

void CParticleEmitter::RegisterComponent(CParticleComponent *component)
{
	m_components.push_back(component);
}

void CParticleEmitter::Update(float gameTime)
{
	for(std::vector<CParticle *>::iterator it = m_particles.begin(); it != m_particles.end(); ++it) 
	{
		DrawParticle(it, gameTime);

		// check if particle should be destroyed
		(*it)->age += gameTime;
		if((*it)->age > (*it)->lifetime)
		{
			it = m_particles.erase(it);
			//it--; // reset
			if(it == m_particles.end())
			{
				break;
			}
			DrawParticle(it, gameTime);
		}

	}

	// add particles
	// figure out emission rate, and add particles accordingly
	m_timer += gameTime;

	if(m_timer > 1/m_emissionRate)
	{
		// make a particle
		CParticle *particle = new CParticle();
		particle->lifetime = m_lifetime;
		particle->size = m_size;
		float x, y, ylim;
		// determine starting location
		switch(m_type)
		{
			case Point:
				break;
			case Sphere:
				// figure out random location within circle
				x = fmod(rand() , (2*m_radius)) - m_radius;
				ylim = sqrt(m_radius * m_radius - x * x);
				y = fmod(rand(), (2 * ylim)) - ylim;
				particle->position = vec3(x,y,0);
				break;
			case Box:
				// figure out random location within box
				x = fmod(rand(), (2*m_width)) - m_width;
				y = fmod(rand(), (2 * m_height)) - m_height;
				particle->position = vec3(x,y,0);
				break;

		}

		m_particles.push_back(particle);


		// reset timer
		m_timer = 0;
	}
}

