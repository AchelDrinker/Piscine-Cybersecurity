// J'ai utiliser le site web suivant pour decompiler :
// https://dogbolt.org/

#include <stdio.h>
#include <string.h>

int main(void)
{
  int iVar1;
  int local_7e;
  char local_70 [100];
  
  local_7e = 0x74735f5f;

  printf("Please enter key: ");
  scanf("%s",local_70);
  iVar1 = strcmp(local_70,(char *)&local_7e);
  printf("Je suis le mot de passe : %s\n", (char *)&local_7e);
  if (iVar1 == 0) {
    printf("Good job.\n");
  }
  else {
    printf("Nope.\n");
  }
  return 0;
}