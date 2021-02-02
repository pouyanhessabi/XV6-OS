#include "types.h"
#include "stat.h"
#include "user.h"

int main() 
{ 
    int pr=0;
    for(int i=0;i<30;i++) // loop will run n times (n=5) 
    {   
        if(i<5)
            pr=6;
        else if (i<10)
        {
            pr=5;
        }
        else if (i<15)
        {
            pr=4;
        }
        else if (i<20)
        {
            pr=3;
        }
        else if (i<25)
        {
            pr=2;
        }
          else if (i<30)
        {
            pr=1;
        }
        

        if(fork() == 0) 
        { 
            set_priority(getpid(),pr);
    

            for (int i = 0; i < 10; i++)
            {
                printf(1," child number :  %d\n",getpid());
            }
            exit(); 
        } 
    } 
  while(wait() != -1) { }

    sleep(1);
} 