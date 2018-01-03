// Aboutit.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "Aboutit.h"


// Aboutit dialog

IMPLEMENT_DYNAMIC(Aboutit, CDialog)

Aboutit::Aboutit(CWnd* pParent /*=NULL*/)
	: CDialog(Aboutit::IDD, pParent)
{

}

Aboutit::~Aboutit()
{
}

void Aboutit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC123, pic_icon);
}


BEGIN_MESSAGE_MAP(Aboutit, CDialog)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// Aboutit message handlers

int Aboutit::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	

	return 0;
}

void Aboutit::DrawPic(void)
{
	CClientDC dc(&pic_icon);

	CRect rect;
	pic_icon.GetClientRect(&rect);

	CDC memdc;
	memdc.CreateCompatibleDC(&dc);

	CBitmap logobmp;
	logobmp.LoadBitmapW(IDB_BITMAP9);

	BITMAP bmpinfo;
	CBitmap *pbit = memdc.SelectObject(&logobmp);
	logobmp.GetBitmap(&bmpinfo);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&memdc,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,SRCCOPY);
	
	memdc.SelectObject(pbit);
}

BOOL Aboutit::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	DrawPic();

	return CDialog::OnEraseBkgnd(pDC);
}
