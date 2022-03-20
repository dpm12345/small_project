#include"action.h"


//Menu类 成员函数实现
//进入菜单
void Menu::menu1()                      
{
	cout << "********************************************" << endl;
	cout << "*****    欢迎来到借还书信息汇总系统    *****" << endl;
	cout << "*****                                     **" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cout << "********************************************" << endl;
	cout << "*Tips：在开始前请先将要合并的两个文件放入  *" << endl;
	cout << "**              程序目录中                **" << endl;
	cout << "*        完成操作后可按回车键开始          *" << endl;
	cout << "********************************************" << endl;
}


//功能菜单
void Menu::menu2()
{
	cout << "********************************************" << endl;
	cout << "***请选择你所要进行的操作(输入数字):   *****" << endl;
	cout << "*** basic function:                    *****" << endl;
	cout << "***      1.合并借还书信息              *****" << endl;
	cout << "***      2.输出借还书信息到文件        *****" << endl;
	cout << "***      3.输出存储借书信息的链表      *****" << endl;
	cout << "***      4.输出存储还书信息的链表      *****" << endl;
	cout << "***      5.输出合并借还书信息的链表    *****" << endl;
	cout << "*** extra function:                    *****" << endl;
	cout << "***      6.查询某人借书信息            *****" << endl;
	cout << "***      7.查询某人还书信息            *****" << endl;
	cout << "***      8.查询某人借还书所花时间      *****" << endl;
	cout << "*** 若要退出请输入数字0                *****" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cout << "请输入:";

}



//Node类 成员函数实现
//创建链表
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


//释放内存
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

//输出链表内容
void Node::show(const node* p)
{
	while (p != nullptr)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}


//Func类 成员函数实现
//合并数据
vector<node*> Func::add(vector<node*>&p1, vector<node*>&p2)    
{
	vector<node*> c(p1.size(), nullptr);
	int index = 0;

    //判断两段数据是否为同一个人同一本书，是则加上还书时间
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


//查询借书时间
string Func::lend_time(vector<node*>&p1, string search, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p1[i]->data == search || p1[i]->next->data == search )
		{
			return p1[i]->next->next->next->data;
		}
	}
	
	//若查无此人，返回空
	return "";                  
}



//查询还书时间
string Func::return_time(vector<node*>&p2, string search, int n)

{
	for (int i = 0; i < n; i++)
	{
		if (p2[i]->data == search || p2[i]->next->data == search)
		{
			return p2[i]->next->next->next->data;
		}
	}
	
	//若查无此人，返回空
	return "";             
}


//判断是否为闰年，为后面计算从借书到换书提供基础
bool Func::is_runyear(int n)
{
	if (n % 400 == 0)
		return true;
	else if (n % 100 != 0 && n % 4 == 0)
		return true;
	else
		return false;
}


//查询从借书到还书共经历了多长时间
int Func::time(string search, vector<node*>&p1, vector<node*>&p2, int n)

{
	if (lend_time(p1, search, n) == ""&&return_time(p2,search,n)=="") 
		return -1;        //查无此人                            
	if (return_time(p2, search,n) == "")  
		return -2;             //还未还书
	
	//正常年的各月底累积天数(前缀和)
	int nums1[13] = { 0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 }; 
	//闰年的各月底累计天数         
	int nums2[13] = { 0,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };          
	
	string a, b;                   //a,b分别存储借书、还书时间
	
	//获取借书时间
	for (int i = 0; i < n; i++)                                         
	{
		if (p1[i]->data == search || p1[i]->next->data == search)
		{
			a = p1[i]->next->next->next->data;
		}
	}
	
	//获取还书时间
	for (int i = 0; i < n; i++)                                         
	{
		if (p2[i]->data == search || p2[i]->next->data == search)
		{
			b = p2[i]->next->next->next->data;
		}
	}

    //将时间的年月份用int存入
	int year1, year2, month1, month2, day1, day2;

	//res记录已获得数值，count用于确认存储的时间单位
	int res=0,count=0;
	
	//借书时间
	for (int i = 0; i < a.length(); i++)                       
	{
		if (a[i] == '-')
		{
			if (count == 0)     //年
			{
				year1 = res;
				res = 0;
				count++;
			}
			else if (count == 1)     //月
			{
				month1 = res;
				res = 0;
				count++;
			}
		}
		else
			res = res * 10 + a[i] - 48;
		
	}
	day1 = res;          //日
	res = 0;
	count = 0;

	//还书时间
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

	//计算间隔时间
	while (year1 < year2)
	{
		if (is_runyear(year1))
		{
			if (count == 0)         //年末与当前时间的间隔
			{
				res = res + nums2[12] - nums2[month1-1] - day1;
				count++;
				day1 = 0;
				month1 = 1;
			}
			else                //相差了整整一年
			{
				res += nums2[12];
				count++;
			}
		}
		else
		{
			if (count == 0)     //年末与当前时间的间隔
			{
				res = res + nums1[12] - nums1[month1-1] - day1;
				count++;
				day1 = 0;
				month1 = 1;
			}
			else               //相差了整整一年
			{
				res += nums1[12];
				count++;
			}
		}
		year1++;
	}
	if (is_runyear(year2))        //计算同年份时的相差日数
		res = res + nums2[month2 - 1] - nums2[month1 - 1] + day2 - day1;
	else
		res = res + nums1[month2 - 1] - nums1[month1 - 1] + day2 - day1;
	return res;
}


//File类 成员函数实现
//获取借书文件的文件名
void File::get_lend_file(string &a_name)
{
	int flag;       //文件正确判断
	string cur;     //输入格式判断
	do
	{
		cout << "请输入借书信息文件名:";
		getline(cin, a_name);
		cout << "借书信息文件名为:" << a_name << endl;
		cout << "若无误，请输入0继续；若有误，请输入1重新输入文件名" << endl;
		cout << "请输入你的判断( 0 / 1 ):";
		cin >> cur;
		T_or_F(cur);
		flag = cur[0] - 48;
	} while (flag);
}

void File::get_return_file(string &b_name)
{
	int flag;       //文件正确判断
	string cur;     //输入格式判断
	do
	{
		cout << "请输入还书信息文件名:";
		getline(cin, b_name);
		cout << "还书信息文件名为:" << b_name << endl;
		cout << "若无误，请输入0继续；若有误，请输入1重新输入文件名" << endl;
		cout << "请输入你的判断( 0 / 1 ):";
		cin >> cur;
		T_or_F(cur);
		flag = cur[0] - 48;
	} while (flag);
}


//输出合并的结果
void File::output_file(ofstream &out_f,vector<node*>&c,int max_len)
{
	//自定义文件名
	string files_name;
	cout << "请输入您希望输出后的文件名(包括文件的后缀名)" << endl;
	cin >> files_name;
	out_f.open(files_name, ios_base::trunc);

	//输出标题
	out_f << setw(max_len + 2) << "账号" << setw(max_len + 2) << "学号";
	out_f << setw(max_len + 2) << "图书索引号" << setw(max_len + 2) << "借书时间";
	out_f << setw(max_len + 2) << "还书时间" << endl;
	
	//输出文件
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
	cout << "操作成功，请在同文件目录下的" << files_name << "文件中查看\n\n\n";
}


//将文件的信息存入数组
void File::store(ifstream &f, vector<vector<string>>&X,int &max_len)
{
	int index = 0;
	string cur;
	while (!f.eof())     //判断文件是否到末尾
	{
		if (index == 0)   //即开始新的一行数据
			X.resize(X.size() + 1, vector<string>(4));
		f >> cur;

		//随时更新数据内的最大长度
		max_len = max(max_len, int(cur.length()));  
		X[X.size() - 1][index] = cur;
		index = (index + 1) % 4;
	}
}


//判断输出格式是否满足为一个数字
void T_or_F(string& cur)
{
	while (cur.length() != 1 || cur[0]<'0' || cur[0]>'9')
	{
		cout << "输入有误，请重新输入:\n";
		cin >> cur;
	}
	getchar();
}
