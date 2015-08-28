#include  "power.h"

void power_init()
{
    GPIO_InitTypeDef  gpio_init                          ;  

    GPIO_StructInit((GPIO_InitTypeDef*)&gpio_init)       ;
    GPIO_Init(GPIOA, &gpio_init)                         ; 
    GPIO_Init(GPIOB, &gpio_init)                         ; 
    GPIO_Init(GPIOC, &gpio_init)                         ; 
    RCC_AHBPeriphClockCmd(
                      RCC_AHBPeriph_GPIOA                |
                      RCC_AHBPeriph_GPIOB                |
                      RCC_AHBPeriph_GPIOC                ,
                      DISABLE)                           ; 
    
    RCC_AHBPeriphClockCmd(Power_PCLOCK, ENABLE)          ; 
    
    gpio_init.GPIO_Speed = GPIO_Speed_2MHz               ;   
    gpio_init.GPIO_Pin = Power_5_Pin                     ;  
    gpio_init.GPIO_Mode = GPIO_Mode_OUT                  ;  
    gpio_init.GPIO_OType = GPIO_OType_PP                 ;        
    gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL               ;  
    GPIO_Init(Power_5_PType, &gpio_init)                 ;  
    gpio_init.GPIO_Speed = GPIO_Speed_2MHz               ;   
    gpio_init.GPIO_Pin = Power_3_3_Pin                   ;  
    gpio_init.GPIO_Mode = GPIO_Mode_OUT                  ;  
    gpio_init.GPIO_OType = GPIO_OType_PP                 ;        
    gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL               ;  
    GPIO_Init(Power_3_3_PType, &gpio_init)               ;      
}

void Clock_Resume()
{
    RCC_HSEConfig(RCC_HSE_ON)                             ;
    while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET) {}
    RCC_PLLCmd(ENABLE)                                    ;
    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) {}
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK)             ;
    while (RCC_GetSYSCLKSource() != 0x0C) {}  
}
void Cat24c_PowerOff(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure                   ;   
//     RCC_AHBPeriphClockCmd(IIC_Pin_CLOCK, ENABLE)           ;     
    GPIO_InitStructure.GPIO_Pin = IIC_SDA_Pin              ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN            ;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP          ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_400KHz      ;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP            ;
    GPIO_Init(IIC_SDA_PType, &GPIO_InitStructure)          ;
    
    GPIO_InitStructure.GPIO_Pin = IIC_SCL_Pin              ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN            ;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP          ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_400KHz      ;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP            ;
    GPIO_Init(IIC_SCL_PType, &GPIO_InitStructure)          ;
    
    GPIO_InitStructure.GPIO_Pin = IIC_WP_Pin               ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN            ;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP          ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_400KHz      ;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP            ;
    GPIO_Init(IIC_WP_PType, &GPIO_InitStructure)           ;   
}

void WP_PowerOff(void)
{
    GPIO_InitTypeDef GPIO_InitStructure                                 ;
    
    RCC_HSICmd(DISABLE)                                                 ;    
    GPIO_InitStructure.GPIO_Pin =  MEASUREMENT_PIN                      ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN                        ;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP                       ;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL                    ;
    GPIO_Init(MEASUREMENT_GPIO, &GPIO_InitStructure)                    ;
    ADC_PowerDownCmd(ADC_Source, ADC_PowerDown_Idle_Delay, DISABLE)     ;
    ADC_Cmd(ADC_Source, DISABLE)                                        ;	
}

void WP_DS18B20Off(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure                   ;     
    GPIO_InitStructure.GPIO_Pin = DS18B20_Pin              ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN            ;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP          ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_400KHz      ;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP            ;
    GPIO_Init(DS18B20_PType, &GPIO_InitStructure)          ;
}

void Mask_CatPin(void)
{
    SCL_L()                                                ;
    SDA_H()                                                ;
    WP_H()                                                 ;

}

 	


