int32_t (* const)() _init()
{
    int32_t (* const eax)() = __gmon_start__;
    if (__gmon_start__ != 0)
    {
        eax = __gmon_start__();
    }
    return eax;
}

int32_t sub_1030()
{
    int32_t var_4 = data_7004;
    /* jump -> data_7008 */
}

int32_t strcmp(char const* arg1, char const* arg2)
{
    /* tailcall */
    return strcmp(arg1, arg2);
}

int32_t sub_1046()
{
    /* tailcall */
    return sub_1030(0);
}

void __libc_start_main(
    int32_t (* main)(int32_t argc, char** argv, char** envp), int32_t argc, 
    char** ubp_av, void (* init)(), void (* fini)(), void (* rtld_fini)(), 
    void* stack_end) __noreturn
{
    /* tailcall */
    return __libc_start_main(main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

int32_t sub_1056()
{
    /* tailcall */
    return sub_1030(8);
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

int32_t sub_1066()
{
    /* tailcall */
    return sub_1030(0x10);
}

int32_t fflush(FILE* fp)
{
    /* tailcall */
    return fflush(fp);
}

int32_t sub_1076()
{
    /* tailcall */
    return sub_1030(0x18);
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int32_t sub_1086()
{
    /* tailcall */
    return sub_1030(0x20);
}

void exit(int32_t status) __noreturn
{
    /* tailcall */
    return exit(status);
}

int32_t sub_1096()
{
    /* tailcall */
    return sub_1030(0x28);
}

size_t strlen(char const* arg1)
{
    /* tailcall */
    return strlen(arg1);
}

int32_t sub_10a6()
{
    /* tailcall */
    return sub_1030(0x30);
}

int32_t memset(void* arg1, int32_t arg2, size_t arg3)
{
    /* tailcall */
    return memset(arg1, arg2, arg3);
}

int32_t sub_10b6()
{
    /* tailcall */
    return sub_1030(0x38);
}

int32_t __isoc99_scanf(char const* format, ...)
{
    /* tailcall */
    return __isoc99_scanf();
}

int32_t sub_10c6()
{
    /* tailcall */
    return sub_1030(0x40);
}

int32_t atoi(char const* nptr)
{
    /* tailcall */
    return atoi(nptr);
}

int32_t sub_10d6()
{
    /* tailcall */
    return sub_1030(0x48);
}

void __cxa_finalize(void* d)
{
    /* tailcall */
    return __cxa_finalize(d);
}

int32_t __convention("regparm") _start(int32_t arg1, void (* arg2)()) __noreturn
{
    int32_t var_4 = arg1;
    __libc_start_main(main, __return_addr, &arg_4, nullptr, nullptr, arg2, &var_4);
    /* no return */
}

int32_t sub_111c()
{
    return;
}

int32_t __x86.get_pc_thunk.bx()
{
    return;
}

void* deregister_tm_clones()
{
    return &__TMC_END__;
}

int32_t register_tm_clones()
{
    return 0;
}

void __do_global_dtors_aux()
{
    if (__TMC_END__ == 0)
    {
        if (__cxa_finalize != 0)
        {
            __cxa_finalize(__dso_handle);
        }
        deregister_tm_clones();
        __TMC_END__ = 1;
    }
}

int32_t frame_dummy()
{
    /* tailcall */
    return register_tm_clones();
}

int32_t __x86.get_pc_thunk.dx()
{
    return;
}

int32_t no() __noreturn
{
    puts("Nope.");
    exit(1);
    /* no return */
}

int32_t xd()
{
    puts("Iii sapores crescit rei habetur …");
    return puts("Author gi ex si im fallat istius…");
}

int32_t ok()
{
    int32_t eax;
    int32_t var_c = eax;
    return puts("Good job.");
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    int32_t var_c = 0;
    printf("Please enter key: ");
    char var_39;
    if (1 != __isoc99_scanf("%23s", &var_39))
    {
        no();
        /* no return */
    }
    char var_38;
    if (0x30 != var_38)
    {
        no();
        /* no return */
    }
    if (0x30 != var_39)
    {
        no();
        /* no return */
    }
    fflush(*stdin);
    char var_21;
    memset(&var_21, 0, 9);
    var_21 = 0x64;
    char var_3a = 0;
    int32_t var_18 = 2;
    int32_t var_14 = 1;
    while (true)
    {
        char var_45_1 = 0;
        int32_t eax_3;
        if (strlen(&var_21) < 8)
        {
            eax_3 = var_18 < strlen(&var_39);
            var_45_1 = eax_3;
        }
        eax_3 = var_45_1;
        if ((eax_3 & 1) == 0)
        {
            break;
        }
        int32_t eax_6;
        eax_6 = &var_39[var_18];
        char var_3d = eax_6;
        int32_t eax_7;
        eax_7 = &var_38[var_18];
        char var_3c_1 = eax_7;
        void var_37;
        int32_t eax_8;
        eax_8 = *(&var_37 + var_18);
        char var_3b_1 = eax_8;
        &var_21[var_14] = atoi(&var_3d);
        var_18 = (var_18 + 3);
        var_14 = (var_14 + 1);
    }
    &var_21[var_14] = 0;
    if (strcmp(&var_21, "delabere") != 0)
    {
        no();
        /* no return */
    }
    ok();
    return 0;
}

int32_t xxd()
{
    puts("Iii sapores crescit rei habetur …");
    return puts("Author gi ex si im fallat istius…");
}

int32_t n()
{
    int32_t eax;
    int32_t var_c = eax;
    return puts("Nope. ");
}

int32_t xxxd()
{
    puts("Iii sapores crescit rei habetur …");
    return puts("Author gi ex si im fallat istius…");
}

int32_t ww()
{
    puts("Good job. ");
    puts("Please entrer key: ");
    puts("%23s. ");
    puts("delabere. ");
    return puts("%s, ");
}

int32_t xyxxd()
{
    puts("Iii sapores crescit rei habetur …");
    return puts("Author gi ex si im fallat istius…");
}

int32_t _fini()
{
    return;
}
