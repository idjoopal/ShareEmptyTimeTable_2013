#pragma once
#include "afxwin.h"


// AddTableDialog dialog
class Edit_AddDialog;

class AddTableDialog : public CDialog
{
	DECLARE_DYNAMIC(AddTableDialog)

public:
	AddTableDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~AddTableDialog();

// Dialog Data
	enum { IDD = IDD_ADDTABLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddinfo();
	CEdit Add_name;
	CEdit Add_pf;
	CEdit Add_room;
	CComboBox Add_week;
	CComboBox Add_start;
	CComboBox Add_finish;
	int weekindex;
	int startindex;
	int finishindex;
	CEdit Add_code;
	CString filename;
};
