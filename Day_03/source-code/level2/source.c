#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void printNope(void) {
    printf("Nope.\n");
    exit(1);
}

void printGoodJob(void) {
    printf("Good job.\n");
    return;
}

int main(void) {
    char input[24];
    char key[9];
    int scanResult;

    printf("Please enter key: ");
    scanResult = scanf("%s", input);
    if (scanResult != 1) {
        printNope();
    }
    if (input[0] != '0' || input[1] != '0') {
        printNope();
    }
    memset(key, 0, 9);
    key[0] = 'd';
    unsigned int keyIndex = 2;
    unsigned int keyPosition = 1;
    while (strlen(key) < 8 && keyIndex < strlen(input)) {
        key[keyPosition] = input[keyIndex];
        keyIndex += 3;
        keyPosition++;
    }
    key[keyPosition] = '\0';
    if (strcmp(key, "delabere") == 0) {
        printGoodJob();
    } else {
        printNope();
    }
    return 0;
}
