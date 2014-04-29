
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "ParticleSystem.h"
#include "ChildView.h"
#include "AccelerationComponent.h"
#include "AlphaOverLifetimeComponent.h"
#include "RandomDirectionComponent.h"
#include "RotationComponent.h"
#include "WaveformComponent.h"
#include "SpiralComponent.h"
#include "ColorChangeComponent.h"
#include "RandomStartPositionComponent.h"
#include <ctime>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_current = std::clock();
	
	emitter = new CParticleEmitter();
	emitter->SetEmissionRate(40000000.5f);
	
	// Extend the lifetime so that they don't disappear as quickly (snow)
	// emitter->SetParticleLifetime(1.0f);

	// For smaller snow particles
	// emitter->SetParticleSize(.50f);

	// For slow falling snow
	//CAccelerationComponent* accel = new CAccelerationComponent(vec3(0,-.81f,0));
	
	//CAccelerationComponent* accel = new CAccelerationComponent(vec3(0,-2.81f,0));
	//CColorChangeComponent* redtoblue = new CColorChangeComponent();
	//emitter = new CParticleEmitter(vec3(0,10,0), 1, 10, 40000000.5f, 3, 0.1, vec3(0,0,0), false);
	//emitter->RegisterComponent(accel);
	//emitter->RegisterComponent(new CSpiralComponent());
	//emitter->RegisterComponent(new CRotationComponent(10));
	//emitter->RegisterComponent(new CWaveformComponent("sounds/dub.wav"));
	//emitter->RegisterComponent(new CRandomDirectionComponent());
	//emitter->RegisterComponent(redtoblue);
	
	// Setting the snowflake texture
	//emitter->SetParticleTexture(L"textures/rain-drop-md.png");

	//FireParticles();
	m_Timer = 0;


}

CChildView::~CChildView()
{	
	delete emitter;
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}




void CChildView::OnGLDraw(CDC * pDC)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f) ;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	  //
    // Set up the camera
    //

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Determine the screen size so we can determine the aspect ratio
    int width, height;
    GetSize(width, height);
    GLdouble aspectratio = GLdouble(width) / GLdouble(height);

    // Set the camera parameters
    gluPerspective(25.,         // Vertical FOV degrees.
        aspectratio, // The aspect ratio.
        10.,         // Near clipping 40/130
        200.);       // Far clipping

    // Set the camera location
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0., 50.,    // eye x,y,z
        0., 0., 0.,       // center x,y,z
        0., 1., 0.);      // Up direction

    //
    // Some standard parameters
    //

    // Enable depth test
    glEnable(GL_DEPTH_TEST);

    // Cull backfacing polygons
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

    // Draw a coordinate axis
    glColor3d(0., 1., 1.);

    glBegin(GL_LINES);
    glVertex3d(0., 0., 0.);
    glVertex3d(12., 0., 0.);
    glVertex3d(0., 0., 0.);
    glVertex3d(0., 12., 0.);
    glVertex3d(0., 0., 0.);
    glVertex3d(0., 0., 12.);
    glEnd();


     // Create the timer
	if(m_Timer == 0)
	     m_Timer = SetTimer(1, 0.000001, NULL);

	// update stuffs
	emitter->Update((float)(( std::clock() - m_current ) / (double) CLOCKS_PER_SEC));

	m_current= std::clock();

}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	


	Invalidate();
	COpenGLWnd::OnTimer(nIDEvent);
}

/*void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}*/



void CChildView::FireParticles(void)
{
	emitter->SetParticleLifetime(10);
	emitter->SetEmitterType(CParticleEmitter::EmitterType::Point);
	emitter->RegisterComponent(new CRotationComponent(2));
	emitter->RegisterComponent(new CAccelerationComponent(vec3(0,0.1f,0)));
	emitter->RegisterComponent(new CRandomStartPositionComponent());
}
void CChildView::SnowParticles(void)
{
}
void CChildView::SmokeParticles(void)
{
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	emitter->ClearComponents();
	//cout << nChar << endl;
	
	// call functions here
	switch (nChar) {
	case '0':
		RainParticles();
		break;
	case '1':
		FireParticles();
		break;
	case '2':
		SmokeParticles();
		break;
	case '3':
		SnowParticles();
		break;
	case '4':
	
		break;
	case '5':
		
	break;
	case '6':
	
		break;
	case '7':
		
		break;
	case '8':
	
		break;
	case '9':
		
		break;
	}

	COpenGLWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::RainParticles()
{
	emitter->SetParticleTexture(L"textures/rain-drop-md.png");
	CAccelerationComponent* accel = new CAccelerationComponent(vec3(0,-.81f,0));
	emitter->SetParticleLifetime(2);
	emitter->SetParticleSize(0.1f);
	emitter->SetEmitterType(CParticleEmitter::Box);
	emitter->SetWidth(10);
	emitter->SetHeight(1);
	emitter->SetStartPosition(vec3(0,10,0));
	//emitter = new CParticleEmitter(vec3(0,10,0), 1, 10, 40000000.5f, 3, 0.1, vec3(0,0,0), false);
	emitter->RegisterComponent(accel);
}