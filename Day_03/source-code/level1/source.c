#include <stdio.h>
#include <string.h>

int main(void) {
    int iVar1;
    char local_70[100];  
    char* local_7e = "\x74\x73\x5f\x5f"; // "ts__"

    printf("Please enter key: ");
    scanf("%s", local_70);

    iVar1 = strcmp(local_70, local_7e);
    if (iVar1 == 0) {
        printf("Good job.\n");
    } else {
        printf("Nope.\n");
    }
    
    return 0;
}