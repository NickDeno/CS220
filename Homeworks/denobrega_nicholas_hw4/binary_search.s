.section .note.GNU-stack,"",%progbits
.text
	.global binary_search

#Assume array address is stored rdi
#Assume array size is in rsi
#Assume target is rdx

#rcx = low idx, rbx = high idx, r8 = mid idx, rdx = target, rax = return value
binary_search:
	#low = 0, high = size-1, set return value to -1
	movq $0, %rcx  
	movq %rsi, %rbx    
	decq %rbx 
	movq $-1, %rax

binary_search_loop: 	
	#If low <= high, continue, else jump to final_not_found
	cmpq %rbx, %rcx   
	jg final_not_found

	#int mid = low + ((high-low)/2)
	movq %rbx, %r8
	subq %rcx, %r8
	shrq $1, %r8
	addq %rcx, %r8

	#If target(rdx) == arr[mid](r9d), return mid(r8) by jumping to final_found
	movl (%rdi,%r8,4), %r9d 
	cmpq %rdx, %r9
	je final_found

	#If target(rdx) < arr[mid](r9d), high(rbx) = mid(r8)-1 and jump back to start of loop, else continue by jumping to binary_search_loop_continue
	cmpq %r9, %rdx
	jge binary_search_loop_continue
	movq %r8, %rbx
	decq %rbx
	jmp binary_search_loop

#target(rdx) > arr[mid](r9d), low(rcx) = mid(r8)+1 and continue by jumping to start of loop binary_search_loop
binary_search_loop_continue:
	movq %r8, %rcx
	incq %rcx
	jmp binary_search_loop	

#Will return -1 if target wasnt found
final_not_found:
	ret

#Will move r8(mid, which contains idx of target) into rax to be returned
final_found:
	movq %r8, %rax
	ret

