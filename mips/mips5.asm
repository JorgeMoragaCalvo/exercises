.data
	msj1: .asciiz "Ingresa el primer numero: "
	msj2: .asciiz "Ingresa el segundo numero: "
	msj3: .asciiz "La suma es: "
	msj4: .asciiz "La resta es: "
	msj5: .asciiz "La multiplicacion es: "
	jump: .asciiz "\n"
	
.text 
	main:
		li $v0, 4
		la $a0, msj1
		syscall 
		
		li $v0, 5 #con 5 se indica que se captura un entero del usuario
		syscall
		move $t0, $v0 #como $v0 es temporal, se necesita mover el dato para despues recuperarlo
				
		li $v0, 4
		la $a0, msj2
		syscall
		
		li $v0, 5
		syscall
		move $t1, $v0
		
		li $v0, 4
		la $a0, msj3
		syscall
		
		li $v0, 1
		add $a0, $t0, $t1
		syscall 
		
		li $v0, 4
		la $a0, jump
		syscall
		
		li $v0, 4
		la $a0, msj4
		syscall
		
		li $v0, 1
		sub $a0, $t0, $t1
		syscall
		
		li $v0, 4
		la $a0, jump
		syscall
		
		li $v0, 4
		la $a0, msj5
		syscall
		
		li $v0, 1
		mul $a0, $t0, $t1
		syscall
	