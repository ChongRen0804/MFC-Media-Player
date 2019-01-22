// Dialog3.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer6.h"
#include "Dialog3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int flag3=0;
/////////////////////////////////////////////////////////////////////////////
// Dialog3 dialog


Dialog3::Dialog3(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog3::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog3)
	m_name3 = _T("");
	//}}AFX_DATA_INIT
}


void Dialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog3)
	DDX_Text(pDX, IDC_EDIT1, m_name3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog3, CDialog)
	//{{AFX_MSG_MAP(Dialog3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog3 message handlers

void Dialog3::OnOK() 
{
	// TODO: Add extra validation here
	flag3=1;
	UpdateData(TRUE);
	CDialog::OnOK();
}

void Dialog3::OnCancel() 
{
	// TODO: Add extra cleanup here
	flag3=0;
	CDialog::OnOK();
	CDialog::OnCancel();
}
