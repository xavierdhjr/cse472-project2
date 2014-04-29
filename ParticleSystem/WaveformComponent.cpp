#include "StdAfx.h"
#include "WaveformComponent.h"


CWaveformComponent::CWaveformComponent(std::string fileName)
{
	m_sampleCount = 0;
	m_currentSamplePos = 0;
	wavFile = fopen(fileName.c_str(),"rb");		// Open wave file in read mode
	//FILE * outfile = fopen("Output.wav","wb");		// Create output ( wave format) file in write mode

	const int BUFSIZE = 512;					// BUFSIZE can be changed according to the frame size required (eg:512)
	int count = 0;						// For counting number of frames in wave file.
	short int buff16[BUFSIZE];				// short int used for 16 bit as input data format is 16 bit PCM audio
	header_p meta = (header_p)malloc(sizeof(header));	// header_p points to a header struct that contains the wave file metadata fields
	int nb;							// variable storing number of byes returned

	int currentSample = 0;
	if (wavFile)
	{
		fread(meta, 1, sizeof(header), wavFile);
		m_samples = new int[meta->subchunk2_size];
		//fwrite(meta,1, sizeof(*meta), outfile);
		//cout << " Size of Header file is "<<sizeof(*meta)<<" bytes" << endl;
		//cout << " Sampling rate of the input wave file is "<< meta->sample_rate <<" Hz" << endl;
		//cout << " Number of samples in wave file are " << meta->subchunk2_size << " samples" << endl;



		while (!feof(wavFile))
		{
			nb = fread(buff16,1,BUFSIZE,wavFile); // Reading data in chunks of BUFSIZE
			for(int i = 0; i < nb; ++i)
			{
				m_samples[currentSample] = buff16[i];
				currentSample++;
			}
			//cout << nb <<endl;
			count++;					// Incrementing Number of frames

			/* Insert your processing code here*/
			
		}
	}
	m_sampleCount = currentSample;
	fclose(wavFile);
	delete meta;
}


CWaveformComponent::~CWaveformComponent(void)
{
	delete[] m_samples;
}

void CWaveformComponent::Update(CParticle* particle, float dt)
{
	if(particle->age == 0)
	{
		int sample_rate = 1000;
		m_currentSamplePos += sample_rate;
		float x = (m_currentSamplePos / sample_rate) % 50 - 25;
		float y = (m_samples[m_currentSamplePos % m_sampleCount] / 2000) * dt * 10;
		particle->position = vec3(x, y,0);
	}
}
