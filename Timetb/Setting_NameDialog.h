#pragma once
#include "afxwin.h"
#include "TimetbDlg.h"


// Setting_NameDialog dialog

class Setting_NameDialog : public CDialog
{
	DECLARE_DYNAMIC(Setting_NameDialog)

public:
	Setting_NameDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~Setting_NameDialog();

// Dialog Data
	enum { IDD = IDD_SETTING_NAMEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
protected:
	
public:
	afx_msg void OnBnClickedOk();
	CEdit name_edit;
};
