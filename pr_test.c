#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char** argv){
    char* tmp = argv[1];
    int num = atoi(tmp);
    int pr=0;
    int temp=changePolicy(num);
    num=temp;
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
            
            for (int i = 0; i < 250; i++)
            {   
                
                printf(1,"\n child :  %d\n",getpid());
                
                /*printf(1," pr :  %d\n",pr);*/
                
            }
             exit(); 
        } 
    } 
  while(wait() != -1) { }

    sleep(1);
      exit(); 
} 