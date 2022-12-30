#include <fs.h>

size_t ramdisk_read(void *buf, size_t offset, size_t len);


size_t fd_size;
size_t* open_offset;


enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB};

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN]  = {"stdin", 0, 0, invalid_read, invalid_write},
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, invalid_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, invalid_write},
#include "files.h"
};


int fs_open(const char *pathname, int flags, int mode){
  for(size_t i=0;i<fd_size;i++){
    if(strcmp(pathname,file_table[i].name)==0){
      return i;
    }
  }
  assert(0);
  return -1;
}

size_t fs_size(int fd){
  return file_table[fd].size;
}

size_t fs_read(int fd, void *buf, size_t len){
  size_t offset=ramdisk_read(buf,file_table[fd].disk_offset+open_offset[fd],  len);
  open_offset[fd]+=offset;
  return offset;
}

void init_fs() {
  // TODO: initialize the size of /dev/fb
  fd_size=sizeof(file_table)/sizeof(Finfo);
  open_offset=(size_t*)malloc(fd_size*sizeof(size_t));
}
