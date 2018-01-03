// EditDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "EditDialog.h"
#include "TimetbDlg.h"
#include "shlwapi.h"


// EditDialog dialog

IMPLEMENT_DYNAMIC(EditDialog, CDialog)

EditDialog::EditDialog(CWnd* pParent /*=NULL*/)
	: CDialog(EditDialog::IDD, pParent)
	, filePath(_T(""))
	, name(_T(""))
	, code(_T(""))
	, pf(_T(""))
	, room(_T(""))
	, m_select(0)
{

}

EditDialog::~EditDialog()
{
}

void EditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FILENAME, filename_edit);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, code);
	DDX_Text(pDX, IDC_EDIT4, pf);
	DDX_Text(pDX, IDC_EDIT5, room);
	DDX_Control(pDX, IDC_BUTTON2, sub_add);
	DDX_Control(pDX, IDC_BUTTON3, sub_edit);
	DDX_Control(pDX, IDC_BUTTON4, sub_del);
	DDX_Control(pDX, IDC_COMBO1, week);
	DDX_Control(pDX, IDC_COMBO2, start);
	DDX_Control(pDX, IDC_COMBO3, finish);
}


BEGIN_MESSAGE_MAP(EditDialog, CDialog)
	ON_BN_CLICKED(IDC_EDIT_ADD, &EditDialog::OnBnClickedEditAdd)
	ON_BN_CLICKED(IDC_EDIT_FIND, &EditDialog::OnBnClickedEditFind)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &EditDialog::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON2, &EditDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &EditDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &EditDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &EditDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_EDIT_DELETE, &EditDialog::OnBnClickedEditDelete)
	ON_BN_CLICKED(IDC_EDIT_MAIN, &EditDialog::OnBnClickedEditMain)
END_MESSAGE_MAP()


// EditDialog message handlers

void EditDialog::OnBnClickedEditAdd()
{
	// TODO: Add your control notification handler code here
	Edit_AddDialog e_add;
	e_add.DoModal();
}

BOOL EditDialog::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
{
	// TODO: Add your specialized code here and/or call the base class


	return CDialog::Create(lpszTemplateName, pParentWnd);
}

void EditDialog::OnBnClickedEditFind()
{
	// TODO: Add your control notification handler code here


	CFileDialog filedlg(true,_T("txt file(*.txt)"),_T("*.txt"),OFN_HIDEREADONLY,
		_T("text file(*.txt)|*.txt|모든파일(*.*)|*.*|"));

	if(filedlg.DoModal()==IDOK)
	{
		CString file_name = filedlg.GetFileName();
		filePath = filedlg.GetPathName();
		
		if(file_name == _T("maintable.txt"))
		{
			AfxMessageBox(_T("프로그램파일이므로 열 수 없습니다."));
		}
		else
		{
			filename_edit.SetWindowTextW(file_name);
			UpdateData(false);

			CFile file;
			CFileException e;

			if(file.Open(filePath, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead, &e))
			{
				m_list.DeleteAllItems();

				char m_code[50]={0};
				char m_name[50]={0};
				char m_pf[50]={0};
				char m_room[50]={0};
				char m_week[50]={0};
				char m_start[50]={0};
				char m_finish[50]={0};

				file.SeekToBegin();

				for(int i=0; i<file.GetLength()/350; i++)
				{
					file.Read(m_code,4);
					file.Seek(46,CFile::current);
					file.Read(m_name,20);
					file.Seek(30,CFile::current);
					file.Read(m_pf,8);
					file.Seek(42,CFile::current);
					file.Read(m_room,20);
					file.Seek(30,CFile::current);
					file.Read(m_week,2);
					file.Seek(48,CFile::current);
					file.Read(m_start,2);
					file.Seek(48,CFile::current);
					file.Read(m_finish,2);
					file.Seek(48,CFile::current);

					CString s_code, s_name, s_pf, s_room, s_week, s_start, s_finish;
					s_code = m_code;
					s_name = m_name;
					s_pf = m_pf;
					s_room = m_room;
					s_week = m_week;
					s_start = m_start;
					s_finish = m_finish;

					int count = m_list.GetItemCount();

					m_list.InsertItem(count, s_name, 0);
					m_list.SetItemText(count, 1, s_code);
					m_list.SetItemText(count, 2, s_pf);
					m_list.SetItemText(count, 3, s_room);
					m_list.SetItemText(count, 4, s_week);
					m_list.SetItemText(count, 5, s_start);
					m_list.SetItemText(count, 6, s_finish);

					UpdateData(false);
				}

			}
			else
			{
				e.ReportError();
			}
		}
	}
}

void EditDialog::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	m_select = pNMLV->iItem;

	name = m_list.GetItemText(m_select, 0);
	code = m_list.GetItemText(m_select, 1);
	pf = m_list.GetItemText(m_select, 2);
	room = m_list.GetItemText(m_select, 3);

	CString m_week=m_list.GetItemText(m_select, 4);
	CString m_start=m_list.GetItemText(m_select, 5);
	CString m_finish=m_list.GetItemText(m_select, 6);

	int i_week=_ttoi(m_week);
	int i_start=_ttoi(m_start);
	int i_finish=_ttoi(m_finish);

	week.SetCurSel(i_week);
	start.SetCurSel(i_start);
	finish.SetCurSel(i_finish);

	UpdateData(false);
}

BOOL EditDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_list.InsertColumn(0, _T("과목명"), LVCFMT_CENTER, 70);
	m_list.InsertColumn(1, _T("과목코드"), LVCFMT_LEFT, 70);
	m_list.InsertColumn(2, _T("교수"), LVCFMT_LEFT, 70);
	m_list.InsertColumn(3, _T("강의실"), LVCFMT_LEFT, 70);
	m_list.InsertColumn(4, _T("요일"), LVCFMT_LEFT, 50);
	m_list.InsertColumn(5, _T("시작시간"), LVCFMT_LEFT, 70);
	m_list.InsertColumn(6, _T("종료시간"), LVCFMT_LEFT, 70);


	m_list.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void EditDialog::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	
	CString file_name,path;
	filename_edit.GetWindowTextW(file_name);

	if(file_name == _T(""))
	{
		AfxMessageBox(_T("시간표를 선택하지 않았습니다."));
	}
	else
	{
		UpdateData(true);
		int count = m_list.GetItemCount();

		CString i_week, i_start, i_finish;
		i_week.Format(_T("%d"), week.GetCurSel());
		i_start.Format(_T("%d"), start.GetCurSel());
		i_finish.Format(_T("%d"), finish.GetCurSel());

		if(code == _T("") || pf == _T("") || room == _T("") || i_week == _T("") || i_start == _T("") || i_finish == _T("") || name == _T(""))
		{
			AfxMessageBox(_T("항목을 모두 입력해주세요."));
		}
		else
		{
			m_list.InsertItem(count, name, 0);
			m_list.SetItemText(count, 1, code);
			m_list.SetItemText(count, 2, pf);
			m_list.SetItemText(count, 3, room);

			m_list.SetItemText(count, 4, i_week);
			m_list.SetItemText(count, 5, i_start);
			m_list.SetItemText(count, 6, i_finish);

			name=_T("");
			code=_T("");
			pf=_T("");
			room=_T("");
			week.SetCurSel(-1);
			start.SetCurSel(-1);
			finish.SetCurSel(-1);

			UpdateData(false);
		}
	}
}

void EditDialog::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CString file_name,path;
	filename_edit.GetWindowTextW(file_name);

	if(file_name == _T(""))
	{
		AfxMessageBox(_T("시간표를 선택하지 않았습니다."));
	}
	else
	{
		UpdateData(true);

		int count = m_list.GetItemCount();

		CString i_week, i_start, i_finish;
		i_week.Format(_T("%d"), week.GetCurSel());
		i_start.Format(_T("%d"), start.GetCurSel());
		i_finish.Format(_T("%d"), finish.GetCurSel());

		if(week.GetCurSel() == -1)
		{
			AfxMessageBox(_T("목록에서 수정할 과목을 선택하세요"));
		}
		else
		{
			if(code == _T("") || pf == _T("") || room == _T("") || i_week == _T("") || i_start == _T("") || i_finish == _T("") || name == _T(""))
			{
				AfxMessageBox(_T("항목을 모두 입력해주세요."));
			}
			else
			{
				m_list.InsertItem(count, name, 0);
				m_list.SetItemText(count, 1, code);
				m_list.SetItemText(count, 2, pf);
				m_list.SetItemText(count, 3, room);
				m_list.SetItemText(count, 4, i_week);
				m_list.SetItemText(count, 5, i_start);
				m_list.SetItemText(count, 6, i_finish);

				m_list.DeleteItem(m_select);

				name=_T("");
				code=_T("");
				pf=_T("");
				room=_T("");
				week.SetCurSel(-1);
				start.SetCurSel(-1);
				finish.SetCurSel(-1);

				UpdateData(false);
			}
		}
	}
}

void EditDialog::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here

	CString file_name,path;
	filename_edit.GetWindowTextW(file_name);

	if(file_name == _T(""))
	{
		AfxMessageBox(_T("시간표를 선택하지 않았습니다."));
	}
	else
	{
		if(week.GetCurSel() == -1)
		{
			AfxMessageBox(_T("목록에서 삭제할 과목을 선택하세요"));
		}
		else
		{
			m_list.DeleteItem(m_select);

			name=_T("");
			code=_T("");
			pf=_T("");
			room=_T("");
			week.SetCurSel(-1);
			start.SetCurSel(-1);
			finish.SetCurSel(-1);

			UpdateData(false);
		}
	}
}

void EditDialog::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here

	char m_code[300]={0};
	char m_name[300]={0};
	char m_pf[300]={0};
	char m_room[300]={0};
	char m_week[300]={0};
	char m_start[300]={0};
	char m_finish[300]={0};

	CString file_name,path;
	filename_edit.GetWindowTextW(file_name);

	if(file_name == _T(""))
	{
		AfxMessageBox(_T("시간표를 선택하지 않았습니다."));
	}
	else
	{
		CFile file;
		CFileException e;

		if(file.Open(filePath, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite, &e))
		{
			file.SetLength(0);

			for(int i=0; i<m_list.GetItemCount();i++)
			{
				CString s_name = m_list.GetItemText(i, 0);
				CString s_code = m_list.GetItemText(i, 1);
				CString s_pf = m_list.GetItemText(i, 2);
				CString s_room = m_list.GetItemText(i, 3);
				CString s_week=m_list.GetItemText(i, 4);
				CString s_start=m_list.GetItemText(i, 5);
				CString s_finish=m_list.GetItemText(i, 6);

				WideCharToMultiByte( CP_ACP, 0, s_code , -1, m_code, 256, NULL, NULL );
				WideCharToMultiByte( CP_ACP, 0, s_name , -1, m_name, 256, NULL, NULL );
				WideCharToMultiByte( CP_ACP, 0, s_pf , -1, m_pf, 256, NULL, NULL );
				WideCharToMultiByte( CP_ACP, 0, s_room , -1, m_room, 256, NULL, NULL );
				WideCharToMultiByte( CP_ACP, 0, s_week , -1, m_week, 256, NULL, NULL );
				WideCharToMultiByte( CP_ACP, 0, s_start , -1, m_start, 256, NULL, NULL );
				WideCharToMultiByte( CP_ACP, 0, s_finish , -1, m_finish, 256, NULL, NULL );

				file.SeekToEnd();

				file.Write(m_code,50);
				file.Write(m_name,50);
				file.Write(m_pf,50);
				file.Write(m_room,50);
				file.Write(m_week,50);
				file.Write(m_start,50);
				file.Write(m_finish,50);
			}

			file.Close();

			AfxMessageBox(_T("저장이 완료되었습니다."));
		}
	}
}
void EditDialog::OnBnClickedEditDelete()
{
	// TODO: Add your control notification handler code here

	CString file_name,path;
	filename_edit.GetWindowTextW(file_name);

	if(file_name == _T(""))
	{
		AfxMessageBox(_T("시간표를 선택하지 않았습니다."));
	}
	else
	{
		path.Format(_T("%s"),filePath);

		m_list.DeleteAllItems();
		name=_T("");
		code=_T("");
		pf=_T("");
		room=_T("");
		week.SetCurSel(-1);
		start.SetCurSel(-1);
		finish.SetCurSel(-1);
		filename_edit.SetWindowTextW(_T(""));

		UpdateData(false);

		::DeleteFileW(path);

		AfxMessageBox(_T("성공적으로 삭제되었습니다."));
	}
}

void EditDialog::OnBnClickedEditMain()
{
	// TODO: Add your control notification handler code here

	CString file_name,path;
	filename_edit.GetWindowTextW(file_name);

	if(file_name == _T(""))
	{
		AfxMessageBox(_T("시간표를 선택하지 않았습니다."));
	}
	else
	{
		TCHAR nowPath[30000];
		GetModuleFileName(NULL, nowPath, 100); 
		//실행중인 프로세스의 경로 + 파일명 얻어 배열에 저장.
		PathRemoveFileSpec(nowPath); //위에서 파일명 부분만 제거한다.

		CString nowfile_Path,file_path;
		nowfile_Path = nowPath;
		file_path = filePath;

		nowfile_Path += _T("\\dat\\maintable.txt");

		::CopyFile(file_path,nowfile_Path,false);

		CTimetbDlg dlg;
		dlg.chk_change = false;

		AfxMessageBox(_T("설정이 완료되었습니다"));
	}

}
