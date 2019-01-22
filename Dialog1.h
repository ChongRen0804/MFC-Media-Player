#if !defined(AFX_DIALOG1_H__96B6CA9A_B1FD_431C_B124_5B0D7321A448__INCLUDED_)
#define AFX_DIALOG1_H__96B6CA9A_B1FD_431C_B124_5B0D7321A448__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dialog1 dialog

class Dialog1 : public CDialog
{
// Construction
public:
	Dialog1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dialog1)
	enum { IDD = IDD_DIALOG1 };
	CString	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dialog1)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1_H__96B6CA9A_B1FD_431C_B124_5B0D7321A448__INCLUDED_)
