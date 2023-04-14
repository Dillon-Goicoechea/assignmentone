#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    struct timespec t0, t1;
    int rc = 0;
    rc = fork();
    if (rc < 0){
        printf("Fork failed, assignment ended");
        exit(1);
    }
    else if(rc == 0){
        execvp(argv[1],argv);
    }
    else{
        timespec_get(&t0, TIME_UTC);
        int rc_wait = wait(NULL);
        timespec_get(&t1, TIME_UTC);
        double time_taken = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
        printf("fork(),execvp(),and wait() time to run: %f \n", time_taken);
        timespec_get(&t0, TIME_UTC);
        system(argv[1]);
        timespec_get(&t1, TIME_UTC);
        time_taken = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
        printf("system() time to run: %f \n", time_taken);
    }
    return 0;
}