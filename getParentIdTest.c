#include "types.h"
#include "stat.h"
#include "user.h"

int main(){

    printf(1,"%d",getParentID());

    /* wait for all child to terminate */
    while(wait() != -1) { }

    /* give time to parent to reach wait clause */
    sleep(1);

    exit();
    return 0;
}
