#pragma once
class ParticleComponent;
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

struct Particle
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
	CParticleEmitter(void);
	~CParticleEmitter(void);

	void Update(float gameTime);

private:
	std::vector<ParticleComponent *> components;
};

