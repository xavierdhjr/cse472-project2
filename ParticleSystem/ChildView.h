
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window
#include "OpenGLWnd.h"

#include "ParticleEmitter.h"

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	CParticleEmitter emitter;

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void OnGLDraw(CDC * pDC);
};

