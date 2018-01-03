#pragma once
#include "afxwin.h"


// SendDialog dialog

class SendDialog : public CDialog
{
	DECLARE_DYNAMIC(SendDialog)

public:
	SendDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~SendDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox mail_combo;
	afx_msg void OnBnClickedButton1();
};
