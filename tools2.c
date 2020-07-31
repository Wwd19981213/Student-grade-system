#include <stdio.h>
#include "tools2.h"
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <getch.h>

//查询学生个人成绩
void chagrade(int num)
{
	int cnt=0;
	int high_c=0,low_c=100,sum_c=0;
	printf("总分：%d  排名:%d  \n",stu[num].sum,stu[num].rank);
	for(int i=0;i<100;i++)
	{
		if(stu[i].sex)
		{
			sum_c+=stu[i].chinese;
			cnt++;
			if(stu[i].chinese>high_c)
			{
				high_c=stu[i].chinese;
			}
			if(stu[i].chinese<low_c)
			{
				low_c=stu[i].chinese;
			}
		}
	}
	printf("语文：%d 最高分: %d 最低分：%d 平均分：%f\n",stu[num].chinese,high_c,low_c,sum_c*1.0/cnt);
	cnt=0;
	int high_m=0,low_m=100,sum_m=0;
	for(int i=0;i<100;i++)
	{
		if(stu[i].sex)
		{
			sum_m+=stu[i].math;
			cnt++;
			if(stu[i].math>high_m)
			{
				high_m=stu[i].math;
			}
			if(stu[i].math<low_m)
			{
				low_m=stu[i].math;
			}
		}
	}
	printf("数学：%d 最高分: %d 最低分：%d 平均分：%f\n",stu[num].math,high_m,low_m,sum_m*1.0/cnt);
	cnt=0;
	int high_e=0,low_e=100,sum_e=0;
	for(int i=0;i<100;i++)
	{
		if(stu[i].sex)
		{
			sum_e+=stu[i].english;
			cnt++;
			if(stu[i].english>high_e)
			{
				high_e=stu[i].english;
			}
			if(stu[i].english<low_e)
			{
				low_e=stu[i].english;
			}
		}
	}
	printf("英语：%d 最高分: %d 最低分：%d 平均分：%f\n",stu[num].english,high_e,low_e,sum_e*1.0/cnt);
	getch();
}

//修改学生个人信息
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

//查找学生个人信息
void chainf(int num)
{
	printf("姓名：%s 性别：%c 学号:%d\n",stu[num].name,stu[num].sex,stu[num].num);
	getch();
}

