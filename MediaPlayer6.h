// MediaPlayer6.h : main header file for the MEDIAPLAYER6 application
//

#if !defined(AFX_MEDIAPLAYER6_H__D0AC20CA_4925_4BE9_92E9_75CA6963B24C__INCLUDED_)
#define AFX_MEDIAPLAYER6_H__D0AC20CA_4925_4BE9_92E9_75CA6963B24C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayer6App:
// See MediaPlayer6.cpp for the implementation of this class
//

class CMediaPlayer6App : public CWinApp
{
public:
	CMediaPlayer6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaPlayer6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMediaPlayer6App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIAPLAYER6_H__D0AC20CA_4925_4BE9_92E9_75CA6963B24C__INCLUDED_)
