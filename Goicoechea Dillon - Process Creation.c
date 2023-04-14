#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        char *args[]={"./test",NULL};
        execv(args[0],args);
     
        /*All statements are ignored after execvp() call as this whole
        process(execDemo.c) is replaced by another process (EXEC.c)
        */
        printf("Ending-----");
     
    return 0;
}