// WhatDIalog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "WhatDIalog.h"
#include "WhatShowDialog.h"


// WhatDIalog dialog

IMPLEMENT_DYNAMIC(WhatDIalog, CDialog)

WhatDIalog::WhatDIalog(CWnd* pParent /*=NULL*/)
	: CDialog(WhatDIalog::IDD, pParent)

	, whatindex(0)
	, genderindex(0)
{

}

WhatDIalog::~WhatDIalog()
{
}

void WhatDIalog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WHAT_TIMECOM, what_time);
	DDX_Control(pDX, IDC_WHAT_GENDERCOM, what_gender);
}


BEGIN_MESSAGE_MAP(WhatDIalog, CDialog)
	ON_BN_CLICKED(IDC_WHAT_SEARCH, &WhatDIalog::OnBnClickedWhatSearch)
END_MESSAGE_MAP()


// WhatDIalog message handlers

void WhatDIalog::OnBnClickedWhatSearch()
{
	// TODO: Add your control notification handler code here

	whatindex = what_time.GetCurSel();
	genderindex = what_gender.GetCurSel();

	WhatShowDialog ws;
	ws.whatindex = whatindex;
	ws.genderindex = genderindex;

	ws.DoModal();
}
