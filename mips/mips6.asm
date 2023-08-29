#EJEMPLO DE FUNCION
.data

.text
	main:
		add $t1, $zero, 5
		add $t2, $zero, 3
		
		jal suma
		
	
	li $v0, 10
	syscall
	
	suma:
		li $v0, 1
		add $a0, $t1, $t2
		syscall
	
	jr $ra #Termino de la funcion 1