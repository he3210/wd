/********************************************************************
	> File Name: /home/he/Desktop/CODE/20150204/my_shm/shm2/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月04日 星期三 10时37分07秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(int argc,char* argv[])
{
	key_t my_key;
	int my_shm;
	char* pstr;

	my_key=ftok("./my_shm1.c",123);
	my_shm=shmget(my_key,1024,0666);
	if(my_shm== -1)
	{
		perror("shmget");
		exit(1);
	}
	pstr=(char*)shmat(my_shm,NULL,0);
	printf("shm:%s\n",pstr);
	shmdt(pstr);
	shmctl(my_shm,IPC_RMID,NULL);
	return 0;
}
