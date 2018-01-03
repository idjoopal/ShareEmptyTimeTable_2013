// AddTableDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "AddTableDialog.h"
#include "EditDialog.h"
#include "stdio.h"
#include "stdlib.h"


// AddTableDialog dialog

IMPLEMENT_DYNAMIC(AddTableDialog, CDialog)

AddTableDialog::AddTableDialog(CWnd* pParent /*=NULL*/)
	: CDialog(AddTableDialog::IDD, pParent)
	, weekindex(-1)
	, startindex(-1)
	, finishindex(-1)
	, filename(_T(""))
{

}

AddTableDialog::~AddTableDialog()
{
}

void AddTableDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_ADD_NAME, Add_name);
	DDX_Control(pDX, IDC_ADD_PF, Add_pf);
	DDX_Control(pDX, IDC_ADD_ROOM, Add_room);
	DDX_Control(pDX, IDC_ADD_WEEK, Add_week);
	DDX_Control(pDX, IDC_TIME_START, Add_start);
	DDX_Control(pDX, IDC_TIME_FIN, Add_finish);
	DDX_Control(pDX, IDC_ADD_CODE, Add_code);
}


BEGIN_MESSAGE_MAP(AddTableDialog, CDialog)
	ON_BN_CLICKED(IDC_ADDINFO, &AddTableDialog::OnBnClickedAddinfo)
END_MESSAGE_MAP()


// AddTableDialog message handlers

BOOL AddTableDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	EditDialog* pDlg
		=(EditDialog*)AfxGetMainWnd();
//	pDlg->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void AddTableDialog::OnBnClickedAddinfo()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(true);

	CString code;
	CString name;
	CString pf;
	CString room;
	CString week;
	CString start;
	CString finish;
	CString clear=_T("");

	char m_code[300]={0};
	char m_name[300]={0};
	char m_pf[300]={0};
	char m_room[300]={0};
	char m_week[300]={0};
	char m_start[300]={0};
	char m_finish[300]={0};
	char enter[300]={0};


	Add_code.GetWindowTextW(code);
	Add_name.GetWindowTextW(name);
	Add_pf.GetWindowTextW(pf);
	Add_room.GetWindowTextW(room);

	weekindex = Add_week.GetCurSel();
	startindex = Add_start.GetCurSel();
	finishindex = Add_finish.GetCurSel();

	if(code == _T("") || name == _T("") || pf == _T("") || room == _T("") || weekindex == -1 || startindex == -1 || finishindex == -1 )
	{
		AfxMessageBox(_T("항목을 모두입력하지 않았습니다."));
	}
	else
	{
		week.Format(_T("%d"),weekindex);
		start.Format(_T("%d"),startindex);
		finish.Format(_T("%d"),finishindex);

		WideCharToMultiByte( CP_ACP, 0, code , -1, m_code, 256, NULL, NULL );
		WideCharToMultiByte( CP_ACP, 0, name , -1, m_name, 256, NULL, NULL );
		WideCharToMultiByte( CP_ACP, 0, pf , -1, m_pf, 256, NULL, NULL );
		WideCharToMultiByte( CP_ACP, 0, room , -1, m_room, 256, NULL, NULL );
		WideCharToMultiByte( CP_ACP, 0, week , -1, m_week, 256, NULL, NULL );
		WideCharToMultiByte( CP_ACP, 0, start , -1, m_start, 256, NULL, NULL );
		WideCharToMultiByte( CP_ACP, 0, finish , -1, m_finish, 256, NULL, NULL );
		WideCharToMultiByte( CP_ACP, 0, _T("\r\n") , -1, enter, 256, NULL, NULL );

		CFile file;
		CFileException e;

		CString filePath;
		filePath.Format(_T("dat\\%s.txt"),filename);
		if(file.Open(filePath, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite, &e))
		{
			file.SeekToEnd();

			file.Write(m_code,4);
			file.Seek(46,CFile::current);
			file.Write(m_name,20);
			file.Seek(30,CFile::current);
			file.Write(m_pf,8);
			file.Seek(42,CFile::current);
			file.Write(m_room,20);
			file.Seek(30,CFile::current);
			file.Write(m_week,2);
			file.Seek(48,CFile::current);
			file.Write(m_start,2);
			file.Seek(48,CFile::current);
			file.Write(m_finish,2);
			file.Seek(48,CFile::current);

			Add_code.SetWindowTextW(clear);
			Add_name.SetWindowTextW(clear);
			Add_pf.SetWindowTextW(clear);
			Add_room.SetWindowTextW(clear);
			Add_week.SetCurSel(0);
			Add_start.SetCurSel(0);
			Add_finish.SetCurSel(0);

		}else
		{
			e.ReportError();
		}

		file.Close();
	}

}
