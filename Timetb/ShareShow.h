#pragma once
#include "afxcmn.h"


// CShareShow dialog

class CShareShow : public CDialog
{
	DECLARE_DYNAMIC(CShareShow)

public:
	CShareShow(CWnd* pParent = NULL);   // standard constructor
	virtual ~CShareShow();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CListCtrl emptylist;
	void printtable(void);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString changetime(int time);
	CString changeweek(int week);
	int tab[5][30];
};
