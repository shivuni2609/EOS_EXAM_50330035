#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include <stdio.h> 
#include <sys/mman.h>        /* For mode constants */
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <semaphore.h>

  mqd_t s1;
    int fd,i;
    char *mqd_ptr;
    mqd_init(&s1,1,1);
    unsigned char buff[100];
int main(int argc , char const *argv[])
{
    s1_attr.mq_flags =0;
    s1_attr.mq_maxmsg =4;
    s1_attr.mq_msgsize =128;
    s1_attr.mq_surmsgs =0;

  

    fd=open("dictionary.txt",O_RDONLY ,S_IRUSR | S_IWUSR); 
    if (fd == -1)
    {
        perror("error-->Source not present \n");              //printf("%d",errno)-->errno 2
        printf("%d",errno);
    
    }  
    int mqd_fd;
    mqd_fd = mq_open("/dictionary",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    if(mqd_fd == -1)
    {
        perror("error msg \n");
    }
    mqd_ptr = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
    read(fd,buff,sizeof(buff));

    while(1)
    {
        sem_wait(&s1);
        for(i=0;i<(sizeof(buff));i++)
        {
            if(buff[i]=='m')
            *mqd_ptr = buff[i];
            mqd_ptr++;

        }
        sem_post(&s1);
    }
        
         mqd_unlink("/dictionary");
    sem_destroy(&s1);
    
    return 0;
}
