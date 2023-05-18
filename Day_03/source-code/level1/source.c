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
  local_7e = 0x74735f5f; ts__
  local_7a = 0x5f6b6361; _kca
  local_76 = 0x63656863; chec
  local_72 = 0x6b; k
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