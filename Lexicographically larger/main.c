#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main(void){
    char *m;

    printf("input string : ");
    m = inputString(stdin, 10);

    printf("input reapeatLimit:");
    int repeatLimit;
    scanf(" %i", &repeatLimit);

    printf("starting %s\n", m);
    int i;
    int trigger = 0;
    int size = strlen(m);
    for(i=0;i <size;i++){
        for(int j=i+1;j<size;j++){
            if(m[i]<m[j]){
                char temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }
    printf("final %s\n", m);

    free(m);
    return 0;
}