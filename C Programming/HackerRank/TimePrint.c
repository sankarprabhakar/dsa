/*
 * TimePrint.c
 *
 *  Created on: Jun 9, 2016
 *      Author: sankarsa
 */


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int time_main(){
    char* time = (char *)malloc(10240 * sizeof(char));
    int hr = 0;
    char *mod_time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    int str = strlen(time);
    if(time[str-2] == 'A' && time[0] == '1' && time[1] == '2')
    {
        time[0] = '0';
        time[1] = '0';

    }
    else if(time[str-2] == 'P')
    {
    	if(! (time[0] != '1' && time[1] != '2'))
    	{
			time[2] = '\0';
			int timed = atoi(time);
			timed +=12;
			sprintf(time,"%0d",timed);
			time[2] = ':';
    	}
    }
    time[str-2] = '\0';
    printf("%s",time);


    return 0;
}
