#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

int compareChars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main(void){
    char *m;

    printf("input string : ");
    m = inputString(stdin, 10);

    printf("input reapeatLimit:");
    int repeatLimit;
    scanf(" %i", &repeatLimit);


    // Record the start time
    clock_t start = clock();
    
    int size = strlen(m);

    printf("starting %s\n", m);
    // Sort the string using qsort (much more efficient than bubble sort)
    qsort(m, size, sizeof(char), compareChars);

    printf("mid %s\n", m);
    printf("sorted %s\n", m);

    int trigger = 1;
    for(int i=0;i <size;i++){
        if(m[i]==m[i+1]){
            trigger++;
            if(trigger>repeatLimit){
                int j = 1;
                while(m[i+j] != '\0' && m[i]==m[i+j]){
                    j++;
                }
                char temp = m[i+j];
                m[i+j] = m[i+1];
                m[i+1] = temp;
                trigger = 0;
            }
        }
        else{
            trigger = 0;
        }
    }

    printf("final %s\n", m);
    free(m);
    
    // Record the end time
    clock_t end = clock();
    // Calculate the elapsed time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}