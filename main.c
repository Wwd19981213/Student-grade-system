#include <stdio.h>
#include <getch.h>
#include "master.h"
#include "stu.h"
#include "tch.h"
#include <stdlib.h>

int main(int argc,const char* argb[])
{
	for(;;)
	{
		system("clear");
		printf("欢迎使用指针学生管理系统！\n");	
		printf("1、管理员子系统\n");
		printf("2、教师子系统\n");
		printf("3、学生子系统\n");
		printf("4、退出系统\n");
		switch(getch())
		{
			case '1':master();break;
			case '2':teacher();break;
			case '3':student();break;
			case '4':return 0;
		}
	}
}
