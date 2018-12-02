#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;
unsigned int choose;    //主菜单选项
unsigned int choose_one;  // 加减乘除运算选择
unsigned int choose_two;   // 多少以内的运算
unsigned int choose_three;  // 题目的类型
unsigned int choose_four;   //题目个数
int user_choose[5000];  //存放使用者的结果
int allresult[5000];   //存放该题的答案
int yes_or_no[5000];   //存放该题是否正确
int last[5000];       //存放运算的正确结果
int Score;       //题目号
ofstream OutFile("test.txt",ios::app);   //题目文件
ofstream OutFile_two("user.txt",ios::app); //使用者的结果文件
int k;  //数组移动
/**
做完一次题 把所有选项清0
*/
void clear_()
{
    choose_one = 0;
    choose_two = 0;
    choose_three = 0;
    choose_four = 0;
    memset(user_choose,0,sizeof(int));
    memset(allresult,0,sizeof(int));
    memset(yes_or_no,0,sizeof(int));
    memset(last,0,sizeof(int));
    k = 0;
    Score = 0;
}
class tools
{
public:
    void Begintools(); //开始的图画
    void skinSet();   //打印标准
    void flash();     //进度条缓冲
};
class test
{
public:
    void jiafa();
    void jianfa();
    void chengfa();
    void chufa();
};
/**
加法
*/
void test::jiafa()
{
    int x = rand();
    int y = rand();
    if(choose_two == 1)
    {
        x = x%11;
        y = y%11;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" + "<<y<<endl;
            allresult[k] = x+y;
            last[k] = x+y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<" = "<<x+y;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x+y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                allresult[k] = 4;
                last[k] = x+y;
                k++;
            }
        }
    }
    if(choose_two == 2)
    {
        x = x%101;
        y = y%101;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" + "<<y<<endl;
            allresult[k] = x+y;
            last[k] = x+y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<" = "<<x+y;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x+y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                allresult[k] = 4;
                last[k] = x+y;
                k++;
            }
        }
    }
    if(choose_two == 3)
    {
        x = x%1001;
        y = y%1001;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" + "<<y<<endl;
            allresult[k] = x+y;
            last[k] = x+y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y+1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<" = "<<x+y;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<" = "<<x+y<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" + "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x+y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                allresult[k] = 4;
                last[k] = x+y;
                k++;
            }
        }
    }
}
/**
减法
*/
void test::jianfa()
{
    int x = rand();
    int y = rand();
    if(choose_two == 1)
    {
        x = x%11;
        y = y%11;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" - "<<y<<endl;
            allresult[k] = x-y;
            last[k] = x-y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<" = "<<x-y;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x-y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                allresult[k] = 4;
                last[k] = x-y;
                k++;
            }
        }
    }
    if(choose_two == 2)
    {
        x = x%101;
        y = y%101;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" - "<<y<<endl;
            allresult[k] = x-y;
            last[k] = x-y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<" = "<<x-y;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x-y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                allresult[k] = 4;
                last[k] = x-y;
                k++;
            }
        }
    }
    if(choose_two == 3)
    {
        x = x%1001;
        y = y%1001;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" - "<<y<<endl;
            allresult[k] = x-y;
            last[k] = x-y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y+1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<" = "<<x-y;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<" = "<<x-y<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" - "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x-y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                allresult[k] = 4;
                last[k] = x-y;
                k++;
            }
        }
    }
}
/**
乘法
*/
void test::chengfa()
{
    int x = rand();
    int y = rand();
    if(choose_two == 1)
    {
        x = x%11;
        y = y%11;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" * "<<y<<endl;
            allresult[k] = x*y;
            last[k] = x*y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<" = "<<x*y;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                allresult[k] = 3;
                last[k] = x*y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                allresult[k] = 4;
                last[k] = x*y;
                k++;
            }
        }
    }
    if (choose_two == 2)
    {
        x = x%101;
        y = y%101;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" * "<<y<<endl;
            allresult[k] = x*y;
            last[k] = x*y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<" = "<<x*y;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                allresult[k] = 3;
                last[k] = x*y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                allresult[k] = 4;
                last[k] = x*y;
                k++;
            }
        }
    }
    if(choose_two == 3)
    {
        x = x%1001;
        y = y%1001;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" * "<<y<<endl;
            allresult[k] = x*y;
            last[k] = x*y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y+1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<" = "<<x*y;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<" = "<<x*y<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" * "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                allresult[k] = 3;
                last[k] = x*y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                allresult[k] = 4;
                last[k] = x*y;
                k++;
            }
        }
    }
}
/**
除法
*/
void test::chufa()
{
    int x = rand();
    int y = rand();
    if(choose_two == 1)
    {
        x = x%10 +1;
        y = y%10 +1;
        x = x*y;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" / "<<y<<endl;
            allresult[k] = x/y;
            last[k] = x/y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<" = "<<x/y;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                allresult[k] = 3;
                last[k] = x/y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                allresult[k] = 4;
                last[k] = x/y;
                k++;
            }
        }
    }
    if (choose_two == 2)
    {
        x = x%100 +1;
        y = y%100 +1;
        x = x*y;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" / "<<y<<endl;
            allresult[k] = x/y;
            last[k] = x/y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<" = "<<x/y;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                allresult[k] = 3;
                last[k] = x/y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                allresult[k] = 4;
                last[k] = x/y;
                k++;
            }
        }
    }
    if(choose_two == 3)
    {
        x = x%1000 +1;
        y = y%1000 +1;
        x = x*y;
        if(choose_three == 1)
        {
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<endl;
            OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<endl;
            OutFile_two<<"第"<< Score <<"题:"<<x<<" / "<<y<<endl;
            allresult[k] = x/y;
            last[k] = x/y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1;
                OutFile<<"\第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1<<" no"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y+1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            else
            {
                cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<" = "<<x/y;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<" yes"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<" = "<<x/y<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t第"<<++Score<<"题:"<<x<<" / "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"选择 2"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                allresult[k] = 3;
                last[k] = x/y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"选择 1"<<endl;
                OutFile_two<<"第"<<Score<<"题:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                allresult[k] = 4;
                last[k] = x/y;
                k++;
            }
        }
    }
}
/**
测试函数
*/
void randtest()
{
    system("cls");
    test rt;
    //输入运算方式
    cout<<"\n\n\t\t1.加法运算"<<endl;
    cout<<"\n\n\t\t2.减法运算"<<endl;
    cout<<"\n\n\t\t3.乘法运算"<<endl;
    cout<<"\n\n\t\t4.除法运算"<<endl;
    cout<<"\n\n\t\t请输入:";
    cin>>choose_one;
    if(choose_one<1||choose_one>4)
    {
        cout<<" \t\t输入有误!"<<endl;
        system("pause");
        return;
    }
    system("cls");
    //多少以内的运算
    cout<<"\n\n\t\t1.10以内的运算"<<endl;
    cout<<"\n\n\t\t2.100以内的运算"<<endl;
    cout<<"\n\n\t\t3.1000以内的运算"<<endl;
    cout<<"\n\n\t\t请输入:";
    cin>>choose_two;
    if(choose_two<1||choose_two>3)
    {
        cout<<" \t\t输入有误!"<<endl;
        system("pause");
        return;
    }
    system("cls");
    //题目类型选择
    cout<<"\n\n\t\t1.填写结果"<<endl;
    cout<<"\n\n\t\t2.对错判断"<<endl;
    cout<<"\n\n\t\t3.选择题"<<endl;
    cout<<"\n\n\t\t请输入:";
    cin>>choose_three;
    if(choose_three<1||choose_three>3)
    {
        cout<<" \t\t输入有误!"<<endl;
        system("pause");
        return;
    }
    system("cls");
    //题目个数选择
    cout<<"\n\n\t\t 题目个数:"<<endl;
    cout<<"\n\n\t\t请输入:";
    cin>>choose_four;
    system("cls");
    //题目打印
    for(int i=0; i<choose_four; i++)
    {
        if(choose_one == 1)
            rt.jiafa();
        else if(choose_one == 2)
            rt.jianfa();
        else if(choose_one == 3)
            rt.chengfa();
        else if(choose_one == 4)
            rt.chufa();
    }
    OutFile<<"------------------------------"<<endl;
    cout<<endl;
    //用户结果输入
    for(int i=0; i<choose_four; i++)
    {
        cout<<"\t\t\t"<<i+1<<":";
        cin>>user_choose[i];
    }
    int win = 0;
    system("cls");
    cout<<"\n";
    //对错的判断
    for(int i=0; i<choose_four; i++)
    {
        if(allresult[i] == user_choose[i])
        {
            win++;
            cout<<"\t第"<<i+1<<"题:正确"<<"  您的结果:"<<user_choose[i]<<" 结果大小:"<<last[i]<<endl;
            OutFile_two<<"第"<<i+1<<"题:正确"<<"  您的结果:"<<user_choose[i]<<" 结果大小:"<<last[i]<<endl;
        }
        else
        {
            cout<<"\t第"<<i+1<<"题:错误"<<"  您的结果:"<<user_choose[i]<<" 正确结果:"<<allresult[i]<<" 结果大小:"<<last[i]<<endl;
            OutFile_two<<"第"<<i+1<<"题:错误"<<"  您的结果:"<<user_choose[i]<<" 正确结果:"<<allresult[i]<<" 结果大小:"<<last[i]<<endl;
        }
    }
    //打印最后的结果
    cout<<"\n\t\t本次测试总分:"<<choose_four<<endl;
    cout<<"\n\t\t您得分:"<<win<<endl;
    if(choose_four*0.8<=win)cout<<"\t\t很不错!继续保持"<<endl;
    else if(choose_four == win) cout<<"\t\t太厉害了!!!!"<<endl;
    else if(choose_four*0.6 <=win)cout<<"\t\t还需要再努努力!"<<endl;
    else if(choose_four*0.3 <=win) cout<<"\t\t这次做的太差了!继续要努力!"<<endl;
    cout<<"\t\t详细题目情况在文件test.txt中保存"<<endl;
    cout<<"\t\t您的做题情况在文件user.txt中保存"<<endl;
    system("pause");
}
/**
进度条
*/
void tools::flash()
{
    system("cls");
    Begintools();
    Sleep(2 * 1000);
    system("cls");
    Begintools();
    cout<<"\t正在加载 ■■ 20%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t正在加载 ■■■■ 40%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t正在加载 ■■■■■■ 60%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t正在加载 ■■■■■■■■ 80%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t正在加载 ■■■■■■■■■■ 100%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t载入界面..";
    Sleep(2 * 1000);
    system("cls");
}
/**
介绍
*/
void introduce()
{
    system("cls");
    cout<<" \t\t___________________"<<endl;
    cout<<" \t\t< You are the best >"<<endl;
    cout<<" \t\t ------------------"<<endl;
    cout<<" \t\t       \   ,__,"<<endl;
    cout<<" \t\t        \  (oo)____"<<endl;
    cout<<" \t\t          (__)    )\ "<<endl;
    cout<<" \t\t             ||--|| *"<<endl;
    cout<<endl;
    cout<<" \t\t使用方法:"<<endl;
    cout<<endl;
    cout<<" \t\t   选择1进入测试,选择不同的测试类型进行测试."<<endl;
    cout<<endl;
    cout<<" \t\t   你测试成绩和对错的题目将会在测试完后就显示出来."<<endl;
    cout<<endl;
    cout<<" \t\t   程序会自动生成test.txt和user.txt,分别用来保存题目和使用者的做题情况"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" \t\t注意事项:"<<endl;
    cout<<endl;
    cout<<" \t\t   部分地方没有进行输入过滤,请不要随便输入字符,按照所给选项输入"<<endl;
    cout<<endl;
    cout<<" \t\t   选择题1为yes/2为no"<<endl;
    cout<<endl;
    cout<<" \t\t   一次性最多做5000题!!!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" \t\t\t      最后感谢您的使用!"<<endl;
    system("pause");
}
void tools::skinSet()
{
    cout<<"\t*\t\t\t\t\t\t\t *\n";
}
void tools::Begintools()
{
    cout<<"\n\t               (0 0)"<<endl;
    cout<<"\n\t   +-----oOO----(_)----------+"<<endl;
    cout<<"\n\t   |                         |"<<endl;
    cout<<"\n\t   |       『欢迎使用QaQ 』      |"<<endl;
    cout<<"\t   |                                    |"<<endl;
    cout<<"\n\t   +------------------oOO----+"<<endl;
    cout<<"\n\t              |__|__|"<<endl;
    cout<<"\n\t               || ||"<<endl;
    cout<<"\n\t              ooO Ooo"<<endl;
}
int main()
{
    system("color f0");
    tools one;
    test t;
    srand(time(0));
    one.flash();
    do
    {
        system("cls");
        cout<<"\n\n\t**********************************************************"<<endl;
        one.skinSet();
        one.skinSet();
        cout<<"\t*\t\t 欢迎使用数学四则运算测试软件\t\t *"<<endl;
        one.skinSet();
        one.skinSet();
        cout<<"\t*\t\t v1.0 \t\t\t\t\t *"<<endl;
        one.skinSet();
        one.skinSet();
        cout<<"\t*\t\t 作者:Rep  \t   \t\t\t *"<<endl;
        one.skinSet();
        one.skinSet();
        cout<<"\t**********************************************************"<<endl;
        cout<<"\n\t1.测试"<<endl;
        cout<<"\n\t2.使用方法详情"<<endl;
        cout<<"\n\t3.退出"<<endl;
        cout<<"\n\thi! please input:";
        cin>>choose;
        switch(choose)
        {
        case 1:
        {
            randtest();
            clear_();
        }
        break;
        case 2:
            introduce();
            break;
        case 3:
            exit(0);
            break;
        default:
            {cout<<"\t\t您的输入有误 请重新输入"<<endl;
             system("pause");
            }
        }
    }
    while(choose!=3);
    OutFile.close();
    OutFile_two.close();
    return 0;
}
