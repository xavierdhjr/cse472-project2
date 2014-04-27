
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window
#include "OpenGLWnd.h"
#include <ctime>

#include "ParticleEmitter.h"


class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	CParticleEmitter * emitter;

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

private:
	std::clock_t m_current;
	UINT_PTR m_Timer;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

};

