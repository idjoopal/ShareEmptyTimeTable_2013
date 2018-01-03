// Set_theme.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "Set_theme.h"


// Set_theme dialog

IMPLEMENT_DYNAMIC(Set_theme, CDialog)

Set_theme::Set_theme(CWnd* pParent /*=NULL*/)
	: CDialog(Set_theme::IDD, pParent)
	, selpic(0)
{

}

Set_theme::~Set_theme()
{
}

void Set_theme::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, pic_basic);
	DDX_Control(pDX, IDC_STATIC2, pic_apple);
	DDX_Control(pDX, IDC_STATIC3, pic_shark);
	DDX_Control(pDX, IDC_STATIC4, pic_milk);
	DDX_Control(pDX, IDC_STATIC5, pic_playboy);
	DDX_Control(pDX, IDC_STATIC6, pic_totoro);
	DDX_Control(pDX, IDC_COMBO1, theme_combo);
}


BEGIN_MESSAGE_MAP(Set_theme, CDialog)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &Set_theme::OnBnClickedOk)
END_MESSAGE_MAP()


// Set_theme message handlers

int Set_theme::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here


	return 0;
}

void Set_theme::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages

	DrawPic();
}

void Set_theme::DrawPic(void)
{
	CClientDC basicdc(&pic_basic);

	CRect rect;
	pic_basic.GetClientRect(&rect);

	CDC memdc;
	memdc.CreateCompatibleDC(&basicdc);

	CBitmap bgbmp;
	CBitmap applebmp;
	CBitmap sharkbmp;
	CBitmap milkbmp;
	CBitmap playboybmp;
	CBitmap totorobmp;
	
	bgbmp.LoadBitmapW(IDB_BITMAP2);
	applebmp.LoadBitmapW(IDB_BITMAP4);
	sharkbmp.LoadBitmapW(IDB_BITMAP5);
	milkbmp.LoadBitmapW(IDB_BITMAP6);
	playboybmp.LoadBitmapW(IDB_BITMAP7);
	totorobmp.LoadBitmapW(IDB_BITMAP8);

	BITMAP bmpinfo;
	CBitmap *pbit = memdc.SelectObject(&bgbmp);
	bgbmp.GetBitmap(&bmpinfo);
	basicdc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,607,513,SRCCOPY);

	CClientDC appledc(&pic_apple);
	pic_apple.GetClientRect(&rect);
	memdc.CreateCompatibleDC(&appledc);
	memdc.SelectObject(&applebmp);
	applebmp.GetBitmap(&bmpinfo);
	appledc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,607,513,SRCCOPY);

	CClientDC sharkdc(&pic_shark);
	pic_shark.GetClientRect(&rect);
	memdc.CreateCompatibleDC(&sharkdc);
	memdc.SelectObject(&sharkbmp);
	sharkbmp.GetBitmap(&bmpinfo);
	sharkdc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,607,513,SRCCOPY);

	CClientDC milkdc(&pic_milk);
	pic_milk.GetClientRect(&rect);
	memdc.CreateCompatibleDC(&milkdc);
	memdc.SelectObject(&milkbmp);
	milkbmp.GetBitmap(&bmpinfo);
	milkdc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,607,513,SRCCOPY);

	CClientDC playboydc(&pic_playboy);
	pic_playboy.GetClientRect(&rect);
	memdc.CreateCompatibleDC(&playboydc);
	memdc.SelectObject(&playboybmp);
	playboybmp.GetBitmap(&bmpinfo);
	playboydc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,607,513,SRCCOPY);

	CClientDC totorodc(&pic_totoro);
	pic_totoro.GetClientRect(&rect);
	memdc.CreateCompatibleDC(&totorodc);
	memdc.SelectObject(&totorobmp);
	totorobmp.GetBitmap(&bmpinfo);
	totorodc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,607,513,SRCCOPY);

}

void Set_theme::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	selpic = theme_combo.GetCurSel()+1;
	CFile file;
	CFileException e;

	if(file.Open(_T("sys\\theme.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite, &e))
	{
		CString str;
		str.Format(_T("%d"),selpic);
		file.SetLength(0);
		file.Write(str,2);
		file.Close();
	}

	AfxMessageBox(_T("설정이 완료되었습니다. 재시작시 테마가 적용됩니다."));
	OnOK();
}
