/**
   *******************************************************
   *FileName:thread_join.c
   *Descripation:Thread wait it ended source file program body
   *Revsion:V1.0
   *Date:2017-11-23
   *Author:Jinliang Zhong
   *******************************************************
    * Copyright @2017 Shenzhen University
    * All right reserved
**/
    #include<stdio.h>
    #include<pthread.h>
    void *create(void *arg)
    {

    	int i;
    	for(i=0;i<4;++i)
    	{

    		sleep(2);
    		printf("This is the thead:%d\n",i);
    	}
    	return NULL;
    }

    int main(int argc, char const *argv[])
    {
    	/* code */
    	pthread_t tid;
    	int i;
    	int res=pthread_create(&tid,NULL,create,NULL);
    	pthread_join(tid,NULL);
    	printf("123\n");
    	for(i=0;i<3;++i)
    	{
    		sleep(1);
    		printf("This is the main:%d\n",i);
    	}
    	return 0;
    }