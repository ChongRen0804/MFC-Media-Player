#if !defined(AFX_DIALOG2_H__7AA83F30_9258_4FC9_8B83_B42649BCA990__INCLUDED_)
#define AFX_DIALOG2_H__7AA83F30_9258_4FC9_8B83_B42649BCA990__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dialog2 dialog

class Dialog2 : public CDialog
{
// Construction
public:
	Dialog2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dialog2)
	enum { IDD = IDD_DIALOG2 };
	CString	m_name2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dialog2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dialog2)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG2_H__7AA83F30_9258_4FC9_8B83_B42649BCA990__INCLUDED_)
