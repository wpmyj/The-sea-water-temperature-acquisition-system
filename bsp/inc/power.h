#ifndef __POWER_H
#define __POWER_H

#include "bsp.h"


extern  void power_init(void);
extern  void Clock_Resume(void);
extern  void Cat24c_PowerOff(void);
extern  void WP_PowerOff(void);
extern  void WP_DS18B20Off(void);
extern  void Mask_CatPin(void);
#define  Power_5_ON()         GPIO_SetBits(Power_5_PType, Power_5_Pin) 
#define  Power_5_OFF()        GPIO_ResetBits(Power_5_PType, Power_5_Pin)
#define  Power_3_3_ON()       GPIO_SetBits(Power_3_3_PType, Power_3_3_Pin) 
#define  Power_3_3_OFF()      GPIO_ResetBits(Power_3_3_PType, Power_3_3_Pin)
#endif 
