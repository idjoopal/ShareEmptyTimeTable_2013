// SettingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "SettingDialog.h"
#include "Set_theme.h"
#include "Aboutit.h"


// SettingDialog dialog

IMPLEMENT_DYNAMIC(SettingDialog, CDialog)

SettingDialog::SettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(SettingDialog::IDD, pParent)
{

}

SettingDialog::~SettingDialog()
{
}

void SettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SettingDialog, CDialog)
	ON_BN_CLICKED(IDC_SETTING_ABOUT, &SettingDialog::OnBnClickedSettingAbout)
	ON_BN_CLICKED(IDC_SETTING_USERNAME, &SettingDialog::OnBnClickedSettingUsername)
	ON_BN_CLICKED(IDC_SETTING_THEME, &SettingDialog::OnBnClickedSettingTheme)
END_MESSAGE_MAP()


// SettingDialog message handlers

void SettingDialog::OnBnClickedSettingAbout()
{
	// TODO: Add your control notification handler code here
	Aboutit about;
	about.DoModal();
}

void SettingDialog::OnBnClickedSettingUsername()
{
	// TODO: Add your control notification handler code here
	Setting_NameDialog name;
	CTimetbDlg dlg;
	name.DoModal();
}

void SettingDialog::OnBnClickedSettingTheme()
{
	// TODO: Add your control notification handler code here
	Set_theme set;
	set.DoModal();
}
