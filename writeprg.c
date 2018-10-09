#include <fctnl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main(){

	int fd, sz;
	fd = open("out3",O_WRONLY | O_CREAT | 0_TRUNC, 0644);
	if(fd < 0) {
		perror("r1");
		exit(1);
	}
	sz = write(fd,"Good\n",strlen("Good\n"));
	printf("Called write(%d, \"Good\\n", %d), it returned %d\n";
			fd, strlen("Good\n"), sz);

	close(fd);		
}