/*
* 
* 
*/
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int infd, outfd;
	void *from, *to;
	struct stat infstat;
	int ret = 0;
	if(argc != 3){
		fprintf(stderr, "Bad usage!\n");
		ret = -1;
		goto fail;
	}
	infd = open(argv[1], O_RDWR| O_CREAT, 0600);
	if(infd == -1){
		perror("Open failed");
		ret = -1;
		goto fail;
	}
	outfd = open(argv[2], O_RDWR| O_CREAT, 0600);
	if(outfd == -1){
		perror("Open failed");
		ret = -1;
		goto close_fail1;
	}
	if(fstat(infd, &infstat)){
		perror("fstat failed");
		ret = -1;
		goto close_fail2;
	}
	if(lseek(outfd, infstat.st_size-1, SEEK_SET) == (off_t) -1){
		perror("lseek failed");
		ret = -1;
		goto close_fail2;
	}
	if(write(outfd, "", 1) != 1){
		perror("write failed");
		ret = -1;
		goto close_fail2;
	}
	if(lseek(outfd, 0, SEEK_SET) == (off_t) -1){
		perror("lseek failed");
		ret = -1;
		goto close_fail2;
	}
	from = mmap(0, (size_t)infstat.st_size, PROT_READ,  MAP_PRIVATE | MAP_NORESERVE, infd, 0);
	if(from == (void*) -1){
		perror("mmap failed");
		ret = -1;
		goto close_fail2;
	}
	to = mmap(0, (size_t)infstat.st_size, PROT_WRITE, MAP_SHARED, outfd, 0);
	if(to == (void*) -1){
		perror("mmap failed");
		ret = -1;
		goto unmap_fail1;
	}
	memcpy(to, from, infstat.st_size);
        
	if( -1 == msync(to, (size_t)infstat.st_size, MS_SYNC)){//同步写
		perror("msync failed");
		ret = -1;
	}
	if (-1 == munmap(to, infstat.st_size)){
		perror("munmap failed");
		ret = -1;
	}

unmap_fail1:
	if( -1 == munmap(from, infstat.st_size)){
		perror("munmap failed");
		ret = -1;
	}

close_fail2:
	if( -1 == close(outfd)){
		perror("close failed");
		ret = -1;
	}

close_fail1:
	if( -1 == close(infd)){
		perror("close failed");
		ret = -1;
	}
fail:
	exit(ret);
}
