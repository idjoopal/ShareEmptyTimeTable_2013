#pragma once
#include "afxwin.h"


// Set_theme dialog

class Set_theme : public CDialog
{
	DECLARE_DYNAMIC(Set_theme)

public:
	Set_theme(CWnd* pParent = NULL);   // standard constructor
	virtual ~Set_theme();

// Dialog Data
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CStatic pic_basic;
	CStatic pic_apple;
	CStatic pic_shark;
	CStatic pic_milk;
	CStatic pic_playboy;
	CStatic pic_totoro;
	afx_msg void OnPaint();
	void DrawPic(void);
	afx_msg void OnBnClickedOk();
	int selpic;
	CComboBox theme_combo;
};
