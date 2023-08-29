.data
	prompt: .asciiz "\n Ingrese un numero: "
	result: .asciiz "La suma de los enteros de 1 hasta n es: "
	bye: .asciiz "\n *** Have a good day ***"
	
.text
	main:
		li $v0, 4       # codigo de llamada para imprimir un string
		la $a0, prompt  # se carga la direccion (load address) del mensaje en $a0
		syscall         # imprime el mensaje
		
		li $v0, 5       # codigo de llamada para leer un entero ingresado por el usuario
		syscall         # Se lee el valor de N en $v0
		
		blez $v0, end   # blez -> branch if less than or equal to zero. Branch to end if $v0 <= 0
		li $t0, 0       # borrar registro $t0 a cero
		
	loop:
		add $t0, $t0, $v0 # suma de numeros en el registro $t0
		addi $v0, $v0, -1 # sumar numeros en orden inverso
		bnez $v0, loop    # bnez -> branch if not equal zero. Branch to loop if $v0 is != zero
		
		li $v0, 4
		la $a0, result
		syscall 
		
		li $v0, 1
		move $a0, $t0    # mover el valor que sera imprimido en $a0
		syscall 
		# b main
		
	end:
		li $v0, 4
		la $a0, bye
		syscall
	
		li $v0, 10
		syscall
		