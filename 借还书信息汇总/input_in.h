#pragma once
#include "afxwin.h"

// input_in �Ի���

class input_in : public CDialogEx    //�����ѯ����Ի���
{
	DECLARE_DYNAMIC(input_in)

public:
	input_in(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~input_in();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CEdit name;              //�����ѯ����Ի����е�edit���Ӧ�ı�����
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
