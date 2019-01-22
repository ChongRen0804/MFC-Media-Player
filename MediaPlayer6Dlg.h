// MediaPlayer6Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
#include "wmpcontrols.h"
#include "wmpsettings.h"
#include "wmpplaylist.h"
#include "wmpmedia.h"
//}}AFX_INCLUDES

#if !defined(AFX_MEDIAPLAYER6DLG_H__523AA236_DAA7_45E7_AD56_92112A317D9B__INCLUDED_)
#define AFX_MEDIAPLAYER6DLG_H__523AA236_DAA7_45E7_AD56_92112A317D9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayer6Dlg dialog

class CMediaPlayer6Dlg : public CDialog
{
// Construction
public:
	CMediaPlayer6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMediaPlayer6Dlg)
	enum { IDD = IDD_MEDIAPLAYER6_DIALOG };
	CListCtrl	m_list;
	CWMPPlayer4	m_player;
	CWMPControls m_control;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaPlayer6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMediaPlayer6Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton4();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnAbout();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnStop();
	afx_msg void OnFullscreen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIAPLAYER6DLG_H__523AA236_DAA7_45E7_AD56_92112A317D9B__INCLUDED_)
