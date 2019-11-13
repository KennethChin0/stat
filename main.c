#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>



int main(){
  // ctime();
  char *file = "makefile";
  struct stat info;
  stat(file, &info);
  printf("Size: %ld\n", info.st_size );
  // printf("%d %d\n", info.st_uid, info.st_gid);
  printf("Mode: %d\n", info.st_mode);
  printf("Last access: %s\n", ctime(&(info.st_atime)));

}
