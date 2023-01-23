#define SDL_malloc  malloc
#define SDL_free    free
#define SDL_realloc realloc

#define SDL_STBIMAGE_IMPLEMENTATION
#include "SDL_stbimage.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

SDL_Surface* IMG_Load_RW(SDL_RWops *src, int freesrc) {
  assert(src->type == RW_TYPE_MEM);
  assert(freesrc == 0);
  return NULL;
}

SDL_Surface* IMG_Load(const char *filename) {
  int fd=open(filename,0);
  struct stat statbuf;
  fstat(fd, &statbuf);
  size_t filesize = statbuf.st_size;
  unsigned char* buf=malloc(filesize);
  size_t readsize=fread(fd,buf,filesize);
  if(readsize!=filesize) assert(0);
  SDL_Surface* imgSurface_p=STBIMG_LoadFromMemory();
  free(buf);
  close(fd);
  printf("filesize:%d\n",filesize);
  return imgSurface_p;
}

int IMG_isPNG(SDL_RWops *src) {
  return 0;
}

SDL_Surface* IMG_LoadJPG_RW(SDL_RWops *src) {
  return IMG_Load_RW(src, 0);
}

char *IMG_GetError() {
  return "Navy does not support IMG_GetError()";
}
