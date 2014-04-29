#include "StdAfx.h"
#include <vector>
#include <math.h>
#include "ParticleEmitter.h"
#include "ParticleComponent.h"

using namespace std;

//
//        Name : Quad()
// Description : Inline function for drawing 
//               a quadrilateral.
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
	m_startPosition = vec3(0,0,0);
	m_emissionRate = 5;
	m_timer = 0;
	m_lifetime = 0.5f;
	m_size = 0.25f;

	m_type = CParticleEmitter::Box;
	m_height = 1;
	m_width = 1;
}

void CParticleEmitter::ClearComponents()
{
	for(int i = 0; i < m_components.size(); i++)
	{
		delete m_components[i];
	}
	m_components.clear();
}

CParticleEmitter::~CParticleEmitter(void)
{
	
	for(int i = 0; i < m_components.size(); ++i)
	{
		delete m_components[i];
	}
	
	for(int i = 0; i < m_particles.size(); ++i)
	{
		delete m_particles[i];
	}
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
	GLdouble a[] = {-(*it)->size, (*it)->size, (*it)->position.z};
	GLdouble b[] = {(*it)->size, (*it)->size, (*it)->position.z};
	GLdouble c[] = {-(*it)->size, -(*it)->size, (*it)->position.z};
	GLdouble d[] = {(*it)->size, -(*it)->size, (*it)->position.z};

	// move particle back

	// TODO: rotate particle
	float x, y;
	x = a[0];
	y = a[1];
	a[0] = x*cos((*it)->rotation) - y*sin((*it)->rotation) + (*it)->position.x;
	a[1] =  y*cos((*it)->rotation) + x*sin((*it)->rotation) + (*it)->position.y;
	x = b[0];
	y = b[1];
	b[0] = x*cos((*it)->rotation) - y*sin((*it)->rotation) + (*it)->position.x;
	b[1] = y*cos((*it)->rotation) + x*sin((*it)->rotation) + (*it)->position.y;
	x = c[0];
	y = c[1];
	c[0] = x*cos((*it)->rotation) - y*sin((*it)->rotation) + (*it)->position.x;
	c[1] =  y*cos((*it)->rotation) + x*sin((*it)->rotation) + (*it)->position.y;
	x = d[0];
	y = d[1];
	d[0] = x*cos((*it)->rotation) - y*sin((*it)->rotation) + (*it)->position.x;
	d[1] = y*cos((*it)->rotation) + x*sin((*it)->rotation) + (*it)->position.y;

	glColor4f(p->color.r,p->color.g,p->color.b, p->color.a);

	glEnable( GL_TEXTURE_2D );
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, m_particleTexture.TexName());
	
	//Quad(a,c,d,b);

	glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex3dv(a);
    glTexCoord2f(0, 0);
    glVertex3dv(c);
    glTexCoord2f(1, 0);
    glVertex3dv(d);
    glTexCoord2f(1, 1);
    glVertex3dv(b);
    glEnd();

	glDisable( GL_TEXTURE_2D );
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
			delete (*it);
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
				y = fmod(rand(), (2 * ylim)) - ylim + m_startPosition.y;
				particle->position = vec3(x+ m_startPosition.x,y,0);
				break;
			case Box:
				// figure out random location within box
				x = fmod(rand(), (2*m_width)) - m_width + m_startPosition.x;
				y = fmod(rand(), (2 * m_height)) - m_height + m_startPosition.y;
				particle->position = vec3(x,y,0);
				break;

		}

		//particle->texture = &m_particleTexture;

		m_particles.push_back(particle);


		// reset timer
		m_timer = 0;
	}
}

