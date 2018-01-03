#pragma once
#include "afxwin.h"


// WhatDIalog dialog

class WhatDIalog : public CDialog
{
	DECLARE_DYNAMIC(WhatDIalog)

public:
	WhatDIalog(CWnd* pParent = NULL);   // standard constructor
	virtual ~WhatDIalog();

// Dialog Data
	enum { IDD = IDD_WHATDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedWhatSearch();

	CComboBox what_time;
	CComboBox what_gender;
	int whatindex;
	int genderindex;
};
