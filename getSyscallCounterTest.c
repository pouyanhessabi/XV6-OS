#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{
    char *tmp = argv[1];
    int num = atoi(tmp);
    int numberOfDone = 3; //for test change it
    for (int i = 1; i < numberOfDone; i++)
        getSyscallCounter(num);

    printf(1, "This syscall with id %d, %d has used\n", num, getSyscallCounter(num));
    while (wait() != 1)
    {
        sleep(1);
        exit();
    }

    return 0;
}