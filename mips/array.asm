#ARRAY EXAMPLE
.data
	names: .space 16
	Ryan: .asciiz "Ryan\n"
	Tammi: .asciiz "Tammi\n"
	Blake: .asciiz "Blake\n"
	Josh: .asciiz "Josh\n"

.text
	main:
		la $t0, names
		
		la $t1, Ryan
		sw $t1, 0($t0)
		
		la $t1, Tammi
		sw $t1, 4($t0)
		
		la $t1, Blake
		sw $t1, 8($t0)
		
		la $t1, Josh
		sw $t1, 12($t0)
		
		#printing ith element
		li $v0, 4
		lw $a0, 0($t0)
		syscall
	
	li $v0, 10
	syscall 