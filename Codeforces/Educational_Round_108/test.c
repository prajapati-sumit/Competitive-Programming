#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Please enter a line:\n");

    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    lineSize = getline(&line, &len, stdin);

    FILE *fptr;
    fptr = fopen("here.txt","w");
    if(fptr == NULL){
        printf("Error Writing to File!\n");   
        exit(1);             
    }
    fprintf(fptr,"%s",line);

    printf("Your entered line is written in the text file\n");

    fclose(fptr);
    free(line);
    return 0;

}