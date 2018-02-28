/**
 * @brief      
 * @file     rfid-test.c
 * @author   cc
 * @version  
 * @date     Wed 28 Feb 2018 05:03:34 AM PST
 * @mail     13568859409@163.com 
 * @note     
 */

#include <stdio.h>
#include "rfid-rc522.h"

int main(int argc,char **argv)
{
	unsigned char UID[5], Temp[4];
	unsigned long num = 0;
	int i;
	int ret;
	ret = OpenRc522Dev();
	if(ret != 0)
	{
		printf("Open Rc522 Dev Error\n");
		return -1;
	}

	ret = Rc522Init();
	if(ret != 0)
	{
		printf("Rc522 Init Error\n");
		return -1;
	}

	while(1)
	{
		if(Rc522Request(0x52,Temp) == MI_OK)			//寻卡
		{
			if(Temp[0]==0x04 && Temp[1]==0x00)  
				printf("MFOne-S50\n");
			else if(Temp[0]==0x02 && Temp[1]==0x00)
				printf("MFOne-S70\n");
			else if(Temp[0]==0x44 && Temp[1]==0x00)
				printf("MF-UltraLight\n");
			else if(Temp[0]==0x08 && Temp[1]==0x00)
				printf("MF-Pro\n");
			else if(Temp[0]==0x44 && Temp[1]==0x03)
				printf("MF Desire\n");
			else
				printf("Unknown\n");
			
			if(Rc522Anticoll(UID) == MI_OK)		//防冲突
			{ 
				printf("Card Id is(%d):", num++);
				for(i=0; i<4; i++)
					printf("%x", UID[i]);
				printf("\n");
				
				Rc522Request(0x52,Temp);//clear
			}
			else
			{
				printf("no serial num read\n");
			}
		}
		else
		{
			printf("No Card!\n");
		}

		usleep(300000);
	
	
	}
	return 0;
}
