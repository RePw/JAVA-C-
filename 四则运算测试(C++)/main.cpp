#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;
unsigned int choose;    //���˵�ѡ��
unsigned int choose_one;  // �Ӽ��˳�����ѡ��
unsigned int choose_two;   // �������ڵ�����
unsigned int choose_three;  // ��Ŀ������
unsigned int choose_four;   //��Ŀ����
int user_choose[5000];  //���ʹ���ߵĽ��
int allresult[5000];   //��Ÿ���Ĵ�
int yes_or_no[5000];   //��Ÿ����Ƿ���ȷ
int last[5000];       //����������ȷ���
int Score;       //��Ŀ��
ofstream OutFile("test.txt",ios::app);   //��Ŀ�ļ�
ofstream OutFile_two("user.txt",ios::app); //ʹ���ߵĽ���ļ�
int k;  //�����ƶ�
/**
����һ���� ������ѡ����0
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
    void Begintools(); //��ʼ��ͼ��
    void skinSet();   //��ӡ��׼
    void flash();     //����������
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
�ӷ�
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" + "<<y<<endl;
            allresult[k] = x+y;
            last[k] = x+y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<" = "<<x+y;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x+y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" + "<<y<<endl;
            allresult[k] = x+y;
            last[k] = x+y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<" = "<<x+y;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x+y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" + "<<y<<endl;
            allresult[k] = x+y;
            last[k] = x+y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y+1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<" = "<<x+y;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<" = "<<x+y<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" + "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y<<"    "<<"2:"<<x+y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x+y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x+y<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x+y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x+y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" + "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y<<endl;
                allresult[k] = 4;
                last[k] = x+y;
                k++;
            }
        }
    }
}
/**
����
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" - "<<y<<endl;
            allresult[k] = x-y;
            last[k] = x-y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<" = "<<x-y;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x-y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" - "<<y<<endl;
            allresult[k] = x-y;
            last[k] = x-y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<" = "<<x-y;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x-y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x+y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" - "<<y<<endl;
            allresult[k] = x-y;
            last[k] = x-y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y+1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<" = "<<x-y;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<" = "<<x-y<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" - "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x-y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x-y<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x-y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y<<"    "<<"4:"<<x-y-1<<endl;
                allresult[k] = 3;
                last[k] = x-y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" - "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x-y+2<<"    "<<"4:"<<x-y<<endl;
                allresult[k] = 4;
                last[k] = x-y;
                k++;
            }
        }
    }
}
/**
�˷�
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" * "<<y<<endl;
            allresult[k] = x*y;
            last[k] = x*y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<" = "<<x*y;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                allresult[k] = 3;
                last[k] = x*y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" * "<<y<<endl;
            allresult[k] = x*y;
            last[k] = x*y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<" = "<<x*y;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                allresult[k] = 3;
                last[k] = x*y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" * "<<y<<endl;
            allresult[k] = x*y;
            last[k] = x*y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y+1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<" = "<<x*y;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<" = "<<x*y<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" * "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x*y<<"    "<<"2:"<<x*y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x*y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x*y<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x*y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y<<"    "<<"4:"<<x*y-1<<endl;
                allresult[k] = 3;
                last[k] = x*y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" * "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x*y+2<<"    "<<"4:"<<x*y<<endl;
                allresult[k] = 4;
                last[k] = x*y;
                k++;
            }
        }
    }
}
/**
����
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" / "<<y<<endl;
            allresult[k] = x/y;
            last[k] = x/y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<" = "<<x/y;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                allresult[k] = 3;
                last[k] = x/y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" / "<<y<<endl;
            allresult[k] = x/y;
            last[k] = x/y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<" = "<<x/y;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                allresult[k] = 3;
                last[k] = x/y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
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
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<endl;
            OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<endl;
            OutFile_two<<"��"<< Score <<"��:"<<x<<" / "<<y<<endl;
            allresult[k] = x/y;
            last[k] = x/y;
            k++;
        }
        if(choose_three == 2)
        {
            int pq = rand()%2;
            if(pq == 0)
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1;
                OutFile<<"\��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1<<" no"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y+1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            else
            {
                cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<" = "<<x/y;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<" yes"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<" = "<<x/y<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            cout<<"   1.yes/2.no"<<endl;
        }
        if(choose_three == 3)
        {
            int pq = rand()%4;
            cout<<"\t\t\t��"<<++Score<<"��:"<<x<<" / "<<y<<endl;
            if(pq == 0)
            {
                cout<<"\t\t1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x/y<<"    "<<"2:"<<x/y+1<<"    "<<"3:"<<x+y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 1;
                last[k] = x/y;
                k++;
            }
            if(pq == 1)
            {
                cout<<"\t\t1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                OutFile<<"ѡ�� 2"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y+1<<"    "<<"2:"<<x/y<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x+y-1<<endl;
                allresult[k] = 2;
                last[k] = x/y;
                k++;
            }
            if(pq == 2)
            {
                cout<<"\t\t1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x-y+2<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y<<"    "<<"4:"<<x/y-1<<endl;
                allresult[k] = 3;
                last[k] = x/y;
                k++;
            }
            if(pq == 3)
            {
                cout<<"\t\t1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;;
                OutFile<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                OutFile<<"ѡ�� 1"<<endl;
                OutFile_two<<"��"<<Score<<"��:"<<x<<" / "<<y<<endl;
                OutFile_two<<"1:"<<x+y-1<<"    "<<"2:"<<x-y+1<<"    "<<"3:"<<x/y+2<<"    "<<"4:"<<x/y<<endl;
                allresult[k] = 4;
                last[k] = x/y;
                k++;
            }
        }
    }
}
/**
���Ժ���
*/
void randtest()
{
    system("cls");
    test rt;
    //�������㷽ʽ
    cout<<"\n\n\t\t1.�ӷ�����"<<endl;
    cout<<"\n\n\t\t2.��������"<<endl;
    cout<<"\n\n\t\t3.�˷�����"<<endl;
    cout<<"\n\n\t\t4.��������"<<endl;
    cout<<"\n\n\t\t������:";
    cin>>choose_one;
    if(choose_one<1||choose_one>4)
    {
        cout<<" \t\t��������!"<<endl;
        system("pause");
        return;
    }
    system("cls");
    //�������ڵ�����
    cout<<"\n\n\t\t1.10���ڵ�����"<<endl;
    cout<<"\n\n\t\t2.100���ڵ�����"<<endl;
    cout<<"\n\n\t\t3.1000���ڵ�����"<<endl;
    cout<<"\n\n\t\t������:";
    cin>>choose_two;
    if(choose_two<1||choose_two>3)
    {
        cout<<" \t\t��������!"<<endl;
        system("pause");
        return;
    }
    system("cls");
    //��Ŀ����ѡ��
    cout<<"\n\n\t\t1.��д���"<<endl;
    cout<<"\n\n\t\t2.�Դ��ж�"<<endl;
    cout<<"\n\n\t\t3.ѡ����"<<endl;
    cout<<"\n\n\t\t������:";
    cin>>choose_three;
    if(choose_three<1||choose_three>3)
    {
        cout<<" \t\t��������!"<<endl;
        system("pause");
        return;
    }
    system("cls");
    //��Ŀ����ѡ��
    cout<<"\n\n\t\t ��Ŀ����:"<<endl;
    cout<<"\n\n\t\t������:";
    cin>>choose_four;
    system("cls");
    //��Ŀ��ӡ
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
    //�û��������
    for(int i=0; i<choose_four; i++)
    {
        cout<<"\t\t\t"<<i+1<<":";
        cin>>user_choose[i];
    }
    int win = 0;
    system("cls");
    cout<<"\n";
    //�Դ���ж�
    for(int i=0; i<choose_four; i++)
    {
        if(allresult[i] == user_choose[i])
        {
            win++;
            cout<<"\t��"<<i+1<<"��:��ȷ"<<"  ���Ľ��:"<<user_choose[i]<<" �����С:"<<last[i]<<endl;
            OutFile_two<<"��"<<i+1<<"��:��ȷ"<<"  ���Ľ��:"<<user_choose[i]<<" �����С:"<<last[i]<<endl;
        }
        else
        {
            cout<<"\t��"<<i+1<<"��:����"<<"  ���Ľ��:"<<user_choose[i]<<" ��ȷ���:"<<allresult[i]<<" �����С:"<<last[i]<<endl;
            OutFile_two<<"��"<<i+1<<"��:����"<<"  ���Ľ��:"<<user_choose[i]<<" ��ȷ���:"<<allresult[i]<<" �����С:"<<last[i]<<endl;
        }
    }
    //��ӡ���Ľ��
    cout<<"\n\t\t���β����ܷ�:"<<choose_four<<endl;
    cout<<"\n\t\t���÷�:"<<win<<endl;
    if(choose_four*0.8<=win)cout<<"\t\t�ܲ���!��������"<<endl;
    else if(choose_four == win) cout<<"\t\t̫������!!!!"<<endl;
    else if(choose_four*0.6 <=win)cout<<"\t\t����Ҫ��ŬŬ��!"<<endl;
    else if(choose_four*0.3 <=win) cout<<"\t\t�������̫����!����ҪŬ��!"<<endl;
    cout<<"\t\t��ϸ��Ŀ������ļ�test.txt�б���"<<endl;
    cout<<"\t\t��������������ļ�user.txt�б���"<<endl;
    system("pause");
}
/**
������
*/
void tools::flash()
{
    system("cls");
    Begintools();
    Sleep(2 * 1000);
    system("cls");
    Begintools();
    cout<<"\t���ڼ��� ���� 20%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t���ڼ��� �������� 40%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t���ڼ��� ������������ 60%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t���ڼ��� ���������������� 80%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t���ڼ��� �������������������� 100%";
    Sleep(2 * 500);
    system("cls");
    Begintools();
    cout<<"\t�������..";
    Sleep(2 * 1000);
    system("cls");
}
/**
����
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
    cout<<" \t\tʹ�÷���:"<<endl;
    cout<<endl;
    cout<<" \t\t   ѡ��1�������,ѡ��ͬ�Ĳ������ͽ��в���."<<endl;
    cout<<endl;
    cout<<" \t\t   ����Գɼ��ͶԴ����Ŀ�����ڲ���������ʾ����."<<endl;
    cout<<endl;
    cout<<" \t\t   ������Զ�����test.txt��user.txt,�ֱ�����������Ŀ��ʹ���ߵ��������"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" \t\tע������:"<<endl;
    cout<<endl;
    cout<<" \t\t   ���ֵط�û�н����������,�벻Ҫ��������ַ�,��������ѡ������"<<endl;
    cout<<endl;
    cout<<" \t\t   ѡ����1Ϊyes/2Ϊno"<<endl;
    cout<<endl;
    cout<<" \t\t   һ���������5000��!!!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" \t\t\t      ����л����ʹ��!"<<endl;
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
    cout<<"\n\t   |       ����ӭʹ��QaQ ��      |"<<endl;
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
        cout<<"\t*\t\t ��ӭʹ����ѧ��������������\t\t *"<<endl;
        one.skinSet();
        one.skinSet();
        cout<<"\t*\t\t v1.0 \t\t\t\t\t *"<<endl;
        one.skinSet();
        one.skinSet();
        cout<<"\t*\t\t ����:Rep  \t   \t\t\t *"<<endl;
        one.skinSet();
        one.skinSet();
        cout<<"\t**********************************************************"<<endl;
        cout<<"\n\t1.����"<<endl;
        cout<<"\n\t2.ʹ�÷�������"<<endl;
        cout<<"\n\t3.�˳�"<<endl;
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
            {cout<<"\t\t������������ ����������"<<endl;
             system("pause");
            }
        }
    }
    while(choose!=3);
    OutFile.close();
    OutFile_two.close();
    return 0;
}
