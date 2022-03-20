
// homeworkDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "homework.h"
#include "homeworkDlg.h"
#include "afxdialogex.h"
#include"my_data.h"
#include"input_in.h"
#include"Cout_file.h"

vector<vector<string>>A, B;
Node t;      //Node������
Func func;    //Func������
File file;    //File������
int max_len = 0;
int max_len1 = 0;
int max_len2 = 0;	
vector<node*>p1, p2, c;
CString person;
CString file_name;
int flag;      //���Ա���Ƿ�������Ϣ   



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ChomeworkDlg �Ի���



ChomeworkDlg::ChomeworkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChomeworkDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ChomeworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILE1, t1);
	DDX_Control(pDX, IDC_FILE2, t2);
	DDX_Control(pDX, IDC_EDIT1, text);
	DDX_Control(pDX, IDC_TEXT, title);
	DDX_Control(pDX, IDC_BUTTON1, bn1);
	DDX_Control(pDX, IDC_BUTTON2, bn2);
	DDX_Control(pDX, IDC_BUTTON3, bn3);
	DDX_Control(pDX, IDC_BUTTON4, bn4);
	DDX_Control(pDX, IDC_BUTTON5, bn5);
	DDX_Control(pDX, IDC_BUTTON6, bn6);
	DDX_Control(pDX, IDC_BUTTON7, bn7);
	DDX_Control(pDX, IDC_BUTTON8, bn8);
	DDX_Control(pDX, IDC_BUTTON9, bn9);
	DDX_Control(pDX, IDC_EDIT2, test0);
	DDX_Control(pDX, IDC_TEXT2, text2);
}

BEGIN_MESSAGE_MAP(ChomeworkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &ChomeworkDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ChomeworkDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ChomeworkDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &ChomeworkDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &ChomeworkDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &ChomeworkDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &ChomeworkDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &ChomeworkDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &ChomeworkDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &ChomeworkDlg::OnBnClickedButton10)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON11, &ChomeworkDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// ChomeworkDlg ��Ϣ�������

BOOL ChomeworkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	//���ò�������༭�������С������
	CFont font;
	font.CreatePointFont(140, _T("����"));
	text.SetFont(&font);

	//���ñ���༭�������С
	CFont font_title;
	font_title.CreatePointFont(300, _T("����"));
	test0.SetFont(&font_title);
	test0.SetWindowTextW(TEXT("��ӭ�����軹����Ϣ����ϵͳ"));
	text2.SetFont(&font_title);
	text2.SetWindowTextW(TEXT("�������"));




	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void ChomeworkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void ChomeworkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR ChomeworkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//ѡ������ļ�
void ChomeworkDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�����ͷ��ڴ棬ɾ��֮ǰ�洢����Ϣ
	for (int i = 0; i < (int)p1.size(); i++)
	{
		t.delete_node(p1[i]);
	}
	p1 = { nullptr };         //ָ���

	//���A���ݣ�����ѡ���ļ����ٴ�ѡ�񣬻��߽��ж�β���
	A.swap(vector<vector<string>>());  
	max_len1 = 0;

	CString filename;//����·��
	CFileDialog opendlg(TRUE, _T("*"), _T(""), OFN_OVERWRITEPROMPT, _T("�����ļ�(*.*;)|*.*||"), NULL);
	if (opendlg.DoModal() == IDOK)
	{
		filename = opendlg.GetPathName();
	}
	t1.SetWindowTextW(filename);
	ifstream a(filename);
	if (a)
	{
		string title;
		for (int i = 0; i < 4; i++)
		{
			a >> title;
		}
		file.store(a, A, max_len1);
		vector<node*>p(A.size());
		for (int i = 0; i < (int)A.size(); i++)
		{
			p[i] = t.HEAD(A[i]);
		}
		p1 = p;
		text.SetSel(-1);
		text.ReplaceSel(TEXT("��ȡ�����ļ��ɹ�\r\n"));
		a.close();                 //�ļ��ر�
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("��ȡ�����ļ�ʧ��\r\n"));
		p1.clear();
	}
}

//ѡ�����ļ�
void ChomeworkDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�ͷ��ڴ�
	for (int i = 0; i < (int)p2.size(); i++)
	{
		t.delete_node(p2[i]);
	}
	p2 = { nullptr };          //ָ���

	//���B���ݣ�����ѡ���ļ����ٴ�ѡ�񣬻��߽��ж�β���
	B.swap(vector<vector<string>>());

	max_len2 = 0; 

	CString filename;//����·��
	CFileDialog opendlg(TRUE, _T("*"), _T(""), OFN_OVERWRITEPROMPT, _T("�����ļ�(*.*;)|*.*||"), NULL);
	if (opendlg.DoModal() == IDOK)
	{
		filename = opendlg.GetPathName();
	}
	t2.SetWindowTextW(filename);
	ifstream b(filename);
	if (b)
	{
		string title;
		for (int i = 0; i < 4; i++)
		{
			b >> title;
		}
		file.store(b, B, max_len2);
		vector<node*>p(B.size());
		for (int i = 0; i < (int)B.size(); i++)
		{
			p[i] = t.HEAD(B[i]);
		}
		p2 = p;
		text.SetSel(-1);
		text.ReplaceSel(TEXT("��ȡ�����ļ��ɹ�\r\n"));
		b.close();                 //�ر��ļ�
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("��ȡ�����ļ�ʧ��\r\n"));
		p2.clear();
	}
	
}

//���������Ϣ
void ChomeworkDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (p1.size() != 0)
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("��������Ϊ���˺š�ѧ�š�ͼ�������š�����ʱ��\r\n"));
		for (int i = 0; i < (int)p1.size(); i++)
		{
			t.show(p1[i], text);
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("����ѡȡ�����ļ�\r\n"));
	}
	
}

//���������Ϣ
void ChomeworkDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (p2.size() != 0)
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("��������Ϊ���˺š�ѧ�š�ͼ�������š�����ʱ��\r\n"));
		for (int i = 0; i < (int)p2.size(); i++)
		{
			t.show(p2[i], text);
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("����ѡȡ�����ļ�\r\n"));
	}
}

//�ϲ���Ϣ
void ChomeworkDlg::OnBnClickedButton5()
{
	//���ͷ��ڴ�
	for (int i = 0; i < (int)c.size(); i++)
	{
		t.delete_node(c[i]);
	}
	c = { nullptr };

	c.swap(vector<node*>());
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (p1.size() != 0 && p2.size() != 0)
	{
		c=func.add(p1, p2);
		text.SetSel(-1);
		text.ReplaceSel(TEXT("�ϲ���Ϣ�ɹ�\r\n"));
		
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("����ѡȡ�ļ���ȫ\r\n"));
	}
}

//����ϲ������Ϣ���༭��
void ChomeworkDlg::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (c.size() != 0)
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("��������Ϊ���˺š�ѧ�š�ͼ�������š�����ʱ�䡢����ʱ��\r\n"));
		for (int i = 0; i < (int)c.size(); i++)
		{
			t.show(c[i], text);
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("���Ƚ��кϲ���Ϣ����\r\n"));
	}

}


//���ĳ�˵Ľ�����Ϣ
void ChomeworkDlg::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (p1.size() != 0)
	{
		input_in d;
		d.DoModal();
		USES_CONVERSION;
		if (flag)
		{
			if (func.lend_time(p1, W2A(person), p1.size()) == "")
				MessageBox(TEXT("�޴�����Ϣ"));         
			else
			{
				CString out;
				out = ("�Ľ���ʱ��Ϊ\r\n" + func.lend_time(p1, W2A(person), p1.size())).c_str();
				MessageBox(person+out);
				out = ("�Ľ���ʱ��Ϊ" + func.lend_time(p1, W2A(person), p1.size())).c_str();
				text.SetSel(-1);
				text.ReplaceSel(person+out+TEXT("\r\n"));
			}
		}
		flag = 0;
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("����ѡ������ļ�\r\n"));
	}
}


//���ĳ�˵Ļ�����Ϣ
void ChomeworkDlg::OnBnClickedButton8()
{
	if (p2.size() != 0)
	{
		// TODO:  �ڴ���ӿؼ�֪ͨ����������
		input_in d;
		d.DoModal();
		USES_CONVERSION;
		if (flag)           //�ж��Ƿ���в���
		{
			if (func.return_time(p2, W2A(person), p2.size()) == "")
				MessageBox(TEXT("�޴�����Ϣ"));
			else
			{
				CString out;
				out = ("�Ļ���ʱ��Ϊ\r\n" + func.return_time(p2, W2A(person), p2.size())).c_str();
				MessageBox(person+out);
				out = ("�Ļ���ʱ��Ϊ" + func.return_time(p2, W2A(person), p2.size())).c_str();
				text.SetSel(-1);
				text.ReplaceSel(person + out + TEXT("\r\n"));
			}
			flag = 0;
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("����ѡ�����ļ�\r\n"));
	}
}


//��ѯĳ�˵Ľ軹����ʱ��
void ChomeworkDlg::OnBnClickedButton9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (p1.size() != 0 && p2.size() != 0)
	{
		input_in d;
		d.DoModal();
		USES_CONVERSION;
		if (flag)    //�ж��Ƿ�����˲���
		{
			if (func.lend_time(p1, W2A(person), p1.size()) == "")
				MessageBox(TEXT("�޴�����Ϣ"));
			else if (func.return_time(p2, W2A(person), p2.size()) == "")
				MessageBox(person + TEXT("��δ����"));
			else
			{
				CString out;
				out.Format(_T("%d"), func.time(W2A(person), p1, p2, p1.size()));
				MessageBox(person + TEXT("�Ľ軹����ʱ��Ϊ\r\n") + out + TEXT("��\r\n"));
				text.SetSel(-1);
				text.ReplaceSel(person + TEXT("�Ľ軹����ʱ��Ϊ") + out + TEXT("��\r\n"));
			}
			flag = 0;
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("���ȶ�ȡ�ļ���ȫ\r\n"));
	}

}

//�˳������ͷ��ڴ�
void ChomeworkDlg::OnBnClickedButton10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < (int)p1.size(); i++)
	{
		t.delete_node(p1[i]);
	}
	for (int i = 0; i < (int)p2.size(); i++)
	{
		t.delete_node(p2[i]);
	}
	for (int i = 0; i < (int)c.size(); i++)
	{
		t.delete_node(c[i]);
	}
	p1 = p2 = c = { nullptr };
	exit(0);
}

//����洢�ϲ���Ϣ���ļ�
void ChomeworkDlg::OnBnClickedButton11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (c.size() != 0)
	{
		max_len = max_len1 > max_len2 ? max_len1 : max_len2;    //����Ŀǰ����ַ�����
		Cout_file F;
		F.DoModal();
		USES_CONVERSION;
		ofstream out;
		if (flag)
		{
			file.output_file(out, W2A(file_name), c, max_len);
			text.SetSel(-1);
			text.ReplaceSel(TEXT("�����ļ��ɹ�������������·���²��ң����δ����·�������������ͬһĿ¼�²���\r\n"));
			text.SetSel(-1);
			text.ReplaceSel(TEXT("���������ϢΪ��\r\n") + file_name+TEXT("\r\n"));
			flag = 0;
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("���Ƚ��кϲ���Ϣ����\r\n"));
	}
	
}

//���ö�Ӧ�ؼ���������ɫ��������ɫ
HBRUSH ChomeworkDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������

	//���ò�������༭�����ɫ���
	if (pWnd->GetDlgCtrlID() == IDC_EDIT1)
	{
		pDC->SetTextColor(RGB(0, 0, 255));
	}
	return hbr;
}



