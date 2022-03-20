#pragma once
#include "afxwin.h"

// input_in 对话框

class input_in : public CDialogEx    //输入查询对象对话框
{
	DECLARE_DYNAMIC(input_in)

public:
	input_in(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~input_in();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CEdit name;              //输入查询对象对话框中的edit框对应的变量名
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
