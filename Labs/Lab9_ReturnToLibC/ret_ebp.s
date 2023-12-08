.section .note.GNU-stack,"",%progbits
.text
    .global get_ebp

get_ebp:
    mov %ebp, %eax
    ret