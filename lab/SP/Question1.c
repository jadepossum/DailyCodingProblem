#include<stdio.h>
#include<stdint.h>
#include<sys/stat.h>
#include<time.h>
int main(){
    struct stat fDetail;
    char filename[100] = "Question1.c";
    stat(filename,&fDetail);
    printf("File Name :%s\n",filename);
    printf("Size : %jd bytes\n",(intmax_t)fDetail.st_size);
    //printf("Blocks : %jd\n",(intmax_t)fDetail.st_blocks);
    //printf("IO Block : %jd\n",(intmax_t)fDetail.st_blksize);
    printf("File type: ");
           switch (fDetail.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");
                          break;
           case S_IFCHR:  printf("character device\n");
                          break;
           case S_IFDIR:  printf("directory\n");
                          break;
           case S_IFIFO:  printf("FIFO/pipe\n");
                          break;
           //case S_IFLNK:  printf("symlink\n");
                            //break;
           case S_IFREG:  printf("regular file\n");            
                          break;
           //case S_IFSOCK: printf("socket\n");
                          //break;
           default:       printf("unknown?\n");
                          break;
           }
    printf("Device ID : %ju\n",fDetail.st_dev);
    printf("Inode Number : %ju\n",(uintmax_t)fDetail.st_ino);
    printf("Number of Links : %ju\n",(uintmax_t)fDetail.st_nlink);
    printf("Access Permissions : %jo\n",(uintmax_t)fDetail.st_mode);
    printf("UID : %ju\n",(uintmax_t)fDetail.st_uid);
    printf("GID : %ju\n",(uintmax_t)fDetail.st_gid);
    printf("Access Time : %s\n",ctime(&fDetail.st_atime));
    printf("Modification Time : %s\n",ctime(&fDetail.st_mtime));
    printf("Change Time : %s\n",ctime(&fDetail.st_ctime));
    
    return 0;
}