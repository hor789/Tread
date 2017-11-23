/**
   *******************************************************
   *FileName:  Thread_Creat.c
   *Description: Creat thread source file program body
   *Revision: V1.0
   *Date:   2017-11-22
   *Author: JinLiang Zhong
   *******************************************************
   *Copyright @2017 Shenzhen univerisity
   *All right reserved
**/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

/**Thread1**/
void *task1()
{
 int i;
 for(i=0;i<5;i++)
 {
  printf("I am task1\n");
  sleep(1);
 }
}
/**Thread2**/
void *task2()
{
 int i;
 for(i=0;i<5;i++)
 {
  printf("I am task2\n");
  sleep(1);
 }
}

int main()
{
 pthread_t id1,id2; 
 int status;
 status=pthread_create(&id1,NULL,(void *)task1,NULL);
 if(status)
 {
	printf("Create thread error!\n");
	return 1;
 }
 status=pthread_create(&id2,NULL,(void *)task2,NULL);
 if(status)
 {
	printf("Create thread error!\n");
	return 1;
 }
 pthread_join(id1,NULL);
 pthread_join(id2,NULL);
 return 1;
}
