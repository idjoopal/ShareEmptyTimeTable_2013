#pragma once
#include "explorer1.h"


// WhatShowDialog dialog

class WhatShowDialog : public CDialog
{
	DECLARE_DYNAMIC(WhatShowDialog)

public:
	WhatShowDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~WhatShowDialog();

// Dialog Data
	enum { IDD = IDD_WHATSHOWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 html;
	int whatindex;
	int genderindex;
	virtual BOOL OnInitDialog();
};
