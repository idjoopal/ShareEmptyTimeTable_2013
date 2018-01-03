// Weather.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Timetb.h"
#include "Weather.h"


// Weather 대화 상자입니다.

IMPLEMENT_DYNAMIC(Weather, CDialog)

Weather::Weather(CWnd* pParent /*=NULL*/)
	: CDialog(Weather::IDD, pParent)
{

}

Weather::~Weather()
{
}

void Weather::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, weather);
}


BEGIN_MESSAGE_MAP(Weather, CDialog)
END_MESSAGE_MAP()


// Weather 메시지 처리기입니다.

BOOL Weather::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString strAppPath;
	GetCurrentDirectory(256,strAppPath.GetBuffer(256));
	CString strPath;

	strPath.Format(_T("http://m.kma.go.kr/m/observation/observation_01.jsp"),strAppPath);
	weather.Navigate(strPath,NULL,NULL,NULL,NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
