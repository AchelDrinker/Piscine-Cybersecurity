/* This file was generated by the Hex-Rays decompiler version 8.2.0.221215.
   Copyright (c) 2007-2021 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

void *init_proc();
void sub_1030();
// int strcmp(const char *s1, const char *s2);
// int __cdecl __libc_start_main(int (__cdecl *main)(int, char **, char **), int argc, char **ubp_av, void (*init)(void), void (*fini)(void), void (*rtld_fini)(void), void *stack_end);
// int printf(const char *format, ...);
// int __cdecl __isoc99_scanf(_DWORD, _DWORD); weak
int __cdecl sub_1080(_DWORD); // weak
// void __usercall __noreturn start(int a1@<eax>, void (*a2)(void)@<edx>);
void sub_10BC();
void _x86_get_pc_thunk_bx();
char *deregister_tm_clones();
int register_tm_clones();
char *_do_global_dtors_aux();
int frame_dummy();
void _x86_get_pc_thunk_dx();
int __cdecl main(int argc, const char **argv, const char **envp);
void term_proc();
// int __cdecl _cxa_finalize(void *);

//-------------------------------------------------------------------------
// Data declarations

void *_dso_handle = &_dso_handle; // weak
char _bss_start; // weak
// extern _UNKNOWN _gmon_start__; weak


//----- (00001000) --------------------------------------------------------
void *init_proc()
{
  void *result; // eax

  result = &_gmon_start__;
  if ( &_gmon_start__ )
    return (void *)((int (*)(void))_gmon_start__)();
  return result;
}

//----- (00001030) --------------------------------------------------------
void sub_1030()
{
  __asm { jmp     dword ptr [ebx+8] }
}
// 1036: unbalanced stack, ignored a potential tail call

//----- (00001090) --------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __noreturn start(int a1@<eax>, void (*a2)(void)@<edx>)
{
  int v2; // esi
  int v3; // [esp-4h] [ebp-4h] BYREF
  char *retaddr; // [esp+0h] [ebp+0h] BYREF

  v2 = v3;
  v3 = a1;
  __libc_start_main((int (__cdecl *)(int, char **, char **))main, v2, &retaddr, 0, 0, a2, &v3);
  __halt();
}
// 1097: positive sp value 4 has been found

//----- (000010BC) --------------------------------------------------------
void sub_10BC()
{
  ;
}

//----- (000010C0) --------------------------------------------------------
void _x86_get_pc_thunk_bx()
{
  ;
}

//----- (000010D0) --------------------------------------------------------
char *deregister_tm_clones()
{
  return &_bss_start;
}
// 10D0: could not find valid save-restore pair for ebp
// 4024: using guessed type char _bss_start;

//----- (00001110) --------------------------------------------------------
int register_tm_clones()
{
  return 0;
}
// 1110: could not find valid save-restore pair for ebp

//----- (00001160) --------------------------------------------------------
char *_do_global_dtors_aux()
{
  char *result; // eax

  if ( !_bss_start )
  {
    if ( &_cxa_finalize )
      sub_1080(_dso_handle);
    result = deregister_tm_clones();
    _bss_start = 1;
  }
  return result;
}
// 1080: using guessed type int __cdecl sub_1080(_DWORD);
// 4020: using guessed type void *_dso_handle;
// 4024: using guessed type char _bss_start;

//----- (000011B0) --------------------------------------------------------
int frame_dummy()
{
  return register_tm_clones();
}

//----- (000011B9) --------------------------------------------------------
void _x86_get_pc_thunk_dx()
{
  ;
}

//----- (000011C0) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  char v4[114]; // [esp+Eh] [ebp-7Ah] BYREF
  int v5; // [esp+80h] [ebp-8h]

  v5 = 0;
  strcpy(v4, "__stack_check");
  printf("Please enter key: ");
  __isoc99_scanf("%s", &v4[14]);
  if ( !strcmp(&v4[14], v4) )
    printf("Good job.\n");
  else
    printf("Nope.\n");
  return 0;
}
// 1070: using guessed type int __cdecl __isoc99_scanf(_DWORD, _DWORD);

//----- (0000127C) --------------------------------------------------------
void term_proc()
{
  ;
}

// nfuncs=22 queued=12 decompiled=12 lumina nreq=0 worse=0 better=0
// ALL OK, 12 function(s) have been successfully decompiled
