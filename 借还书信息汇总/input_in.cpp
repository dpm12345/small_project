// input_in.cpp : 实现文件
//

#include "stdafx.h"
#include "homework.h"
#include "input_in.h"
#include "afxdialogex.h"

extern CString person;
extern int flag;

// input_in 对话框

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


// input_in 消息处理程序


void input_in::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	flag = 1;
	name.GetWindowTextW(person);
	CDialogEx::OnOK();

}


void input_in::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	flag = 0;
	CDialogEx::OnCancel();
}
