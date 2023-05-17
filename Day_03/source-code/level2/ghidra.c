#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void no(void)
{
    puts("Nope.");
    exit(1);
}

void ok(void)
{
    puts("Good job.");
    return;
}

int main(void)
{
    unsigned int uVar1;
    size_t sVar2;
    int iVar3;
    bool bVar4;
    char local_3d;
    char local_3c;
    char local_3b;
    char local_3a;
    char local_39[24];
    char local_21[9];
    unsigned int local_18;
    int local_14;
    int local_10;
    
    printf("Please enter key: ");
    local_10 = scanf("%23s", local_39);
    if (local_10 != 1) {
        no();
    }
    if (local_39[1] != '0') {
        no();
    }
    if (local_39[0] != '0') {
        no();
    }
    fflush(stdin);
    memset(local_21, 0, sizeof(local_21));
    local_21[0] = 'd';
    local_3a = 0;
    local_18 = 2;
    local_14 = 1;
    
    while (1) {
        sVar2 = strlen(local_21);
        uVar1 = local_18;
        bVar4 = false;
        
        if (sVar2 < 8) {
            sVar2 = strlen(local_39);
            bVar4 = uVar1 < sVar2;
        }
        
        if (!bVar4)
            break;
        
        local_3d = local_39[local_18];
        local_3c = local_39[local_18 + 1];
        local_3b = local_39[local_18 + 2];
        iVar3 = atoi(&local_3d);
        local_21[local_14] = (char)iVar3;
        local_18 = local_18 + 3;
        local_14 = local_14 + 1;
    }
    
    local_21[local_14] = '\0';
    iVar3 = strcmp(local_21, "delabere");
    
    if (iVar3 == 0) {
        ok();
    } else {
        no();
    }
    
    return 0;
}
