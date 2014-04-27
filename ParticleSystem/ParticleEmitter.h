#pragma once
#include "ParticleComponent.h"
#include <vector>
#include "ShaderWnd\external\glew-1.9.0\include\GL\glew.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include "ShaderWnd\external/glew-1.9.0/include/GL/glext.h"
#include "ShaderWnd\external/glew-1.9.0/include/GL/wglext.h"
#include "ShaderWnd\external/glm/glm.hpp"
#include "ShaderWnd\external/glm/gtc/constants.hpp"
#include "ShaderWnd\external/glm/gtc/matrix_transform.hpp"
#include "ShaderWnd\external//glm/gtc/type_ptr.hpp"
#include <math.h>
#include "graphics/GrTexture.h"

using namespace glm;

struct CParticle
{
	CParticle()
	{
		color = vec4(0,0,0,1);
		position = vec3(0,0,0);
		velocity = vec3(0,0,0);
		lifetime = 2;
		age = 0;
		size = 1;
	}

	vec4 color;
	vec3 position;
	vec3 velocity;
	mat4 rotation;
	int lifetime;
	float age;
	float size;
	CGrTexture* texture;
};

class CParticleEmitter
{


public:
	CParticleEmitter(void);
	CParticleEmitter(vec3 startPositon, float emissionRate, float lifetime);
	~CParticleEmitter(void);

	void RegisterComponent(CParticleComponent * component);

	
	void Update(float gameTime);

private:
	std::vector<CParticleComponent *> m_components;
	std::vector<CParticle *> m_particles;
	float m_emissionRate;
	vec3 m_startPosition;
	float m_timer;
	float m_lifetime;
	void DrawParticle(std::vector<CParticle *>::iterator it, float gameTime);
};

