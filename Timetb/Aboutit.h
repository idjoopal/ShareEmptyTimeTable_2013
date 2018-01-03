#pragma once
#include "afxwin.h"


// Aboutit dialog

class Aboutit : public CDialog
{
	DECLARE_DYNAMIC(Aboutit)

public:
	Aboutit(CWnd* pParent = NULL);   // standard constructor
	virtual ~Aboutit();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic pic_icon;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void DrawPic(void);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
