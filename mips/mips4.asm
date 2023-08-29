.data
	msj1: .asciiz "Ingresa un double: "
	msj2: .asciiz "Este es tu numero: "
	msj3: .asciiz "Ingresa tu nombre: "
	msj4: .asciiz "Hola "
	name: .space 20 #se reserva espacio para lo que ingrese el usuario
	jump: .asciiz "\n"
	
.text
	main:
		li $v0, 4
		la $a0, msj1
		syscall
		
		li $v0, 7
		syscall
		
		li $v0, 4
		la $a0, msj2
		syscall
		
		li $v0, 3
		add.d $f12, $f2, $f0 #$f2 tiene que ser par, es decir, $f(2*n) con n >= 1
		syscall
		
		li $v0, 4
		la $a0, jump
		syscall 
		
		li $v0, 4
		la $a0, msj3
		syscall
		
		li $v0, 8 #para capturar string
		la $a0, name #capturar string del usuario
		li $a1, 20
		syscall 
		
		li $v0, 4
		la $a0, msj4
		syscall
		
		li $v0, 4
		la $a0, name
		syscall 
		
	
	li $v0, 10
	syscall 
	
	
	