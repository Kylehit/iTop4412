/**
 * @brief      
 * @file     esp8266.c
 * @author   cc
 * @version  
 * @date     Sat 30 Jun 2018 11:18:12 PM PDT
 * @mail     13568859409@163.com 
 * @note     
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../uart/uart.h"
#include "esp8266.h"

#define RECVBUFSIZE		1024
#define SENDBUFSIZE		1024

//定义串口接收数据存放空间
static char UartRecvBuf[RECVBUFSIZE];
//定义串口发送数据存放空间
static char UartSendBuf[SENDBUFSIZE];

/**
 *@brief Esp8266模块初始化
 */
int Esp8266Init(void)
{
	int ret = -1;
	ret = Esp8266SendCmd("AT","OK");		//检测模块是否在线
	return ret;
}

/**
 *@brief Esp8266模块发送密令
 *@param cmd:发送的密令字符串
 *@param ack:期待的应答结果，为空，则表示不需要等待应答
 *@return 成功：0	失败：-1
 */
int Esp8266SendCmd(const char *cmd,const char *ack)
{
	int ret;
	sprintf(UartSendBuf,"%s\r\n",cmd);
	ret = UartSendData(UartSendBuf,strlen(UartSendBuf));
	if(ret < 0)
	{
		printf("Esp8266SendCmd SendData error.-L:%d\n",__LINE__);
		return -1;
	}
	memset(UartRecvBuf,0,RECVBUFSIZE);
	ret = UartRecvData(UartRecvBuf,RECVBUFSIZE);
	if(ret < 0)
	{
		printf("Esp8266SendCmd RecvData error.-L:%d\n",__LINE__);
		return -1;
	}
	if(strstr(UartRecvBuf,ack) == NULL)	//在接收到的数据中没有找到指定的ACK字符串
	{
		return -1;
	}
	return 0;
}

/**
 *@brief Esp8266模块发送数据
 *@param cmd:发送的数据字符串,此时不需要添加回车
 *@param ack:期待的应答结果，为空，则表示不需要等待应答
 *@return 成功：0	失败：-1
 */
int Esp8266SendData(const char *data,const char *ack)
{
	int ret = -1;
	ret = UartSendData(data,strlen(data));
	if(ret < 0)
	{
		printf("Esp8266SendData SendData error.-L:%d\n",__LINE__);
		return -1;
	}
	if(ack != NULL)			//需要对接收的数据进行比较
	{
		memset(UartRecvBuf,0,RECVBUFSIZE);
		ret = UartRecvData(UartRecvBuf,RECVBUFSIZE);
		if(ret < 0)
		{
			printf("Esp8266SendData RecvData error.-L:%d\n",__LINE__);
			return -1;
		}
		if(strstr(UartRecvBuf,ack) == NULL)
		{
			printf("Esp8266SendData ack error.-L:%d\n",__LINE__);
			return -1;
		}
		return 0;
	}
	return 0;
}

/**
 *@brief Esp8266模块重启
 *@return 成功：0	失败：-1
 */
int Esp8266Reseat(void)
{
	int ret = -1;
	ret = Esp8266SendCmd("AT+RST","OK");
	if(ret == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/**
 *@brief Esp8266版本信息
 *@param info:版本信息
 *@return 成功：0	失败：-1
 *@pote 只有当成功调用时，info信息才有效
 */
int Esp8266VersionInfo(char *info)
{
	int ret = -1;
	ret = Esp8266SendCmd("AT+GMR","OK");
	if(ret == 0)
	{
		strncpy(info,UartRecvBuf,strlen(UartRecvBuf));
		return 0;
	}
	else
	{
		return -1;
	}
}

