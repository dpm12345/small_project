
// homeworkDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// ChomeworkDlg 对话框
class ChomeworkDlg : public CDialogEx
{
// 构造
public:
	ChomeworkDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HOMEWORK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CStatic t1;         //借书文件路径
	CStatic t2;         //还书文件路径
public:
	afx_msg void OnBnClickedButton1();        //选择借书文件按钮
	afx_msg void OnBnClickedButton2();        //选择还书文件按钮
private:
	CEdit text;        //显示结果的编辑框
public:
	afx_msg void OnBnClickedButton3();        //输出借书信息按钮
	afx_msg void OnBnClickedButton4();        //输出还书信息按钮
	afx_msg void OnBnClickedButton5();        //合并信息按钮
	afx_msg void OnBnClickedButton6();        //输出合并后的信息按钮
	afx_msg void OnBnClickedButton7();        //查询某人的借书信息按钮
	afx_msg void OnBnClickedButton8();        //查询某人的还书信息按钮
private:
	CStatic title;                      //功能选项标题
	CButton bn1;                        //选择借书文件
	CButton bn2;                        //选择还书文件 
	CButton bn3;                        //输出借书信息
	CButton bn4;                        //输出还书信息
	CButton bn5;                        //合并信息
	CButton bn6;                        //输出合并后的信息
	CButton bn7;                        //查询某人的借书信息		
	CButton bn8;                        //查询某人的还书信息
	CButton bn9;                        //查询某人的借还书间隔时间
public:
	afx_msg void OnBnClickedButton9();            //查询某人的借还书间隔时间
	afx_msg void OnBnClickedButton10();           //退出程序按钮
private:
	CEdit test0;                //项目名称标题/欢迎
	CStatic text2;              //操作结果标题
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);    //设置颜色
	afx_msg void OnBnClickedButton11();        //创建合并信息后的文件按钮
};
