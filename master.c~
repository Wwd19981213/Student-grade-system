#include <stdio.h>
#include "master.h"
#include <unistd.h>
#include "tools3.h"
#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <getch.h>

char master_password[20];

void master(void)
{
	char password[20];
	if(0 == master_password[0])
	{
		printf("这是您第一次登录，请设置您的密码:\n");
		scanf("%s",master_password);
		printf("设置成功，请重新登录！\n");
		sleep(3);
	}
	else
	{
		while(1)
		{
			printf("请输入您的密码:\n");
			scanf("%s",password);
			if(!strcmp(password,master_password))
			{
				printf("密码正确！\n");
				sleep(3);
				for(;;)
				{
					system("clear");
					printf("1、重置密码\n");
					printf("2、重置教师密码\n");
					printf("3、添加教师\n");
					printf("4、删除教师\n");
					printf("5、显示所有在职教师\n");
					printf("6、显示所有离职教师\n");
					printf("7、退出管理员模式\n");
					switch(getch())
					{
						case '1':reset_admin();break;
						case '2':reset_tch();break;
						case '3':add_tch();break;
						case '4':del_tch();break;
						case '5':view();break;
						case '6':view_exit();break;
						case '7':return;
					}
				}
			}
			else
			{	
				printf("密码错误,请重试!\n");
			}
		}
	}
}
