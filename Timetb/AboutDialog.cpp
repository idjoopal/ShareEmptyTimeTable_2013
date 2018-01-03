// AboutDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "AboutDialog.h"


// AboutDialog dialog

IMPLEMENT_DYNAMIC(AboutDialog, CDialog)

AboutDialog::AboutDialog(CWnd* pParent /*=NULL*/)
	: CDialog(AboutDialog::IDD, pParent)
{

}

AboutDialog::~AboutDialog()
{
}

void AboutDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AboutDialog, CDialog)
END_MESSAGE_MAP()


// AboutDialog message handlers
