/**
  ******************************************************************
  *FileName:		Thread_clean.c
  *Descripation: 	Thread clean source file program body
  *Revision:		V1.0
  *Date:			2017-11-23
  *Author:			JinLiang Zhong
  ******************************************************************
  *Copyright @2017 Shenzhen univerisity
  *All right reserved
 **/
  #include<stdio.h>
  #include<pthread.h>

  void *clean(void *arg)
  {
  	printf("clean up:%s\n",(char *)arg);
  	return (void*)0;
  }

  void *thr_fn1(void *arg)
  {
  	printf("Thread1 start\n");
  	pthread_cleanup_push((void *)clean,"thread1 first handler");
  	pthread_cleanup_push((void *)clean,"thread1 second handler");
  	printf("thread1 push complete\n");
  	if (arg)
  	{
  		/* code */
  		return((void *)1);
  	}
  	pthread_cleanup_pop(1);
  	pthread_cleanup_pop(1);
  	return(void *)2;
  }

  void *thr_fn2(void *arg)
  {
  	printf("Thread2 start\n");
  	pthread_cleanup_push((void *)clean,"thread2 first handler");
  	pthread_cleanup_push((void *)clean,"thread2 second handler");
  	printf("thread2 push complete\n");
  	if (arg)
  	{
  		/* code */
  		return((void *)3);
  	}
  	pthread_cleanup_pop(1);
  	pthread_cleanup_pop(0);
  	return(void *)4;
  }

  int main(int argc, char const *argv[])
  {
  	
  	int res;
  	pthread_t tid1,tid2;
  	void *temp;
  	/*************** thread1 new*****************************/
  	res = pthread_create(&tid1,NULL,thr_fn1,(void *)1);
  	if (res!=0)
  	{
  		/* code */
  		printf("Create thread error...\n");
  		return -1;
  	}
  	/*************** thread2 new*****************************/
  	res = pthread_create(&tid2,NULL,thr_fn2,(void *)0);
  	if (res!=0)
  	{
  		/* code */
  		printf("Create thread error...\n");
  		return -1;
  	}
    /*************** thread1 wait exit*****************************/
    res=pthread_join(tid1,&temp);
    if (res !=0)
    {
    	/* code */
    	printf("Thread_join error\n");
      return -1;
    }
    printf("Thread1 exit code:%d\n",(int)temp);
    /*************** thread2 wait exit*****************************/
    res=pthread_join(tid2,&temp);
    if (res !=0)
    {
      /* code */
      printf("Thread_join error\n");
      return -1;
    }
    printf("Thread2 exit code:%d\n",(int)temp);
  	return 0;
  }