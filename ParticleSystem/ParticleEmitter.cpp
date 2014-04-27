#include "StdAfx.h"
#include <vector>
#include "ParticleEmitter.h"
#include "ParticleComponent.h"

using namespace std;

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
	}
}