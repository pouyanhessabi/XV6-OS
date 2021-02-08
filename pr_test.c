#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{  
    char *tmp = argv[1];
    int num = atoi(tmp);
    int pr = 0;
    int pid[30];
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
        for (int i = 0; i < 30; i++){
            pid[i] = waitAndReturnTime(i);
            // printf(1, "\n\nmy id is %d\ncreation time : %d\ntermination time : %d\nrunning time : %d\nready time : %d\nsleeping time : %d\n\n", pid[i], getCreationUpdate(i), getTerminationUpdate(i), getRunningUpdate(i), getReadyUpdate(i), getSleepUpdate(i));
            avg_creationTime += getCreationUpdate(i);
            avg_terminationTime += getTerminationUpdate(i);
            avg_runningTime += getRunningUpdate(i); 
            avg_readyTime += getReadyUpdate(i);
            avg_sleepingTime += getSleepUpdate(i);
        }
        for (int i = 0; i < 30; i++)
            printf(1, "\n\nmy id is %d\ncreation time : %d\ntermination time : %d\nrunning time : %d\nready time : %d\nsleeping time : %d\n\n", pid[i], getCreationUpdate(i), getTerminationUpdate(i), getRunningUpdate(i), getReadyUpdate(i), getSleepUpdate(i));
        avg_creationTime = avg_creationTime / 30;
        avg_terminationTime /= 30;
        avg_runningTime /= 30;
        avg_readyTime /= 30;
        avg_sleepingTime /= 30;
        printf(1, "avg creation : %d \navg termination : %d \navg running : %d \navg ready : %d \navg sleeep : %d\n", avg_creationTime, avg_terminationTime, avg_runningTime, avg_readyTime, avg_sleepingTime);
        int cbt = avg_runningTime;
        int waitingTime = avg_readyTime + avg_sleepingTime;
        int turnAroundTime = avg_terminationTime - avg_creationTime;
        printf(1, "\n\nQuantum is %d\n\nCBT(running state): %d\nWaiting time(ready + sleep): %d\nturnarround time(termmination - creation): %d\n", 10, cbt, waitingTime, turnAroundTime);
    }










    //loop for round-robin test
    if (num == 3)
    {
        for (int i = 0; i < 30; i++)
        {
            pid[i] = 0;
            if (fork() == 0)
            {
                for (int j = 0; j < 250; j++)
                {
                    printf(1, "pi %d : %d\n", getpid(), j);
                }
                
                exit();
            }
        }
        for (int i = 0; i < 30; i++){
            pid[i] = waitAndReturnTime(i);
            // printf(1, "\n\nmy id is %d\ncreation time : %d\ntermination time : %d\nrunning time : %d\nready time : %d\nsleeping time : %d\n\n", pid[i], getCreationUpdate(i), getTerminationUpdate(i), getRunningUpdate(i), getReadyUpdate(i), getSleepUpdate(i));
            avg_creationTime += getCreationUpdate(i);
            avg_terminationTime += getTerminationUpdate(i);
            avg_runningTime += getRunningUpdate(i); 
            avg_readyTime += getReadyUpdate(i);
            avg_sleepingTime += getSleepUpdate(i);
       
        }
        for (int i = 0; i < 30; i++)
            printf(1, "\n\nmy id is %d\ncreation time : %d\ntermination time : %d\nrunning time : %d\nready time : %d\nsleeping time : %d\n\n", pid[i], getCreationUpdate(i), getTerminationUpdate(i), getRunningUpdate(i), getReadyUpdate(i), getSleepUpdate(i));
        avg_creationTime = avg_creationTime / 30;
        avg_terminationTime /= 30;
        avg_runningTime /= 30;
        avg_readyTime /= 30;
        avg_sleepingTime /= 30;
        printf(1, "avg creation : %d \navg termination : %d \navg running : %d \navg ready : %d \navg sleeep : %d\n", avg_creationTime, avg_terminationTime, avg_runningTime, avg_readyTime, avg_sleepingTime);
        int cbt = avg_runningTime;
        int waitingTime = avg_readyTime + avg_sleepingTime;
        int turnAroundTime = avg_terminationTime - avg_creationTime;
        printf(1, "\n\nQuantum is %d\n\nCBT(running state): %d\nWaiting time(ready + sleep): %d\nturnarround time(termmination - creation): %d\n", 10, cbt, waitingTime, turnAroundTime);
    }
    while (wait() != -1)
    {
    }

    sleep(1);
    exit();
}