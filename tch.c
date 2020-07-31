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
	int cnt,cnt_false=0;
	printf("请输入您的姓名\n");
	scanf("%s",name);
	for(cnt=0;cnt<100;cnt++)
	{
		if(tch[cnt].sex)
		{
			if(!strcmp(tch[cnt].name,name))
			{
				//若tch[cnt].lock为1,则帐号已锁定
				if(tch[cnt].lock)
				{
					printf("帐号已锁定\n");
					sleep(3);
					return;
				}
				if(tch[cnt].password[0])
				{
					while('\n'!=getchar());
					while(cnt_false<3)
					{
						printf("请输入您的密码\n");
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
								printf("6、学生成绩排名\n");
								printf("7、重置学生密码\n");
								printf("8、显示所有在校学生信息\n");
								printf("9、显示所有退出学生信息\n");
								printf("0、退出帐号\n");
								switch(getch())
								{
									case '1':add();break;
									case '2':del();break;
									case '3':found();break;
									case '4':modify();break;
									case '5':input();break;
									case '6':rank();break;
									case '7':reset();break;
									case '8':view_online();break;
									case '9':view_offline();break;
									case '0':return;
								}
							}
						}
						else
						{
							printf("密码错误！\n");
							cnt_false++;
						}
					}
					tch[cnt].lock=1;
					printf("帐号已锁定！\n");
					sleep(3);
					return;	
				}
				else
				{
					printf("这是您第一次登录，请设置您的密码！:\n");
					while('\n'!=getchar());
					scanf("%s",tch[cnt].password);
					printf("设置成功！请重新登录！\n");
					sleep(3);
					return;
				}
			}
		}
	}
	//若直至退出循环仍未找到该用户名，则此人尚未录入
	printf("查无此人！\n");
	sleep(3);
}
