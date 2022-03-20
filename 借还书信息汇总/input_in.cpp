// input_in.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "homework.h"
#include "input_in.h"
#include "afxdialogex.h"

extern CString person;
extern int flag;

// input_in �Ի���

IMPLEMENT_DYNAMIC(input_in, CDialogEx)

input_in::input_in(CWnd* pParent /*=NULL*/)
	: CDialogEx(input_in::IDD, pParent)
{

}

input_in::~input_in()
{
}

void input_in::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(input_in, CDialogEx)
	ON_BN_CLICKED(IDOK, &input_in::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &input_in::OnBnClickedCancel)
END_MESSAGE_MAP()


// input_in ��Ϣ�������


void input_in::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	flag = 1;
	name.GetWindowTextW(person);
	CDialogEx::OnOK();

}


void input_in::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	flag = 0;
	CDialogEx::OnCancel();
}
