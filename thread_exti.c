/**
  ******************************************************************
  *FileName:Thread_exti.c
  *Descripation: Thread exti source file program body
  *Revision:V1.0
  *Date:2017-11-23
  *Author:JinLiang Zhong
  ******************************************************************
  *Copyright @2017 Shenzhen univerisity
  *All right reserved
 **/
#include<stdio.h>
#include<pthread.h>
void *create(void *arg)
{
 printf("New thread is created...\n");
 pthread_exit((void *)6);
}

int main()
{
 pthread_t tid;
 int res;
 void *temp;
 res=pthread_create(&tid,NULL,create,NULL);
 printf("I am the main thread!\n");
 if(res)
 {
  printf("thread is not created...\n");
  return -1; 
 }
 res=pthread_join(tid,&temp);
 if(res)
 {
   printf("Thread is not exit...\n");
   return -2;
 }
 printf("Thread is exit code %d \n",(int)temp);
 return 0;
}









