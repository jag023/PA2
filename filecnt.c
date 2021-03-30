//changes
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void countFileRecursively(char *path);
int file_count = 0;
int directory_count =0;
int fileTotalBytes=0;

int main(int argc, char *argv[]) {



    countFileRecursively(argv[1]);

    printf("The total number of directories in directory < %s > is: %d. \n", argv[1], directory_count);
    printf("The total number of files in directory < %s > is: %d. \n", argv[1] , file_count);
    printf("The total number of bytes occupied by all files in directory < %s > is: %d. \n", argv[1], fileTotalBytes);

    return 0;

}

void countFileRecursively(char *basepath){
    char path[1000];
    DIR * dir;
    struct dirent * entry;
    struct stat file_stats;
    dir = opendir(basepath);
    if (!dir){
        return;
    }
    while ((entry=readdir(dir)) != NULL) {
        if(strcmp(entry->d_name,".") !=0 && strcmp(entry->d_name, "..") !=0){
            if(entry->d_type==DT_REG && !((stat(entry->d_name,&file_stats)))){
                file_count++;
                fileTotalBytes = file_stats.st_size + fileTotalBytes;
            }

            if (entry->d_type == DT_DIR){
                directory_count++;
            }
            strcpy(path, basepath);
            strcat(path, "/");
            strcat(path, entry->d_name);
            countFileRecursively(path);
        }

    }
    closedir(dir);
}

