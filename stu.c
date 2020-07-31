#include <stdio.h>
#include "stu.h"
#include <stdlib.h>
#include "main.h"
#include "tools2.h"
#include <getch.h>
#include <string.h>
#include <unistd.h>

Stu stu[100];

void student(void)
{
	char name[10],password[10];
	int cnt=0,cnt_false=0;
	printf("请输入您的姓名\n");
	scanf("%s",name);
	while(0 != stu[cnt].sex)
	{
		if(!strcmp(stu[cnt].name,name))
		{
			//若stu[cnt].lock为1,则帐号已锁定
			if(stu[cnt].lock)
			{
				printf("帐号已锁定\n");
				sleep(3);
				return;
			}
			if(0 == stu[cnt].password[0])
			{
				printf("这是你第一次登录，请设置你的密码:");
				while('\n'!=getchar());
				scanf("%s",stu[cnt].password);
				printf("设置完成!\n");
				sleep(3);
				return;
			}
			else
			{
				while('\n'!=getchar());
				//若错误次数超过3次则锁定帐号
				while(cnt_false<3)
				{
					printf("请输入你的密码:");
					gets(password);
					if(!strcmp(password,stu[cnt].password))
					{
						printf("密码正确!\n");
						sleep(3);
						for(;;)
						{
							system("clear");
							printf("-------------------------------\n");
							printf("   1、查询成绩\n");
							printf("-------------------------------\n");
							printf("   2、修改密码\n");
							printf("-------------------------------\n");
							printf("   3、查询个人信息\n");
							printf("-------------------------------\n");
							printf("   4、退出帐号\n");
							printf("-------------------------------\n");
							switch(getch())
							{
								case '1':chagrade(cnt);break;
								case '2':change(cnt);break;
								case '3':chainf(cnt);break;
								case '4':return;
							}
						}
					}
					else
					{
						printf("密码错误!");
						cnt_false++;
					}
				}
				stu[cnt].lock=1;
				printf("帐号已锁定\n");
				getch();
				return;
			}
		}
		cnt++;
	}
	//若直至退出循环仍未找到该用户名，则此人尚未录入
	printf("查无此人！\n");
	sleep(3);
}
