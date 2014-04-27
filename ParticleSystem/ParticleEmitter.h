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
	vec4 color;
	vec3 position;
	mat4 rotation;
	int lifetime;
	int age;
	float size;
	vec3 velocity;
	CGrTexture* texture;
};

class CParticleEmitter
{


public:
	CParticleEmitter(vec3 startPositon, int emissionRate);
	~CParticleEmitter(void);


	
	void Update(float gameTime);

private:
	std::vector<CParticleComponent *> m_components;
	std::vector<CParticle *> m_particles;
	int m_emissionRate;
	vec3 m_startPosition;

};

