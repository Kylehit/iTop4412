/**
 * @brief      
 * @file     bigiot.h
 * @author   cc
 * @version  
 * @date     Wed 27 Jun 2018 01:02:14 AM PDT
 * @mail     13568859409@163.com 
 * @note     
 */

#ifndef _BIGIOT_H
#define _BIGIOT_H

//设备登录
void BigiotLogin(const char *,const char *);

//发送数据
//void BigiotSendData(const char *,const char *,const char *,...);

//接收数据
int BigiotRecvData(char *,int len);

//查询设备或者用户是否在线
void BigiotIsOnLine(const char *,...);

//查询当前设备状态
void BigiotStatus(void);

//查询服务器时间
void BigiotTime(void);

//发送报警信息
void BigiotAlertMessage(const char *,const char *);

//设备下线
void BigiotLogout(const char *,const char *);

#endif
