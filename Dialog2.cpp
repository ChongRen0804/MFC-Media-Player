// Dialog2.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer6.h"
#include "Dialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int flag2=0;
/////////////////////////////////////////////////////////////////////////////
// Dialog2 dialog


Dialog2::Dialog2(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog2::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog2)
	m_name2 = _T("");
	//}}AFX_DATA_INIT
}


void Dialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog2)
	DDX_Text(pDX, IDC_EDIT1, m_name2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog2, CDialog)
	//{{AFX_MSG_MAP(Dialog2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog2 message handlers

void Dialog2::OnOK() 
{
	// TODO: Add extra validation here
	flag2=1;
	UpdateData(TRUE);
	CDialog::OnOK();
}

void Dialog2::OnCancel() 
{
	// TODO: Add extra cleanup here
	flag2=0;
	CDialog::OnOK();
	CDialog::OnCancel();
}
