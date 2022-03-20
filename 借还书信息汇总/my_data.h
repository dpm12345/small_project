#ifndef MY_DATA_H
#define MY_DATA_H
#include"stdafx.h"
#include"action.h"


extern vector<vector<string>>A, B;       //存文件信息    
extern Node t1;      //Node类载入
extern Func func;    //Func类载入
extern File file;    //File类载入
extern int max_len;           //记录目前输入文件内容的最长长度
extern vector<node*>p1, p2, c;    //存储信息的链表指针数组
extern CString person;          //查询对象的名称
extern CString file_name;       //自定义合并后的(路径+)文件名
extern int max_len1;     //记录借书文件信息内容的最长长度
extern int max_len2;     //记录还书文件信息内容的最长长度

#endif