#include"action.h"


//Menu�� ��Ա����ʵ��
//����˵�
void Menu::menu1()                      
{
	cout << "********************************************" << endl;
	cout << "*****    ��ӭ�����軹����Ϣ����ϵͳ    *****" << endl;
	cout << "*****                                     **" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cout << "********************************************" << endl;
	cout << "*Tips���ڿ�ʼǰ���Ƚ�Ҫ�ϲ��������ļ�����  *" << endl;
	cout << "**              ����Ŀ¼��                **" << endl;
	cout << "*        ��ɲ�����ɰ��س�����ʼ          *" << endl;
	cout << "********************************************" << endl;
}


//���ܲ˵�
void Menu::menu2()
{
	cout << "********************************************" << endl;
	cout << "***��ѡ������Ҫ���еĲ���(��������):   *****" << endl;
	cout << "*** basic function:                    *****" << endl;
	cout << "***      1.�ϲ��軹����Ϣ              *****" << endl;
	cout << "***      2.����軹����Ϣ���ļ�        *****" << endl;
	cout << "***      3.����洢������Ϣ������      *****" << endl;
	cout << "***      4.����洢������Ϣ������      *****" << endl;
	cout << "***      5.����ϲ��軹����Ϣ������    *****" << endl;
	cout << "*** extra function:                    *****" << endl;
	cout << "***      6.��ѯĳ�˽�����Ϣ            *****" << endl;
	cout << "***      7.��ѯĳ�˻�����Ϣ            *****" << endl;
	cout << "***      8.��ѯĳ�˽軹������ʱ��      *****" << endl;
	cout << "*** ��Ҫ�˳�����������0                *****" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cout << "������:";

}



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
void Node::show(const node* p)
{
	while (p != nullptr)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}


//Func�� ��Ա����ʵ��
//�ϲ�����
vector<node*> Func::add(vector<node*>&p1, vector<node*>&p2)    
{
	vector<node*> c(p1.size(), nullptr);
	int index = 0;

    //�ж����������Ƿ�Ϊͬһ����ͬһ���飬������ϻ���ʱ��
	for (int i = 0; i < p1.size(); i++)               
	{
		for (int j = 0; j < p2.size(); j++)
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
		if (p1[i]->data == search || p1[i]->next->data == search )
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
	if (lend_time(p1, search, n) == ""&&return_time(p2,search,n)=="") 
		return -1;        //���޴���                            
	if (return_time(p2, search,n) == "")  
		return -2;             //��δ����
	
	//������ĸ��µ��ۻ�����(ǰ׺��)
	int nums1[13] = { 0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 }; 
	//����ĸ��µ��ۼ�����         
	int nums2[13] = { 0,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };          
	
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
	int res=0,count=0;
	
	//����ʱ��
	for (int i = 0; i < a.length(); i++)                       
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
	for (int i = 0; i < b.length(); i++)
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
				res = res + nums2[12] - nums2[month1-1] - day1;
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
				res = res + nums1[12] - nums1[month1-1] - day1;
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
//��ȡ�����ļ����ļ���
void File::get_lend_file(string &a_name)
{
	int flag;       //�ļ���ȷ�ж�
	string cur;     //�����ʽ�ж�
	do
	{
		cout << "�����������Ϣ�ļ���:";
		getline(cin, a_name);
		cout << "������Ϣ�ļ���Ϊ:" << a_name << endl;
		cout << "������������0������������������1���������ļ���" << endl;
		cout << "����������ж�( 0 / 1 ):";
		cin >> cur;
		T_or_F(cur);
		flag = cur[0] - 48;
	} while (flag);
}

void File::get_return_file(string &b_name)
{
	int flag;       //�ļ���ȷ�ж�
	string cur;     //�����ʽ�ж�
	do
	{
		cout << "�����뻹����Ϣ�ļ���:";
		getline(cin, b_name);
		cout << "������Ϣ�ļ���Ϊ:" << b_name << endl;
		cout << "������������0������������������1���������ļ���" << endl;
		cout << "����������ж�( 0 / 1 ):";
		cin >> cur;
		T_or_F(cur);
		flag = cur[0] - 48;
	} while (flag);
}


//����ϲ��Ľ��
void File::output_file(ofstream &out_f,vector<node*>&c,int max_len)
{
	//�Զ����ļ���
	string files_name;
	cout << "��������ϣ���������ļ���(�����ļ��ĺ�׺��)" << endl;
	cin >> files_name;
	out_f.open(files_name, ios_base::trunc);

	//�������
	out_f << setw(max_len + 2) << "�˺�" << setw(max_len + 2) << "ѧ��";
	out_f << setw(max_len + 2) << "ͼ��������" << setw(max_len + 2) << "����ʱ��";
	out_f << setw(max_len + 2) << "����ʱ��" << endl;
	
	//����ļ�
	for (int i = 0; i < c.size(); i++)
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
void File::store(ifstream &f, vector<vector<string>>&X,int &max_len)
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


//�ж������ʽ�Ƿ�����Ϊһ������
void T_or_F(string& cur)
{
	while (cur.length() != 1 || cur[0]<'0' || cur[0]>'9')
	{
		cout << "������������������:\n";
		cin >> cur;
	}
	getchar();
}
