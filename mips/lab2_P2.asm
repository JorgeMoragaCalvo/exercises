.data
    arr: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    tam: .word 20
    msj: .asciiz "La suma del array es: "
    
.text
.globl main
main:
    la $s0, arr # Carga dirección del array en $s0
    lw $t0, tam # Se carga el tamaño del array en $t0
    li $t1, 0   # Contador para la suma en $t1
    li $t2, 0   # índice del ciclo en $t2
    
    funcion_suma:
        beq $t2, $t0, fin_suma # Comprobar si se ha alcanzado el final del array
        lw $t3, 0($s0) # Cargar el elemento actual del array en $t3
        add $t1, $t1, $t3 # Sumar el elemento actual al contador de suma
        add $s0, $s0, 4 # Avanzar al siguiente elemento del array        
        add $t2, $t2, 1 # Incrementar el índice del bucle
        
        j funcion_suma
        
    fin_suma:
        li $v0, 4
        la $a0, msj
        syscall
        
        li $v0, 1
        move $a0, $t1
        syscall    
    
    li $v0, 10
    syscall
