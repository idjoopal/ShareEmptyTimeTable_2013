#pragma once
#include "explorer1.h"


// Weather 대화 상자입니다.

class Weather : public CDialog
{
	DECLARE_DYNAMIC(Weather)

public:
	Weather(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Weather();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_WEATHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 weather;
	virtual BOOL OnInitDialog();
};
