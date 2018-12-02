#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "mmsystem.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <conio.h>
#include "mysql_api.h"
#include <regex>
#include <sstream>
#include <time.h>
#include <fstream>
#include <map>
//#include <system.h>
using namespace std;
int a;
string mysql_user;
int act_goods[10];
map<string, string> act_file;
void map_robot()
{
    cout<<"\n\t               (0 0)"<<endl;
    cout<<"\n\t   +-----oOO----(_)----------+"<<endl;
    cout<<"\n\t   |                         |"<<endl;
    cout<<"\n\t   |       �����㷭���Ŷ� ��      |"<<endl;
    cout<<"\t   |                                    |"<<endl;
    cout<<"\n\t   +------------------oOO----+"<<endl;
    cout<<"\n\t              |__|__|"<<endl;
    cout<<"\n\t               || ||"<<endl;
    cout<<"\n\t              ooO Ooo"<<endl;
    //Sleep(4 * 1000);
}
void map_heart()
{
    system("cls");
    for (float y=1.5f; y>-1.5f; y-=0.13f)
    {
        for(float x=-1.5f; x<1.5f; x+=0.05f)
        {
            float a=x*x+y*y-1;
            float f= a*a*a-x*x*y*y*y;
            putchar(f<=0.0?".:-=+*#%@"[(int)(f*-8)]:' ');
        }
        putchar('\n');
    }
    //gotoxy(1,2);
    //Sleep(4 * 1000);
}
unsigned int login_flag = 0;

void Heapify(int *,int,int);
void HeapSort(int arr[],int len)
{
    int i;
    //��ʼ���ѣ������һ�����ڵ㿪ʼ
    for(i = len/2 - 1; i >= 0; --i)
    {
        Heapify(arr,i,len);
    }
    //�Ӷ��е�ȡ������Ԫ���ٵ�����
    for(i = len - 1; i > 0; --i)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        //�����ɶ�
        Heapify(arr,0,i);
    }
}
void Heapify(int arr[], int first, int end)
{
    int father = first;
    int son = father * 2 + 1;
    while(son < end)
    {
        if(son + 1 < end && arr[son] < arr[son+1])
            ++son;
        //������ڵ�����ӽڵ����ʾ�������
        if(arr[father] > arr[son])
            break;
        else
        {
            //��Ȼ�ͽ������ڵ���ӽڵ��Ԫ��
            int temp = arr[father];
            arr[father] = arr[son];
            arr[son] = temp;
            //�����ӽڵ�����һ��Ҫ�Ƚϵ�λ��
            father = son;
            son = 2 * father + 1;
        }
    }
}
/*void quickSort(int* A,int first,int last)         //����A,first�ǵ�һ��Ԫ���±꣬last�����һ��Ԫ���±�
{
    if(last<=first)                           //���˳���С��1��������Ѿ�����������
        return;

    int pivot=A[first];
    int left=first+1;                         //left���ڵڶ���Ԫ��
    int right=last;
    int temp;
    while(left<=right)
    {
        while(A[right]>pivot&&right>=left)//�ҵ�һ����firstС��,�����뱣֤leftֵС�ڵ���rightֵ
            right--;

        while(A[left]<pivot&&left<=right) //�ҵ�һ����first���,���ñ�֤leftֵС�ڵ���rightֵ
            left++;

        if(left>=right)                   //˵���Ѿ�������������У����轻��
            break;

        temp=A[left];                     //����λ��
        A[left]=A[right];
        A[right]=temp;
        left++,right--;                   //��Ӧ�Ľ�һλ
    }
    A[first]=A[right];                        //��Ϊrightһ����ͣ�ڴ��ҵ����һ��С��first�����ϣ�����֮��
    //��Ȼ�ܱ�֤firstֵ��ߵı�firstС���ұߵı�first��
    A[right]=pivot;

    quickSort(A,first,right-1);               //��벿��
    quickSort(A,left,last);                   //�Ұ벿��
}*/

void skinSet()
{
    cout<<"\t*\t\t\t\t\t\t\t *\n";
}//���Ƹ�ʽ
class mysql_do
{
public:
    /*
      �û�����
      */
    bool login_mysql_user(string name_);//��ѯ�Ƿ�����˺�
    bool login_mysql_pwd(string name_,string name_pwd);//��ѯ�����Ƿ���ȷ
    void look_mysql_user();//������Ϣ
    void mysql_user_buy();//��������¼
    void mysql_user_own();//����Լ����ϼ���Ʒ
    void mysql_up();//�ϼ���Ʒ
    void mysql_down();//�¼���Ʒ
    void mysql_goods_all();//���������Ʒ
    void mysql_goods_lookfor();//�Ѳ���Ʒ
    void mysql_goods_buy();//������Ʒ
    bool Format_Matching (string, const char *);//����ƥ��
    void user_vip(string m);
    void user_activity();//�û�����
    /*
      ����Ա����
      */
    void admin_look_buy();//������й����¼
    void admin_look_user();//��������û�
    void admin_look_del();//ɾ���û�
    void admin_activity();//�����
    void admin_act_add();//���Ʒ���
    void admin_act_del();//���Ʒɾ��
    void admin_act_begin();//���ʼ
    void admin_act_end();//��ر�
    void admin_file_read();//�ļ���ȡ
};
void mysql_do::admin_file_read()
{
    system("cls");
    string t_;
    stringstream ss;
    string a = "\"";
    cout<<"\n\n\t\t\t������Ҫ������ļ�:";
    cin>>t_;
    fstream out(t_,ios::in);
    string s,m;
    if(!out.is_open())
    {
        MessageBox(NULL,TEXT("�ļ������ڻ��ȡ����"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    while(true)
    {
        if(!out)
            break;
        out>>s>>m;
        act_file.insert(map<string, string>::value_type(s,m));
        cout<<"\t�ļ���ȡ��..."<<endl;
    }
    cout<<"\t�ļ���ȡ���!"<<endl;
    out.close();
    for(map<string,string>::iterator iter = act_file.begin(); iter != act_file.end(); iter++)
    {
        ss<<"insert into act values("<<a<<iter->first<<a<<","<<a<<iter->second<<a<<");";
        mysql_query(&mysql,ss.str().c_str());
        //cout<<ss.str()<<endl;
        ss.str("");
    }
    system("pause");
}
void mysql_do::user_activity()
{
    system("cls");
    stringstream ss,ss_mysql_wh,ss_mysql_de,ss_mysql,ss_mysql_d,ss_mysql_t,t,ss_b;
    string a = "\"";
    int gift = 0;
    ss<<"select * from admin_;";
    mysql_query(&mysql, ss.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    cout<<row[0]<<endl;
    if(atoi(row[0])==0)
    {
        MessageBox(NULL, TEXT("��ʱû�л"),TEXT("������Ʒ����"), MB_OK);
        return;
    }
    ss_mysql_wh<<"select * from users where user = "<<a<<mysql_user<<a<<";";
    mysql_query(&mysql, ss_mysql_wh.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(atoi(row[7])==0)
    {
        MessageBox(NULL, TEXT("��û�г齱����"),TEXT("������Ʒ����"), MB_OK);
        return;
    }
    int index = 0;
    memset(act_goods,0,sizeof(int));
    ss_mysql<<"select * from act;";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    cout<<"\n\t\t\t\t��Ʒ����"<<endl;
    while((row = mysql_fetch_row(result)) != NULL)
    {
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t\t\t\t��Ʒ:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�۸�:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
        act_goods[index++] = atoi(row[1]);
//        cout<<act_goods[index-1]<<endl;
        //cout<<act_goods[index-1]<<endl;
    }
    int res = MessageBox(NULL, TEXT("��ȷ����ʼ���?"),TEXT("������Ʒ����"), MB_YESNO|MB_ICONWARNING);
    if(res == 6)
    {
        //quickSort(act_goods,0,index-1);
        HeapSort(act_goods,index);
        //cout<<index<<endl;
        //for(int i =0; i<=5; i++)
       //     cout<<act_goods[i]<<endl;
        //system("pause");
        srand(time(0));
        int rd = rand()%20;
        //cout<<"rd:"<<rd<<endl;
        if(rd>5&&rd<16)
        {
            int rp = rand()%index;
            gift = act_goods[index];
            //cout<<1111111<<endl;
        }
        else if(rd>=16&&rd<+19)
            gift = act_goods[0];
        //cout<<gift<<endl;
        //system("pause");
        //cout<<rd<<endl;
        if(gift != 0)
        {
            system("cls");
            ss_mysql_t<<"select * from act where money ="<<a<<gift<<a<<";";
            mysql_query(&mysql, ss_mysql_t.str().c_str());
            result = mysql_store_result(&mysql);
            row = mysql_fetch_row(result);
            //cout<<ss_mysql_t.str()<<endl;
            MessageBox(NULL, TEXT("��ϲ�����!"),TEXT("������Ʒ����"), MB_OK);
            cout<<"\n\n\t**********************************************************"<<endl;
            skinSet();
            cout<<"\t\t\t\t��Ʒ:"<<row[0]<<"\t\t\t "<<endl;
            skinSet();
            cout<<"\t\t\t\t�۸�:"<<row[1]<<"\t\t\t\t "<<endl;
            skinSet();
            cout<<"\t**********************************************************"<<endl;
            ss_mysql_d<<"insert into buy values("<<a<<row[0]<<"[����]"<<a<<","<<a<<gift<<a<<","<<a<<mysql_user<<a<<");";
            mysql_query(&mysql, ss_mysql_d.str().c_str());
            ss_b<<"delete from act where name ="<<a<<row[0]<<a<<";";
            //cout<<ss_b.str()<<endl;
            mysql_query(&mysql, ss_b.str().c_str());
            system("pause");
            return;
        }
        MessageBox(NULL, TEXT("���ź�û�ý�"),TEXT("������Ʒ����"), MB_OK);
    }
    ss_mysql_de<<"update users set times = times-1 where user ="<<a<<mysql_user<<a<<";";
    mysql_query(&mysql, ss_mysql_de.str().c_str());
    system("pause");
}
void mysql_do::admin_act_begin()
{
    stringstream ss_mysql,ss_mysql_d,ss_mysql_t,ss;
    string a = "\"";
    ss_mysql_d<<"select * from admin_;";
    mysql_query(&mysql, ss_mysql_d.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(atoi(row[0])==1)
    {
        MessageBox(NULL, TEXT("��Ѿ�����!"),TEXT("������Ʒ����"), MB_OK);
        return;
    }
    int rest = MessageBox(NULL, TEXT("��ȷ����ʼ���?"),TEXT("������Ʒ����"), MB_YESNO|MB_ICONWARNING);
    if(rest == 6)
    {
        ss_mysql<<"update admin_ set doit ='1' where doit = '0';";
        mysql_query(&mysql, ss_mysql.str().c_str());
        ss_mysql_t<<"select * from users;";
        mysql_query(&mysql, ss_mysql_t.str().c_str());
        result = mysql_store_result(&mysql);
        while((row = mysql_fetch_row(result))!=NULL)
        {

            ss<<"update users set times = 1+"<<row[6]<<" "<<"where user ="<<a<<row[4]<<a<<";";
            //cout<<ss.str()<<endl;
            mysql_query(&mysql, ss.str().c_str());
            ss.str("");
        }
        //mysql_query(&mysql, ss.str().c_str());
        MessageBox(NULL, TEXT("�����!"),TEXT("������Ʒ����"), MB_OK);
    }
    //system("pause");
}
void mysql_do::admin_act_end()
{
    stringstream ss_mysql,ss_mysql_d;
    string a = "\"";
    ss_mysql_d<<"select * from admin_;";
    mysql_query(&mysql, ss_mysql_d.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(atoi(row[0])==0)
    {
        MessageBox(NULL, TEXT("��Ѿ��ر�!"),TEXT("������Ʒ����"), MB_OK);
        return;
    }
    int rest = MessageBox(NULL, TEXT("��ȷ���رջ��?"),TEXT("������Ʒ����"), MB_YESNO|MB_ICONWARNING);
    if(rest == 6)
    {
        ss_mysql<<"update admin_ set doit ='0' where doit = '1';";
        mysql_query(&mysql, ss_mysql.str().c_str());
        MessageBox(NULL, TEXT("��ر�!"),TEXT("������Ʒ����"), MB_OK);
    }
}
void mysql_do::admin_act_del()
{
    stringstream ss_mysql,ss_mysql_;
    string a = "\"";
    string name_;
    cout<<"\n\n\t\t��������Ʒ����:";
    cin>>name_;
    ss_mysql_<<"select count(*) from act where name ="<<a<<name_<<a<<";";
    //cout<<ss_mysql.str()<<endl;
    mysql_query(&mysql, ss_mysql_.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(!strcmp(row[0],"0"))
    {
        MessageBox(NULL, TEXT("�����ڸ���Ʒ"), TEXT("������Ʒ����"), MB_OK);
    }
    else
    {
        ss_mysql<<"delete from act where name ="<<a<<name_<<a<<";";
        mysql_query(&mysql, ss_mysql.str().c_str());
        MessageBox(NULL, TEXT("ɾ���ɹ�"), TEXT("������Ʒ����"), MB_OK);
    }
}
void mysql_do::admin_act_add()
{
    system("cls");
    stringstream ss_mysql;
    string a = "\"";
    string name,money;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    cout<<"\n\n\t+            ��Ʒ����:";
    cin>>name;
    cout<<endl;
    cout<<"\n\n\t+            ��Ʒ�۸�:";
    cin>>money;
    cout<<endl;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    ss_mysql<<"insert into act values("<<a<<name<<a<<","<<a<<money<<a<<");";
    mysql_query(&mysql, ss_mysql.str().c_str());
    MessageBox(NULL, TEXT("��ӳɹ�"), TEXT("������Ʒ����"), MB_OK);
}
void mysql_do::admin_activity()
{
    system("cls");
    mysql_do t;
    int cho;
    do
    {
        system("cls");
        stringstream ss_mysql,ss_mysql_admin;
        string a = "\"";
        ss_mysql_admin<<"select count(*) from act;";
        mysql_query(&mysql, ss_mysql_admin.str().c_str());
        result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        if(!strcmp(row[0],"0"))
        {
            MessageBox(NULL, TEXT("������Ʒ"), TEXT("������Ʒ����"),MB_OK);
        }
        ss_mysql<<"select * from act;";
        mysql_query(&mysql, ss_mysql.str().c_str());
        result = mysql_store_result(&mysql);
        while((row = mysql_fetch_row(result)) != NULL)
        {
            cout<<"\n\n\t**********************************************************"<<endl;
            skinSet();
            cout<<"\t\t\t\t��Ʒ:"<<row[0]<<"\t\t\t "<<endl;
            skinSet();
            cout<<"\t\t\t\t�۸�:"<<row[1]<<"\t\t\t\t "<<endl;
            skinSet();
            cout<<"\t**********************************************************"<<endl;
        }
        cout<<"\t\t\t1.���뽱Ʒ"<<endl;
        cout<<"\t\t\t2.ɾ����Ʒ"<<endl;
        cout<<"\t\t\t3.��ʼ�"<<endl;
        cout<<"\t\t\t4.�رջ"<<endl;
        cout<<"\t\t\t5.�˳�"<<endl;
        cout<<"\t\t\tplease input:";
        cin>>cho;
        switch(cho)
        {
        case 1:
            t.admin_act_add();
            break;
        case 2:
            t.admin_act_del();
            break;
        case 3:
            t.admin_act_begin();
            break;
        case 4:
            t.admin_act_end();
            break;
        case 5:
            break;
        default:
            MessageBox(NULL, TEXT("�������"), TEXT("������Ʒ����"),MB_OK);
        }
    }
    while(cho!=5);
}
void mysql_do::admin_look_del()
{
    stringstream ss_mysql,ss_mysql_admin;
    string a = "\"";
    string user_user;
    cout<<"\n\t\t\t������ע���û����˺�:";
    cin>>user_user;
    ss_mysql_admin<<"select count(*) from users where user ="<<a<<user_user<<a<<";";
    mysql_query(&mysql, ss_mysql_admin.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(!strcmp(row[0],"0"))
    {
        MessageBox(NULL, TEXT("û�и��˻�"), TEXT("������Ʒ����"),MB_OK);
        return;
    }
    int result_ = MessageBox(NULL, TEXT("��ȷ��ע�����û���?"), TEXT("������Ʒ����"), MB_YESNO|MB_ICONWARNING);
    if(result_ == 6)
    {
        ss_mysql<<"delete from users where user ="<<a<<user_user<<a<<";";
        mysql_query(&mysql, ss_mysql.str().c_str());
        MessageBox(NULL,TEXT("ע�����û��ɹ�"), TEXT("������Ʒ����"),MB_OK);
    }
}
void mysql_do::admin_look_buy()
{
    system("cls");
    stringstream ss_mysql;
    string a = "\"";
    int admin_flag = 0;
    ss_mysql<<"select * from buy;";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    while((row = mysql_fetch_row(result)) != NULL)
    {
        admin_flag = 1;
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t\t\t\t��Ʒ:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�۸�:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�û�:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!admin_flag)
        MessageBox(NULL, TEXT("�����û������¼"), TEXT("������Ʒ����"), MB_OK);
    system("pause");
}
void mysql_do::admin_look_user()
{
    //system("cls");
    stringstream ss_mysql;
    string a = "\"";
    int admin_flag = 0;
    ss_mysql<<"select * from users;";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    while((row = mysql_fetch_row(result)) != NULL)
    {
        admin_flag = 1;
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t\t\t\t����:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�绰:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�Ա�:"<<row[2]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t���:"<<row[3]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�˺�:"<<row[4]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t����:"<<row[5]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\tVIP:"<<row[6]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!admin_flag)
        MessageBox(NULL, TEXT("�����û���¼"), TEXT("������Ʒ����"), MB_OK);
}
void mysql_do::user_vip(string m)
{
    stringstream ss_mysql,ss_mysql_vip;
    string a = "\"";
    ss_mysql<<"select * from users where user ="<<a<<mysql_user<<a<<";";
    //cout<<ss_mysql.str()<<endl;
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(atoi(row[3])>=200000&&(atoi(row[3])-atoi(m.c_str()))<200000)
    {
        //cout<<row[3]<<endl;
        //cout<<atoi(row[3])-atoi(m.c_str())<<endl;
        ss_mysql_vip<<"update users set vip ='10' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP10"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=100000&&(atoi(row[3])-atoi(m.c_str()))<100000)
    {
        ss_mysql_vip<<"update users set vip ='9' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP9"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=50000&&(atoi(row[3])-atoi(m.c_str()))<50000)
    {
        ss_mysql_vip<<"update users set vip ='8' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP8"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=20000&&(atoi(row[3])-atoi(m.c_str()))<20000)
    {
        ss_mysql_vip<<"update users set vip ='7' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP7"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=10000&&(atoi(row[3])-atoi(m.c_str()))<10000)
    {
        ss_mysql_vip<<"update users set vip ='6' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP6"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=5000&&(atoi(row[3])-atoi(m.c_str()))<5000)
    {
        ss_mysql_vip<<"update users set vip ='5' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP5"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=2000&&(atoi(row[3])-atoi(m.c_str()))<2000)
    {
        ss_mysql_vip<<"update users set vip ='4' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP4"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=1000&&(atoi(row[3])-atoi(m.c_str()))<1000)
    {
        ss_mysql_vip<<"update users set vip ='3' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP3"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=500&&(atoi(row[3])-atoi(m.c_str()))<500)
    {
        ss_mysql_vip<<"update users set vip ='2' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP2"),TEXT("������Ʒ����"),MB_OK);
        return;
    }
    if(atoi(row[3])>=300&&(atoi(row[3])-atoi(m.c_str()))<300)
    {
        ss_mysql_vip<<"update users set vip ='1' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("��ϲ���ΪVIP1"),TEXT("������Ʒ����"),MB_OK);
        return;
    }

}
bool mysql_do::Format_Matching(string Matched_Str, const char *Format_Str)
{
    regex repPattern(Format_Str,regex_constants::extended);
    match_results<string::const_iterator> rerResult;
    bool bValid = regex_match(Matched_Str, rerResult, repPattern);
    if (!bValid)
    {

        return false;
    }
    return true;
}
void mysql_do::mysql_goods_lookfor()
{
    system("cls");
    int flag_buy = 0;
    stringstream ss_mysql;
    string a = "\"";
    string name;
    cout<<"\n\t\t�������Ѳ�����:";
    cin>>name;
    ss_mysql<<"select * from Goods where name ="<<a<<name<<a<<";";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    while((row = mysql_fetch_row(result)) != NULL)
    {
        flag_buy = 1;
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t\t\t\t��Ʒ:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�۸�:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t��ע��Ϣ:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�û�:"<<row[3]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\tID:"<<row[4]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!flag_buy)
        MessageBox(NULL, TEXT("������Ʒ"), TEXT("������Ʒ����"), MB_OK);
}
void mysql_do::mysql_goods_buy()
{
    //system("cls");
    //int flag_buy = 0;
    stringstream ss_mysql,ss_mysql_d,ss_mysql_i,ss_mysql_us,ss_mysql_do,ss_mysql_p,ss;
    string a = "\"";
    string id;
    cout<<"\n\t\t��������Ʒ��id:";
    cin>>id;
    ss_mysql_p<<"select count(*) from Goods where id="<<a<<id<<a<<";";
    mysql_query(&mysql, ss_mysql_p.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    mysql_free_result(result);
    //cout<<1<<endl;
    if(!strcmp(row[0],"0"))
    {
        MessageBox(NULL, TEXT("����Ʒ������"), TEXT("������Ʒ����"), MB_OK);
    }
    else
    {
        ss_mysql_us<<"select * from users where user ="<<a<<mysql_user<<a<<";";
        //cout<<ss_mysql_us.str()<<endl;
        mysql_query(&mysql, ss_mysql_us.str().c_str());
        result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        string money_one = row[3];
        //cout<<money_one<<endl;
        ss_mysql<<"select * from Goods where id ="<<a<<id<<a<<";";
        //cout<<ss_mysql.str()<<endl;
        mysql_query(&mysql, ss_mysql.str().c_str());
        result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        string money_two = row[1];
        //cout<<money_one<<" "<<money_two<<endl;
        int t_one = stoi(money_one);
        int t_two = stoi(money_two);
        //cout<<t_one<<endl;
        bool pt = (t_one<t_two);
        if(!pt)
        {
            ss<<"update users set money = money + "<<money_two<<" "<<"where user ="<<a<<row[3]<<a<<";";
            mysql_query(&mysql,ss.str().c_str());
            ss_mysql_do<<"update users set money = money-"<<money_two<<" where user ="<<a<<mysql_user<<a<<";";
            mysql_query(&mysql,ss_mysql_do.str().c_str());
            ss_mysql_d<<"delete from Goods where id ="<<a<<id<<a<<";";
            mysql_query(&mysql, ss_mysql_d.str().c_str());
            ss_mysql_i<<"insert into buy values ("<<a<<row[0]<<a<<","<<a<<row[1]<<a<<","<<a<<mysql_user<<a<<");";
            //cout<<ss_mysql_i.str()<<endl;
            mysql_query(&mysql, ss_mysql_i.str().c_str());
            MessageBox(NULL, TEXT("����ɹ�!"), TEXT("������Ʒ����"), MB_OK);
        }
        else
        {
            cout<<"\n\t\t��������!!"<<endl;
            cout<<"\t\t�����Ϊ:"<<money_one<<endl;
            system("pause");
        }
    }
}
void mysql_do::mysql_goods_all()
{
    system("cls");
    int flag_buy = 0;
    stringstream ss_mysql;
    string a = "\"";
    ss_mysql<<"select * from Goods;";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    while((row = mysql_fetch_row(result)) != NULL)
    {
        flag_buy = 1;
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t\t\t\t��Ʒ:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�۸�:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t��ע��Ϣ:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�û�:"<<row[3]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\tid:"<<row[4]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!flag_buy)
        MessageBox(NULL, TEXT("������Ʒ"), TEXT("������Ʒ����"), MB_OK);
}
void mysql_do::mysql_up()
{
    system("cls");
    //int flag_buy = 0;
    stringstream ss_mysql;
    string a = "\"";
    string name,money,note;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    cout<<"\n\n\t+            ��Ʒ����:";
    cin>>name;
    cout<<endl;
    cout<<"\n\n\t+            ��Ʒ�۸�:";
    cin>>money;
    cout<<endl;
    cout<<"\n\n\t+            ��ע:";
    cin>>note;
    cout<<endl;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    ss_mysql<<"insert into Goods values("<<a<<name<<a<<","<<a<<money<<a<<","<<a<<note<<a<<","<<a<<mysql_user<<a<<","<<a<<a<<");";
    //cout<<ss_mysql.str()<<endl;
    mysql_query(&mysql, ss_mysql.str().c_str());
    MessageBox(NULL, TEXT("�ϼܳɹ�"), TEXT("������Ʒ����"), MB_OK);
    //system("pause");
}
void mysql_do::mysql_down()
{
    stringstream ss_mysql,ss_mysql_;
    string a = "\"";
    string id;
    cout<<"\n\n\t\t��������Ʒid:";
    cin>>id;
    ss_mysql_<<"select count(*) from Goods where id ="<<a<<id <<a<<"&& user ="<<a<<mysql_user<<a<<";";
    //cout<<ss_mysql.str()<<endl;
    mysql_query(&mysql, ss_mysql_.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(!strcmp(row[0],"0"))
    {
        MessageBox(NULL, TEXT("�����ڸ�id���id�������Ʒ"), TEXT("������Ʒ����"), MB_OK);
    }
    else
    {
        ss_mysql<<"delete from Goods where id ="<<a<<id<<a<<";";
        mysql_query(&mysql, ss_mysql.str().c_str());
        MessageBox(NULL, TEXT("�¼ܳɹ�"), TEXT("������Ʒ����"), MB_OK);
    }
    //system("pause");
}
void mysql_do::mysql_user_own()
{
    system("cls");
    int flag_buy = 0;
    stringstream ss_mysql;
    string a = "\"";
    ss_mysql<<"select * from Goods where user ="<<a<<mysql_user<<a<<";";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    while((row = mysql_fetch_row(result)) != NULL)
    {
        flag_buy = 1;
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t\t\t\t��Ʒ:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�۸�:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t��ע��Ϣ:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\tid:"<<row[4]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!flag_buy)
        MessageBox(NULL, TEXT("�������ϼܼ�¼"), TEXT("������Ʒ����"), MB_OK);
}
void mysql_do::look_mysql_user()
{
    system("cls");
    stringstream ss_mysql;
    string a = "\"";
    ss_mysql<<"select * from users where user ="<<a<<mysql_user<<a<<";";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    //mysql_free_result(result);
    cout<<"\n\n\t**********************************************************"<<endl;
    skinSet();
    cout<<"\t\t\t\t����:"<<row[0]<<"\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t�Ա�:"<<row[2]<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t�绰:"<<row[1]<<"\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t���:"<<row[3]<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\tVIP:"<<row[6]<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t**********************************************************"<<endl;
}
bool mysql_do::login_mysql_user(string name_)
{
    stringstream ss_mysql;
    string a = "\"";
    ss_mysql<<"select count(*) from users where user ="<<a<<name_<<a<<";";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    mysql_free_result(result);
    if(!strcmp(row[0],"0"))
        return false;
    else
        return true;
}
bool mysql_do::login_mysql_pwd(string name_,string name_pwd)
{
    stringstream ss_mysql;
    string a = "\"";
    ss_mysql<<"select * from users where user ="<<a<<name_<<a<<";";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    string key = row[5];
    if(key != name_pwd)
        return false;
    else
        return true;
}
void mysql_do::mysql_user_buy()
{
    int flag_buy = 0;
    system("cls");
    stringstream ss_mysql;
    string a = "\"";
    ss_mysql<<"select * from buy where user ="<<a<<mysql_user<<a<<";";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    while((row = mysql_fetch_row(result)) != NULL)
    {
        flag_buy = 1;
        cout<<"\n\n\t**********************************************************"<<endl;
//        skinSet();
//        cout<<"\t\t\t\t����ʱ��:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t��Ʒ:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t�۸�:"<<row[1]<<"\t\t\t\t "<<endl;
//        skinSet();
//        cout<<"\t\t\t\t����ʱ��:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t************************************************************"<<endl;
    }
    if(!flag_buy)
        MessageBox(NULL, TEXT("�����޹����¼"), TEXT("������Ʒ����"), MB_OK);
}
class tools
{
public:
    void pause_clear();//�����ͻ���
    void Voicep();//���ƽ�������
    void showcopy();//��������
    void pressany();//��½֮�����
    void admin_pressany();
};
void tools::admin_pressany()
{
    int choose_;
    mysql_do t;
    do
    {
        system("cls");
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t*\t\t\t1.������й����¼\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t2.�����û�\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t3.�����\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t4.���Ʒ�ϴ�\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t5.�˳�\t\t\t\t *"<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
        cout<<"\t please input:";
        cin>>choose_;
        switch(choose_)
        {
        case 1:
            t.admin_look_buy();
            break;
        case 2:
        {

            int admin_choose;
            do
            {
                system("cls");
                t.admin_look_user();
                cout<<"\n\n\t**********************************************************"<<endl;
                skinSet();
                cout<<"\t*\t\t\t1.ע���û�\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t2.�˳�\t\t\t\t *"<<endl;
                skinSet();
                cout<<"\t**********************************************************"<<endl;
                cout<<"\n\t\t\t\tplease input:";
                cin>>admin_choose;
                switch(admin_choose)
                {
                case 1:
                    t.admin_look_del();
                    break;
                case 2:
                    //�˳�
                    break;
                default:
                    MessageBox(NULL, TEXT("������������"), TEXT("������Ʒ����"),MB_OK);
                }
            }
            while(admin_choose!=2);
        }
        break;
        case 3:
            t.admin_activity();
            break;
        case 4:
            t.admin_file_read();
            break;
        case 5://
            break;
        default:
            MessageBox(NULL, TEXT("������������"), TEXT("������Ʒ����"),MB_OK);
        }
    }
    while(choose_!=5);
}
void tools::pause_clear()
{
    system("pause");
    system("cls");
}
void tools::Voicep()
{
    Beep(523,500);
    Beep(587,500);
    Beep(659,500);
    Beep(698,500);
}
void tools::showcopy()
{
    system("cls");
    map_robot();
    system("pause");
}
void tools::pressany()
{
    int choose_;
    mysql_do t;
    do
    {
        system("cls");
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t*\t\t\t1.���������Ʒ\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t2.�ҵ��ϼ���Ʒ\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t3.�ҹ������Ʒ\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t4.������Ϣ\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t5.�\t\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t6.�˳�\t\t\t\t *"<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
        cout<<"\t please input:";
        cin>>choose_;
        switch(choose_)
        {
        case 1:
        {
            int find_;
            do
            {
                t.mysql_goods_all();
                cout<<"\n\n\t\t1.�Ѳ���Ʒ"<<endl;
                cout<<"\t\t2.������Ʒ"<<endl;
                cout<<"\t\t3.������һ��"<<endl;
                cout<<"\t\tplease input:";
                cin>>find_;
                switch(find_)
                {
                case 1:
                {
                    t.mysql_goods_lookfor();
                    system("pause");
                }
                break;
                case 2:
                {
                    t.mysql_goods_buy();
                    //system("pause");
                }
                break;
                case 3:
                    break;
                default:
                    MessageBox(NULL, TEXT("��������"), TEXT("������Ʒ����"),MB_OK);
                }

            }
            while(find_ != 3);
            break;
        }
        case 2:
        {
            int find_;
            do
            {
                t.mysql_user_own();
                cout<<"\n\n\t\t1.�ϼ���Ʒ"<<endl;
                cout<<"\t\t2.�¼���Ʒ"<<endl;
                cout<<"\t\t3.������һ��"<<endl;
                cout<<"\t\tplease input:";
                cin>>find_;
                switch(find_)
                {
                case 1:
                    t.mysql_up();
                    break;
                case 2:
                    t.mysql_down();
                    break;
                case 3:
                    break;
                default:
                    cout<<"\n\t\t������������!"<<endl;
                }
            }
            while(find_ != 3);
            break;
        }
        case 3:
        {
            t.mysql_user_buy();
            system("pause");
        }
        break;
        case 4:
        {
            int find_;
            do
            {
                t.look_mysql_user();
                cout<<"\n\n\t**********************************************************"<<endl;
                skinSet();
                cout<<"\t*\t\t\t1.�޸�����\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t2.�޸��Ա�\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t3.�޸ĵ绰\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t4.��ֵ\t\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t5.������һ��\t\t\t *"<<endl;
                skinSet();
                cout<<"\t**********************************************************"<<endl;
                cout<<"\t please input:";
                cin>>find_;
                system("cls");
                bool flag = 1;
                switch(find_)
                {
                case 1:
                {
                    stringstream ss_mysql;
                    string a = "\"";
                    string name;

                    while(flag)
                    {
                        cout<<"\n\n\n\t\t ����������:";
                        cin>>name;
                        if(t.Format_Matching(name, "[\u4e00-\u9fa5a-zA-Z]{2,10}"))
                        {
                            flag = 0;
                        }
                        else
                        {
                            MessageBox(NULL,"���벻�Ϸ���������2��10����Ӣ���ַ�","������Ʒ����",NULL);
                        }
                        system("cls");
                    }
                    ss_mysql<<"update users set name ="<<a<<name<<a<<" where user ="<<a<<mysql_user<<a<<";";
                    mysql_query(&mysql, ss_mysql.str().c_str());
                    MessageBox(NULL, TEXT("�޸ĳɹ�"), TEXT("������Ʒ����"), MB_OK);
                    system("cls");
                }
                break;
                case 2:
                {
                    stringstream ss_mysql;
                    string a = "\"";
                    string sex;
                    flag = 1;
                    while(flag)
                    {
                        cout<<"\n\n\t\t�������л���Ů!"<<endl;
                        cout<<"\n\n\n\n\t\t+            �Ա�:";
                        cin>>sex;
                        if(sex == "��"|| sex == "Ů")
                        {
                            flag = 0;
                        }
                        else
                        {
                            MessageBox(NULL,"�����벻�Ϸ�����������","������Ʒ����",NULL);
                        }
                        system("cls");
                    }
                    ss_mysql<<"update users set sex ="<<a<<sex<<a<<" where user ="<<a<<mysql_user<<a<<";";
                    mysql_query(&mysql, ss_mysql.str().c_str());
                    MessageBox(NULL, TEXT("�޸ĳɹ�"), TEXT("������Ʒ����"), MB_OK);
                    //system("pause");
                    system("cls");
                }
                break;
                case 3:
                {
                    stringstream ss_mysql,ss_mysql_money;
                    string a = "\"";
                    string phone;
                    flag = 1;
                    while(flag)
                    {
                        cout<<"\n\n\n\n\t\t+            �绰:";
                        cin>>phone;
                        if(t.Format_Matching(phone, "[0-9]{3,15}"))
                        {
                            flag = 0;
                        }
                        else
                        {
                            MessageBox(NULL,"�����벻�Ϸ�����������","������Ʒ����",NULL);
                        }
                        system("cls");
                    }
                    ss_mysql<<"update users set phone ="<<a<<phone<<a<<" where user ="<<a<<mysql_user<<a<<";";
                    mysql_query(&mysql, ss_mysql.str().c_str());
                    MessageBox(NULL, TEXT("�޸ĳɹ�"), TEXT("������Ʒ����"), MB_OK);
                    //cout<<"\n\t\t�޸ĳɹ�!!"<<endl;
                    //system("pause");
                    system("cls");
                }
                break;
                case 4:
                {
                    stringstream ss_mysql,ss_mysql_money;
                    string a = "\"";
                    string money;
                    cout<<"\n\n\n\t\t �������ֵǮ��:";
                    cin>>money;
                    ss_mysql<<"update users set money = money +"<<money<<" where user ="<<a<<mysql_user<<a<<";";
                    ss_mysql_money<<"select * from users where user ="<<a<<mysql_user<<a<<";";
                    mysql_query(&mysql, ss_mysql.str().c_str());
                    MessageBox(NULL, TEXT("��ֵ�ɹ�"), TEXT("������Ʒ����"), MB_OK);
                    t.user_vip(money);
                    mysql_query(&mysql, ss_mysql_money.str().c_str());
                    result = mysql_store_result(&mysql);
                    row = mysql_fetch_row(result);
                    printf("\n\t\t ��ǰ���:%s\n",row[3]);
                    //system("pause");
                    system("cls");
                }
                break;
                case 5://
                    break;
                default:
                {
                    MessageBox(NULL, TEXT("�������!!����������"), TEXT("������Ʒ����"), MB_OK);
                    //cout<<"\n\t\t�������!!����������!!"<<endl;
                    //system("pause");
                    system("cls");
                }
                }
            }
            while(find_!=5);
            break;
        }
        case 5:
            t.user_activity();
            break;
        case 6:
        {
            int result_t =  MessageBox(NULL, TEXT("��ȷ���˳���?"),TEXT("������Ʒ����"), MB_YESNO|MB_ICONWARNING);
            if(result_t != 6)
                choose_ = 0;
        }
        break;
        default:
            MessageBox(NULL, TEXT("�������!!����������"), TEXT("������Ʒ����"), MB_OK);
        }
    }
    while(choose_!=6);
}
void Registered_user()
{
    system("cls");
    mysql_do t;
    string name,sex,phone,user_,pwd_;
    stringstream ss_mysql,ss_table_sale,ss_mysql_find;
    string a = "\"";
    unsigned flag = 1;
    cout<<"\n\n\t\t��������������Ϣ!!"<<endl;
    while(flag)
    {
        cout<<"\n\n\n\n\t\t+            ����:";
        cin>>name;
        if(t.Format_Matching(name, "[\u4e00-\u9fa5a-zA-Z]{2,10}"))
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"���벻�Ϸ���������2��10����Ӣ���ַ�","������Ʒ����",NULL);
        }
        system("cls");
    }
    flag = 1;
    while(flag)
    {
        cout<<"\n\n\t\t�������л���Ů!"<<endl;
        cout<<"\n\n\n\n\t\t+            �Ա�:";
        cin>>sex;
        if(sex == "��"|| sex == "Ů")
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"�����벻�Ϸ�����������","������Ʒ����",NULL);
        }
        system("cls");
    }
    flag = 1;
    while(flag)
    {
        cout<<"\n\n\n\n\t\t+            �绰:";
        cin>>phone;
        if(t.Format_Matching(phone, "[0-9]{3,15}"))
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"�����벻�Ϸ�����������","������Ʒ����",NULL);
        }
        system("cls");
    }
    flag = 1;
    while(flag)
    {
        cout<<"\n\n\n\n\t\t+            �˺�:";
        cin>>user_;
        if(t.Format_Matching(user_, "[0-9a-zA-Z]{4,12}"))
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"�����벻�Ϸ���������4��12λ��ĸ������","������Ʒ����",NULL);
        }
        system("cls");
    }
    flag = 1;
    while(flag)
    {
        cout<<"\n\n\n\n\t\t+            ����:";
        cin>>pwd_;
        if(t.Format_Matching(pwd_, "[0-9a-zA-Z]{4,16}"))
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"�����벻�Ϸ���������4��12λ��ĸ������","������Ʒ����",NULL);
        }
        system("cls");
    }
    cout<<"\n\n\t**********************************************************"<<endl;
    skinSet();
    cout<<"\t\t\t\t����:"<<name<<"\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t�Ա�:"<<sex<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t�绰:"<<phone<<"\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t�˺�:"<<user_<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t����:"<<pwd_<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t**********************************************************"<<endl;
    int result_user = MessageBox(NULL, TEXT("��ȷ��ע����?"),TEXT("������Ʒ����"), MB_YESNO|MB_ICONWARNING);
    if(result_user == 6)
    {
        //flag = 1;
        //cout<<"\n\n\t+--------------------------------------+"<<endl;
        system("cls");
        ss_mysql_find<<"select count(*) from users where user ="<<a<<user_<<a<<";";
        mysql_query(&mysql, ss_mysql_find.str().c_str());
        result = mysql_store_result(&mysql);
        row = mysql_fetch_row(result);
        mysql_free_result(result);
        if(!strcmp(row[0],"0"))
        {
            ss_mysql<<"insert into users values("<<a<<name<<a<<","<<a<<phone<<a<<","<<a<<sex<<a<<","
                    <<a<<"0"<<a<<","<<a<<user_<<a<<","<<a<<pwd_<<a<<","<<a<<"0"<<a<<","<<a<<"1"<<a<<");";
            mysql_query(&mysql, ss_mysql.str().c_str());
            MessageBox(NULL, TEXT("ע��ɹ�"), TEXT("������Ʒ����"), MB_OK);
            //cout<<"\n\t\tע��ɹ�!!!"<<endl;
        }
        else
        {
            MessageBox(NULL, TEXT("���˺��Ѵ��� ������ע��!"), TEXT("������Ʒ����"), MB_OK);
            //cout<<"\n\t\t ���˺��Ѵ��� ������ע��!!"<<endl;
        }
        //system("pause");
    }
    else
    {
        system("cls");
    }
}

void coverit(char test[])
{
    char t;
    int i = 0;
    while((t = getch())!='\r'&&i <= 19)
    {
        if(t == '\b' && i!=0)
        {
            cout<<'\b'<<' '<<'\b';
            i--;
            continue;
        }
        else if(t == '\b')
        {
            continue;
        }
        test[i++] = t;
        putchar('*');
    }
    test[i]='\0';
}

bool login_in()//ȷ���Ƿ��ܹ���½
{
    mysql_do t;
    login_flag = 0;
    //int flag;
    system("cls");
    //string user = "admin";
    //char pwd[] = "admin";
    string one;
    string two;
    char first[20]= {'\0'};
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    cout<<"\n\n\t+            �˺�:";
    cin>>one;
    cout<<endl;
    cout<<"\n\n\t+            ����:";
    coverit(first);
    two = first;
    cout<<endl;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    if(t.login_mysql_user(one))
    {
        if(t.login_mysql_pwd(one,two))

        {
            mysql_user = one;
            return true;
        }
        else
            return false;
    }
    else
    {
        login_flag = 1;
        return false;
    }
}
void mysql_connect()//�������ݿ�
{
    map_heart();
    cout<<"\t\t���Ժ�..";
    mysql_init(&mysql);
    if((sock = mysql_real_connect(&mysql, host, user, pwd, db,
                                  port, unix_socket, client_flag)) == NULL)
    {
        cout<<"����ʧ��!!��"<<endl;
        fprintf(stderr, " %s\n", mysql_errno(&mysql));
        exit(1);
    }
    else
    {
        system("cls");
        map_heart();
        cout<<"\t���ݿ�������..";
        Sleep(2 * 1000);
        system("cls");
        map_heart();
        cout<<"\t���ڼ��� ���� 20%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t���ڼ��� �������� 40%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t���ڼ��� ������������ 60%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t���ڼ��� ���������������� 80%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t���ڼ��� �������������������� 100%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t�������..";
        Sleep(2 * 1000);
        system("cls");
    }
}
void list_use()
{
    tools tool_one;
    do
    {
        system("cls");
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        skinSet();
        cout<<"\t*\t\t ��ӭʹ��������Ʒ����ϵͳ\t\t *"<<endl;
        skinSet();
        skinSet();
        cout<<"\t*\t\t v2.0 \t\t\t\t\t *"<<endl;
        skinSet();
        skinSet();
        cout<<"\t*\t\t ����:���㷭���Ŷ� \t\t\t *"<<endl;
        skinSet();
        skinSet();
        cout<<"\t**********************************************************"<<endl;
        cout<<"\n\t1.��½"<<endl;
        cout<<"\n\t2.ע��"<<endl;
        cout<<"\n\t3.��������"<<endl;
        cout<<"\n\t4.�˳�"<<endl;
        cout<<"\n\thi! please input:";
        cin>>a;
        switch(a)
        {
        case 1:
        {
            int result_ = login_in();
            if(result_)
            {
                if(mysql_user == "admin"| mysql_user == "admin2")
                    tool_one.admin_pressany();
                else
                {
                    tool_one.pressany();
                }
            }
            else if(login_flag)
            {
                MessageBox(NULL, TEXT("�����ڸ��˺�"), TEXT("������Ʒ����"), MB_OK);
                //system("pause");
            }
            else
            {
                MessageBox(NULL, TEXT("�������"), TEXT("������Ʒ����"), MB_OK);
                //system("pause");
            }
            break;
        }
        case 2:
            Registered_user();
            break;
        case 3:
            tool_one.showcopy();
            break;
        case 4:
            //�˳�
            break;
        default:
            MessageBox(NULL, TEXT("�������"), TEXT("������Ʒ����"), MB_OK);
            tool_one.pause_clear();
        }
    }
    while(a!=4);
    cout<<"exit success"<<endl;
    //tool_one.Voicep();
    PlaySound("Test.wav", NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
    system("pause");
}
int main()
{
    system("color f0");
    //map_robot();
    mysql_connect();

    //mysql_do t;
    //string name = "namet";
    //t.login_mysql(name);
    list_use();
    map_heart();
    mysql_free_result(result);                                //�ͷŽ����
    mysql_close(sock);//�ر����ݿ�
    return 0;
}
