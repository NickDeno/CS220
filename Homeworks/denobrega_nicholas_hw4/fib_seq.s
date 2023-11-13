.section .note.GNU-stack,"",%progbits
.text
	.global fib_seq
	
#Assume n is in rdi
fib_seq:
	#If n(rdi) == 0, return 0
    cmpq $0, %rdi  
    je final      

	#If n(rdi) == 0, return 1     
    cmpq $1, %rdi  
    je final          

	movq $0, %rax    
    movq $1, %rcx 

fib_loop:
	#Sums first and second term and stores in nth term(rax), then updates first and second term
	addq %rcx, %rax 
	movq %rcx, %rdx  
	movq %rax, %rcx  
	movq %rdx, %rax  

	#Decrements n(rdi) by 1, loop will run n times until n == 0
    decq %rdi     
    jnz fib_loop      

final:
    ret


