/********************************************************************
	> File Name: ./client_out.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月04日 星期三 23时43分45秒
 *******************************************************************/

#include "client.h"

int main(int argc,char* argv[])
{
	key_t shm_key,sem_key;
	int my_shm,my_sem;

	char line[1024];

	pMBUF p;
	shm_key=atoi(argv[1]);
	sem_key=atoi(argv[2]);

	my_shm=shmget(shm_key,sizeof(MBUF),0666);
	my_sem=semget(sem_key,1,0666);

	semctl(my_sem,0,SETVAL,1);

	p=(pMBUF)shmat(my_shm,NULL,0);
	memset(p,0,sizeof(MBUF));

	while(1)
	{
		while(P(my_sem),p->m_flag==0)
		{
			V(my_sem);
			sleep(1);
		}
		printf("%d:%s\n",getpid(),p->m_buf);
		if(strcmp(p->m_buf,"over")==0)
		{
			V(my_sem);
			break;
		}
		p->m_flag=0;
		V(my_sem);
	}
	shmdt(p);
}
