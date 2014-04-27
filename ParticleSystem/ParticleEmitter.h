#pragma once
struct Vector3
{
	double x;
	double y;
	double z;
};

struct Particle
{
	Vector3 position;
	Vector3 velocity;
	int age;
	int lifespan;
	int color;
	int size;
};

class CParticleEmitter
{


public:
	CParticleEmitter(void);
	~CParticleEmitter(void);

	void Update(float gameTime);
};

