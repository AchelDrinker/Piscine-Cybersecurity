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
    int32_t var_4 = data_4004;
    /* jump -> data_4008 */
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

int32_t __isoc99_scanf(char const* format, ...)
{
    /* tailcall */
    return __isoc99_scanf();
}

int32_t sub_1076()
{
    /* tailcall */
    return sub_1030(0x18);
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

int32_t sub_10bc()
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

int32_t main(int32_t argc, char** argv, char** envp)
{
    int32_t var_c = 0;
    int32_t var_7e;
    __builtin_strcpy(var_7e, "__stack_check");
    printf("Please enter key: ");
    void var_70;
    __isoc99_scanf(&data_2029, &var_70, &_GLOBAL_OFFSET_TABLE_);
    if (strcmp(&var_70, &var_7e) != 0)
    {
        printf("Nope.\n");
    }
    else
    {
        printf("Good job.\n");
    }
    return 0;
}

int32_t _fini()
{
    return;
}

