#los datos o variables del programa
.data
	numero: .word 5 #se guardar el 5 en la variable numero. .word le indica a mips que se guarda un entero
	flotante: .float 6.9
	num_double: .double 9.6
	espacio: .asciiz "\n"
	
#Todas las instrucciones que el programa necesita
.text
	main:
	li $v0, 1 # Setencia que indica que se va a mostrar un entero
	lw $a0, numero #trae el valor en memoria para mostrar en pantalla
	syscall
	
	li $v0, 4
	la $a0, espacio
	syscall
	
	li $v0, 2 # Setencia que indica que se va a mostrar un flotante
	lwc1 $f12, flotante #trae el valor en memoria para mostrar en pantalla. Ojo con las palabras reservadas para flotantes
	syscall
	
	li $v0, 4
	la $a0, espacio
	syscall
	
	li $v0, 3 # Setencia que indica que se va a mostrar un double
	ldc1 $f12, num_double
	syscall
	
	li $v0, 10
	syscall #termino de la funcion main