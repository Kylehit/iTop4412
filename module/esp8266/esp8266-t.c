/**
 * @brief      
 * @file     esp8266-t.c
 * @author   cc
 * @version  
 * @date     Sun 01 Jul 2018 12:12:02 AM PDT
 * @mail     13568859409@163.com 
 * @note     
 */

#include <stdio.h>
#include "esp8266.h"

#include "../uart/uart.h"

int main(int argc,char **argv)
{
	int ret;
	char c;
	char versioninfo[500];
	ret = UartInit("/dev/ttySAC0",115200,8,'N',1);
	if(ret < 0)
	{
		printf("UartInit error\n");
		return -1;
	}
	ret = Esp8266Init();
	if(ret < 0)
	{
		printf("esp8266 init error\n");
		UartClose();
		return -1;
	}
	while(1)
	{
		c = getchar();
		switch(c)
		{
			case 'T':
				ret = Esp8266Init();
				if(ret == 0)
				{
					printf("AT cmd is ok\n");
				}
				else
				{
					printf("Esp8266Init error\n");
				}
				break;
			case 'S':
				ret = Esp8266SendCmd("AT","OK");
				if(ret == 0)
				{
					printf("Esp8266SendCmd is ok\n");
				}
				else
				{
					printf("Esp8266SendCmd error\n");
				}
				break;
			case 'D':
				ret = Esp8266SendData("hello",NULL);
				if(ret == 0)
				{
					printf("Esp8266SendData is ok\n");
				}
				else
				{
					printf("Esp8266SendData error\n");
				}
				break;
			case 'V':
				ret = Esp8266VersionInfo(versioninfo);
				if(ret == 0)
				{
					printf("Version infor:%s\n",versioninfo);
				}
				else
				{
					printf("Get Version infor error\n");
				}
				break;
			default:
				break;
		};
	}

	return 0;
}
