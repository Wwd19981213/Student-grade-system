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
	int N;
	printf("请输入您要添加的学生个数:\n");
	scanf("%d",&N);
	getchar();
	printf("请输入学生信息(性别 姓名):\n");
	for(int i=0;i<N;i++)
	{
		int cnt=0;
		while(stu[cnt].sex) cnt++;
		scanf("%c%s",&stu[cnt].sex,stu[cnt].name);
		getchar();
		stu[cnt].num=cnt;
	}
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
	printf("删除成功！\n");
	sleep(2);
}

//查找学生
void found(void)
{
	printf("请选择查找方式(n/m 姓名/学号):\n");
	char key;
	scanf("%c",&key);
	if(key == 'n')
	{
		char name[20];
		int cnt=0;
		printf("请输入要查询的姓名:\n");
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
		printf("请输入要查询的学号\n");
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
	char key;
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
	printf("请选择您要修改的信息（a/b 基础信息/成绩）\n");
	getchar();
	scanf("%c",&key);
	getchar();
	if('a' == key)
	{
		char inf;
		printf("请选择您要修改的信息(s/n 性别/学号)\n");
		scanf("%c",&inf);
		if('s' == inf)
		{
			printf("请输入您要修改的内容:\n");
			scanf("%c",&stu[cnt].sex);
			printf("修改成功！\n");
			sleep(3);
		}
		else
		{
			printf("请输入您要修改的内容\n");
			scanf("%d",&stu[cnt].num);
			printf("修改成功!\n");
			sleep(3);
		}
	}
	else
	{
		char subject;
		int score;
		printf("请输入您要修改的科目(c/m/e)\n");
		scanf("%c",&subject);
		printf("请输入您要修改的成绩\n");
		scanf("%d",&score);
		switch(subject)
		{
			case 'c':stu[cnt].chinese=score;break;
			case 'm':stu[cnt].math=score;break;
			case 'e':stu[cnt].english=score;break;
		}
		printf("修改成功！\n");
		sleep(2);
	}
}

//录入学生成绩
void input(void)
{
	char name[20];
	int N;
	printf("请输入想录入的学生个数\n");
	scanf("%d",&N);
	printf("请开始录入（姓名 语文 数学 英语）:\n");
	for(int i=0;i<N;i++)
	{
		int cnt=0;
		scanf("%s",name);
		while(stu[cnt].sex)
		{
			if(!strcmp(stu[cnt].name,name))
			{
				scanf("%d%d%d",&stu[cnt].chinese,&stu[cnt].math,&stu[cnt].english);
				stu[cnt].sum=stu[cnt].chinese+stu[cnt].math+stu[cnt].english;
			}
			cnt++;
		}
	}
	printf("录入成功！\n");
	sleep(3);
}

//学生成绩排名
void rank(void)
{
	Stu temp;
	int cnt=0;
	while(stu[cnt].sex) cnt++;
	for(int i=0;i<cnt-1;i++)
	{
		for(int j=cnt-1;j>0;j--)
		{
			if(stu[j].sum>stu[j-1].sum)
			{
				temp=stu[j];
				stu[j]=stu[j-1];
				stu[j-1]=temp;
			}
		}
	}
	for(int i=0;i<cnt;i++)
	{
		stu[i].rank=i;
	}
	printf("排名已完成！\n");
	getch();
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
			stu[cnt].lock=0;
			printf("重置成功！\n");
			sleep(3);
			break;
		}
	}
}

//显示所有在校学生信息
void view_online(void)
{
	for(int i=0;i<100;i++)
	{
		if(stu[i].sex)
		{
			printf("%s %c %d %d %d %d %d %d\n",stu[i].name,stu[i].sex,stu[i].num,stu[i].rank,stu[i].sum,stu[i].chinese,stu[i].math,stu[i].english);
		}
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
