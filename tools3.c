#include <stdio.h>
#include "tools3.h"
#include "main.h"
#include <unistd.h>
#include <string.h>
#include <getch.h>

Tch_exit tch_exit[100];

//重置管理员自身密码
void reset_admin(void)
{
	master_password[0]='\0';
	printf("已重置！\n");
	sleep(3);
}

//重置教师密码
void reset_tch(void)
{
	char name[20];
	int cnt=0;
	printf("请输入需要重置的教师姓名:\n");
	scanf("%s",name);
	while(tch[cnt].sex)
	{
		if(!strcmp(name,tch[cnt].name))
		{
			tch[cnt].password[0]='\0';
			tch[cnt].lock=0;
		}
		cnt++;
	}
	printf("重置成功！\n");
	sleep(3);
}

//添加教师
void add_tch(void)
{
	int N;
	printf("请输入您想录入的教师人数\n");
	scanf("%d",&N);
	printf("请输入教师信息(姓名 工号 性别):\n");
	for(int i=0;i<N;i++)
	{
		int cnt=0;
		while(tch[cnt].sex) cnt++;
		scanf("%s%s",tch[cnt].name,tch[cnt].id);
		getchar();
		tch[cnt].sex=getchar();
	}
	printf("录入成功！\n");
	sleep(3);
}

//删除教师
void del_tch(void)
{
	char name[20];
	int cnt=0,k=0;
	printf("请输入您想删除的教师姓名:\n");
	scanf("%s",name);
	while(tch[cnt].sex)
	{
		if(!strcmp(name,tch[cnt].name))
		{
			while(tch_exit[k].sex) k++;
			strcpy(tch_exit[k].name,tch[cnt].name);
			tch_exit[k].sex=tch[cnt].sex;
			strcpy(tch_exit[k].id,tch[cnt].id);
			tch[cnt].sex='\0';
		}
		cnt++;
	}
	printf("删除成功！\n");
	sleep(3);
}

//显示所有在职教师
void view(void)
{
	int cnt=0;
	for(;cnt<100;cnt++)
	{
		if(tch[cnt].sex)
		{
			printf("   %s %s %c\n",tch[cnt].name,tch[cnt].id,tch[cnt].sex);
			printf("-------------------------------\n");
		}
	}
	getch();
}

//显示所有离职教师
void view_exit(void)
{
	int cnt=0;
	while(tch_exit[cnt].sex)
	{
		printf("   %s %c %s\n",tch_exit[cnt].name,tch_exit[cnt].sex,tch_exit[cnt].id);
		printf("-------------------------------\n");
		cnt++;
	}
	getch();
}
