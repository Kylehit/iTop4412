/**
 * @brief      
 * @file     esp8266.h
 * @author   cc
 * @version  
 * @date     Sat 30 Jun 2018 11:17:55 PM PDT
 * @mail     13568859409@163.com 
 * @note     
 */

#ifndef _ESP8266_H
#define _ESP8266_H

/**
 *@brief Esp8266模块初始化
 *@return 成功：0	失败：-1
 */
int Esp8266Init(void);

/**
 *@brief Esp8266模块发送密令
 *@param cmd:发送的密令字符串
 *@param ack:期待的应答结果，为空，则表示不需要等待应答
 *@return 成功：0	失败：-1
 */
int Esp8266SendCmd(const char *cmd,const char *ack);

/**
 *@brief Esp8266模块发送数据
 *@param cmd:发送的数据字符串,此时不需要添加回车
 *@param ack:期待的应答结果，为空，则表示不需要等待应答
 *@return 成功：0	失败：-1
 */
int Esp8266SendData(const char *data,const char *ack);

/**
 *@brief Esp8266模块重启
 *@return 成功：0	失败：-1
 */
int Esp8266Reseat(void);

/**
 *@brief Esp8266版本信息
 *@param info:版本信息
 *@return 成功：0	失败：-1
 *@note 只有当成功调用时，info信息才有效
 */
int Esp8266VersionInfo(char *info);



#endif  /* _ESP8266_H */

