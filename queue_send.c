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

	char buff[100];
	mqd_t queue_1 = mq_open("/Queue", O_CREAT | O_WRONLY, 0666, &attr);
	for(;;)
	{
		printf("Ingrese algo a enviar\n");
		fflush(stdin);
		char * str = fgets(buff, 100, stdin);
		if(NULL == str)
		{
			break;
		}
		int bytes_read = mq_send(queue_1, buff, 100, 2);
	}
	mq_close(queue_1);
	return 0;
}
