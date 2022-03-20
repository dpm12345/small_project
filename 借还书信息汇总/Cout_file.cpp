// Cout_file.cpp : 实现文件
//

#include "stdafx.h"
#include "homework.h"
#include "Cout_file.h"
#include "afxdialogex.h"

extern CString file_name;   //声明全局变量

// Cout_file 对话框

IMPLEMENT_DYNAMIC(Cout_file, CDialogEx)

Cout_file::Cout_file(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cout_file::IDD, pParent)
{

}

Cout_file::~Cout_file()
{
}

void Cout_file::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, f_name);
}


BEGIN_MESSAGE_MAP(Cout_file, CDialogEx)
	ON_BN_CLICKED(IDOK, &Cout_file::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Cout_file::OnBnClickedCancel)
END_MESSAGE_MAP()


// Cout_file 消息处理程序

extern int flag;



void Cout_file::OnBnClickedOk()             //确认键
{
	// TODO:  在此添加控件通知处理程序代码
	flag = 1;          //进行操作的标记
	f_name.GetWindowTextW(file_name);
	CDialogEx::OnOK();
}


void Cout_file::OnBnClickedCancel()         //取消键
{
	// TODO:  在此添加控件通知处理程序代码
	flag = 0;          //没有进行操作的标记
	CDialogEx::OnCancel();
}
