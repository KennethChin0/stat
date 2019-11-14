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
  float size = info.st_size;
  printf("Size: %ld\n", info.st_size );
  printf("Mode: %o\n", info.st_mode);
  printf("Last access: %s", ctime(&(info.st_atime)));
  int i = 0;
  while(size >= 1024){
    size /= 1024;
    i++;
  }
  char * type[] = {"B", "KB", "MB", "GB"};
  printf("Size (readable): %f %s\n", size, type[i] );


  char permissions[10];
  sprintf(permissions, "%o", info.st_mode);
  // printf("%s\n", permissions);
  printf("Permissions (ls -l): \n");
  int x = 3;
  for (; x < 7; x++){
    switch(permissions[x] - 48){
      case 0:
        printf("---");
        break;
      case 1:
        printf("--x");
        break;
      case 2:
        printf("-w-");
        break;
      case 3:
        printf("-wx");
        break;
      case 4:
        printf("r--");
        break;
      case 5:
        printf("r-x");
        break;
      case 6:
        printf("rw-");
        break;
      case 7:
        printf("rwx");
        break;
    }
  }
  printf("\n");


  return 0;
}
