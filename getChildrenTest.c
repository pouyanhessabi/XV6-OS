#include "types.h"
#include "stat.h"
#include "user.h"



int main(){
    int n1 = fork(); 
    int n2 = fork();
    int n3 = fork();
    int n4 = fork();
    int n5 = fork();
     if (n1 > 0 && n2 > 0 && n3 > 0 && n4 > 0 && n5 > 0) {
        int*children = malloc(sizeof(int)*64);
        getchildren(children);
        printf(1 , "This is process %d and children are : " , getpid());
        for(int i = 0; i<64 ;i++){
            if (children[i]==0)
                break;
            printf(1 , "%d / " , children[i]);
            
        }
        printf(0,"\n");
     }
    while(wait() != -1) { }
    sleep(1);

    exit();
}
