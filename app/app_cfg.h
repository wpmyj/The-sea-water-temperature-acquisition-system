#define STARTUP_TASK_PRIO 4


#define TASK0_PRIO   5                        //�������ȼ�
#define TASK1_PRIO   6                        //�������ȼ�
#define TASK2_PRIO   7                        //�������ȼ�
#define TASK3_PRIO   5                        //�������ȼ�

/* task stack size */
#define STARTUP_TASK_STK_SIZE 80
#define TASK_STK_SIZE_0 64	                  //
#define TASK_STK_SIZE_1 256	                  //
#define TASK_STK_SIZE_2 256                   //
#define TASK_STK_SIZE_3 64	                  //



#define  Get_Data_Time             1        //��ȡʱ��
#define  Get_Time_Over             2        //�ɹ���ȡʱ�� 
#define  Work_Up_Water             3        //ˮ�Ϲ���
#define  Work_Down_Water           4        //ˮ�¹��� 
#define  Send_Ok                   5        //�ɹ����ͽ���
#define  Flash_Data                6        //����Flash����
#define  Flash_Data_W              7        //дFlash����
#define  Flash_Data_R              8        //��Flash����

#define  Start_Data_R              '&'       //������������
#define  Send_Data_Can             '^'       //���Է�������
#define  Send_Data_Over            '#'       //�����������

#define  Task_DS18B20              11       //�¶���������
#define  Task_AD                   12       //AD��������
#define  Task_Flash                13       //Flash��������
#define  Task_Time                 14       //ʱ����������
#define  Task_NRF                  15       //������������