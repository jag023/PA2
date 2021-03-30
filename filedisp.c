#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int args, char *argv[]) {
    char line[256];
    FILE *fp = stdin;
    while(fgets(line, sizeof(line), fp) != NULL) {
        if(strcmp(argv[1],"-d")==0){
            if(strstr(line,"directories"))
                printf("%s",line);
        }else if(strcmp(argv[1],"-f")==0){
            if(strstr(line,"file"))
                printf("%s",line);
        }else if(strcmp(argv[1],"-b")==0){
            if(strstr(line,"byte"))
                printf("%s",line);
        }

    }
    return 0;
}
