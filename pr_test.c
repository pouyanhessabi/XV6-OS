#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{  
    char *tmp = argv[1];
    int num = atoi(tmp);
    int pr = 0;
    changePolicy(num);
    int avg_creationTime = 0, avg_terminationTime = 0, avg_runningTime = 0, avg_readyTime = 0, avg_sleepingTime = 0;
    if (num == 2)
    {
        for (int i = 0; i < 30; i++)
        {
            if (i < 5)
                pr = 6;
            else if (i < 10)
            {
                pr = 5;
            }
            else if (i < 15)
            {
                pr = 4;
            }
            else if (i < 20)
            {
                pr = 3;
            }
            else if (i < 25)
            {
                pr = 2;
            }
            else if (i < 30)
            {
                pr = 1;
            }

            if (fork() == 0)
            {
                set_priority(getpid(), pr);

                for (int j = 0; j < 250; j++)
                {

                    printf(1, "\n child :  %d\n", getpid());

                    /*printf(1," pr :  %d\n",pr);*/
                }
                exit();
            }
        }
    }
    //loop for round-robin test
    int pid[10];
    if (num == 3)
    {
        for (int i = 0; i < 10; i++)
        {
            pid[i] = 0;
            if (fork() == 0)
            {
                for (int j = 0; j < 1000; j++)
                {
                    printf(1, "pi %d : %d\n", getpid(), j);
                }
                
                exit();
            }
        }
        for (int i = 0; i < 10; i++){
            pid[i] = waitAndReturnTime(i);
            // printf(1, "pid %d, %d \n", pid[i], creationTime[i]);
            avg_creationTime += creationTime[i];
            avg_terminationTime += terminationTime[i];
            avg_runningTime += runningTime[i]; 
            avg_readyTime += readyTime[i];
            avg_sleepingTime += sleepingTime[i];
       
        }
        num = pid[3];
        printf(1, "avg creation : %d \navg termination : %d \navg running : %d \navg ready : %d \navg sleeep : %d\n", avg_creationTime, avg_terminationTime, avg_runningTime, avg_readyTime, avg_sleepingTime);
        avg_creationTime = avg_creationTime / 10 ;
        avg_terminationTime /= 10;
        avg_runningTime /= 10;
        avg_readyTime /= 10;
        avg_sleepingTime /= 10;
    }

    while (wait() != -1)
    {
    }

    sleep(1);
    exit();
}