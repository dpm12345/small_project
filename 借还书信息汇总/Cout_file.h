#pragma once
#include "afxwin.h"


// Cout_file 对话框

class Cout_file : public CDialogEx      //输入文件信息的对话框
{
	DECLARE_DYNAMIC(Cout_file)

public:
	Cout_file(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cout_file();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CEdit f_name;               //输入文件信息对话框的edit框对应变量
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
