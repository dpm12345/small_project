
// homeworkDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// ChomeworkDlg �Ի���
class ChomeworkDlg : public CDialogEx
{
// ����
public:
	ChomeworkDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HOMEWORK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CStatic t1;         //�����ļ�·��
	CStatic t2;         //�����ļ�·��
public:
	afx_msg void OnBnClickedButton1();        //ѡ������ļ���ť
	afx_msg void OnBnClickedButton2();        //ѡ�����ļ���ť
private:
	CEdit text;        //��ʾ����ı༭��
public:
	afx_msg void OnBnClickedButton3();        //���������Ϣ��ť
	afx_msg void OnBnClickedButton4();        //���������Ϣ��ť
	afx_msg void OnBnClickedButton5();        //�ϲ���Ϣ��ť
	afx_msg void OnBnClickedButton6();        //����ϲ������Ϣ��ť
	afx_msg void OnBnClickedButton7();        //��ѯĳ�˵Ľ�����Ϣ��ť
	afx_msg void OnBnClickedButton8();        //��ѯĳ�˵Ļ�����Ϣ��ť
private:
	CStatic title;                      //����ѡ�����
	CButton bn1;                        //ѡ������ļ�
	CButton bn2;                        //ѡ�����ļ� 
	CButton bn3;                        //���������Ϣ
	CButton bn4;                        //���������Ϣ
	CButton bn5;                        //�ϲ���Ϣ
	CButton bn6;                        //����ϲ������Ϣ
	CButton bn7;                        //��ѯĳ�˵Ľ�����Ϣ		
	CButton bn8;                        //��ѯĳ�˵Ļ�����Ϣ
	CButton bn9;                        //��ѯĳ�˵Ľ軹����ʱ��
public:
	afx_msg void OnBnClickedButton9();            //��ѯĳ�˵Ľ軹����ʱ��
	afx_msg void OnBnClickedButton10();           //�˳�����ť
private:
	CEdit test0;                //��Ŀ���Ʊ���/��ӭ
	CStatic text2;              //�����������
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);    //������ɫ
	afx_msg void OnBnClickedButton11();        //�����ϲ���Ϣ����ļ���ť
};
