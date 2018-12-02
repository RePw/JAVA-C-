#ifndef MYSQL_API_H_INCLUDED
#define MYSQL_API_H_INCLUDED
#include <winsock.h>
#include <mysql.h>  //包含MySQL所需要的头文件
#include <WinSock2.h> //Socket，连接MySQL也需要用的
MYSQL mysql, *sock;
const char * host = "119.29.221.116";//本地
const char * user = "root";//用户
const char * pwd = "root";//密码
const char * db = "students";//需要连接的数据库
unsigned int port = 3306;//连接端口
const char * unix_socket = NULL;
unsigned long client_flag = 0;
MYSQL_RES * result;  //保存结果集的
MYSQL_ROW row;      //代表的是结果集中的一行

#endif // MYSQL_API_H_INCLUDED
