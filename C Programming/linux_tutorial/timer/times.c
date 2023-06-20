#include<stdio.h>
#include<time.h>
#include<sys/times.h>
#include<unistd.h>
int main()
{

struct tms stime,stime1;
clock_t time = times(&stime);
printf("Sankar P S\n");


int i = 100;
for(i = 1000000; i!=0 ; i--)
{
	//sleep(1);
	printf("dummy\n");
	;
}
//sleep(3);
//struct tms stime;
printf("Sysconfig = %u\n", sysconf(_SC_CLK_TCK));
//time =times(&stime1);
printf("Real time = %u\n", times(&stime1) - time);

printf("S=%lu \n",stime1.tms_stime - stime.tms_stime);
//printf("U=%jd \n",stime);
		//- stime.tms_stime);
printf("U=%lu \n",stime1.tms_utime - stime.tms_utime);
//printf("U=%lu \n",stime1.tms_stime - stime.tms_stime);

}
