#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<sys/msg.h>

#define MAX 10
struct mesg_buffer
{
long mesg_type;
char mesg_text[100];
message;
}
int main()
{
key_t key;
int msgid;
key = ftok("program",65);
message.mesg_type=1;
printf("write:");
fgets(message.mesg_text,MAX,stdin);
msgnd(msgid,&message,sizeof(message),0);

printf("data send is:%s\n",message.mesg_text);
return 0;
}


