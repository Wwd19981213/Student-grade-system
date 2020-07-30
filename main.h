#ifndef MAIN_H
#define MAIN_H

typedef struct Tch
{
	char name[10];
	char sex;
	char id[20];
	char password[20];
	int lock;
}Tch;

typedef struct Tch_exit
{
	char name[10];
	char sex;
	char id[20];
}Tch_exit;

typedef struct Stu
{
	char name[10];
	char sex;
	int num;
	char password[10];
	int chinese;
	int math;
	int english;
	int lock;
}Stu;

typedef struct Stu_exit
{
	char name[10];
	char sex;
	int num;
}Stu_exit;

extern char master_password[20];
extern Tch tch[100];
extern Tch_exit tch_exit[100];
extern Stu stu[100];
extern Stu_exit stu_exit[100];

#endif//MAIN_H
