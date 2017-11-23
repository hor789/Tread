/**
   *******************************************************
   *FileName:		thread_self.c
   *Descripation:	Get thread id source file program body
   *Revsion:		V1.0
   *Date:			2017-11-23
   *Author:			Jinliang Zhong
   *******************************************************
    * Copyright @2017 Shenzhen University
    * All right reserved
**/
    #include<stdio.h>
    #include<pthread.h>
    void *create(void *arg)
    {

    	printf("New thread...\n");
    	printf("This thread's id %u\n",(unsigned int)pthread_self());
    	printf("this thread process pid is %d\n",getpid());
        return NULL;
    }

    int main(int argc, char const *argv[])
    {
    	/* code */
    	pthread_t tid;
    	printf("Main thread is starting...\n");
    	int res = pthread_create(&tid,NULL,create,NULL);
    	if(res)
    	{
          printf("thread is not create...\n");
          return -1;
    	}
    	printf("The main process pid is %d\n",getpid());
    	sleep(1);
    	return 0;
    }