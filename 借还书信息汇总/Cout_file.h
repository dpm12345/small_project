#pragma once
#include "afxwin.h"


// Cout_file �Ի���

class Cout_file : public CDialogEx      //�����ļ���Ϣ�ĶԻ���
{
	DECLARE_DYNAMIC(Cout_file)

public:
	Cout_file(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cout_file();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CEdit f_name;               //�����ļ���Ϣ�Ի����edit���Ӧ����
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
