#include <stdio.h>
#include "tools.h"
#include "main.h"
#include <unistd.h>
#include <getch.h>
#include <string.h>

Stu_exit stu_exit[100];

//添加学生
void add(void)
{
	printf("请输入学生信息:\n");
	int cnt=0;
	while(0 != stu[cnt].sex) cnt++;
	scanf("%c%s",&stu[cnt].sex,stu[cnt].name);
	stu[cnt].num=cnt;
	printf("录入成功\n");
	sleep(3);
}

//删除学生
void del(void)
{
	printf("请输入要删除学生的学号:\n");
	int num=0;
	scanf("%d",&num);
	int cnt=0;
	while(stu_exit[cnt].sex) cnt++;
	strcpy(stu_exit[cnt].name,stu[num].name);
	stu_exit[cnt].sex=stu[num].sex;
	stu_exit[cnt].num=stu[num].num;
	stu[num].sex=0;
}

//查找学生
void found(void)
{
	printf("请选择查找方式:");
	char key;
	scanf("%c",&key);
	if(key == 'n')
	{
		char name[20];
		int cnt=0;
		printf("请输入要查询的姓名:");
		scanf("%s",name);
		while(stu[cnt].sex)
		{
			if(!strcmp(stu[cnt].name,name))
			{
				printf("%s %c %d %d %d %d",stu[cnt].name,stu[cnt].sex,stu[cnt].num,stu[cnt].chinese,stu[cnt].math,stu[cnt].english);
				getch();
				getch();
				return;
			}
			cnt++;
		}
		printf("查无此人\n");
		getch();
		getch();
	}
	else if(key == 'm')
	{
		int num;
		printf("请输入要查询的学号");
		scanf("%d",&num);
		if(0 != stu[num].sex)
		{
			printf("%s %c %d %d %d %d",stu[num].name,stu[num].sex,stu[num].num,stu[num].chinese,stu[num].math,stu[num].english);
			getch();
		}
		else
		{
			printf("查无此人\n");
			getch();
		}
	}
}

//修改学生信息
void modify(void)
{
	char name[20];
	printf("请输入要修改的学生姓名:\n");
	scanf("%s",name);
	int cnt=0;
	while(stu[cnt].sex)
	{			
		if(!strcmp(stu[cnt].name,name))
		{
			break;
		}
		cnt++;
	}
	printf("请输入修改信息(c/m/e)\n");
	char subject;
	int score;
	scanf("%c %d",&subject,&score);
	switch(subject)
	{
		case 'c':stu[cnt].chinese=score;break;
		case 'm':stu[cnt].math=score;break;
		case 'e':stu[cnt].english=score;break;
	}
}

//录入学生成绩
void input(void)
{
	char name[20];
	int N;
	printf("请输入想录入的学生个数\n");
	scanf("%d",&N);
	printf("请开始录入:\n");
	for(int i=0;i<N;i++)
	{
		int cnt=0;
		scanf("%s",name);
		while(stu[cnt].sex)
		{
			if(!strcmp(stu[cnt].name,name))
			{
				scanf("%d%d%d",&stu[cnt].chinese,&stu[cnt].math,&stu[cnt].english);
			}
			cnt++;
		}
	}
	printf("录入成功！\n");
	sleep(3);
}

//重置学生密码
void reset(void)
{
	char name[20];
	printf("请输入您想重置的学生姓名:\n");
	scanf("%s",name);
	for(int cnt=0;cnt<100;cnt++)
	{
		if(!strcmp(stu[cnt].name,name))
		{
			stu[cnt].password[0]='\0';
			break;
		}
	}
}

//显示所有在校学生信息
void view_online(void)
{
	int cnt=0;
	while(0 != stu[cnt].sex)
	{
		printf("%s %c %d %d %d %d\n",stu[cnt].name,stu[cnt].sex,stu[cnt].num,stu[cnt].chinese,stu[cnt].math,stu[cnt].english);
		cnt++;
	}
	getch();
}

//显示所有退出学生信息
void view_offline(void)
{
	int cnt=0;
	while(stu_exit[cnt].sex)
	{
		printf("%s %c %d",stu_exit[cnt].name,stu_exit[cnt].sex,stu_exit[cnt].num);
		cnt++;
	}
	getch();
}
