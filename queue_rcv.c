#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>

int main(int args, char * argv[])
{
	struct mq_attr attr;
	attr.mq_maxmsg = 20;
	attr.mq_msgsize = 100;
	attr.mq_flags = 0;
	attr.mq_curmsgs = 0;
	
	int prio;

	char buff[100];
	mqd_t queue_1 = mq_open("/Queue", O_CREAT | O_RDONLY, 0666, &attr);
	for(;;)
	{
		int bytes_read = mq_receive(queue_1, buff, 100, &prio);
		printf("El mensaje es: %s\n", buff);
	}
	mq_close(queue_1);
	mq_unlink("/Queue");
	return 0;
}
