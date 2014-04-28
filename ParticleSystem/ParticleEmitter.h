#pragma once
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

// fwd declaration so components have all the includes / structs from here
class CParticleComponent;

struct CParticle
{
	CParticle()
	{
		color = vec4(.97,0.5,0,1);
		position = vec3(0,0,0);
		velocity = vec3(0,0,0);
		rotation = 0;
		lifetime = 2;
		age = 0;
		size = 1;
	}

	vec4 color;
	vec3 position;
	vec3 velocity;
	//mat4 rotation;
	float rotation;
	float lifetime;
	float age;
	float size;
	CGrTexture* texture;
};


class CParticleEmitter
{


public:
	enum EmitterType 
	{
		Point,
		Sphere,
		Box
	};

	CParticleEmitter(void);
	CParticleEmitter(vec3 startPosition, float emissionRate = 0.5f, float lifetime=10, float size=1, vec3 initialVelocity = vec3(0,0,0), bool randomStartDirection=false);
	CParticleEmitter(vec3 startPosition, float radius, float emissionRate = 0.5f, float lifetime=10, float size=1, vec3 initialVelocity = vec3(0,0,0), bool randomStartDirection=false);
	CParticleEmitter(vec3 startPosition, float height, float width, float emissionRate = 0.5f, float lifetime=10, float size=1, vec3 initialVelocity = vec3(0,0,0), bool randomStartDirection=false);
	~CParticleEmitter(void);

	void RegisterComponent(CParticleComponent * component);

	void SetStartPosition(vec3 pos){ m_startPosition = pos; }
	void SetEmissionRate(float rate){ m_emissionRate = rate; }
	void SetParticleLifetime(float lifetime){ m_lifetime = lifetime; }
	void SetParticleSize(float size){ m_size = size; }
	void SetInitialVelocity(vec3 velocity){  }
	void SetWidth(float width){ m_width = width; }
	void SetHeight(float height){ m_height = height; }
	void SetRadius(float radius){ m_radius = radius; }
	void SetEmitterType(EmitterType type){ m_type = type; }
	void SetRandomStartDirection(bool on){  }
	void SetParticleTexture(LPCTSTR fileLocation) { m_particleTexture.LoadFile(fileLocation); }
	
	void Update(float gameTime);

private:
	std::vector<CParticleComponent *> m_components;
	std::vector<CParticle *> m_particles;
	float m_emissionRate;
	vec3 m_startPosition;
	float m_timer;
	float m_lifetime;
	float m_size;
	void DrawParticle(std::vector<CParticle *>::iterator it, float gameTime);

	// properties of initial emission mesh
	EmitterType m_type;
	float m_radius;
	float m_height;
	float m_width;
	CGrTexture m_particleTexture;
};

