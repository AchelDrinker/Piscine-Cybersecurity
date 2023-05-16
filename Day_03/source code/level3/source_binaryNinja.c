void _init()
{
    if (__gmon_start__ != 0)
    {
        __gmon_start__();
    }
}

int64_t sub_1020()
{
    int64_t var_8 = data_4008;
    /* jump -> data_4010 */
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int64_t sub_1036()
{
    int64_t var_8 = 0;
    /* tailcall */
    return sub_1020();
}

uint64_t strlen(char const* arg1)
{
    /* tailcall */
    return strlen(arg1);
}

int64_t sub_1046()
{
    int64_t var_8 = 1;
    /* tailcall */
    return sub_1020();
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

int64_t sub_1056()
{
    int64_t var_8 = 2;
    /* tailcall */
    return sub_1020();
}

int64_t memset(void* arg1, int32_t arg2, uint64_t arg3)
{
    /* tailcall */
    return memset(arg1, arg2, arg3);
}

int64_t sub_1066()
{
    int64_t var_8 = 3;
    /* tailcall */
    return sub_1020();
}

int32_t strcmp(char const* arg1, char const* arg2)
{
    /* tailcall */
    return strcmp(arg1, arg2);
}

int64_t sub_1076()
{
    int64_t var_8 = 4;
    /* tailcall */
    return sub_1020();
}

int32_t fflush(FILE* fp)
{
    /* tailcall */
    return fflush(fp);
}

int64_t sub_1086()
{
    int64_t var_8 = 5;
    /* tailcall */
    return sub_1020();
}

int32_t atoi(char const* nptr)
{
    /* tailcall */
    return atoi(nptr);
}

int64_t sub_1096()
{
    int64_t var_8 = 6;
    /* tailcall */
    return sub_1020();
}

int32_t __isoc99_scanf(char const* format, ...)
{
    /* tailcall */
    return __isoc99_scanf();
}

int64_t sub_10a6()
{
    int64_t var_8 = 7;
    /* tailcall */
    return sub_1020();
}

void exit(int32_t status) __noreturn
{
    /* tailcall */
    return exit(status);
}

int64_t sub_10b6()
{
    int64_t var_8 = 8;
    /* tailcall */
    return sub_1020();
}

void __cxa_finalize(void* d)
{
    /* tailcall */
    return __cxa_finalize(d);
}

int64_t _start(int64_t arg1, int64_t arg2, void (* arg3)()) __noreturn
{
    int64_t rax;
    int64_t var_8 = rax;
    __libc_start_main(main, __return_addr, &arg_8, nullptr, nullptr, arg3, &var_8);
    /* no return */
}

void deregister_tm_clones()
{
    return;
}

void register_tm_clones()
{
    return;
}

void __do_global_dtors_aux()
{
    if (__TMC_END__ != 0)
    {
        return;
    }
    if (__cxa_finalize != 0)
    {
        __cxa_finalize(__dso_handle);
    }
    deregister_tm_clones();
    __TMC_END__ = 1;
}

void frame_dummy()
{
    /* tailcall */
    return register_tm_clones();
}

int64_t wt()
{
    return puts("********");
}

int64_t nice()
{
    return puts("nice");
}

int64_t try()
{
    return puts(&data_2012);
}

int64_t but()
{
    return puts(&data_2016);
}

int64_t this()
{
    return puts("this");
}

int64_t it()
{
    return puts(&data_201f);
}

int64_t not()
{
    return puts("not.");
}

int64_t that()
{
    return puts("that.");
}

int64_t easy()
{
    return puts("easy.");
}

int64_t ___syscall_malloc() __noreturn
{
    puts("Nope.");
    exit(1);
    /* no return */
}

int64_t ____syscall_malloc()
{
    return puts("Good job.");
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    int32_t var_c = 0;
    int64_t rax;
    rax = 0;
    printf("Please enter key: ");
    int64_t rax_1;
    rax_1 = 0;
    char var_48;
    if (1 != __isoc99_scanf("%23s", &var_48))
    {
        ___syscall_malloc();
        /* no return */
    }
    char var_47;
    if (0x32 != var_47)
    {
        ___syscall_malloc();
        /* no return */
    }
    if (0x34 != var_48)
    {
        ___syscall_malloc();
        /* no return */
    }
    fflush(*stdin);
    char var_29;
    memset(&var_29, 0, 9);
    var_29 = 0x2a;
    char var_49 = 0;
    int64_t var_20 = 2;
    int32_t var_14 = 1;
    while (true)
    {
        char var_4d_1 = 0;
        int64_t rax_4;
        if (strlen(&var_29) < 8)
        {
            rax_4 = var_20 < strlen(&var_48);
            var_4d_1 = rax_4;
        }
        rax_4 = var_4d_1;
        if ((rax_4 & 1) == 0)
        {
            break;
        }
        int64_t rax_7;
        rax_7 = &var_48[var_20];
        char var_4c = rax_7;
        int64_t rax_8;
        rax_8 = &var_47[var_20];
        char var_4b_1 = rax_8;
        void var_46;
        int64_t rax_9;
        rax_9 = *(&var_46 + var_20);
        char var_4a_1 = rax_9;
        &var_29[var_14] = atoi(&var_4c);
        var_20 = (var_20 + 3);
        var_14 = (var_14 + 1);
    }
    &var_29[var_14] = 0;
    switch (strcmp(&var_29, "********"))
    {
        case 0:
        {
            ____syscall_malloc();
            return 0;
            break;
        }
        case 1:
        {
            ___syscall_malloc();
            /* no return */
        }
        case 2:
        {
            ___syscall_malloc();
            /* no return */
        }
        case 3:
        {
            ___syscall_malloc();
            /* no return */
        }
        case 4:
        {
            ___syscall_malloc();
            /* no return */
        }
        case 5:
        {
            ___syscall_malloc();
            /* no return */
        }
        case 0x73:
        {
            ___syscall_malloc();
            /* no return */
        }
        case 0xfffffffe:
        {
            ___syscall_malloc();
            /* no return */
        }
        case 0xffffffff:
        {
            ___syscall_malloc();
            /* no return */
        }
    }
    ___syscall_malloc();
    /* no return */
}

int64_t _fini()
{
    return;
}

