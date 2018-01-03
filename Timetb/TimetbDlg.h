// TimetbDlg.h : 헤더 파일
//

#pragma once
#include "EditDialog.h"
#include "ShareDialog.h"
#include "WhatDIalog.h"
#include "SettingDialog.h"
#include "atltypes.h"
#include "afxwin.h"
#include "afxcmn.h"


// CTimetbDlg 대화 상자
class CTimetbDlg : public CDialog
{
// 생성입니다.
public:
	CTimetbDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TIMETB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedShare();
	afx_msg void OnBnClickedWhat();
	afx_msg void OnBnClickedSetting();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CRect timerect;
	CString name_str;
	bool chk_change;
	CEdit m_greet;
	CEdit m_time;
};
