#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char n[100]; //zarezerwuj pamięć dla tablicy 100 znaków
    int i;
    strcpy(n, "Ala");

    printf("%s", n);

    for (i=0; i < 3; i++){
        printf("[%d] %c\n", i, n[i]);
    }
    printf("%s", n);
return 0;
}