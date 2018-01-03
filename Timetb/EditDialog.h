#pragma once
#include "Edit_AddDialog.h"
#include "afxwin.h"
#include "afxcmn.h"


// EditDialog dialog

class EditDialog : public CDialog
{
	DECLARE_DYNAMIC(EditDialog)

public:
	EditDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~EditDialog();

// Dialog Data
	enum { IDD = IDD_EDITDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedEditAdd();
	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	afx_msg void OnBnClickedEditFind();
	CEdit filename_edit;
	CString filePath;
	CListCtrl m_list;
	CString name;
	CString code;
	CString pf;
	CString room;
	CButton sub_add;
	CButton sub_edit;
	CButton sub_del;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	int m_select;
	virtual BOOL OnInitDialog();
	CComboBox week;
	CComboBox start;
	CComboBox finish;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedEditDelete();
	afx_msg void OnBnClickedEditMain();
};
