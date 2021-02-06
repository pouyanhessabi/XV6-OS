#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int n = fork();
    if (n == 0 ) { 
    printf(2,"This is process %d and the parent id is %d\n",getpid(),getParentID());
    /*printf(1," %d\n",getpid());*/
    }
    while(wait() != -1) { }

    sleep(1);
 exit();
}
