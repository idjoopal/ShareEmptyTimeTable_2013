#pragma once


// ShareDialog dialog

class ShareDialog : public CDialog
{
	DECLARE_DYNAMIC(ShareDialog)

public:
	ShareDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~ShareDialog();

// Dialog Data
	enum { IDD = IDD_SHAREDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedShareLoad();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString othertable;
	afx_msg void OnBnClickedShareSend();
};
