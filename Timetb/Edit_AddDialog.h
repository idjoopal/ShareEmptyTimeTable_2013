#pragma once
#include "afxwin.h"


// Edit_AddDialog dialog
class AddTableDialog;
class Edit_AddDialog : public CDialog
{
	DECLARE_DYNAMIC(Edit_AddDialog)

public:
	Edit_AddDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~Edit_AddDialog();

// Dialog Data
	enum { IDD = IDD_EDIT_ADDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedEditAddAdd();
	CEdit new_name;
};
