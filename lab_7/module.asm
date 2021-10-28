bits 64
default rel
segment .text
global string_copy

string_copy:
    cld

    cmp     rsi, rdi
    jge     start_copy

    add     rdi, rdx 
    dec     rdi
    add     rsi, rdx
    dec     rsi

    std

start_copy:
    mov     rcx, rdx
    rep     movsb
    ret
