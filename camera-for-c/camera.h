/**
 * @brief      
 * @file     camera.h
 * @author   cc
 * @version  
 * @date     Mon 15 Jan 2018 21:44:50 CST
 * CST
 * @mail     13568859409@163.com 
 * @note     
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <sys/types.h>

//类相关参数初始化
void Camera(char *DEV_NAME,int w,int h);
int OpenDevice();//打开设备
void CloseDevice();
int GetBuffer(unsigned char *image);//获取数据流
unsigned int getImageSize();

#endif // CAMERA_H

