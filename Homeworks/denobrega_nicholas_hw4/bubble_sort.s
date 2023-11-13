.section .note.GNU-stack,"",%progbits
.text
	.global bubble_sort

#Assume array address in rdi
#Assume array size in rsi
bubble_sort:
	#Decrement size(rsi) by 1 and set outer loop idx i(rcx) to 0
	decq %rsi
	movq $0, %rcx  

loop1:
	#If i(rcx) < size-1(rsi), set inner loop idx j(rdx) to 0 and continue, else jump to final
	cmpq %rsi, %rcx 
	jge final
	movq $0, %rdx

#rcx = i, rdx = j, rsi = size-1, r8d = arr[j], r9d = arr[j+1]
loop2:
	#If j(rdx) < size-1(rsi), continue, else jump to loop1_next
	cmpq %rsi, %rdx
	jge loop1_next 

	#Loads arr[j] into r8d and arr[j+1] into r9d
	movl (%rdi,%rdx,4), %r8d  
    movl 4(%rdi,%rdx,4), %r9d

	#If arr[j] <= arr[j+1], jump to loop2_next, else swap elements 
    cmpl %r9d, %r8d 
    jle loop2_next  

	# Swap array[j](r8d) with array[j+1](r9d)
    movl %r8d, 4(%rdi,%rdx,4)
    movl %r9d, (%rdi,%rdx,4) 

loop2_next:
#Increment inner loop idx j(rdx) by 1, and restart inner loop by jumping back to loop2
	incq %rdx 
	jmp loop2

loop1_next:
	#Increment outer loop idx i(rcx) by 1, and restart outer loop by jumping back to loop1
	incq %rcx
	jmp loop1

final:
	movq $0, %rax
	ret

