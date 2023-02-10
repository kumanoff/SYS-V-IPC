#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/stat.h>
#include <locale.h>
void text_file(char* name_of_file){
    int inputFd, outputFd, numRead, total, openFlags;
    mode_t filePerms;
    inputFd = open(name_of_file, O_RDONLY);

    for (int i =0; i<strlen(name_of_file);i++){
        printf("%d  ", name_of_file[i]);
    }
    printf("\n");

    if (inputFd == -1) {
        printf("Error opening file: %s\n", name_of_file);
        exit(-2);
    }
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    char output_name[]="out.txt";
    outputFd = open(output_name, openFlags, filePerms);
    char buf;
    total = 0;
    // цикл для обработки файла
    while ((numRead = read(inputFd, &buf, 1) > 0))
       {
        write(outputFd, &buf, numRead);
        if (buf == '.') {
           buf = 0x0a;
           write(outputFd, &buf, numRead);
           total++;
        }
    }
    printf("Amount of operations: %d\n", total);
    close(inputFd);
    close(outputFd);
}