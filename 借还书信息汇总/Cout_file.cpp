// Cout_file.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "homework.h"
#include "Cout_file.h"
#include "afxdialogex.h"

extern CString file_name;   //����ȫ�ֱ���

// Cout_file �Ի���

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


// Cout_file ��Ϣ�������

extern int flag;



void Cout_file::OnBnClickedOk()             //ȷ�ϼ�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	flag = 1;          //���в����ı��
	f_name.GetWindowTextW(file_name);
	CDialogEx::OnOK();
}


void Cout_file::OnBnClickedCancel()         //ȡ����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	flag = 0;          //û�н��в����ı��
	CDialogEx::OnCancel();
}
