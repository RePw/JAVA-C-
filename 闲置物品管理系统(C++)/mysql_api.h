#ifndef MYSQL_API_H_INCLUDED
#define MYSQL_API_H_INCLUDED
#include <winsock.h>
#include <mysql.h>  //����MySQL����Ҫ��ͷ�ļ�
#include <WinSock2.h> //Socket������MySQLҲ��Ҫ�õ�
MYSQL mysql, *sock;
const char * host = "119.29.221.116";//����
const char * user = "root";//�û�
const char * pwd = "root";//����
const char * db = "students";//��Ҫ���ӵ����ݿ�
unsigned int port = 3306;//���Ӷ˿�
const char * unix_socket = NULL;
unsigned long client_flag = 0;
MYSQL_RES * result;  //����������
MYSQL_ROW row;      //������ǽ�����е�һ��

#endif // MYSQL_API_H_INCLUDED
