#if !defined(AFX_WMPPLAYLISTARRAY_H__1D48E9EA_B71E_4DB2_985E_8E481A9D63BD__INCLUDED_)
#define AFX_WMPPLAYLISTARRAY_H__1D48E9EA_B71E_4DB2_985E_8E481A9D63BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CWMPPlaylist;

/////////////////////////////////////////////////////////////////////////////
// CWMPPlaylistArray wrapper class

class CWMPPlaylistArray : public COleDispatchDriver
{
public:
	CWMPPlaylistArray() {}		// Calls COleDispatchDriver default constructor
	CWMPPlaylistArray(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPPlaylistArray(const CWMPPlaylistArray& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	CWMPPlaylist Item(long lIndex);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPPLAYLISTARRAY_H__1D48E9EA_B71E_4DB2_985E_8E481A9D63BD__INCLUDED_)
