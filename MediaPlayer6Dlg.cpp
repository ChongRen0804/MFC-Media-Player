// MediaPlayer6Dlg.cpp : implementation file
//
#include <fstream>
#include <readline/readline.h>
#include <readline/history.h>
#include "stdio.h"
#include "stdafx.h"
#include "MediaPlayer6.h"
#include "MediaPlayer6Dlg.h"
#include "DIALOG1.h "
#include "DIALOG2.h "
#include "DIALOG3.h "
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CStdioFile file;
CStdioFile file1;
CStdioFile file2;
CStdioFile file3;
CStdioFile file4;
CStdioFile file5;
CStdioFile file6;
CStdioFile file7;
CStdioFile file8;
CStdioFile file9;
CStdioFile file10;
CStdioFile file11;
CString str;
CString tempstr;
extern int flag;
extern int flag2;
extern int flag3;
int i=0;
int listnum=0;
int listloc=0;//菜单列表双击位置
int dgl=0;
int hang=0;
int listx=0;//内容双击位置
int listlocd=0;//菜单单击位置
int spaceflag=1;
CString dizhi,as;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayer6Dlg dialog

CMediaPlayer6Dlg::CMediaPlayer6Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMediaPlayer6Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMediaPlayer6Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMediaPlayer6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMediaPlayer6Dlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_OCX1, m_player);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMediaPlayer6Dlg, CDialog)
	//{{AFX_MSG_MAP(CMediaPlayer6Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_FULLSCREEN, OnFullscreen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayer6Dlg message handlers

BOOL CMediaPlayer6Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	dgl=0;
	// Add "About..." menu item to system menu.
	if(file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeReadWrite))
    {
		//AfxMessageBox("success");
	}
	else
	{
		//AfxMessageBox("fail");
	}
	m_list.DeleteAllItems();
	m_list.InsertItem(0,"最近播放");
	file.SeekToBegin();
	i=1;
	while(file.ReadString(str))//while循环读取每一行字符
	{
		//AfxMessageBox(str);
		m_list.InsertItem(i,str);
		i++;
	}
	listnum=i;
	file.Close();
	i=0;
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_control=static_cast<CWMPControls>(m_player.GetControls());
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMediaPlayer6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMediaPlayer6Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMediaPlayer6Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMediaPlayer6Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char  szFileFilter[]="Mp3  File(*.mp3)|*.mp3|"  
              "Wma   File(*.wma)|*.wma|"  
              "Video   File(*.dat)|*.dat|"  
              "Wave   File(*.wav)|*.wav|"  
              "AVI   File(*.avi)|*.avi|"  
              "Movie   File(*.mov)|*.mov|"  
              "Media   File(*.mmm)|*.mmm|"  
              "Mid   File(*.mid;*,rmi)|*.mid;*.rmi|"  
              "MPEG   File(*.mpeg)|*.mpeg|"    
              "All   File(*.*)|*.*|| ";//文件类型过滤  
       CFileDialog  dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,szFileFilter);  
       if(dlg.DoModal()==IDOK)  
       {
            CString   PathName=dlg.GetPathName();  
            PathName.MakeUpper();  
            m_player.SetUrl(PathName);
			file11.Open("A:\\Project\\MediaPlayer6\\txt\\11.txt",CFile::modeReadWrite);
			file11.SeekToEnd();
			file11.WriteString(PathName);
			file11.WriteString("\n");
			file11.Close();
			as=PathName;
       }  
}

void CMediaPlayer6Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
    CMediaPlayer6Dlg::OnStop();
	SendMessage(WM_CLOSE);
}

void CMediaPlayer6Dlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	Dialog1  Dlg;
	Dlg.DoModal();
	if(file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeReadWrite))
    {
		//AfxMessageBox("success");
	}
	else
	{
		//AfxMessageBox("fail");
	}
	if(flag==1)//是否点击确定
	{
		file.SeekToEnd();
		file.WriteString(Dlg.m_name);
		//AfxMessageBox(Dlg.m_name);
		file.WriteString("\n");
		//m_list.InsertItem(0,Dlg.m_name);
	}
	m_list.DeleteAllItems();
	m_list.InsertItem(0,"最近播放");
	file.SeekToBegin();
	i=1;
	while(file.ReadString(str))//while循环读取每一行字符
	{
		//AfxMessageBox(str);
		m_list.InsertItem(i,str);
		i++;
	}
	listnum=i-1;
	file.Close();
}

void CMediaPlayer6Dlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	for(i=0;i<=listnum;i++)
	{
		  if( m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
		 {
			//str.Format(_T("选中了第%d行"), i+1);
			//AfxMessageBox(str);
			listlocd=i;
		 }
	 }
	*pResult = 0;
}

void CMediaPlayer6Dlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeCreate | CFile::modeWrite);
	file1.Open("A:\\Project\\MediaPlayer6\\txt\\1.txt",CFile::modeCreate | CFile::modeWrite);
	file2.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeCreate | CFile::modeWrite);
	file3.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeCreate | CFile::modeWrite);
	file4.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeCreate | CFile::modeWrite);
	file5.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeCreate | CFile::modeWrite);
	file6.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeCreate | CFile::modeWrite);
	file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate | CFile::modeWrite);
	file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate | CFile::modeWrite);
	file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeWrite);
	file10.Open("A:\\Project\\MediaPlayer6\\txt\\10.txt",CFile::modeCreate | CFile::modeWrite);
	m_list.DeleteAllItems();
	m_list.InsertItem(0,"最近播放");
	file.Close();
	file1.Close();
	file2.Close();
	file3.Close();
	file4.Close();
	file5.Close();
	file6.Close();
	file7.Close();
	file8.Close();
	file9.Close();
	file10.Close();

	if(file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeReadWrite))
		{
			//AfxMessageBox("success");
		}
		else
		{
			//AfxMessageBox("fail");
		}
			m_list.DeleteAllItems();
			file.SeekToBegin();
			m_list.InsertItem(0,"最近播放");
			i=1;
			while(file.ReadString(str))//while循环读取每一行字符
		{
			//AfxMessageBox(str);
			m_list.InsertItem(i,str);
			i++;
		}
		i=0;
		dgl=0;
		file.Close();

}

void CMediaPlayer6Dlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	if(dgl==0)//检测是第几级菜单
	{
		  for(i=0;i<=listnum;i++)
		  {
			   if( m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
			   {
					//str.Format(_T("选中了第%d行"), i+1);
					//AfxMessageBox(str);
				   listloc=i;
			   }
		  }
		switch(listloc)
		{

		case 0:
			{
				//AfxMessageBox("aaaa");
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\11.txt",CFile::modeReadWrite))
				{
					//AfxMessageBox("success");
				}
				else
				{
					//AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=0;
				file.Close();
				break;
			}
		case 1:
			{
				//AfxMessageBox("aaaa");
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\1.txt",CFile::modeReadWrite))
				{
					//AfxMessageBox("success");
				}
				else
				{
					//AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=0;
				file.Close();
				break;
			}

		case 2:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=1;
				file.Close();
				break;
			}
		case 3:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=2;
				file.Close();
				break;
			}
		case 4:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=3;
				file.Close();
				break;
			}
		case 5:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=4;
				file.Close();
				break;
			}

		case 6:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=5;
				file.Close();
				break;
			}
		case 7:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=6;
				file.Close();
				break;
			}
			
		case 8:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=7;
				file.Close();
				break;
			}
		
		case 9:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=8;
				file.Close();
				break;
			}
		case 10:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\10.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				m_list.DeleteAllItems();
				file.SeekToBegin();
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					m_list.InsertItem(i,str);
					i++;
				}
				//file.Close();
				dgl=1;
				listx=9;
				file.Close();
				break;
			}
		}//大case

	
	}//if
	else/////////////////////////////第二级菜单
	{
		
		for(i=0;i<100;i++)
		  {
			   if( m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
			   {
				//	str.Format(_T("选中了第%d行"), i+1);
				//	AfxMessageBox(str);
				   listloc=i;
				   break;
			   }
		  }
		switch(listx)
		{
		case 0:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\1.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				break;
			}

		case 1:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				break;
			}
		case 2:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				
				break;
			}
		case 3:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				
				break;
			}
		case 4:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				break;
			}

		case 5:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}

				break;
			}
		case 6:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
		
				break;
			}
			
		case 7:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
			
				break;
			}
		
		case 8:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
	
				break;
			}
		case 9:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\10.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
			
				break;
			}
		}//大case
		///////////////////////////////////////////////////////////////
		file.SeekToBegin();
		while(file.ReadString(str))  
		{  
			if(hang==listloc)
			{
				dizhi=str;
			}
			hang++;
		}
		hang=0;
		m_player.SetUrl(dizhi);
		file11.Open("A:\\Project\\MediaPlayer6\\txt\\11.txt",CFile::modeReadWrite);
		file11.SeekToEnd();
		file11.WriteString(dizhi);
		file11.WriteString("\n");
		file11.Close();
		file.Close();
	}
	*pResult = 0;
}

void CMediaPlayer6Dlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	if(dgl==1)
	{
		if(file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeReadWrite))
		{
			//AfxMessageBox("success");
		}
		else
		{
			//AfxMessageBox("fail");
		}
			m_list.DeleteAllItems();
			file.SeekToBegin();
			m_list.InsertItem(0,"最近播放");
			i=1;
			while(file.ReadString(str))//while循环读取每一行字符
		{
			//AfxMessageBox(str);
			m_list.InsertItem(i,str);
			i++;
		}
		i=0;
		dgl=0;
		file.Close();
	}
	else
	{
		AfxMessageBox("已退至一级菜单！");
	}
}

void CMediaPlayer6Dlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	if(dgl==0)
	{
		file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeReadWrite);
		file1.Open("A:\\Project\\MediaPlayer6\\txt\\1.txt",CFile::modeReadWrite);
		file2.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeReadWrite);
		file3.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeReadWrite);
		file4.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeReadWrite);	
		file5.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeReadWrite);
		file6.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeReadWrite);
		file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeReadWrite);
		file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeReadWrite);
		file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeReadWrite);
		file10.Open("A:\\Project\\MediaPlayer6\\txt\\10.txt",CFile::modeReadWrite);
	
		switch(listlocd)
		{
		case 0:
			{
				AfxMessageBox("最近播放不可删除！");
			}
		case 1:
			{
				//AfxMessageBox("aaaaaaaa");
				file1.Close();
				file1.Open("A:\\Project\\MediaPlayer6\\txt\\1.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file2.ReadString(str))//while循环读取每一行字符
				{
					file1.WriteString(str);
					file1.WriteString("\n");
					i++;
				}
				i=0;
				//AfxMessageBox("aaaaaaaa");
				file2.Close();
				file2.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file3.ReadString(str))//while循环读取每一行字符
				{
					file2.WriteString(str);
					file2.WriteString("\n");
					i++;
				}
				i=0;
				//AfxMessageBox("aaaaaaaa");
				file3.Close();
				file3.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file4.ReadString(str))//while循环读取每一行字符
				{
					file3.WriteString(str);
					file3.WriteString("\n");
					i++;
				}
				i=0;
				file4.Close();
				file4.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file5.ReadString(str))//while循环读取每一行字符
				{
					file4.WriteString(str);
					file4.WriteString("\n");
					i++;
				}
				i=0;
				file5.Close();
				file5.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file6.ReadString(str))//while循环读取每一行字符
				{
					file5.WriteString(str);
					file5.WriteString("\n");
					i++;
				}
				i=0;
				file6.Close();
				file6.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file7.ReadString(str))//while循环读取每一行字符
				{
					file6.WriteString(str);
					file6.WriteString("\n");
					i++;
				}
				i=0;
				file7.Close();
				file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file8.ReadString(str))//while循环读取每一行字符
				{
					file7.WriteString(str);
					file7.WriteString("\n");
					i++;
				}
				i=0;
				file8.Close();
				file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file9.ReadString(str))//while循环读取每一行字符
				{
					file8.WriteString(str);
					file8.WriteString("\n");
					i++;
				}
				i=0;
				//AfxMessageBox("aaaaaaaa");
				file9.Close();
				if(file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeReadWrite))
				{
					//AfxMessageBox("success");
				}
				else
					//AfxMessageBox("fail");
				//AfxMessageBox("aaaaaaaa");
				//file10.SeekToBegin();
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox("aaaaaaaa");
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
			
				break;
			
			}
		case 2:
			{
				
				file2.Close();
				file2.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file3.ReadString(str))//while循环读取每一行字符
				{
					file2.WriteString(str);
					file2.WriteString("\n");
					i++;
				}
				
				i=0;
				file3.Close();
				file3.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file4.ReadString(str))//while循环读取每一行字符
				{
					file3.WriteString(str);
					file3.WriteString("\n");
					i++;
				}
				i=0;
				file4.Close();
				file4.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file5.ReadString(str))//while循环读取每一行字符
				{
					file4.WriteString(str);
					file4.WriteString("\n");
					i++;
				}
				i=0;
				file5.Close();
				file5.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file6.ReadString(str))//while循环读取每一行字符
				{
					file5.WriteString(str);
					file5.WriteString("\n");
					i++;
				}
				i=0;
				file6.Close();
				file6.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file7.ReadString(str))//while循环读取每一行字符
				{
					file6.WriteString(str);
					file6.WriteString("\n");
					i++;
				}
				i=0;
				file7.Close();
				file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file8.ReadString(str))//while循环读取每一行字符
				{
					file7.WriteString(str);
					file7.WriteString("\n");
					i++;
				}
				i=0;
				file8.Close();
				file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file9.ReadString(str))//while循环读取每一行字符
				{
					file8.WriteString(str);
					file8.WriteString("\n");
					i++;
				}
				i=0;
				file9.Close();
				file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
				break;
			}
		case 3:
			{
				file3.Close();
				file3.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeCreate |CFile::modeReadWrite);
				while(file4.ReadString(str))//while循环读取每一行字符
				{
					file3.WriteString(str);
					file3.WriteString("\n");
					i++;
				}
				i=0;
				file4.Close();
				file4.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file5.ReadString(str))//while循环读取每一行字符
				{
					file4.WriteString(str);
					file4.WriteString("\n");
					i++;
				}
				i=0;
				file5.Close();
				file5.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file6.ReadString(str))//while循环读取每一行字符
				{
					file5.WriteString(str);
					file5.WriteString("\n");
					i++;
				}
				i=0;
				file6.Close();
				file6.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file7.ReadString(str))//while循环读取每一行字符
				{
					file6.WriteString(str);
					file6.WriteString("\n");
					i++;
				}
				i=0;
				file7.Close();
				file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file8.ReadString(str))//while循环读取每一行字符
				{
					file7.WriteString(str);
					file7.WriteString("\n");
					i++;
				}
				i=0;
				file8.Close();
				file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file9.ReadString(str))//while循环读取每一行字符
				{
					file8.WriteString(str);
					file8.WriteString("\n");
					i++;
				}
				i=0;
				file9.Close();
				file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
				break;
			}
		case 4:
			{
				file4.Close();
				file4.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeCreate |CFile::modeReadWrite);
				while(file5.ReadString(str))//while循环读取每一行字符
				{
					file4.WriteString(str);
					file4.WriteString("\n");
					i++;
				}
				i=0;
				file5.Close();
				file5.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file6.ReadString(str))//while循环读取每一行字符
				{
					file5.WriteString(str);
					file5.WriteString("\n");
					i++;
				}
				i=0;
				file6.Close();
				file6.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file7.ReadString(str))//while循环读取每一行字符
				{
					file6.WriteString(str);
					file6.WriteString("\n");
					i++;
				}
				i=0;
				file7.Close();
				file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file8.ReadString(str))//while循环读取每一行字符
				{
					file7.WriteString(str);
					file7.WriteString("\n");
					i++;
				}
				i=0;
				file8.Close();
				file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file9.ReadString(str))//while循环读取每一行字符
				{
					file8.WriteString(str);
					file8.WriteString("\n");
					i++;
				}
				i=0;
				file9.Close();
				file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
				break;
			}
		case 5:
			{
				file5.Close();
				file5.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeCreate |CFile::modeReadWrite);
				while(file6.ReadString(str))//while循环读取每一行字符
				{
					file5.WriteString(str);
					file5.WriteString("\n");
					i++;
				}
				i=0;
				file6.Close();
				file6.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file7.ReadString(str))//while循环读取每一行字符
				{
					file6.WriteString(str);
					file6.WriteString("\n");
					i++;
				}
				i=0;
				file7.Close();
				file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file8.ReadString(str))//while循环读取每一行字符
				{
					file7.WriteString(str);
					file7.WriteString("\n");
					i++;
				}
				i=0;
				file8.Close();
				file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file9.ReadString(str))//while循环读取每一行字符
				{
					file8.WriteString(str);
					file8.WriteString("\n");
					i++;
				}
				i=0;
				file9.Close();
				file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
				break;
			}
		case 6:
			{
				file6.Close();
				file6.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeCreate |CFile::modeReadWrite);
				while(file7.ReadString(str))//while循环读取每一行字符
				{
					file6.WriteString(str);
					file6.WriteString("\n");
					i++;
				}
				i=0;
				file7.Close();
				file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file8.ReadString(str))//while循环读取每一行字符
				{
					file7.WriteString(str);
					file7.WriteString("\n");
					i++;
				}
				i=0;
				file8.Close();
				file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file9.ReadString(str))//while循环读取每一行字符
				{
					file8.WriteString(str);
					file8.WriteString("\n");
					i++;
				}
				i=0;
				file9.Close();
				file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
				break;
			}
		case 7:
			{
				file7.Close();
				file7.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate |CFile::modeReadWrite);
				while(file8.ReadString(str))//while循环读取每一行字符
				{
					file7.WriteString(str);
					file7.WriteString("\n");
					i++;
				}
				i=0;
				file8.Close();
				file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file9.ReadString(str))//while循环读取每一行字符
				{
					file8.WriteString(str);
					file8.WriteString("\n");
					i++;
				}
				i=0;
				file9.Close();
				file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
				break;
			}
		case 8:
			{
				file8.Close();
				file8.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate |CFile::modeReadWrite);
				while(file9.ReadString(str))//while循环读取每一行字符
				{
					file8.WriteString(str);
					file8.WriteString("\n");
					i++;
				}
				i=0;
				file9.Close();
				file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate | CFile::modeReadWrite);
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
				break;
			}
		case 9:
			{
				file9.Close();
				file9.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate |CFile::modeReadWrite);
				while(file10.ReadString(str))//while循环读取每一行字符
				{
					file9.WriteString(str);
					file9.WriteString("\n");
					i++;
				}
				i=0;
				break;
			}
		case 10:
			{
				file10.Close();
				file10.Open("A:\\Project\\MediaPlayer6\\txt\\10.txt",CFile::modeCreate |CFile::modeReadWrite);
				break;
			}
		}//大switch
		i=1;
		while(file.ReadString(str))//while循环读取每一行字符
		{
			//AfxMessageBox(str);
			if(i==listlocd)
			{
				i++;
				continue;
				
			}
			tempstr+=str;
			tempstr+="\n";
			i++;
		}
		file.Close();
		file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeCreate |CFile::modeReadWrite);
		file.WriteString(tempstr);
		tempstr="";
		m_list.DeleteAllItems();
		m_list.InsertItem(0,"最近播放");
		file.SeekToBegin();
		i=1;
		while(file.ReadString(str))//while循环读取每一行字符
		{
			//AfxMessageBox(str);
			m_list.InsertItem(i,str);
			i++;
		}
		file.Close();
		file1.Close();
		file2.Close();
		file3.Close();
		file4.Close();
		file5.Close();
		file6.Close();
		file7.Close();
		file8.Close();
		file9.Close();
		file10.Close();
	}//if
	else
	{
		switch(listloc)
		{
			case 0:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\11.txt",CFile::modeReadWrite))
				{
					//AfxMessageBox("success");
				}
				else
				{
					//AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						//AfxMessageBox(str);
						i++;
						continue;
						//AfxMessageBox(str);

					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\11.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}

		case 1:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\1.txt",CFile::modeReadWrite))
				{
					//AfxMessageBox("success");
				}
				else
				{
					//AfxMessageBox("fail");
				}
				i=0;
				//AfxMessageBox("aaaaaaaa");
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					//AfxMessageBox("aaaaaaaa");
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				//AfxMessageBox("aaaaaaaa");
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\1.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				//AfxMessageBox("aaaaaaaa");
				break;
			}

		case 2:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				//str.Format("%d",i);
				//AfxMessageBox(str);
				file.SeekToBegin();
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox("aaaaa");
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				//AfxMessageBox("aaaaa");
				file.Close();
				
				file.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeCreate |CFile::modeReadWrite);
				
				file.WriteString(tempstr);
				tempstr="";
				//AfxMessageBox("aaaaa");
				break;
			}
		case 3:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}
		case 4:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}
		case 5:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}

		case 6:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}
		case 7:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}
			
		case 8:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}
		
		case 9:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}
		case 10:
			{
				if(file.Open("A:\\Project\\MediaPlayer6\\txt\\10.txt",CFile::modeReadWrite))
				{
				//	AfxMessageBox("success");
				}
				else
				{
				//	AfxMessageBox("fail");
				}
				i=0;
				while(file.ReadString(str))//while循环读取每一行字符
				{
					//AfxMessageBox(str);
					if(i==listlocd)
					{
						i++;
						continue;
						
					}
					tempstr+=str;
					tempstr+="\n";
					i++;
				}
				file.Close();
				file.Open("A:\\Project\\MediaPlayer6\\txt\\10.txt",CFile::modeCreate |CFile::modeReadWrite);
				file.WriteString(tempstr);
				tempstr="";
				break;
			}
		}//大case
	//	AfxMessageBox("aaaaa");
		m_list.DeleteAllItems();
		file.SeekToBegin();
		i=0;
		while(file.ReadString(str))//while循环读取每一行字符
		{
			//AfxMessageBox(str);
			m_list.InsertItem(i,str);
			i++;
		}
		file.Close();
	}//else回括	
}

void CMediaPlayer6Dlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	
	if(dgl==1)
	{
		//Dialog2  Dlg;
		//Dlg.DoModal();
		switch(listloc)
			{
			case 0:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\11.txt",CFile::modeReadWrite))
					{
						//AfxMessageBox("success");
					}
					else
					{
						//AfxMessageBox("fail");
					}
					
					break;
				}

			case 1:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\1.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
					
					break;
				}
			case 2:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\2.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
				
					break;
				}
			case 3:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\3.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
					
					break;
				}
			case 4:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\4.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
					
					break;
				}

			case 5:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\5.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
				
					break;
				}
			case 6:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\6.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
			
					break;
				}
				
			case 7:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\7.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
				
					break;
				}
			
			case 8:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\8.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
				
					break;
				}
			case 9:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\9.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
					
					break;
				}
			case 10:
				{
					if(file.Open("A:\\Project\\MediaPlayer6\\txt\\10.txt",CFile::modeReadWrite))
					{
					//	AfxMessageBox("success");
					}
					else
					{
					//	AfxMessageBox("fail");
					}
					
					break;
				}
				
			}//大case
			char  szFileFilter[]="Mp3  File(*.mp3)|*.mp3|"  
            "Wma   File(*.wma)|*.wma|"  
            "Video   File(*.dat)|*.dat|"  
            "Wave   File(*.wav)|*.wav|"  
            "AVI   File(*.avi)|*.avi|"  
            "Movie   File(*.mov)|*.mov|"  
            "Media   File(*.mmm)|*.mmm|"  
            "Mid   File(*.mid;*,rmi)|*.mid;*.rmi|"  
            "MPEG   File(*.mpeg)|*.mpeg|"    
            "All   File(*.*)|*.*|| ";//文件类型过滤  
			 CFileDialog  dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,szFileFilter);  
			 if(dlg.DoModal()==IDOK)  
			{
				CString   PathName=dlg.GetPathName();  
				PathName.MakeUpper();
				file.SeekToEnd();
				file.WriteString(PathName);
				//AfxMessageBox(Dlg.m_name);
				file.WriteString("\n");
				//m_player.SetUrl(PathName);
				//as=PathName;
			}
			m_list.DeleteAllItems();
			file.SeekToBegin();
			i=0;
			while(file.ReadString(str))//while循环读取每一行字符
			{	
				
				//AfxMessageBox(str);
				m_list.InsertItem(i,str);
				i++;
			}
			file.Close();
		}
		else
		{
			AfxMessageBox("请选择列表！");
		}
}

void CMediaPlayer6Dlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	if(listlocd==0&&dgl==0)
	{
		AfxMessageBox("最近播放不可编辑！");
	}
	else if(dgl==0)
	{
		Dialog3  Dlg;
		Dlg.DoModal();
		if(Dlg.m_name3!="")
		{
			file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeReadWrite);
			i=1;
			while(file.ReadString(str))//while循环读取每一行字符
			{
				//AfxMessageBox(str);
				if(i==listlocd)
				{
					//AfxMessageBox(str);
					str.Replace(str,Dlg.m_name3);
				}
				tempstr+=str;
				tempstr+="\n";
				i++;
			}
			i=0;
			file.Close();
			file.Open("A:\\Project\\MediaPlayer6\\txt\\0.txt",CFile::modeCreate |CFile::modeReadWrite);
			file.WriteString(tempstr);
			tempstr="";
			m_list.DeleteAllItems();
			m_list.InsertItem(0,"最近播放");
			file.SeekToBegin();
			i=1;
			while(file.ReadString(str))//while循环读取每一行字符
			{
				//AfxMessageBox(str);
				m_list.InsertItem(i,str);
				i++;
			}
			file.Close();
		}
		else if(flag3==1)
		{
			AfxMessageBox("列表名不能为空！");
		}
	}
	else if(dgl==1)
	{
		AfxMessageBox("请退到一级菜单再进行操作！");
	}
}

void CMediaPlayer6Dlg::OnAbout() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CMediaPlayer6Dlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	KillTimer(0);
    m_control.play();
	if(m_control.GetCurrentPosition()==0)
		m_control.SetCurrentPosition(0.01);
	SetTimer(0,20,NULL);
	spaceflag=0;
}

void CMediaPlayer6Dlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	m_control.pause();
	spaceflag=1;
}

void CMediaPlayer6Dlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	KillTimer(0);
	m_control.stop();
}

void CMediaPlayer6Dlg::OnFullscreen() 
{
	// TODO: Add your control notification handler code here
	if(m_control.GetCurrentPosition()!=0&&!m_player.GetFullScreen())
	{
		m_control.pause();
		m_player.SetFullScreen(true);
		m_control.play();

	}
}
