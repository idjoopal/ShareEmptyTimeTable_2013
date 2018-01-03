// SendDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "SendDialog.h"


// SendDialog dialog

IMPLEMENT_DYNAMIC(SendDialog, CDialog)

SendDialog::SendDialog(CWnd* pParent /*=NULL*/)
	: CDialog(SendDialog::IDD, pParent)
{

}

SendDialog::~SendDialog()
{
}

void SendDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, mail_combo);
}


BEGIN_MESSAGE_MAP(SendDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &SendDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// SendDialog message handlers

void SendDialog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	int index = mail_combo.GetCurSel();

	switch(index)
	{
	case 0:
		ShellExecute(NULL, _T("open"),_T("explorer"), _T("http://mail.naver.com"), NULL,SW_SHOW);
		break;
	case 1:
		ShellExecute(NULL, _T("open"),_T("explorer"), _T("http://mail.daum.net"), NULL,SW_SHOW);
		break;
	case 2:
		ShellExecute(NULL, _T("open"),_T("explorer"), _T("http://gmail.com"), NULL,SW_SHOW);
		break;
	case 3:
		ShellExecute(NULL, _T("open"),_T("explorer"), _T("http://mail.konkuk.ac.kr"), NULL,SW_SHOW);
		break;
	case 4:
		ShellExecute(NULL, _T("open"),_T("explorer"), _T("http://"), NULL,SW_SHOW);
		break;
	}
}
