#include <stdio.h>
#include "get_next_line.h"
int main(){
	int fd;
	char *s = "1";
	fd = open("txt.txt", O_RDONLY);
	while(s){
		s = get_next_line(fd);	
		printf("%s", s);
	}
	return 0;

}
