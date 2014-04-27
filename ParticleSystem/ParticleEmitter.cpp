#include "StdAfx.h"
#include <vector>
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

CParticleEmitter::CParticleEmitter(vec3 startPosition, int emissionRate)
{
	m_startPosition = startPosition;
	m_emissionRate = emissionRate;
	m_timer = 0;
}

CParticleEmitter::CParticleEmitter(void)
{

}


CParticleEmitter::~CParticleEmitter(void)
{
}


void CParticleEmitter::Update(float gameTime)
{
	for(std::vector<CParticle *>::iterator it = m_particles.begin(); it != m_particles.end(); ++it) 
	{
		for(std::vector<CParticleComponent *>::iterator itc = m_components.begin(); itc != m_components.end(); ++itc) 
		{
			(*itc)->Update(*it, gameTime);
		}

		// draw particle
		GLdouble a[] = {(*it)->position.x - (*it)->size, (*it)->position.y + (*it)->size, (*it)->position.z};
	    GLdouble b[] = {(*it)->position.x + (*it)->size, (*it)->position.y + (*it)->size, (*it)->position.z};
		GLdouble c[] = {(*it)->position.x - (*it)->size, (*it)->position.y - (*it)->size, (*it)->position.z};
		GLdouble d[] = {(*it)->position.x + (*it)->size, (*it)->position.y - (*it)->size, (*it)->position.z};

		glColor3d(0.7,0,0);
		Quad(a,b,c,d);

		// check if particle should be destroyed
		(*it)->age += gameTime;
		if((*it)->age > (*it)->lifetime)
		{
			it = m_particles.erase(it);
			it--; // reset
		}

		

	}

	// add particles
	// figure out emission rate, and add particles accordingly
	m_timer += gameTime;

	if(m_timer > m_emissionRate)
	{
		// make a particle
		CParticle *particle = new CParticle();
		m_particles.push_back(particle);


		// reset timer
		m_timer = 0;
	}
}

