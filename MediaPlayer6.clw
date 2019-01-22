; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMediaPlayer6Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MediaPlayer6.h"

ClassCount=6
Class1=CMediaPlayer6App
Class2=CMediaPlayer6Dlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MEDIAPLAYER6_DIALOG
Class4=Dialog1
Resource4=IDD_DIALOG2
Class5=Dialog2
Resource5=IDD_DIALOG1
Class6=Dialog3
Resource6=IDD_DIALOG3

[CLS:CMediaPlayer6App]
Type=0
HeaderFile=MediaPlayer6.h
ImplementationFile=MediaPlayer6.cpp
Filter=N

[CLS:CMediaPlayer6Dlg]
Type=0
HeaderFile=MediaPlayer6Dlg.h
ImplementationFile=MediaPlayer6Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=MediaPlayer6Dlg.h
ImplementationFile=MediaPlayer6Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MEDIAPLAYER6_DIALOG]
Type=1
Class=CMediaPlayer6Dlg
ControlCount=16
Control1=IDC_OCX1,{6BF52A52-394A-11D3-B153-00C04F79FAA6},1342242816
Control2=IDC_LIST1,SysListView32,1350631426
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_BUTTON5,button,1342242816
Control8=IDC_BUTTON6,button,1342242816
Control9=IDC_BUTTON7,button,1342242816
Control10=IDC_BUTTON8,button,1342242816
Control11=IDC_STATIC,button,1342177287
Control12=IDC_ABOUT,button,1342242816
Control13=IDC_PLAY,button,1342242816
Control14=IDC_PAUSE,button,1342242816
Control15=IDC_STOP,button,1342242816
Control16=IDC_FULLSCREEN,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=Dialog1
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[CLS:Dialog1]
Type=0
HeaderFile=Dialog1.h
ImplementationFile=Dialog1.cpp
BaseClass=CDialog
Filter=D
LastObject=Dialog1
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=Dialog2
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[CLS:Dialog2]
Type=0
HeaderFile=Dialog2.h
ImplementationFile=Dialog2.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Dialog2

[DLG:IDD_DIALOG3]
Type=1
Class=Dialog3
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[CLS:Dialog3]
Type=0
HeaderFile=Dialog3.h
ImplementationFile=Dialog3.cpp
BaseClass=CDialog
Filter=D
LastObject=Dialog3
VirtualFilter=dWC

