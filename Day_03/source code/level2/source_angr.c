int _init()
{
    return;
    if (false)
    {
        *((int *)(4198413 + 24563 - 16))();
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

int sub_4010e0()
{
    goto *((int *)(ebx<4> - 20));
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

// No decompilation output for function sub_40111b

int sub_40111c()
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
    v4 = v3 + 24267;
    return;
    if (false)
    {
        if (*((int *)(v4 - 24)) != 0)
        {
            v1 = stack_base + 0;
            v0 = v4 + 60;
            *((int *)(v4 - 24))();
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
    v6 = v5 + 24203;
    v3 = stack_base + 0;
    v2 = v7;
    v10 = v2;
    return 0;
    if (false)
    {
        if (*((int *)(v6 - 4)) != 0)
        {
            v1 = 0;
            v0 = v6 + 60;
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
            sub_4010e0();
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

int no()
{
    unsigned int v0;  // [bp-0x1c], Other Possible Types: char *
    unsigned int v1;  // [bp-0xc]
    unsigned int v2;  // [bp-0x8]
    unsigned int v4;  // ebx

    v2 = v4;
    v1 = &_GLOBAL_OFFSET_TABLE_;
    v0 = "Nope.";
    puts(v0);
    v0 = 1;
    exit(v0); /* do not return */
}

extern char _GLOBAL_OFFSET_TABLE_;

int xd()
{
    char *v0;  // [bp-0x1c]
    unsigned int v1;  // [bp-0xc]

    v1 = &_GLOBAL_OFFSET_TABLE_;
    v0 = "Iii sapores crescit rei habetur disputo. An ab istud mo prius tanta error debet. Firma foret tes mea age capax sumne. Ex ex ipsas actum culpa neque ab saepe. Existenti et principia co immittere probandam imaginari re mo. Quapropter industriam ibi cui dissimilem cucurbitas progressus perciperem. Essendi ratione si habetur gi ignotas cognitu nusquam et.Sumpta vel uti obvium hoc tribuo libere. Egisse ingens hic sed inquam tamque rum gaudet aetate dat. Sum ignem jam ullas tur nexum vul. Divelli certius si errandi accipio colores de numerum. Is quavis tangam istius lumini essent vereor ab si. Aliam rea res tango vix simul certa certi.Imponere tractatu advenire ad superest occurret se quicquam si ha. Nihil solus pappo mo ei. Tum iis rom innata gloria hos quales. Ac sequentium im sufficeret institutum ad permittere at. Aliquis aliarum quaenam at de totaque notitia ob exhibet. Simus tes sae sacra error. Neque nomen ac ad opera is reges gi nobis. Se in objectivae ab is offerendum videbuntur satyriscos. Uno sequor trit";
    puts(v0);
    v0 = v1 - 17716;
    return puts(v0);
}

int ok()
{
    unsigned int v0;  // [bp-0xc], Other Possible Types: char *
    unsigned int v2;  // eax

    v0 = v2;
    v0 = "Good job.";
    puts(v0);
    return;
}

extern char _GLOBAL_OFFSET_TABLE_;

int main()
{
    char *v0;  // [bp-0x5c], Other Possible Types: void*
    void* v1;  // [bp-0x58], Other Possible Types: unsigned int, char *
    unsigned int v2;  // [bp-0x54]
    unsigned int v3;  // [bp-0x4c]
    char v4;  // [bp-0x45]
    unsigned int v5;  // [bp-0x44]
    char v6;  // [bp-0x3d]
    char v7;  // [bp-0x3c]
    char v8;  // [bp-0x3b]
    char v9;  // [bp-0x3a]
    char v10;  // [bp-0x39]
    char v11;  // [bp-0x38]
    char v12;  // [bp-0x37]
    char v13;  // [bp-0x21]
    unsigned int v14;  // [bp-0x18]
    unsigned int v15;  // [bp-0x14]
    unsigned int v16;  // [bp-0x10]
    void* v17;  // [bp-0xc]
    unsigned int v19;  // eax

    v5 = &_GLOBAL_OFFSET_TABLE_;
    v17 = 0;
    v0 = "Please enter key: ";
    printf(v0);
    v0 = v5 - 17106;
    v1 = stack_base + -57;
    v16 = __isoc99_scanf(v0);
    if (v16 != 1)
    {
        no(); /* do not return */
    }
    if (v11 != 48)
    {
        no(); /* do not return */
    }
    if (v10 != 48)
    {
        no(); /* do not return */
    }
    v0 = *((int *)*((int *)(v5 - 12)));
    fflush(v0);
    v0 = stack_base + -33;
    v1 = 0;
    v2 = 9;
    memset(v0, v1, v2);
    v13 = 100;
    v9 = 0;
    v14 = 2;
    v15 = 1;
    while (true)
    {
        v0 = &(stack_base)[33];
        v19 = strlen(v0);
        v4 = 0;
        if (v19 < 8)
        {
            v3 = v14;
            v0 = &(stack_base)[57];
            v4 = v3 < strlen(v0);
        }
        if ((v4 & 1) == 0)
        {
            break;
        }
        v6 = v10;
        v7 = v11;
        v8 = v12;
        v0 = &(stack_base)[61];
        v13 = atoi(v0);
        v14 += 3;
        v15 += 1;
    }
    v13 = 0;
    v1 = v5 - 17101;
    v0 = &(stack_base)[33];
    if (strcmp(v0, v1) == 0)
    {
        ok();
        return 0;
    }
    no(); /* do not return */
}

extern char _GLOBAL_OFFSET_TABLE_;

int xxd()
{
    char *v0;  // [bp-0x1c]
    unsigned int v1;  // [bp-0xc]

    v1 = &_GLOBAL_OFFSET_TABLE_;
    v0 = "Iii sapores crescit rei habetur disputo. An ab istud mo prius tanta error debet. Firma foret tes mea age capax sumne. Ex ex ipsas actum culpa neque ab saepe. Existenti et principia co immittere probandam imaginari re mo. Quapropter industriam ibi cui dissimilem cucurbitas progressus perciperem. Essendi ratione si habetur gi ignotas cognitu nusquam et.Sumpta vel uti obvium hoc tribuo libere. Egisse ingens hic sed inquam tamque rum gaudet aetate dat. Sum ignem jam ullas tur nexum vul. Divelli certius si errandi accipio colores de numerum. Is quavis tangam istius lumini essent vereor ab si. Aliam rea res tango vix simul certa certi.Imponere tractatu advenire ad superest occurret se quicquam si ha. Nihil solus pappo mo ei. Tum iis rom innata gloria hos quales. Ac sequentium im sufficeret institutum ad permittere at. Aliquis aliarum quaenam at de totaque notitia ob exhibet. Simus tes sae sacra error. Neque nomen ac ad opera is reges gi nobis. Se in objectivae ab is offerendum videbuntur satyriscos. Uno sequor trit";
    puts(v0);
    v0 = v1 - 14340;
    return puts(v0);
}

int n()
{
    unsigned int v0;  // [bp-0xc], Other Possible Types: char *
    unsigned int v2;  // eax

    v0 = v2;
    v0 = "Nope. ";
    return puts(v0);
}

extern char _GLOBAL_OFFSET_TABLE_;

int xxxd()
{
    char *v0;  // [bp-0x1c]
    unsigned int v1;  // [bp-0xc]

    v1 = &_GLOBAL_OFFSET_TABLE_;
    v0 = "Iii sapores crescit rei habetur disputo. An ab istud mo prius tanta error debet. Firma foret tes mea age capax sumne. Ex ex ipsas actum culpa neque ab saepe. Existenti et principia co immittere probandam imaginari re mo. Quapropter industriam ibi cui dissimilem cucurbitas progressus perciperem. Essendi ratione si habetur gi ignotas cognitu nusquam et.Sumpta vel uti obvium hoc tribuo libere. Egisse ingens hic sed inquam tamque rum gaudet aetate dat. Sum ignem jam ullas tur nexum vul. Divelli certius si errandi accipio colores de numerum. Is quavis tangam istius lumini essent vereor ab si. Aliam rea res tango vix simul certa certi.Imponere tractatu advenire ad superest occurret se quicquam si ha. Nihil solus pappo mo ei. Tum iis rom innata gloria hos quales. Ac sequentium im sufficeret institutum ad permittere at. Aliquis aliarum quaenam at de totaque notitia ob exhibet. Simus tes sae sacra error. Neque nomen ac ad opera is reges gi nobis. Se in objectivae ab is offerendum videbuntur satyriscos. Uno sequor trit";
    puts(v0);
    v0 = v1 - 10997;
    return puts(v0);
}

extern char _GLOBAL_OFFSET_TABLE_;

int ww()
{
    char *v0;  // [bp-0x1c]
    unsigned int v1;  // [bp-0xc]

    v1 = &_GLOBAL_OFFSET_TABLE_;
    v0 = "Good job. ";
    puts(v0);
    v0 = v1 - 10402;
    puts(v0);
    v0 = v1 - 10382;
    puts(v0);
    v0 = v1 - 10375;
    puts(v0);
    v0 = v1 - 10364;
    return puts(v0);
}

extern char _GLOBAL_OFFSET_TABLE_;

int xyxxd()
{
    char *v0;  // [bp-0x1c]
    unsigned int v1;  // [bp-0xc]

    v1 = &_GLOBAL_OFFSET_TABLE_;
    v0 = "Iii sapores crescit rei habetur disputo. An ab istud mo prius tanta error debet. Firma foret tes mea age capax sumne. Ex ex ipsas actum culpa neque ab saepe. Existenti et principia co immittere probandam imaginari re mo. Quapropter industriam ibi cui dissimilem cucurbitas progressus perciperem. Essendi ratione si habetur gi ignotas cognitu nusquam et.Sumpta vel uti obvium hoc tribuo libere. Egisse ingens hic sed inquam tamque rum gaudet aetate dat. Sum ignem jam ullas tur nexum vul. Divelli certius si errandi accipio colores de numerum. Is quavis tangam istius lumini essent vereor ab si. Aliam rea res tango vix simul certa certi.Imponere tractatu advenire ad superest occurret se quicquam si ha. Nihil solus pappo mo ei. Tum iis rom innata gloria hos quales. Ac sequentium im sufficeret institutum ad permittere at. Aliquis aliarum quaenam at de totaque notitia ob exhibet. Simus tes sae sacra error. Neque nomen ac ad opera is reges gi nobis. Se in objectivae ab is offerendum videbuntur satyriscos. Uno sequor trit";
    puts(v0);
    v0 = v1 - 7605;
    return puts(v0);
}

int _fini()
{
    return;
}