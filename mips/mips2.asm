.data
	msj1: .asciiz "Ingresa un numero: "
	msj2: .asciiz "Tu numero es: "

.text
	main:
	li $v0, 4
	la $a0, msj1
	syscall
	
	li $v0, 5 #sentencia para capturar un entero. Se guarda temporalmente en v0
	syscall 
	move $t0, $v0 #el valor se mueve de v0 a t0
	
	li $v0, 4
	la $a0, msj2
	syscall 
	
	li $v0, 1
	move $a0, $t0 #para mostrar en pantalla, el valor se mueve de t0 a a0
	syscall
	
	li $v0, 10
	syscall #termino de la funcion main