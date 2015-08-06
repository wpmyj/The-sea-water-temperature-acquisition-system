#define STARTUP_TASK_PRIO 4


#define TASK0_PRIO   5                        //任务优先级
#define TASK1_PRIO   6                        //任务优先级
#define TASK2_PRIO   7                        //任务优先级
#define TASK3_PRIO   5                        //任务优先级

/* task stack size */
#define STARTUP_TASK_STK_SIZE 80
#define TASK_STK_SIZE_0 64	                  //
#define TASK_STK_SIZE_1 256	                  //
#define TASK_STK_SIZE_2 256                   //
#define TASK_STK_SIZE_3 64	                  //



#define  Get_Data_Time             1        //获取时间
#define  Get_Time_Over             2        //成功获取时间 
#define  Work_Up_Water             3        //水上工作
#define  Work_Down_Water           4        //水下工作 
#define  Send_Ok                   5        //成功发送接收
#define  Flash_Data                6        //发送Flash数据
#define  Flash_Data_W              7        //写Flash数据
#define  Flash_Data_R              8        //读Flash数据

#define  Start_Data_R              '&'       //告诉主机数据
#define  Send_Data_Can             '^'       //可以发生数据
#define  Send_Data_Over            '#'       //发送数据完成

#define  Task_DS18B20              11       //温度任务请求
#define  Task_AD                   12       //AD任务请求
#define  Task_Flash                13       //Flash任务请求
#define  Task_Time                 14       //时间任务请求
#define  Task_NRF                  15       //无线任务请求
