#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>  

int main(void) {
    int fd[2];
    if(pipe(fd) == -1 ){
        printf("%s\n","lol bad." );fflush(stdout);
        return EXIT_FAILURE;
    }

    if(fork() == 0){
        close(fd[0]);
        char str[100];
        printf("say something \n");
        scanf("%s",(char*)&str);
        write(fd[1], str,sizeof(str)+1);
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    char str2[100];
    close(fd[1]);
    read(fd[0],str2,100);
    printf("%s\n",str2);
    return 0;
}