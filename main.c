#include <stdio.h>
#include <getch.h>
#include "master.h"
#include "main.h"
#include "stu.h"
#include "tch.h"
#include <stdlib.h>


int main(int argc,const char* argb[])
{
	//载入文件中所保存的数据
	FILE *fp;
	fp=fopen("data.txt","r");
	fread(master_password,sizeof(master_password),1,fp);
	fread(tch,sizeof(tch),1,fp);
	fread(tch_exit,sizeof(tch_exit),1,fp);
	fread(stu,sizeof(stu),1,fp);
	fread(stu_exit,sizeof(stu_exit),1,fp);
	fclose(fp);
	for(;;)
	{
		system("clear");
		printf("-------------------------------\n");
		printf("   欢迎使用指针学生管理系统！\n");
		printf("-------------------------------\n");	
		printf("   1、管理员子系统\n");
		printf("-------------------------------\n");
		printf("   2、教师子系统\n");
		printf("-------------------------------\n");
		printf("   3、学生子系统\n");
		printf("-------------------------------\n");
		printf("   4、退出系统\n");
		printf("-------------------------------\n");
		switch(getch())
		{
			case '1':master();break;
			case '2':teacher();break;
			case '3':student();break;
			case '4':
				//将数据保存在文件中
				fp=fopen("data.txt","w");
				fwrite(master_password,sizeof(master_password),1,fp);
				fwrite(tch,sizeof(tch),1,fp);
				fwrite(tch_exit,sizeof(tch_exit),1,fp);
				fwrite(stu,sizeof(stu),1,fp);
				fwrite(stu_exit,sizeof(stu_exit),1,fp);
				fclose(fp);
				return 0;
		}
	}
}
