#include "out.h"



int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void FUN_00101020(void)

{
                    // WARNING: Treating indirect jump as call
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = strcmp(__s1,__s2);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fflush(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = atoi(__nptr);
  return iVar1;
}



void __isoc99_scanf(void)

{
  __isoc99_scanf();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)

{
                    // WARNING: Subroutine does not return
  exit(__status);
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void _start(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 unaff_retaddr;
  undefined auStack_8 [8];
  
  __libc_start_main(main,unaff_retaddr,&stack0x00000008,0,0,param_3,auStack_8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x00101113)
// WARNING: Removing unreachable block (ram,0x0010111f)

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x00101154)
// WARNING: Removing unreachable block (ram,0x00101160)

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  if (completed_0 != '\0') {
    return;
  }
  __cxa_finalize(&__dso_handle);
  deregister_tm_clones();
  completed_0 = 1;
  return;
}



void frame_dummy(void)

{
  register_tm_clones();
  return;
}



void wt(void)

{
  puts("********");
  return;
}



int nice(int __inc)

{
  int iVar1;
  
  iVar1 = puts("nice");
  return iVar1;
}



void try(void)

{
  puts("try");
  return;
}



void but(void)

{
  puts("but");
  return;
}



void this(void)

{
  puts("this");
  return;
}



void it(void)

{
  puts("it");
  return;
}



void not(void)

{
  puts("not.");
  return;
}



void that(void)

{
  puts("that.");
  return;
}



void easy(void)

{
  puts("easy.");
  return;
}



void ___syscall_malloc(void)

{
  puts("Nope.");
                    // WARNING: Subroutine does not return
  exit(1);
}



void ____syscall_malloc(void)

{
  puts("Good job.");
  return;
}



int main(void)

{
  long uVar1;
  int iVar2;
  size_t sVar3;
  bool bVar4;
  char local_4c;
  char local_4b;
  char local_4a;
  int local_49;
  char local_48 [31];
  char local_29 [9];
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  printf("Please enter key: ");
  local_10 = scanf(&DAT_00102056);
  if (local_10 != 1) {
    ___syscall_malloc();
  }
  if (local_48[1] != '2') {
    ___syscall_malloc();
  }
  if (local_48[0] != '4') {
    ___syscall_malloc();
  }
  fflush(stdin);
  memset(local_29,0,9);
  local_29[0] = '*';
  local_49 = 0;
  local_20 = 2;
  local_14 = 1;
  while( true ) {
    sVar3 = strlen(local_29);
    uVar1 = local_20;
    bVar4 = false;
    if (sVar3 < 8) {
      sVar3 = strlen(local_48);
      bVar4 = uVar1 < sVar3;
    }
    if (!bVar4) break;
    local_4c = local_48[local_20];
    local_4b = local_48[local_20 + 1];
    local_4a = local_48[local_20 + 2];
    iVar2 = atoi(&local_4c);
    local_29[local_14] = (char)iVar2;
    local_20 = local_20 + 3;
    local_14 = local_14 + 1;
  }
  local_29[local_14] = '\0';
  local_18 = strcmp(local_29,"********");
  if (local_18 == -2) {
    ___syscall_malloc();
  }
  else if (local_18 == -1) {
    ___syscall_malloc();
  }
  else if (local_18 == 0) {
    ____syscall_malloc();
  }
  else if (local_18 == 1) {
    ___syscall_malloc();
  }
  else if (local_18 == 2) {
    ___syscall_malloc();
  }
  else if (local_18 == 3) {
    ___syscall_malloc();
  }
  else if (local_18 == 4) {
    ___syscall_malloc();
  }
  else if (local_18 == 5) {
    ___syscall_malloc();
  }
  else if (local_18 == 0x73) {
    ___syscall_malloc();
  }
  else {
    ___syscall_malloc();
  }
  return 0;
}



void _fini(void)

{
  return;
}



