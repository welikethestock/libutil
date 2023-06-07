text SEGMENT READ EXECUTE 'CODE'

    LibUtil_Syscall0 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx
        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp


    LibUtil_Syscall0 endp

    LibUtil_Syscall1 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx

        mov     rcx,    rdx

        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp


    LibUtil_Syscall1 endp

    LibUtil_Syscall2 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx

        mov     rcx,    rdx
        mov     rdx,    r8

        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp


    LibUtil_Syscall2 endp

    LibUtil_Syscall3 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx

        mov     rcx,    rdx
        mov     rdx,    r8
        mov     r8,     r9

        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp

    LibUtil_Syscall3 endp

    LibUtil_Syscall4 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx

        mov     rcx,    rdx
        mov     rdx,    r8
        mov     r8,     r9
        mov     r9,     qword ptr [rbp + 018h]

        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp

    LibUtil_Syscall4 endp

    LibUtil_Syscall5 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx

        mov     rcx,    rdx
        mov     rdx,    r8
        mov     r8,     r9
        mov     r9,     qword ptr [rbp + 018h]

        push    qword ptr [rbp + 020h]

        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp

        ret

    LibUtil_Syscall5 endp

    LibUtil_Syscall6 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx

        mov     rcx,    rdx
        mov     rdx,    r8
        mov     r8,     r9
        mov     r9,     qword ptr [rbp + 018h]

        push    qword ptr [rbp + 020h]
        push    qword ptr [rbp + 028h]

        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp

        ret

    LibUtil_Syscall6 endp

    LibUtil_Syscall7 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx

        mov     rcx,    rdx
        mov     rdx,    r8
        mov     r8,     r9
        mov     r9,     qword ptr [rbp + 018h]

        push    qword ptr [rbp + 020h]
        push    qword ptr [rbp + 028h]
        push    qword ptr [rbp + 030h]

        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp

        ret

    LibUtil_Syscall7 endp

    LibUtil_Syscall8 proc

        push    rbp
        mov     rbp,    rsp

        and     rsp,    -010h

        mov     rax,    rcx

        mov     rcx,    rdx
        mov     rdx,    r8
        mov     r8,     r9
        mov     r9,     qword ptr [rbp + 018h]

        push    qword ptr [rbp + 020h]
        push    qword ptr [rbp + 028h]
        push    qword ptr [rbp + 030h]
        push    qword ptr [rbp + 038h]

        mov     r10,    rax

        sub     rsp,    028h
        syscall
        add     rsp,    028h

        mov     rdx,    rax
        mov     ax,     ds
        mov     ss,     ax
        mov     rax,    rdx

        mov     rsp,    rbp
        pop     rbp

        ret

    LibUtil_Syscall8 endp

text ends

end
