/**
 * @brief      
 * @file     bigito.c
 * @author   cc
 * @version  
 * @date     Wed 27 Jun 2018 01:30:42 AM PDT
 * @mail     13568859409@163.com 
 * @note     
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../tcp/tcp.h"
#define USETCP

#ifdef USETCP
//#include "../tcp/tcp.h"
#else

#endif

//设备登录
void BigiotLogin(const char *id,const char *apikey)
{
	char ptr1[] = "{\"M\":\"checkin\",\"ID\":\"";
	char ptr2[] = "\",\"K\":\"";
	char ptr3[] = "\"}\n";
	char *ptr = malloc(100);
	int len;
	memset(ptr,0,100);
	memcpy(ptr,ptr1,sizeof(ptr1));				//ptr1
	len = sizeof(ptr1) - 1;
	memcpy((ptr + len),id,strlen(id));			//id
	len = len + strlen(id);
	memcpy((ptr + len),ptr2,sizeof(ptr2));		//ptr2
	len = len + sizeof(ptr2) - 1;
	memcpy((ptr + len),apikey,strlen(apikey));	//apikey
	len = len + strlen(apikey);
	memcpy((ptr + len),ptr3,sizeof(ptr3));		//ptr3
	len = strlen(ptr);
	ptr[len-1] = '\n';							//添加\n，必须要

#ifdef USETCP
	TcpSendData((const char *)ptr,len);
#else

#endif

}

//发送数据
//void BigiotSendData(const char *,const char *,const char *,...);

//接收数据
int BigiotRecvData(char *data,int len)
{
	int ret = 0;
#ifdef USETCP
	ret = TcpRecvdData(data,len);
#else

#endif
	*(data+ret) = '\0';		//在末尾添加字符串结束标志
	return ret;
}

//查询设备或者用户是否在线
void BigiotIsOnLine(const char *ptr,...)
{

}

//查询当前设备状态
void BigiotStatus(void)
{
	char ptr[] = "{\"M\":\"status\"}\n";
#ifdef USETCP
	TcpSendData(ptr,strlen(ptr));
#else
#endif
}

//查询服务器时间
void BigiotTime(void)
{
	char ptr[] = "{\"M\":\"time\",\"F\":\"Y-m-d H:i:s\"}\n";
#ifdef USETCP
	TcpSendData(ptr,strlen(ptr));
#else

#endif
}

//发送报警信息
void BigiotAlertMessage(const char *message,const char *type)
{
	char ptr1[] = "{\"M\":\"alert\",\"C\":\"";
	char ptr2[] = "\",\"B\":\"";
	char ptr3[] = "\"}\n";
	char *ptr = malloc(100);
	int len;
	memset(ptr,0,100);
	memcpy(ptr,ptr1,sizeof(ptr1));				//ptr1
	len = sizeof(ptr1) - 1;
	memcpy((ptr + len),message,strlen(message));		//message
	len = len + strlen(message);
	memcpy((ptr + len),ptr2,sizeof(ptr2));		//ptr2
	len = len + sizeof(ptr2) - 1;
	memcpy((ptr + len),type,strlen(type));		//type
	len = len + strlen(type);
	memcpy((ptr + len),ptr3,sizeof(ptr3));		//ptr3
	len = strlen(ptr);
	ptr[len-1] = '\n';							//添加\n，必须要
#ifdef USETCP
	TcpSendData(ptr,strlen(ptr));
#else

#endif

}

//设备下线
void BigiotLogout(const char *id,const char *apikey)
{
	char ptr1[] = "{\"M\":\"checkout\",\"ID\":\"";
	char ptr2[] = "\",\"K\":\"";
	char ptr3[] = "\"}\n";
	char *ptr = malloc(100);
	int len;
	memset(ptr,0,100);
	memcpy(ptr,ptr1,sizeof(ptr1));				//ptr1
	len = sizeof(ptr1) - 1;
	memcpy((ptr + len),id,strlen(id));			//id
	len = len + strlen(id);
	memcpy((ptr + len),ptr2,sizeof(ptr2));		//ptr2
	len = len + sizeof(ptr2) - 1;
	memcpy((ptr + len),apikey,strlen(apikey));	//apikey
	len = len + strlen(apikey);
	memcpy((ptr + len),ptr3,sizeof(ptr3));		//ptr3
	len = strlen(ptr);
	ptr[len-1] = '\n';							//添加\n，必须要
#ifdef USETCP
	TcpSendData(ptr,strlen(ptr));
#else

#endif
}
