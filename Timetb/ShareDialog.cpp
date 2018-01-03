// ShareDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "ShareDialog.h"
#include "ShareShow.h"
#include "SendDialog.h"
#include "shlwapi.h"

// ShareDialog dialog

IMPLEMENT_DYNAMIC(ShareDialog, CDialog)

ShareDialog::ShareDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ShareDialog::IDD, pParent)
	, othertable(_T(""))
{

}

ShareDialog::~ShareDialog()
{
}

void ShareDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ShareDialog, CDialog)
	ON_BN_CLICKED(IDC_SHARE_LOAD, &ShareDialog::OnBnClickedShareLoad)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SHARE_SEND, &ShareDialog::OnBnClickedShareSend)
END_MESSAGE_MAP()


// ShareDialog message handlers

void ShareDialog::OnBnClickedShareLoad()
{
	CFileDialog dlg(true,_T("txt file(*.txt)"),_T("*.txt"),OFN_HIDEREADONLY,
		_T("text file(*.txt)|*.txt|모든파일(*.*)|*.*|"));
	if(dlg.DoModal()==IDOK)
	{
		CString str;
		str = dlg.GetPathName();

		TCHAR nowPath[30000];
		GetModuleFileName(NULL, nowPath, 100); 
		//실행중인 프로세스의 경로 + 파일명 얻어 배열에 저장.
		PathRemoveFileSpec(nowPath); //위에서 파일명 부분만 제거한다.

		CString nowfile_Path;
		nowfile_Path = nowPath;

		nowfile_Path += _T("\\share\\shared.txt");
		
		::CopyFile(str,nowfile_Path,false);

		CShareShow s_show;
		s_show.DoModal();
		OnOK();
	}
}

int ShareDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}

void ShareDialog::OnBnClickedShareSend()
{
	// TODO: Add your control notification handler code here
	SendDialog send;

	send.DoModal();
}
