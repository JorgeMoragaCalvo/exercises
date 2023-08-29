.data
	msj1: .asciiz "Ingresa un numero flotante: "
	msj2: .asciiz "Tu numero flotante es: "

.text
	main:
	li $v0, 4
	la $a0, msj1
	syscall
	
	li $v0, 6 #los flotantes se guardan por defecto en f0
	syscall 
	
	li $v0, 4
	la $a0, msj2
	syscall 
	
	li $v0, 2
	add.s $f12, $f1, $f0 #f12 = f1 + f0 -> f12 = 0.0 + valor ingresado
	syscall 
	
	li $v0, 10
	syscall #termino de la funcion main