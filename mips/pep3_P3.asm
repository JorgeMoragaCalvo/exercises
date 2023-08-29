.data
    arr: .word 10, 20, 7, 830, 40, 6, 5, 7
    tam: .word 8
    value: .word 7
    msj1: .asciiz "El número "
    msj2: .asciiz " del array, aparece "
    msj3: .asciiz " veces."
    
.text
.globl main
main:
    la $t0, arr   # Dirección base del arreglo
    lw $t1, tam   # Tamaño del arreglo
    lw $t2, value # Valor buscado
    li $t3, 0     # Contador de apariciones del número
    
    # Inicio del ciclo
    loop:
        lw $t4, 0($t0)      # Cargar el elemento actual del arreglo
        beq $t4, $t2, found # Si es igual al valor buscado, saltar a found
        add $t0, $t0, 4   # Avanzar al siguiente elemento del arreglo
        add $t1, $t1, -1  # Decrementar el contador de tamaño
        bgtz $t1, loop      # Si el tamaño es mayor a cero, continuar el ciclo
        j end               # Si el tamaño es cero, terminar el programa

    found:
        add $t3, $t3, 1   # Incrementar el contador de apariciones
        add $t0, $t0, 4   # Avanzar al siguiente elemento del arreglo
        add $t1, $t1, -1  # Decrementar el contador de tamaño
        bgtz $t1, loop    # Si el tamaño es mayor a cero, continuar el ciclo

    # Se imprime el resultado
    end:
    	li $v0, 4
    	la $a0, msj1
    	syscall
    	
	li $v0, 1
	lw $a0, value
	syscall

	li $v0, 4
    	la $a0, msj2
    	syscall

        move $a0, $t3      
        li $v0, 1            
        syscall

	li $v0, 4
    	la $a0, msj3
    	syscall

        li $v0, 10           
        syscall
