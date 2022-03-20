
// homeworkDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "homework.h"
#include "homeworkDlg.h"
#include "afxdialogex.h"
#include"my_data.h"
#include"input_in.h"
#include"Cout_file.h"

vector<vector<string>>A, B;
Node t;      //Node类载入
Func func;    //Func类载入
File file;    //File类载入
int max_len = 0;
int max_len1 = 0;
int max_len2 = 0;	
vector<node*>p1, p2, c;
CString person;
CString file_name;
int flag;      //用以标记是否输入信息   



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// ChomeworkDlg 对话框



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


// ChomeworkDlg 消息处理程序

BOOL ChomeworkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	//设置操作结果编辑框字体大小、背景
	CFont font;
	font.CreatePointFont(140, _T("楷体"));
	text.SetFont(&font);

	//设置标题编辑框字体大小
	CFont font_title;
	font_title.CreatePointFont(300, _T("楷体"));
	test0.SetFont(&font_title);
	test0.SetWindowTextW(TEXT("欢迎来到借还书信息汇总系统"));
	text2.SetFont(&font_title);
	text2.SetWindowTextW(TEXT("操作结果"));




	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ChomeworkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ChomeworkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//选择借书文件
void ChomeworkDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//首先释放内存，删除之前存储的信息
	for (int i = 0; i < (int)p1.size(); i++)
	{
		t.delete_node(p1[i]);
	}
	p1 = { nullptr };         //指向空

	//清空A数据，便于选错文件后再次选择，或者进行多次操作
	A.swap(vector<vector<string>>());  
	max_len1 = 0;

	CString filename;//保存路径
	CFileDialog opendlg(TRUE, _T("*"), _T(""), OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"), NULL);
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
		text.ReplaceSel(TEXT("读取借书文件成功\r\n"));
		a.close();                 //文件关闭
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("读取借书文件失败\r\n"));
		p1.clear();
	}
}

//选择还书文件
void ChomeworkDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	//释放内存
	for (int i = 0; i < (int)p2.size(); i++)
	{
		t.delete_node(p2[i]);
	}
	p2 = { nullptr };          //指向空

	//清空B数据，便于选错文件后再次选择，或者进行多次操作
	B.swap(vector<vector<string>>());

	max_len2 = 0; 

	CString filename;//保存路径
	CFileDialog opendlg(TRUE, _T("*"), _T(""), OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"), NULL);
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
		text.ReplaceSel(TEXT("读取还书文件成功\r\n"));
		b.close();                 //关闭文件
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("读取还书文件失败\r\n"));
		p2.clear();
	}
	
}

//输出借书信息
void ChomeworkDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	if (p1.size() != 0)
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("数据依次为：账号、学号、图书索引号、借书时间\r\n"));
		for (int i = 0; i < (int)p1.size(); i++)
		{
			t.show(p1[i], text);
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("请先选取借书文件\r\n"));
	}
	
}

//输出还书信息
void ChomeworkDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	if (p2.size() != 0)
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("数据依次为：账号、学号、图书索引号、还书时间\r\n"));
		for (int i = 0; i < (int)p2.size(); i++)
		{
			t.show(p2[i], text);
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("请先选取还书文件\r\n"));
	}
}

//合并信息
void ChomeworkDlg::OnBnClickedButton5()
{
	//先释放内存
	for (int i = 0; i < (int)c.size(); i++)
	{
		t.delete_node(c[i]);
	}
	c = { nullptr };

	c.swap(vector<node*>());
	// TODO:  在此添加控件通知处理程序代码
	if (p1.size() != 0 && p2.size() != 0)
	{
		c=func.add(p1, p2);
		text.SetSel(-1);
		text.ReplaceSel(TEXT("合并信息成功\r\n"));
		
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("请先选取文件完全\r\n"));
	}
}

//输出合并后的信息到编辑框
void ChomeworkDlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	if (c.size() != 0)
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("数据依次为：账号、学号、图书索引号、借书时间、还书时间\r\n"));
		for (int i = 0; i < (int)c.size(); i++)
		{
			t.show(c[i], text);
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("请先进行合并信息操作\r\n"));
	}

}


//输出某人的借书信息
void ChomeworkDlg::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	if (p1.size() != 0)
	{
		input_in d;
		d.DoModal();
		USES_CONVERSION;
		if (flag)
		{
			if (func.lend_time(p1, W2A(person), p1.size()) == "")
				MessageBox(TEXT("无此人信息"));         
			else
			{
				CString out;
				out = ("的借书时间为\r\n" + func.lend_time(p1, W2A(person), p1.size())).c_str();
				MessageBox(person+out);
				out = ("的借书时间为" + func.lend_time(p1, W2A(person), p1.size())).c_str();
				text.SetSel(-1);
				text.ReplaceSel(person+out+TEXT("\r\n"));
			}
		}
		flag = 0;
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("请先选择借书文件\r\n"));
	}
}


//输出某人的还书信息
void ChomeworkDlg::OnBnClickedButton8()
{
	if (p2.size() != 0)
	{
		// TODO:  在此添加控件通知处理程序代码
		input_in d;
		d.DoModal();
		USES_CONVERSION;
		if (flag)           //判断是否进行操作
		{
			if (func.return_time(p2, W2A(person), p2.size()) == "")
				MessageBox(TEXT("无此人信息"));
			else
			{
				CString out;
				out = ("的还书时间为\r\n" + func.return_time(p2, W2A(person), p2.size())).c_str();
				MessageBox(person+out);
				out = ("的还书时间为" + func.return_time(p2, W2A(person), p2.size())).c_str();
				text.SetSel(-1);
				text.ReplaceSel(person + out + TEXT("\r\n"));
			}
			flag = 0;
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("请先选择还书文件\r\n"));
	}
}


//查询某人的借还书间隔时间
void ChomeworkDlg::OnBnClickedButton9()
{
	// TODO:  在此添加控件通知处理程序代码
	if (p1.size() != 0 && p2.size() != 0)
	{
		input_in d;
		d.DoModal();
		USES_CONVERSION;
		if (flag)    //判断是否进行了操作
		{
			if (func.lend_time(p1, W2A(person), p1.size()) == "")
				MessageBox(TEXT("无此人信息"));
			else if (func.return_time(p2, W2A(person), p2.size()) == "")
				MessageBox(person + TEXT("还未还书"));
			else
			{
				CString out;
				out.Format(_T("%d"), func.time(W2A(person), p1, p2, p1.size()));
				MessageBox(person + TEXT("的借还书间隔时间为\r\n") + out + TEXT("天\r\n"));
				text.SetSel(-1);
				text.ReplaceSel(person + TEXT("的借还书间隔时间为") + out + TEXT("天\r\n"));
			}
			flag = 0;
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("请先读取文件完全\r\n"));
	}

}

//退出程序，释放内存
void ChomeworkDlg::OnBnClickedButton10()
{
	// TODO:  在此添加控件通知处理程序代码
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

//输出存储合并信息的文件
void ChomeworkDlg::OnBnClickedButton11()
{
	// TODO:  在此添加控件通知处理程序代码
	if (c.size() != 0)
	{
		max_len = max_len1 > max_len2 ? max_len1 : max_len2;    //更新目前的最长字符长度
		Cout_file F;
		F.DoModal();
		USES_CONVERSION;
		ofstream out;
		if (flag)
		{
			file.output_file(out, W2A(file_name), c, max_len);
			text.SetSel(-1);
			text.ReplaceSel(TEXT("创建文件成功，请在所输入路径下查找，如果未输入路径，则在与程序同一目录下查找\r\n"));
			text.SetSel(-1);
			text.ReplaceSel(TEXT("您输入的信息为：\r\n") + file_name+TEXT("\r\n"));
			flag = 0;
		}
	}
	else
	{
		text.SetSel(-1);
		text.ReplaceSel(TEXT("请先进行合并信息操作\r\n"));
	}
	
}

//设置对应控件的文字颜色、背景颜色
HBRUSH ChomeworkDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔

	//设置操作结果编辑框的颜色相关
	if (pWnd->GetDlgCtrlID() == IDC_EDIT1)
	{
		pDC->SetTextColor(RGB(0, 0, 255));
	}
	return hbr;
}



