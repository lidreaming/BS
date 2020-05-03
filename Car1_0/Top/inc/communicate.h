/**
  ******************************************************************************
  * @file    communicate.h
  * @author  fire
  * @version V1.0
  * @date    2020-xx-xx
  * @brief   
  ******************************************************************************
  * @attention
  *
  * 实验平台:双创实验室-LZM
  * 
  * Wechat：qabc132321
  *
  ******************************************************************************
  */
#ifndef __COMMUNICATE_H
#define	__COMMUNICATE_H


#include "includes.h" 

/*UI同步*/
typedef struct _ui_t
{
	u8       Sync;                  //是否开启同步模式0：不开启
	
	u8       Step_Index;            //步长索引
	u8       Page_Index;            //页面索引
	u8       Page_Index_Last;       //上次页面索引
	u8       Para_Index;            //参数索引
	u8       Para_IfControl;        //参数是否可控

}ui_t;

/*********************** 外发 ***********************/

/*编码器*/
typedef struct
{
	int  motorA;
	int  motorB;
	int  motorC;
	int  motorD;
}encoder_t;
/*电机PWM*/
typedef struct
{
	int  pwmoutA;
	int  pwmoutB;
	int  pwmoutC;
	int  pwmoutD;
}motor_t;



/* 广播 */
extern encoder_t Encoder;
extern motor_t   Motorpwm;

/*********************** 接收 ***********************/
/*通讯数据结构*/
/*LED*/
typedef struct
{
	u8  name;
	u8  mode;
	int cycle;
}led_t;

/* LED种类的nameID 用于LED种类下data[2] */
#define NAME_LEDA 0x01
#define NAME_LEDB 0x02
#define NAME_FMQ  0x11

/* KEY种类的nameID 用于KEY种类下data[2] */
#define NAME_KEYU 0x01 /* 单击 */
#define NAME_KEYD 0x02
#define NAME_KEYL 0x03
#define NAME_KEYR 0x04
#define NAME_KEYM 0x05

/* 防爆墙 */
typedef struct _connect_t connect_t;
/* 广播 */
extern led_t carLEDA;
extern led_t carFMQ;
extern led_t envLEDA;
extern led_t envLEDB;
extern led_t envFMQ;
extern connect_t   uart1Connect;


void CommunicateParaInit(void);


#endif /* __USART_H */
