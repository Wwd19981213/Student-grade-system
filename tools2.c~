#include <stdio.h>
#include "tools2.h"
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <getch.h>

void chagrade(int num)
{
	int cnt=0;
	int high_c=0,low_c=100,sum_c=0;
	for(int i=0;i<100;i++)
	{
		if(stu[cnt].sex)
		{
			sum_c+=stu[cnt].chinese;
			cnt++;
			if(stu[cnt].chinese>high_c)
			{
				high_c=stu[cnt].chinese;
			}
			if(stu[cnt].chinese<low_c)
			{
				low_c=stu[cnt].chinese;
			}
		}
	}
	printf("语文：%d 最高分: %d 最低分：%d 平均分：%f\n",stu[num].chinese,high_c,low_c,sum_c*1.0/cnt);
	cnt=0;
	int high_m=0,low_m=100,sum_m=0;
	for(int i=0;i<100;i++)
	{
		if(stu[cnt].sex)
		{
			sum_m+=stu[cnt].math;
			cnt++;
			if(stu[cnt].math>high_m)
			{
				high_m=stu[cnt].math;
			}
			if(stu[cnt].math<low_m)
			{
				low_m=stu[cnt].math;
			}
		}
	}
	printf("数学：%d 最高分: %d 最低分：%d 平均分：%f\n",stu[num].math,high_m,low_m,sum_m*1.0/cnt);
	cnt=0;
	int high_e=0,low_e=100,sum_e=0;
	for(int i=0;i<100;i++)
	{
		if(stu[cnt].sex)
		{
			sum_e+=stu[cnt].english;
			cnt++;
			if(stu[cnt].english>high_e)
			{
				high_e=stu[cnt].english;
			}
			if(stu[cnt].english<low_e)
			{
				low_e=stu[cnt].english;
			}
		}
	}
	printf("英语：%d 最高分: %d 最低分：%d 平均分：%f\n",stu[num].english,high_e,low_e,sum_e*1.0/cnt);
	getch();
}

void change(int num)
{
	char password[20];
	printf("请输入原密码:\n");
	scanf("%s",password);
	if(!strcmp(password,stu[num].password))
	{
		printf("请输入新密码:\n");
		scanf("%s",stu[num].password);
		printf("修改成功!\n");
		sleep(3);
	}
	else
	{
		printf("密码错误！\n");
	}
}

void chainf(int num)
{
	printf("姓名：%s 性别：%c 学号:%d\n",stu[num].name,stu[num].sex,stu[num].num);
	getch();
}

