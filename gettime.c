#include<stdio.h>
#include<time.h>
int main()
{
    time_t nowtime;
    time(&nowtime);
    char* time2 = ctime(&nowtime);
    printf("%s\n",time2);
    return 0;
}
