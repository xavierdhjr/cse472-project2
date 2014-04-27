
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "ParticleSystem.h"
#include "ChildView.h"
#include "AccelerationComponent.h"
#include <ctime>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_current = std::clock();
	
	CAccelerationComponent* accel = new CAccelerationComponent(vec3(0,-0.05,0));
	emitter = new CParticleEmitter(vec3(0,0,0), 5.5f, 2, 0.1);
	emitter->RegisterComponent(accel);

	m_Timer = 0;


}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
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
	     m_Timer = SetTimer(1, 30, NULL);

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
