#include <stdio.h>
#include <stdlib.h>
#include "tch.h"
#include "main.h"
#include <string.h>
#include <unistd.h>
#include <getch.h>
#include "tools.h"

Tch tch[100];

void teacher(void)
{
	char name[10],password[10];
	int cnt=0;
	printf("请输入您的姓名\n");
	scanf("%s",name);
	while(tch[cnt].sex)
	{
		if(!strcmp(tch[cnt].name,name))
		{
			if(tch[cnt].password[0])
			{
				printf("请输入您的密码\n");
				while('\n'!=getchar());
				gets(password);
				if(!strcmp(password,tch[cnt].password))
				{
					printf("密码正确！\n");
					sleep(3);
					for(;;)
					{
						system("clear");
						printf("1、添加学生\n");
						printf("2、删除学生\n");
						printf("3、查找学生\n");
						printf("4、修改学生信息\n");
						printf("5、录入学生成绩\n");
						printf("6、重置学生密码\n");
						printf("7、显示所有在校学生信息\n");
						printf("8、显示所有退出学生信息\n");
						printf("9、退出帐号\n");
						switch(getch())
						{
							case '1':add();break;
							case '2':del();break;
							case '3':found();break;
							case '4':modify();break;
							case '5':input();break;
							case '6':reset();break;
							case '7':view_online();break;
							case '8':view_offline();break;
							case '9':return;
						}
					}
				}
				else
				{
					printf("密码错误！\n");
				}
			}
			else
			{
				printf("这是您第一次登录，请设置您的密码！:\n");
				while('\n'!=getchar());
				scanf("%s",tch[cnt].password);
				printf("设置成功！请重新登录！\n");
				sleep(3);	
			}
		}
		cnt++;
	}
	printf("查无此人！\n");
	sleep(3);
}
