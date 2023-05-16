int _init()
{
    return;
    if (false)
    {
        *((int *)(4198413 + 12275 - 12))();
        return;
    }
}

typedef struct struct_0 {
    char padding_0[4];
    unsigned int field_4;
} struct_0;

int sub_401030()
{
    unsigned int v0;  // [bp-0x4]
    struct_0 *v2;  // ebx

    v0 = v2->field_4;
    goto v2[1].padding_0;
}

int sub_401080()
{
    goto *((int *)(ebx<4> - 16));
}

extern char main;

int _start()
{
    char *v0;  // [bp-0x1c]
    char *v1;  // [bp-0x18]
    void* v2;  // [bp-0x10]
    void* v3;  // [bp-0xc]
    unsigned int v4;  // [bp-0x8]
    unsigned int v5;  // [bp+0x0], Other Possible Types: char *
    char *v7;  // esi
    unsigned int v8;  // eax
    unsigned int v9;  // edx
    char *v10;  // ecx

    v7 = v5;
    v5 = v8;
    v4 = v9;
    v3 = 0;
    v2 = 0;
    v1 = v7;
    v0 = &main;
    __libc_start_main(v0, v1, v10, v2, v3); /* do not return */
}

// No decompilation output for function sub_4010bb

int sub_4010bc()
{
    unsigned int v0;  // [bp+0x0]
    unsigned int v2;  // ebx

    v2 = v0;
    return;
}

int __x86.get_pc_thunk.bx()
{
    unsigned int v0;  // [bp+0x0]
    unsigned int v2;  // ebx

    v2 = v0;
    return;
}

int deregister_tm_clones()
{
    unsigned int v0;  // [bp-0x1c]
    unsigned int v1;  // [bp-0x4]
    unsigned int v3;  // edx
    unsigned int v4;  // edx
    unsigned int v5;  // ebp

    __x86.get_pc_thunk.dx();
    v4 = v3 + 12075;
    return;
    if (false)
    {
        if (*((int *)(v4 - 20)) != 0)
        {
            v1 = stack_base + 0;
            v0 = v4 + 36;
            *((int *)(v4 - 20))();
            v5 = v1;
            return;
        }
        return;
    }
}

int register_tm_clones()
{
    unsigned int v0;  // [bp-0x1c]
    void* v1;  // [bp-0x18]
    unsigned int v2;  // [bp-0x8]
    unsigned int v3;  // [bp-0x4]
    unsigned int v5;  // edx
    unsigned int v6;  // edx
    unsigned int v7;  // ebx
    unsigned int v10;  // ebx

    __x86.get_pc_thunk.dx();
    v6 = v5 + 12011;
    v3 = stack_base + 0;
    v2 = v7;
    v10 = v2;
    return 0;
    if (false)
    {
        if (*((int *)(v6 - 4)) != 0)
        {
            v1 = 0;
            v0 = v6 + 36;
            v10 = v2;
            return edx<4>(v0);
        }
        v10 = v2;
        return 0;
    }
}

extern char __TMC_END__;
extern unsigned int __dso_handle;

int __do_global_dtors_aux()
{
    unsigned int v0;  // [bp-0x1c]

    if (__TMC_END__ == 0)
    {
        if (false)
        {
            v0 = __dso_handle;
            sub_401080();
            deregister_tm_clones();
            __TMC_END__ = 1;
            return;
        }
        deregister_tm_clones();
        __TMC_END__ = 1;
        return;
    }
    return;
}

int frame_dummy()
{
    return register_tm_clones();
}

int __x86.get_pc_thunk.dx()
{
    return;
}

extern char _GLOBAL_OFFSET_TABLE_;

int main()
{
    char *v0;  // [bp-0x8c]
    char *v1;  // [bp-0x88], Other Possible Types: unsigned int
    unsigned int v2;  // [bp-0x84]
    unsigned int v3;  // [bp-0x7e]
    unsigned int v4;  // [bp-0x7a]
    unsigned int v5;  // [bp-0x76]
    unsigned short v6;  // [bp-0x72]
    void* v7;  // [bp-0xc]

    v2 = &_GLOBAL_OFFSET_TABLE_;
    v7 = 0;
    v3 = 1953718111;
    v4 = 1600873313;
    v5 = 1667590243;
    v6 = 1817182315;
    v0 = "Please enter key: ";
    printf(v0);
    v0 = v2 - 8151;
    v1 = stack_base + -112;
    __isoc99_scanf(v0);
    v1 = &(stack_base)[126];
    v0 = &(stack_base)[112];
    if (strcmp(v0, v1) == 0)
    {
        v0 = v2 - 8148;
        printf(v0);
        return 0;
    }
    v0 = v2 - 8137;
    printf(v0);
    return 0;
}

int _fini()
{
    return;
}
