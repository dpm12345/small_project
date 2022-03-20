#ifndef ACTION_H
#define ACTION_H

#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<Windows.h>
#include"stdafx.h"
using namespace std;


 
//��㶨��
struct node{                     
	string data;                     //����������
	struct node *next;              //���ָ�����һ���ṹ��ָ��
};

//Node��
class Node{
public:
	//������������ͷָ��
	struct node* HEAD(vector<string> &p);

	//�ͷ��ڴ�
	void delete_node(node*p);

	//�����������
	void show(const node* p, CEdit &text);
};


//Func��
class Func{
public:
	//�ϲ�����
	vector<node*> add(vector<node*>&p1, vector<node*>&p2);

	//��ѯ����ʱ��
	string lend_time(vector<node*>&p1, string search, int n);

	//��ѯ����ʱ��
	string return_time(vector<node*>&p2, string search, int n);

	//�ж��Ƿ�Ϊ���꣬Ϊ�������ӽ��鵽�����ṩ����
	bool is_runyear(int n);

	//��ѯ�ӽ��鵽���鹲�����˶೤ʱ��
	int time(string search, vector<node*>&p1, vector<node*>&p2, int n);
};


//File ��
class File{
public:
	//����ϲ��Ľ��
	void output_file(ofstream &out_f, string files_name, vector<node*>&c, int max_len);

	//���ļ�����Ϣ��������
	void store(ifstream &f, vector<vector<string>>&X,int &max_len);
};


//Node�� ��Ա����ʵ��
//��������
struct node* Node::HEAD(vector<string> &p){

	node* head = new node;
	head->data = p[0];
	head->next = nullptr;
	node*a = head;
	int i = 1;
	while (i < 4)
	{
		node *b = new node;
		b->data = p[i];
		b->next = nullptr;
		a->next = b;
		a = b;
		i++;
	}
	return head;
}


//�ͷ��ڴ�
void Node::delete_node(node*p)
{
	while (p->next != nullptr)
	{
		node*temp = p;
		p = p->next;
		delete temp;

	}
	delete p;
}

//�����������
void Node::show(const node* p, CEdit &text)
{
	CString out;
	while (p != nullptr)
	{
		out += (p->data + "->").c_str();
		p = p->next;
	}
	text.SetSel(-1);
	text.ReplaceSel(out+"NULL\r\n");
}


//Func�� ��Ա����ʵ��
//�ϲ�����
vector<node*> Func::add(vector<node*>&p1, vector<node*>&p2)
{
	vector<node*> c(p1.size(), nullptr);
	int index = 0;

	//�ж����������Ƿ�Ϊͬһ����ͬһ���飬������ϻ���ʱ��
	for (int i = 0; i < (int)p1.size(); i++)
	{
		for (int j = 0; j < (int)p2.size(); j++)
		{
			if (p1[i]->data != ""&&p1[i]->next->data != ""&&p1[i]->data != ""&&p1[i]->next->next->data != "")
			{
				if (p1[i]->data == p2[j]->data&&p1[i]->next->data == p2[j]->next->data&&p1[i]->next->next->data == p2[j]->next->next->data)
				{
					c[index] = new node;
					c[index]->data = p1[i]->data;
					c[index]->next = nullptr;
					node* pos = c[index];
					node* cur = p1[i]->next;
					while (cur != nullptr)
					{
						node* p = new node;
						pos->next = p;
						p->data = cur->data;
						p->next = nullptr;
						cur = cur->next;
						pos = pos->next;
					}
					pos->next = new node;
					pos->next->data = p2[j]->next->next->next->data;
					pos->next->next = nullptr;
					index++;
				}
			}
		}
	}
	c.resize(index);
	return c;
}


//��ѯ����ʱ��
string Func::lend_time(vector<node*>&p1, string search, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p1[i]->data == search || p1[i]->next->data == search)
		{
			return p1[i]->next->next->next->data;
		}
	}

	//�����޴��ˣ����ؿ�
	return "";
}



//��ѯ����ʱ��
string Func::return_time(vector<node*>&p2, string search, int n)

{
	for (int i = 0; i < n; i++)
	{
		if (p2[i]->data == search || p2[i]->next->data == search)
		{
			return p2[i]->next->next->next->data;
		}
	}

	//�����޴��ˣ����ؿ�
	return "";
}


//�ж��Ƿ�Ϊ���꣬Ϊ�������ӽ��鵽�����ṩ����
bool Func::is_runyear(int n)
{
	if (n % 400 == 0)
		return true;
	else if (n % 100 != 0 && n % 4 == 0)
		return true;
	else
		return false;
}


//��ѯ�ӽ��鵽���鹲�����˶೤ʱ��
int Func::time(string search, vector<node*>&p1, vector<node*>&p2, int n)

{
	//������ĸ��µ��ۻ�����(ǰ׺��)
	int nums1[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	//����ĸ��µ��ۼ�����         
	int nums2[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };

	string a, b;                   //a,b�ֱ�洢���顢����ʱ��

	//��ȡ����ʱ��
	for (int i = 0; i < n; i++)
	{
		if (p1[i]->data == search || p1[i]->next->data == search)
		{
			a = p1[i]->next->next->next->data;
		}
	}

	//��ȡ����ʱ��
	for (int i = 0; i < n; i++)
	{
		if (p2[i]->data == search || p2[i]->next->data == search)
		{
			b = p2[i]->next->next->next->data;
		}
	}

	//��ʱ������·���int����
	int year1, year2, month1, month2, day1, day2;

	//res��¼�ѻ����ֵ��count����ȷ�ϴ洢��ʱ�䵥λ
	int res = 0, count = 0;

	//����ʱ��
	for (int i = 0; i < (int)a.length(); i++)
	{
		if (a[i] == '-')
		{
			if (count == 0)     //��
			{
				year1 = res;
				res = 0;
				count++;
			}
			else if (count == 1)     //��
			{
				month1 = res;
				res = 0;
				count++;
			}
		}
		else
			res = res * 10 + a[i] - 48;

	}
	day1 = res;          //��
	res = 0;
	count = 0;

	//����ʱ��
	for (int i = 0; i < (int)b.length(); i++)
	{
		if (b[i] == '-')
		{
			if (count == 0)
			{
				year2 = res;
				res = 0;
				count++;
			}
			else if (count == 1)
			{
				month2 = res;
				res = 0;
				count++;
			}
		}
		else
			res = res * 10 + b[i] - 48;
	}
	day2 = res;
	res = 0;
	count = 0;

	//������ʱ��
	while (year1 < year2)
	{
		if (is_runyear(year1))
		{
			if (count == 0)         //��ĩ�뵱ǰʱ��ļ��
			{
				res = res + nums2[12] - nums2[month1 - 1] - day1;
				count++;
				day1 = 0;
				month1 = 1;
			}
			else                //���������һ��
			{
				res += nums2[12];
				count++;
			}
		}
		else
		{
			if (count == 0)     //��ĩ�뵱ǰʱ��ļ��
			{
				res = res + nums1[12] - nums1[month1 - 1] - day1;
				count++;
				day1 = 0;
				month1 = 1;
			}
			else               //���������һ��
			{
				res += nums1[12];
				count++;
			}
		}
		year1++;
	}
	if (is_runyear(year2))        //����ͬ���ʱ���������
		res = res + nums2[month2 - 1] - nums2[month1 - 1] + day2 - day1;
	else
		res = res + nums1[month2 - 1] - nums1[month1 - 1] + day2 - day1;
	return res;
}


//File�� ��Ա����ʵ��


//����ϲ��Ľ��
void File::output_file(ofstream &out_f,string files_name, vector<node*>&c, int max_len)
{

	out_f.open(files_name, ios_base::trunc);

	//�������
	out_f << setw(max_len + 2) << "�˺�" << setw(max_len + 2) << "ѧ��";
	out_f << setw(max_len + 2) << "ͼ��������" << setw(max_len + 2) << "����ʱ��";
	out_f << setw(max_len + 2) << "����ʱ��" << endl;

	//����ļ�
	for (int i = 0; i <(int)c.size(); i++)
	{
		node*bl = c[i];
		while (bl != nullptr)
		{
			out_f << setw(max_len + 2) << bl->data;
			bl = bl->next;
		}
		out_f << endl;
	}
	cout << "�����ɹ�������ͬ�ļ�Ŀ¼�µ�" << files_name << "�ļ��в鿴\n\n\n";
}


//���ļ�����Ϣ��������
void File::store(ifstream &f, vector<vector<string>>&X, int &max_len)
{
	int index = 0;
	string cur;
	while (!f.eof())     //�ж��ļ��Ƿ�ĩβ
	{
		if (index == 0)   //����ʼ�µ�һ������
			X.resize(X.size() + 1, vector<string>(4));
		f >> cur;

		//��ʱ���������ڵ���󳤶�
		max_len = max(max_len, int(cur.length()));
		X[X.size() - 1][index] = cur;
		index = (index + 1) % 4;
	}
}

#endif