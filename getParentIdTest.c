#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int n = fork();
    if (n > 0 ) { 
    printf(1,"%d\n",getParentID());

   
    while(wait() != -1) { }

    sleep(1);
}
 exit();
}
