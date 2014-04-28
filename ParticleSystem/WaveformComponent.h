#pragma once
#include "particlecomponent.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// WAVE PCM soundfile format (you can find more in https://ccrma.stanford.edu/courses/422/projects/WaveFormat/ )
typedef struct header_file
{
    char chunk_id[4];
    int chunk_size;
    char format[4];
    char subchunk1_id[4];
    int subchunk1_size;
    short int audio_format;
    short int num_channels;
    int sample_rate;			// sample_rate denotes the sampling rate.
    int byte_rate;
    short int block_align;
    short int bits_per_sample;
    char subchunk2_id[4];
    int subchunk2_size;			// subchunk2_size denotes the number of samples.
} header;

typedef struct header_file* header_p;

class CWaveformComponent :
	public CParticleComponent
{
public:
	CWaveformComponent(std::string fileName);
	~CWaveformComponent(void);
	virtual void Update(CParticle* particle, float dt);

private:
	FILE* wavFile;
	int* m_samples;
	int m_sampleCount;
	int m_currentSamplePos;
};

