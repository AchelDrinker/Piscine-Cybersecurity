long long _init()
{
    return 0;
    if (false)
    {
        return 0();
    }
}

long long sub_401020()
{
    void* v0;  // [bp-0x8]

    v0 = 0;
    goto *((long long *)4210704);
}

extern unsigned long long main;

long long _start()
{
    unsigned long long v0;  // [bp+0x0], Other Possible Types: unsigned long
    unsigned long v1;  // [bp+0x8]
    unsigned long long v2;  // rsi
    unsigned long v3;  // rax
    unsigned long long v4;  // rdx

    v2 = v0;
    v0 = v3;
    __libc_start_main(&main, v2, &v1, 0x0, 0x0, v4); /* do not return */
}

// No decompilation output for function sub_4010f5

extern char __TMC_END__;

int deregister_tm_clones()
{
    return;
    if (false)
    {
        return;
    }
}

long long register_tm_clones()
{
    return 0;
    if (false)
    {
        return 0;
    }
}

extern char __TMC_END__;

long long __do_global_dtors_aux()
{
    unsigned long v0;  // [bp-0x8]
    unsigned long v2;  // rax

    if (__TMC_END__ == 0)
    {
        v0 = stack_base + 0;
        __TMC_END__ = 1;
        return deregister_tm_clones();
        if (false)
        {
            __cxa_finalize();
            __TMC_END__ = 1;
            return deregister_tm_clones();
        }
    }
    else
    {
        return v2;
    }
}

long long frame_dummy()
{
    return register_tm_clones();
}

long long wt()
{
    return puts("********");
}

long long nice()
{
    return puts("nice");
}

long long try()
{
    return puts("try");
}

long long but()
{
    return puts("but");
}

long long this()
{
    return puts("this");
}

long long it()
{
    return puts("it");
}

long long not()
{
    return puts("not.");
}

long long that()
{
    return puts("that.");
}

long long easy()
{
    return puts("easy.");
}

int ___syscall_malloc()
{
    puts("Nope.");
    exit(0x1); /* do not return */
}

int ____syscall_malloc()
{
    puts("Good job.");
    return;
}

extern char stdin;

int main()
{
    unsigned int v0;  // [bp-0x5c]
    unsigned long long v1;  // [bp-0x58]
    char v2;  // [bp-0x4d]
    char v3;  // [bp-0x4c]
    char v4;  // [bp-0x4b]
    char v5;  // [bp-0x4a]
    char v6;  // [bp-0x49]
    char v7;  // [bp-0x48]
    char v8;  // [bp-0x47]
    char v9;  // [bp-0x46]
    char v10;  // [bp-0x29]
    unsigned long long v11;  // [bp-0x20]
    unsigned int v12;  // [bp-0x18]
    unsigned int v13;  // [bp-0x14]
    unsigned int v14;  // [bp-0x10]
    unsigned int v15;  // [bp-0xc]

    v15 = 0;
    printf("Please enter key: ");
    v14 = __isoc99_scanf("%23s", (unsigned int)&v7);
    if (v14 != 1)
    {
        ___syscall_malloc(); /* do not return */
    }
    if (v8 != 50)
    {
        ___syscall_malloc(); /* do not return */
    }
    if (v7 != 52)
    {
        ___syscall_malloc(); /* do not return */
    }
    fflush(stdin);
    memset(&v10, 0x0, 0x9);
    v10 = 42;
    v6 = 0;
    v11 = 2;
    v13 = 1;
    while (true)
    {
        v2 = 0;
        if (strlen(&v10) < 8)
        {
            v1 = v11;
            v2 = v1 < strlen(&v7);
        }
        if ((v2 & 1) == 0)
        {
            break;
        }
        v3 = v7;
        v4 = v8;
        v5 = v9;
        v10 = atoi(&v3);
        v11 += 3;
        v13 += 1;
    }
    v10 = 0;
    v12 = strcmp(&v10, "********");
    v0 = v12;
    if (v12 != -2)
    {
        if (v0 != -1)
        {
            if (v0 != 0)
            {
                if (v0 != 1)
                {
                    if (v0 != 2)
                    {
                        if (v0 != 3)
                        {
                            if (v0 != 4)
                            {
                                if (v0 != 5)
                                {
                                    if (v0 == 115)
                                    {
                                        ___syscall_malloc(); /* do not return */
                                    }
                                    ___syscall_malloc(); /* do not return */
                                }
                                ___syscall_malloc(); /* do not return */
                            }
                            ___syscall_malloc(); /* do not return */
                        }
                        ___syscall_malloc(); /* do not return */
                    }
                    ___syscall_malloc(); /* do not return */
                }
                ___syscall_malloc(); /* do not return */
            }
            ____syscall_malloc();
            return 0;
        }
        ___syscall_malloc(); /* do not return */
    }
    ___syscall_malloc(); /* do not return */
}

long long sub_40151d()
{
}

long long sub_401527()
{
}

long long sub_401531()
{
}

long long sub_40153b()
{
}

long long sub_401545()
{
}

long long sub_40154f()
{
}

long long sub_401559()
{
}

long long sub_40156d()
{
}

long long _fini()
{
    unsigned long v1;  // rax

    return v1;
}

