#include "out.h"



// WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx

int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void FUN_00011030(void)

{
                    // WARNING: Treating indirect jump as call
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = strcmp(__s1,__s2);
  return iVar1;
}



void __libc_start_main(void)

{
  __libc_start_main();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



void __isoc99_scanf(void)

{
  __isoc99_scanf();
  return;
}



void FUN_00011080(void)

{
  int unaff_EBX;
  
                    // WARNING: Could not recover jumptable at 0x00011080. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(unaff_EBX + -0x10))();
  return;
}



// WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx

void _start(void)

{
  __libc_start_main(main);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: This is an inlined function

void __i686_get_pc_thunk_bx(void)

{
  return;
}



// WARNING: This is an inlined function

void __x86_get_pc_thunk_bx(void)

{
  return;
}



// WARNING: Function: __x86.get_pc_thunk.dx replaced with injection: get_pc_thunk_dx
// WARNING: Removing unreachable block (ram,0x000110eb)
// WARNING: Removing unreachable block (ram,0x000110f5)

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Function: __x86.get_pc_thunk.dx replaced with injection: get_pc_thunk_dx
// WARNING: Removing unreachable block (ram,0x0001113e)
// WARNING: Removing unreachable block (ram,0x00011148)

void register_tm_clones(void)

{
  return;
}



// WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx

void __do_global_dtors_aux(void)

{
  if (completed_0 == '\0') {
    FUN_00011080(&__dso_handle);
    deregister_tm_clones();
    completed_0 = '\x01';
  }
  return;
}



void frame_dummy(void)

{
  register_tm_clones();
  return;
}



// WARNING: This is an inlined function

void __x86_get_pc_thunk_dx(void)

{
  return;
}



undefined4 main(void)

{
  int iVar1;
  undefined4 local_7e;
  undefined4 local_7a;
  undefined4 local_76;
  undefined2 local_72;
  char local_70 [100];
  undefined4 local_c;
  
  local_c = 0;
  local_7e = 0x74735f5f;
  local_7a = 0x5f6b6361;
  local_76 = 0x63656863;
  local_72 = 0x6b;
  printf("Please enter key: ");
  __isoc99_scanf(&DAT_00012029,local_70);
  iVar1 = strcmp(local_70,(char *)&local_7e);
  if (iVar1 == 0) {
    printf("Good job.\n");
  }
  else {
    printf("Nope.\n");
  }
  return 0;
}



// WARNING: Function: __x86.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx

void _fini(void)

{
  return;
}
