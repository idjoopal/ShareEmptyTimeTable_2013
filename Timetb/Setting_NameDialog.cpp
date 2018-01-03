// Setting_NameDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "Setting_NameDialog.h"
#include "TimetbDlg.h"


// Setting_NameDialog dialog

IMPLEMENT_DYNAMIC(Setting_NameDialog, CDialog)

Setting_NameDialog::Setting_NameDialog(CWnd* pParent /*=NULL*/)
	: CDialog(Setting_NameDialog::IDD, pParent)
{

}

Setting_NameDialog::~Setting_NameDialog()
{
}

void Setting_NameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME_EDIT, name_edit);
}


BEGIN_MESSAGE_MAP(Setting_NameDialog, CDialog)
	ON_BN_CLICKED(IDOK, &Setting_NameDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// Setting_NameDialog message handlers

void Setting_NameDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
