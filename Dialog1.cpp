// Dialog1.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer6.h"
#include "Dialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int flag=0;
/////////////////////////////////////////////////////////////////////////////
// Dialog1 dialog


Dialog1::Dialog1(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog1)
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void Dialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog1)
	DDX_Text(pDX, IDC_EDIT1, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog1, CDialog)
	//{{AFX_MSG_MAP(Dialog1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog1 message handlers

void Dialog1::OnButton1() 
{
	// TODO: Add your control notification handler code here
	flag=1;
	UpdateData(TRUE);
	OnCancel();
}

void Dialog1::OnButton2() 
{
	// TODO: Add your control notification handler code here
	flag=0;
	CDialog::OnOK();
}

void Dialog1::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
