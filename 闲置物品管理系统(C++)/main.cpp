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
    cout<<"\n\t   |       『咸鱼翻身团队 』      |"<<endl;
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
    //初始化堆，从最后一个父节点开始
    for(i = len/2 - 1; i >= 0; --i)
    {
        Heapify(arr,i,len);
    }
    //从堆中的取出最大的元素再调整堆
    for(i = len - 1; i > 0; --i)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        //调整成堆
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
        //如果父节点大于子节点则表示调整完毕
        if(arr[father] > arr[son])
            break;
        else
        {
            //不然就交换父节点和子节点的元素
            int temp = arr[father];
            arr[father] = arr[son];
            arr[son] = temp;
            //父和子节点变成下一个要比较的位置
            father = son;
            son = 2 * father + 1;
        }
    }
}
/*void quickSort(int* A,int first,int last)         //数组A,first是第一个元素下标，last是最后一个元素下标
{
    if(last<=first)                           //到了长度小于1这种情况已经是有序列了
        return;

    int pivot=A[first];
    int left=first+1;                         //left等于第二个元素
    int right=last;
    int temp;
    while(left<=right)
    {
        while(A[right]>pivot&&right>=left)//找到一个比first小的,但必须保证left值小于等于right值
            right--;

        while(A[left]<pivot&&left<=right) //找到一个比first大的,但得保证left值小于等于right值
            left++;

        if(left>=right)                   //说明已经是相对有序序列，无需交换
            break;

        temp=A[left];                     //交换位置
        A[left]=A[right];
        A[right]=temp;
        left++,right--;                   //相应的进一位
    }
    A[first]=A[right];                        //因为right一定是停在从右到左第一个小于first的数上，交换之后，
    //依然能保证first值左边的比first小，右边的比first大
    A[right]=pivot;

    quickSort(A,first,right-1);               //左半部分
    quickSort(A,left,last);                   //右半部分
}*/

void skinSet()
{
    cout<<"\t*\t\t\t\t\t\t\t *\n";
}//控制格式
class mysql_do
{
public:
    /*
      用户功能
      */
    bool login_mysql_user(string name_);//查询是否存在账号
    bool login_mysql_pwd(string name_,string name_pwd);//查询密码是否正确
    void look_mysql_user();//个人信息
    void mysql_user_buy();//浏览购买记录
    void mysql_user_own();//浏览自己的上架商品
    void mysql_up();//上架物品
    void mysql_down();//下架物品
    void mysql_goods_all();//浏览所有商品
    void mysql_goods_lookfor();//搜查商品
    void mysql_goods_buy();//购买商品
    bool Format_Matching (string, const char *);//正则匹配
    void user_vip(string m);
    void user_activity();//用户活动浏览
    /*
      管理员功能
      */
    void admin_look_buy();//浏览所有购买记录
    void admin_look_user();//浏览所有用户
    void admin_look_del();//删除用户
    void admin_activity();//活动管理
    void admin_act_add();//活动奖品添加
    void admin_act_del();//活动奖品删除
    void admin_act_begin();//活动开始
    void admin_act_end();//活动关闭
    void admin_file_read();//文件读取
};
void mysql_do::admin_file_read()
{
    system("cls");
    string t_;
    stringstream ss;
    string a = "\"";
    cout<<"\n\n\t\t\t请输入要读入的文件:";
    cin>>t_;
    fstream out(t_,ios::in);
    string s,m;
    if(!out.is_open())
    {
        MessageBox(NULL,TEXT("文件不存在或读取错误"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    while(true)
    {
        if(!out)
            break;
        out>>s>>m;
        act_file.insert(map<string, string>::value_type(s,m));
        cout<<"\t文件读取中..."<<endl;
    }
    cout<<"\t文件读取完毕!"<<endl;
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
        MessageBox(NULL, TEXT("暂时没有活动"),TEXT("闲置物品管理"), MB_OK);
        return;
    }
    ss_mysql_wh<<"select * from users where user = "<<a<<mysql_user<<a<<";";
    mysql_query(&mysql, ss_mysql_wh.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(atoi(row[7])==0)
    {
        MessageBox(NULL, TEXT("您没有抽奖次数"),TEXT("闲置物品管理"), MB_OK);
        return;
    }
    int index = 0;
    memset(act_goods,0,sizeof(int));
    ss_mysql<<"select * from act;";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    cout<<"\n\t\t\t\t奖品如下"<<endl;
    while((row = mysql_fetch_row(result)) != NULL)
    {
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t\t\t\t物品:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t价格:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
        act_goods[index++] = atoi(row[1]);
//        cout<<act_goods[index-1]<<endl;
        //cout<<act_goods[index-1]<<endl;
    }
    int res = MessageBox(NULL, TEXT("您确定开始活动吗?"),TEXT("闲置物品管理"), MB_YESNO|MB_ICONWARNING);
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
            MessageBox(NULL, TEXT("恭喜你获奖了!"),TEXT("闲置物品管理"), MB_OK);
            cout<<"\n\n\t**********************************************************"<<endl;
            skinSet();
            cout<<"\t\t\t\t物品:"<<row[0]<<"\t\t\t "<<endl;
            skinSet();
            cout<<"\t\t\t\t价格:"<<row[1]<<"\t\t\t\t "<<endl;
            skinSet();
            cout<<"\t**********************************************************"<<endl;
            ss_mysql_d<<"insert into buy values("<<a<<row[0]<<"[活动获得]"<<a<<","<<a<<gift<<a<<","<<a<<mysql_user<<a<<");";
            mysql_query(&mysql, ss_mysql_d.str().c_str());
            ss_b<<"delete from act where name ="<<a<<row[0]<<a<<";";
            //cout<<ss_b.str()<<endl;
            mysql_query(&mysql, ss_b.str().c_str());
            system("pause");
            return;
        }
        MessageBox(NULL, TEXT("很遗憾没得奖"),TEXT("闲置物品管理"), MB_OK);
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
        MessageBox(NULL, TEXT("活动已经开启!"),TEXT("闲置物品管理"), MB_OK);
        return;
    }
    int rest = MessageBox(NULL, TEXT("您确定开始活动吗?"),TEXT("闲置物品管理"), MB_YESNO|MB_ICONWARNING);
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
        MessageBox(NULL, TEXT("活动开启!"),TEXT("闲置物品管理"), MB_OK);
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
        MessageBox(NULL, TEXT("活动已经关闭!"),TEXT("闲置物品管理"), MB_OK);
        return;
    }
    int rest = MessageBox(NULL, TEXT("您确定关闭活动吗?"),TEXT("闲置物品管理"), MB_YESNO|MB_ICONWARNING);
    if(rest == 6)
    {
        ss_mysql<<"update admin_ set doit ='0' where doit = '1';";
        mysql_query(&mysql, ss_mysql.str().c_str());
        MessageBox(NULL, TEXT("活动关闭!"),TEXT("闲置物品管理"), MB_OK);
    }
}
void mysql_do::admin_act_del()
{
    stringstream ss_mysql,ss_mysql_;
    string a = "\"";
    string name_;
    cout<<"\n\n\t\t请输入物品名字:";
    cin>>name_;
    ss_mysql_<<"select count(*) from act where name ="<<a<<name_<<a<<";";
    //cout<<ss_mysql.str()<<endl;
    mysql_query(&mysql, ss_mysql_.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(!strcmp(row[0],"0"))
    {
        MessageBox(NULL, TEXT("不存在该物品"), TEXT("闲置物品管理"), MB_OK);
    }
    else
    {
        ss_mysql<<"delete from act where name ="<<a<<name_<<a<<";";
        mysql_query(&mysql, ss_mysql.str().c_str());
        MessageBox(NULL, TEXT("删除成功"), TEXT("闲置物品管理"), MB_OK);
    }
}
void mysql_do::admin_act_add()
{
    system("cls");
    stringstream ss_mysql;
    string a = "\"";
    string name,money;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    cout<<"\n\n\t+            物品名字:";
    cin>>name;
    cout<<endl;
    cout<<"\n\n\t+            物品价格:";
    cin>>money;
    cout<<endl;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    ss_mysql<<"insert into act values("<<a<<name<<a<<","<<a<<money<<a<<");";
    mysql_query(&mysql, ss_mysql.str().c_str());
    MessageBox(NULL, TEXT("添加成功"), TEXT("闲置物品管理"), MB_OK);
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
            MessageBox(NULL, TEXT("暂无商品"), TEXT("闲置物品管理"),MB_OK);
        }
        ss_mysql<<"select * from act;";
        mysql_query(&mysql, ss_mysql.str().c_str());
        result = mysql_store_result(&mysql);
        while((row = mysql_fetch_row(result)) != NULL)
        {
            cout<<"\n\n\t**********************************************************"<<endl;
            skinSet();
            cout<<"\t\t\t\t物品:"<<row[0]<<"\t\t\t "<<endl;
            skinSet();
            cout<<"\t\t\t\t价格:"<<row[1]<<"\t\t\t\t "<<endl;
            skinSet();
            cout<<"\t**********************************************************"<<endl;
        }
        cout<<"\t\t\t1.加入奖品"<<endl;
        cout<<"\t\t\t2.删除奖品"<<endl;
        cout<<"\t\t\t3.开始活动"<<endl;
        cout<<"\t\t\t4.关闭活动"<<endl;
        cout<<"\t\t\t5.退出"<<endl;
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
            MessageBox(NULL, TEXT("输入错误"), TEXT("闲置物品管理"),MB_OK);
        }
    }
    while(cho!=5);
}
void mysql_do::admin_look_del()
{
    stringstream ss_mysql,ss_mysql_admin;
    string a = "\"";
    string user_user;
    cout<<"\n\t\t\t请输入注销用户的账号:";
    cin>>user_user;
    ss_mysql_admin<<"select count(*) from users where user ="<<a<<user_user<<a<<";";
    mysql_query(&mysql, ss_mysql_admin.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(!strcmp(row[0],"0"))
    {
        MessageBox(NULL, TEXT("没有该账户"), TEXT("闲置物品管理"),MB_OK);
        return;
    }
    int result_ = MessageBox(NULL, TEXT("你确定注销该用户吗?"), TEXT("闲置物品管理"), MB_YESNO|MB_ICONWARNING);
    if(result_ == 6)
    {
        ss_mysql<<"delete from users where user ="<<a<<user_user<<a<<";";
        mysql_query(&mysql, ss_mysql.str().c_str());
        MessageBox(NULL,TEXT("注销该用户成功"), TEXT("闲置物品管理"),MB_OK);
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
        cout<<"\t\t\t\t物品:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t价格:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t用户:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!admin_flag)
        MessageBox(NULL, TEXT("暂无用户购买记录"), TEXT("闲置物品管理"), MB_OK);
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
        cout<<"\t\t\t\t名字:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t电话:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t性别:"<<row[2]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t余额:"<<row[3]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t账号:"<<row[4]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t密码:"<<row[5]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\tVIP:"<<row[6]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!admin_flag)
        MessageBox(NULL, TEXT("暂无用户记录"), TEXT("闲置物品管理"), MB_OK);
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
        MessageBox(NULL, TEXT("恭喜你成为VIP10"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=100000&&(atoi(row[3])-atoi(m.c_str()))<100000)
    {
        ss_mysql_vip<<"update users set vip ='9' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP9"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=50000&&(atoi(row[3])-atoi(m.c_str()))<50000)
    {
        ss_mysql_vip<<"update users set vip ='8' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP8"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=20000&&(atoi(row[3])-atoi(m.c_str()))<20000)
    {
        ss_mysql_vip<<"update users set vip ='7' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP7"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=10000&&(atoi(row[3])-atoi(m.c_str()))<10000)
    {
        ss_mysql_vip<<"update users set vip ='6' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP6"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=5000&&(atoi(row[3])-atoi(m.c_str()))<5000)
    {
        ss_mysql_vip<<"update users set vip ='5' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP5"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=2000&&(atoi(row[3])-atoi(m.c_str()))<2000)
    {
        ss_mysql_vip<<"update users set vip ='4' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP4"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=1000&&(atoi(row[3])-atoi(m.c_str()))<1000)
    {
        ss_mysql_vip<<"update users set vip ='3' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP3"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=500&&(atoi(row[3])-atoi(m.c_str()))<500)
    {
        ss_mysql_vip<<"update users set vip ='2' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP2"),TEXT("闲置物品管理"),MB_OK);
        return;
    }
    if(atoi(row[3])>=300&&(atoi(row[3])-atoi(m.c_str()))<300)
    {
        ss_mysql_vip<<"update users set vip ='1' where user ="<<a<<mysql_user<<a<<";";
        mysql_query(&mysql, ss_mysql_vip.str().c_str());
        MessageBox(NULL, TEXT("恭喜你成为VIP1"),TEXT("闲置物品管理"),MB_OK);
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
    cout<<"\n\t\t请输入搜查名字:";
    cin>>name;
    ss_mysql<<"select * from Goods where name ="<<a<<name<<a<<";";
    mysql_query(&mysql, ss_mysql.str().c_str());
    result = mysql_store_result(&mysql);
    while((row = mysql_fetch_row(result)) != NULL)
    {
        flag_buy = 1;
        cout<<"\n\n\t**********************************************************"<<endl;
        skinSet();
        cout<<"\t\t\t\t物品:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t价格:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t备注信息:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t用户:"<<row[3]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\tID:"<<row[4]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!flag_buy)
        MessageBox(NULL, TEXT("暂无商品"), TEXT("闲置物品管理"), MB_OK);
}
void mysql_do::mysql_goods_buy()
{
    //system("cls");
    //int flag_buy = 0;
    stringstream ss_mysql,ss_mysql_d,ss_mysql_i,ss_mysql_us,ss_mysql_do,ss_mysql_p,ss;
    string a = "\"";
    string id;
    cout<<"\n\t\t请输入物品的id:";
    cin>>id;
    ss_mysql_p<<"select count(*) from Goods where id="<<a<<id<<a<<";";
    mysql_query(&mysql, ss_mysql_p.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    mysql_free_result(result);
    //cout<<1<<endl;
    if(!strcmp(row[0],"0"))
    {
        MessageBox(NULL, TEXT("该商品不存在"), TEXT("闲置物品管理"), MB_OK);
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
            MessageBox(NULL, TEXT("购买成功!"), TEXT("闲置物品管理"), MB_OK);
        }
        else
        {
            cout<<"\n\t\t您的余额不足!!"<<endl;
            cout<<"\t\t您余额为:"<<money_one<<endl;
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
        cout<<"\t\t\t\t物品:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t价格:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t备注信息:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t用户:"<<row[3]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\tid:"<<row[4]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!flag_buy)
        MessageBox(NULL, TEXT("暂无商品"), TEXT("闲置物品管理"), MB_OK);
}
void mysql_do::mysql_up()
{
    system("cls");
    //int flag_buy = 0;
    stringstream ss_mysql;
    string a = "\"";
    string name,money,note;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    cout<<"\n\n\t+            物品名字:";
    cin>>name;
    cout<<endl;
    cout<<"\n\n\t+            物品价格:";
    cin>>money;
    cout<<endl;
    cout<<"\n\n\t+            备注:";
    cin>>note;
    cout<<endl;
    cout<<"\n\n\t+--------------------------------------+"<<endl;
    ss_mysql<<"insert into Goods values("<<a<<name<<a<<","<<a<<money<<a<<","<<a<<note<<a<<","<<a<<mysql_user<<a<<","<<a<<a<<");";
    //cout<<ss_mysql.str()<<endl;
    mysql_query(&mysql, ss_mysql.str().c_str());
    MessageBox(NULL, TEXT("上架成功"), TEXT("闲置物品管理"), MB_OK);
    //system("pause");
}
void mysql_do::mysql_down()
{
    stringstream ss_mysql,ss_mysql_;
    string a = "\"";
    string id;
    cout<<"\n\n\t\t请输入物品id:";
    cin>>id;
    ss_mysql_<<"select count(*) from Goods where id ="<<a<<id <<a<<"&& user ="<<a<<mysql_user<<a<<";";
    //cout<<ss_mysql.str()<<endl;
    mysql_query(&mysql, ss_mysql_.str().c_str());
    result = mysql_store_result(&mysql);
    row = mysql_fetch_row(result);
    if(!strcmp(row[0],"0"))
    {
        MessageBox(NULL, TEXT("不存在该id或该id非你的商品"), TEXT("闲置物品管理"), MB_OK);
    }
    else
    {
        ss_mysql<<"delete from Goods where id ="<<a<<id<<a<<";";
        mysql_query(&mysql, ss_mysql.str().c_str());
        MessageBox(NULL, TEXT("下架成功"), TEXT("闲置物品管理"), MB_OK);
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
        cout<<"\t\t\t\t物品:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t价格:"<<row[1]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t备注信息:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\tid:"<<row[4]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t**********************************************************"<<endl;
    }
    if(!flag_buy)
        MessageBox(NULL, TEXT("你暂无上架记录"), TEXT("闲置物品管理"), MB_OK);
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
    cout<<"\t\t\t\t名字:"<<row[0]<<"\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t性别:"<<row[2]<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t电话:"<<row[1]<<"\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t余额:"<<row[3]<<"\t\t\t\t "<<endl;
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
//        cout<<"\t\t\t\t购买时间:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t物品:"<<row[0]<<"\t\t\t "<<endl;
        skinSet();
        cout<<"\t\t\t\t价格:"<<row[1]<<"\t\t\t\t "<<endl;
//        skinSet();
//        cout<<"\t\t\t\t购买时间:"<<row[2]<<"\t\t\t\t "<<endl;
        skinSet();
        cout<<"\t************************************************************"<<endl;
    }
    if(!flag_buy)
        MessageBox(NULL, TEXT("您暂无购买记录"), TEXT("闲置物品管理"), MB_OK);
}
class tools
{
public:
    void pause_clear();//清屏和缓冲
    void Voicep();//控制结束声音
    void showcopy();//关于我们
    void pressany();//登陆之后界面
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
        cout<<"\t*\t\t\t1.浏览所有购买记录\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t2.管理用户\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t3.活动管理\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t4.活动奖品上传\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t5.退出\t\t\t\t *"<<endl;
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
                cout<<"\t*\t\t\t1.注销用户\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t2.退出\t\t\t\t *"<<endl;
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
                    //退出
                    break;
                default:
                    MessageBox(NULL, TEXT("您的输入有误"), TEXT("闲置物品管理"),MB_OK);
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
            MessageBox(NULL, TEXT("您的输入有误"), TEXT("闲置物品管理"),MB_OK);
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
        cout<<"\t*\t\t\t1.浏览所有商品\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t2.我的上架物品\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t3.我购买的物品\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t4.个人信息\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t5.活动\t\t\t\t *"<<endl;
        skinSet();
        cout<<"\t*\t\t\t6.退出\t\t\t\t *"<<endl;
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
                cout<<"\n\n\t\t1.搜查物品"<<endl;
                cout<<"\t\t2.购买物品"<<endl;
                cout<<"\t\t3.返回上一级"<<endl;
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
                    MessageBox(NULL, TEXT("输入有误"), TEXT("闲置物品管理"),MB_OK);
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
                cout<<"\n\n\t\t1.上架物品"<<endl;
                cout<<"\t\t2.下架物品"<<endl;
                cout<<"\t\t3.返回上一级"<<endl;
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
                    cout<<"\n\t\t您的输入有误!"<<endl;
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
                cout<<"\t*\t\t\t1.修改姓名\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t2.修改性别\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t3.修改电话\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t4.充值\t\t\t\t *"<<endl;
                skinSet();
                cout<<"\t*\t\t\t5.返回上一级\t\t\t *"<<endl;
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
                        cout<<"\n\n\n\t\t 请输入名字:";
                        cin>>name;
                        if(t.Format_Matching(name, "[\u4e00-\u9fa5a-zA-Z]{2,10}"))
                        {
                            flag = 0;
                        }
                        else
                        {
                            MessageBox(NULL,"输入不合法，请输入2到10个中英文字符","闲置物品管理",NULL);
                        }
                        system("cls");
                    }
                    ss_mysql<<"update users set name ="<<a<<name<<a<<" where user ="<<a<<mysql_user<<a<<";";
                    mysql_query(&mysql, ss_mysql.str().c_str());
                    MessageBox(NULL, TEXT("修改成功"), TEXT("闲置物品管理"), MB_OK);
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
                        cout<<"\n\n\t\t请输入男或者女!"<<endl;
                        cout<<"\n\n\n\n\t\t+            性别:";
                        cin>>sex;
                        if(sex == "男"|| sex == "女")
                        {
                            flag = 0;
                        }
                        else
                        {
                            MessageBox(NULL,"您输入不合法请重新输入","闲置物品管理",NULL);
                        }
                        system("cls");
                    }
                    ss_mysql<<"update users set sex ="<<a<<sex<<a<<" where user ="<<a<<mysql_user<<a<<";";
                    mysql_query(&mysql, ss_mysql.str().c_str());
                    MessageBox(NULL, TEXT("修改成功"), TEXT("闲置物品管理"), MB_OK);
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
                        cout<<"\n\n\n\n\t\t+            电话:";
                        cin>>phone;
                        if(t.Format_Matching(phone, "[0-9]{3,15}"))
                        {
                            flag = 0;
                        }
                        else
                        {
                            MessageBox(NULL,"您输入不合法请重新输入","闲置物品管理",NULL);
                        }
                        system("cls");
                    }
                    ss_mysql<<"update users set phone ="<<a<<phone<<a<<" where user ="<<a<<mysql_user<<a<<";";
                    mysql_query(&mysql, ss_mysql.str().c_str());
                    MessageBox(NULL, TEXT("修改成功"), TEXT("闲置物品管理"), MB_OK);
                    //cout<<"\n\t\t修改成功!!"<<endl;
                    //system("pause");
                    system("cls");
                }
                break;
                case 4:
                {
                    stringstream ss_mysql,ss_mysql_money;
                    string a = "\"";
                    string money;
                    cout<<"\n\n\n\t\t 请输入充值钱数:";
                    cin>>money;
                    ss_mysql<<"update users set money = money +"<<money<<" where user ="<<a<<mysql_user<<a<<";";
                    ss_mysql_money<<"select * from users where user ="<<a<<mysql_user<<a<<";";
                    mysql_query(&mysql, ss_mysql.str().c_str());
                    MessageBox(NULL, TEXT("充值成功"), TEXT("闲置物品管理"), MB_OK);
                    t.user_vip(money);
                    mysql_query(&mysql, ss_mysql_money.str().c_str());
                    result = mysql_store_result(&mysql);
                    row = mysql_fetch_row(result);
                    printf("\n\t\t 当前余额:%s\n",row[3]);
                    //system("pause");
                    system("cls");
                }
                break;
                case 5://
                    break;
                default:
                {
                    MessageBox(NULL, TEXT("输入错误!!请重新输入"), TEXT("闲置物品管理"), MB_OK);
                    //cout<<"\n\t\t输入错误!!请重新输入!!"<<endl;
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
            int result_t =  MessageBox(NULL, TEXT("您确定退出吗?"),TEXT("闲置物品管理"), MB_YESNO|MB_ICONWARNING);
            if(result_t != 6)
                choose_ = 0;
        }
        break;
        default:
            MessageBox(NULL, TEXT("输入错误!!请重新输入"), TEXT("闲置物品管理"), MB_OK);
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
    cout<<"\n\n\t\t请您依次输入信息!!"<<endl;
    while(flag)
    {
        cout<<"\n\n\n\n\t\t+            名字:";
        cin>>name;
        if(t.Format_Matching(name, "[\u4e00-\u9fa5a-zA-Z]{2,10}"))
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"输入不合法，请输入2到10个中英文字符","闲置物品管理",NULL);
        }
        system("cls");
    }
    flag = 1;
    while(flag)
    {
        cout<<"\n\n\t\t请输入男或者女!"<<endl;
        cout<<"\n\n\n\n\t\t+            性别:";
        cin>>sex;
        if(sex == "男"|| sex == "女")
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"您输入不合法请重新输入","闲置物品管理",NULL);
        }
        system("cls");
    }
    flag = 1;
    while(flag)
    {
        cout<<"\n\n\n\n\t\t+            电话:";
        cin>>phone;
        if(t.Format_Matching(phone, "[0-9]{3,15}"))
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"您输入不合法请重新输入","闲置物品管理",NULL);
        }
        system("cls");
    }
    flag = 1;
    while(flag)
    {
        cout<<"\n\n\n\n\t\t+            账号:";
        cin>>user_;
        if(t.Format_Matching(user_, "[0-9a-zA-Z]{4,12}"))
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"您输入不合法，请输入4到12位字母和数字","闲置物品管理",NULL);
        }
        system("cls");
    }
    flag = 1;
    while(flag)
    {
        cout<<"\n\n\n\n\t\t+            密码:";
        cin>>pwd_;
        if(t.Format_Matching(pwd_, "[0-9a-zA-Z]{4,16}"))
        {
            flag = 0;
        }
        else
        {
            MessageBox(NULL,"您输入不合法，请输入4到12位字母和数字","闲置物品管理",NULL);
        }
        system("cls");
    }
    cout<<"\n\n\t**********************************************************"<<endl;
    skinSet();
    cout<<"\t\t\t\t名字:"<<name<<"\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t性别:"<<sex<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t电话:"<<phone<<"\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t账号:"<<user_<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t\t\t\t密码:"<<pwd_<<"\t\t\t\t "<<endl;
    skinSet();
    cout<<"\t**********************************************************"<<endl;
    int result_user = MessageBox(NULL, TEXT("您确定注册吗?"),TEXT("闲置物品管理"), MB_YESNO|MB_ICONWARNING);
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
            MessageBox(NULL, TEXT("注册成功"), TEXT("闲置物品管理"), MB_OK);
            //cout<<"\n\t\t注册成功!!!"<<endl;
        }
        else
        {
            MessageBox(NULL, TEXT("该账号已存在 请重新注册!"), TEXT("闲置物品管理"), MB_OK);
            //cout<<"\n\t\t 该账号已存在 请重新注册!!"<<endl;
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

bool login_in()//确定是否能够登陆
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
    cout<<"\n\n\t+            账号:";
    cin>>one;
    cout<<endl;
    cout<<"\n\n\t+            密码:";
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
void mysql_connect()//连接数据库
{
    map_heart();
    cout<<"\t\t请稍后..";
    mysql_init(&mysql);
    if((sock = mysql_real_connect(&mysql, host, user, pwd, db,
                                  port, unix_socket, client_flag)) == NULL)
    {
        cout<<"连接失败!!！"<<endl;
        fprintf(stderr, " %s\n", mysql_errno(&mysql));
        exit(1);
    }
    else
    {
        system("cls");
        map_heart();
        cout<<"\t数据库连接中..";
        Sleep(2 * 1000);
        system("cls");
        map_heart();
        cout<<"\t正在加载 ■■ 20%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t正在加载 ■■■■ 40%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t正在加载 ■■■■■■ 60%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t正在加载 ■■■■■■■■ 80%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t正在加载 ■■■■■■■■■■ 100%";
        Sleep(2 * 500);
        system("cls");
        map_heart();
        cout<<"\t载入界面..";
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
        cout<<"\t*\t\t 欢迎使用闲置物品管理系统\t\t *"<<endl;
        skinSet();
        skinSet();
        cout<<"\t*\t\t v2.0 \t\t\t\t\t *"<<endl;
        skinSet();
        skinSet();
        cout<<"\t*\t\t 作者:咸鱼翻身团队 \t\t\t *"<<endl;
        skinSet();
        skinSet();
        cout<<"\t**********************************************************"<<endl;
        cout<<"\n\t1.登陆"<<endl;
        cout<<"\n\t2.注册"<<endl;
        cout<<"\n\t3.关于我们"<<endl;
        cout<<"\n\t4.退出"<<endl;
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
                MessageBox(NULL, TEXT("不存在该账号"), TEXT("闲置物品管理"), MB_OK);
                //system("pause");
            }
            else
            {
                MessageBox(NULL, TEXT("密码错误"), TEXT("闲置物品管理"), MB_OK);
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
            //退出
            break;
        default:
            MessageBox(NULL, TEXT("输入错误"), TEXT("闲置物品管理"), MB_OK);
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
    mysql_free_result(result);                                //释放结果集
    mysql_close(sock);//关闭数据库
    return 0;
}
