#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 
#include "fdf.h"

int main(int *argv, char **argc){
    int fd;
    int n;
    char b;
    int i;
    char buf[100000];
    fdf_t field;
    n = 1;
    fd = open(argc[1], O_RDONLY);
    if (fd < 0){
        write(1, "error\n", 6);
        exit(1);
    }
    while(read(fd, &b, 1))
        buf[i++]=b;
    //i--;
    //while(buf[i]){
    //        
    //    write(1, &buf[i--], 1);
    //}
    close(fd);
    i=0;
    while(buf[i]){
        if(n=1 && buf[i] == ' '){
            
        }
        if(buf[i] == '\n' && buf[i+1] == '\n' && buf[i+1] != '\0'){
            write(1, "Map error", 9);
            exit(2);
        }
        if(buf[i] == '\n')
            n++;
        i++;
    }
    i=0;
    
    printf("%d", n);

}