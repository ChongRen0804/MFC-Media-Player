#if !defined(AFX_DIALOG3_H__1CFB5F1C_4508_486C_A233_E99197A8F0B4__INCLUDED_)
#define AFX_DIALOG3_H__1CFB5F1C_4508_486C_A233_E99197A8F0B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dialog3 dialog

class Dialog3 : public CDialog
{
// Construction
public:
	Dialog3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dialog3)
	enum { IDD = IDD_DIALOG3 };
	CString	m_name3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dialog3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dialog3)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG3_H__1CFB5F1C_4508_486C_A233_E99197A8F0B4__INCLUDED_)
