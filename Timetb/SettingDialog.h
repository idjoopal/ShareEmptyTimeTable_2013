#pragma once
#include "AboutDialog.h"
#include "Setting_NameDialog.h"
#include "TimetbDlg.h"


// SettingDialog dialog

class SettingDialog : public CDialog
{
	DECLARE_DYNAMIC(SettingDialog)

public:
	SettingDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~SettingDialog();

// Dialog Data
	enum { IDD = IDD_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSettingAbout();
	afx_msg void OnBnClickedSettingUsername();
	afx_msg void OnBnClickedSettingTheme();
};
