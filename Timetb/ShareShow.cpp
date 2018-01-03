// ShareShow.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "ShareShow.h"
#include "ShareDialog.h"
#include "shlwapi.h"


#define ROWS 50
#define COLS 12.5

// CShareShow dialog

IMPLEMENT_DYNAMIC(CShareShow, CDialog)

CShareShow::CShareShow(CWnd* pParent /*=NULL*/)
	: CDialog(CShareShow::IDD, pParent)
{

}

CShareShow::~CShareShow()
{
}

void CShareShow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, emptylist);
}


BEGIN_MESSAGE_MAP(CShareShow, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CShareShow message handlers

BOOL CShareShow::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	for(int k=0;k<5;k++)
	{
		for(int l=0;l<30;l++)
		{
			tab[k][l] = 0;
		}
	}

	emptylist.InsertColumn(0,_T("요일"),LVCFMT_CENTER,50);
	emptylist.InsertColumn(1,_T("시간"),LVCFMT_CENTER,100);


	ShareDialog share;
	CFile file;
	CFileException e;

	TCHAR nowPath[30000];
	GetModuleFileName(NULL, nowPath, 100); 
	//실행중인 프로세스의 경로 + 파일명 얻어 배열에 저장.
	PathRemoveFileSpec(nowPath); //위에서 파일명 부분만 제거한다.

	CString nowfile_Path;
	nowfile_Path = nowPath;

	nowfile_Path += _T("\\share\\shared.txt");

	if(file.Open(nowfile_Path, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead, &e))
	{
		char m_week[50]={0};
		char m_start[50]={0};
		char m_finish[50]={0};

		file.SeekToBegin();

		for(int i=0; i<file.GetLength()/350; i++)
		{
			file.Seek(200,CFile::current);
			file.Read(m_week,2);
			file.Seek(48,CFile::current);
			file.Read(m_start,2);
			file.Seek(48,CFile::current);
			file.Read(m_finish,2);
			file.Seek(48,CFile::current);

			int week=atoi(m_week);
			int i_start=atoi(m_start);
			int i_finish=atoi(m_finish);

			for(int j = i_start; j<i_finish ; j++)
			{
				tab[week][j] = 1;
			}
		}
		file.Close();
	}

	
	GetModuleFileName(NULL, nowPath, 100); 
	//실행중인 프로세스의 경로 + 파일명 얻어 배열에 저장.
	PathRemoveFileSpec(nowPath); //위에서 파일명 부분만 제거한다.

	nowfile_Path = nowPath;

	nowfile_Path += _T("\\dat\\maintable.txt");

	if(file.Open(nowfile_Path, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead, &e))
	{
		char m_week[50]={0};
		char m_start[50]={0};
		char m_finish[50]={0};

		for(int i=0; i<file.GetLength()/350; i++)
		{
			file.Seek(200,CFile::current);
			file.Read(m_week,2);
			file.Seek(48,CFile::current);
			file.Read(m_start,2);
			file.Seek(48,CFile::current);
			file.Read(m_finish,2);
			file.Seek(48,CFile::current);

			int week=atoi(m_week);
			int i_start=atoi(m_start);
			int i_finish=atoi(m_finish);

			for(int j = i_start; j<i_finish ; j++)
			{
				tab[week][j] = 1;
			}
		}
		file.Close();
	}
	else
	{
		e.ReportError();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CShareShow::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	SetTimer(1,100,NULL);

	return true;
}

void CShareShow::printtable(void)
{
	CClientDC dc(this);

}

void CShareShow::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
	CRect rect;
	GetClientRect(&rect);

	CDC memdc;
	memdc.CreateCompatibleDC(&dc);

	CBitmap bgbmp;
	CBitmap tablebmp;
	
	tablebmp.LoadBitmapW(IDB_BITMAP1);
	bgbmp.LoadBitmapW(IDB_BITMAP2);
	BITMAP bmpinfo;
	CBitmap *pbit = memdc.SelectObject(&bgbmp);
	bgbmp.GetBitmap(&bmpinfo);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(), &memdc, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	memdc.SelectObject(&tablebmp);
	tablebmp.GetBitmap(&bmpinfo);
	dc.TransparentBlt(20,20,bmpinfo.bmWidth,bmpinfo.bmHeight,&memdc,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,RGB(200,200,200));
	dc.SelectObject(pbit);

	CBrush m_brush;
	m_brush.CreateSolidBrush(RGB(255,0,0));
	dc.SelectObject(&m_brush);


	for(int i=0; i<5; i++)
	{
		for(int j=0; j<30; j++)
		{
			if(tab[i][j] == 0)
			{
				int count = emptylist.GetItemCount();
				
				emptylist.InsertItem(count,changeweek(i));
				emptylist.SetItemText(count,1,changetime(j));
			}
		}
	}

	


}

void CShareShow::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);

	CBrush m_brush;
	m_brush.CreateSolidBrush(RGB(rand()&255,rand()&255,rand()&255));
	dc.SelectObject(&m_brush);

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<30; j++)
		{
			if(tab[i][j] == 0)
			{
				dc.Rectangle(54+ROWS*i,54+COLS*j,54+ROWS+ROWS*i,54+COLS+COLS*j);
			}
		}
	}

	CDialog::OnTimer(nIDEvent);
}

CString CShareShow::changetime(int time)
{
	CString time_str;

	if(time == 0)
		time_str = _T("07:00");
	else if(time == 1)
		time_str = _T("07:30");
	else if(time == 2)
		time_str = _T("08:00");
	else if(time == 3)
		time_str = _T("08:30");
	else if(time == 4)
		time_str = _T("09:00");
	else if(time == 5)
		time_str = _T("09:30");
	else if(time == 6)
		time_str = _T("10:00");
	else if(time == 7)
		time_str = _T("10:30");
	else if(time == 8)
		time_str = _T("11:00");
	else if(time == 9)
		time_str = _T("11:30");
	else if(time == 10)
		time_str = _T("12:00");
	else if(time == 11)
		time_str = _T("12:30");
	else if(time == 12)
		time_str = _T("01:00");
	else if(time == 13)
		time_str = _T("01:30");
	else if(time == 14)
		time_str = _T("02:00");
	else if(time == 15)
		time_str = _T("02:30");
	else if(time == 16)
		time_str = _T("03:00");
	else if(time == 17)
		time_str = _T("03:30");
	else if(time == 18)
		time_str = _T("04:00");
	else if(time == 19)
		time_str = _T("04:30");
	else if(time == 20)
		time_str = _T("05:00");
	else if(time == 21)
		time_str = _T("05:30");
	else if(time == 22)
		time_str = _T("06:00");
	else if(time == 23)
		time_str = _T("06:30");
	else if(time == 24)
		time_str = _T("07:00");
	else if(time == 25)
		time_str = _T("07:30");
	else if(time == 26)
		time_str = _T("08:00");
	else if(time == 27)
		time_str = _T("08:30");
	else if(time == 28)
		time_str = _T("09:00");
	else if(time == 29)
		time_str = _T("09:30");
	else if(time == 30)
		time_str = _T("10:00");
	
	return time_str;
}

CString CShareShow::changeweek(int week)
{
	CString week_str;

	if(week == 0)
		week_str = _T("월요일");
	else if(week == 1)
		week_str = _T("화요일");
	else if(week == 2)
		week_str = _T("수요일");
	else if(week == 3)
		week_str = _T("목요일");
	else if(week == 4)
		week_str = _T("금요일");

	return week_str;
}
