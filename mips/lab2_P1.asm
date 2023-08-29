.data
    menu: .asciiz "Seleccione una opci�n:\n1. Calcular complemento (C-1 y C-2) de un n�mero decimal.\n2. Sumar dos n�meros.\n3. Restar dos n�meros.\n4. Salir\n"
    num1: .asciiz "Ingrese un n�mero: "
    num2: .asciiz "Ingrese otro n�mero: "
    complemento1: .asciiz "El complemento (C-1) del n�mero es: "
    complemento2: .asciiz "\nEl complemento (C-2) del n�mero es: "
    sum: .asciiz "La suma es: "
    rest: .asciiz "La resta es: "
    error_invalid_option: .asciiz "Opci�n inv�lida.\n"
    error_negative_decimal: .asciiz "Debe ingresar un n�mero decimal positivo.\n"

.text
.globl main
main:
    # Mostrar men�
    li $v0, 4
    la $a0, menu
    syscall

    # Leer opci�n ingresada
    li $v0, 5
    syscall
    move $s0, $v0 # Guardar la opci�n en $s0

    # Dependiendo de la opci�n ingresada se lleva a cabo una acci�n en particular
    beq $s0, 1, complement
    beq $s0, 2, suma
    beq $s0, 3, resta
    beq $s0, 4, fin_programa

    j invalid_option

complement:
    # Solicitar n�mero decimal
    li $v0, 4
    la $a0, num1
    syscall

    # Leer n�mero decimal
    li $v0, 5
    syscall
    move $s1, $v0 # Guardar n�mero decimal en $s1

    # Verificar si el n�mero es negativo
    bltz $s1, invalid_decimal

    # Calcular complemento (C-1)
    sub $s2, $zero, $s1

    # Calcular complemento (C-2)
    li $s3, 1
    xor $s3, $s3, $s2

    # Imprimir resultados
    li $v0, 4
    la $a0, complemento1
    syscall

    move $a0, $s2
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, complemento2
    syscall

    move $a0, $s3
    li $v0, 1
    syscall

    j fin_programa

suma:
    # Solicitar primer n�mero decimal
    li $v0, 4
    la $a0, num1
    syscall

    # Leer primer n�mero decimal
    li $v0, 5
    syscall
    move $s1, $v0 # Guardar primer n�mero decimal en $s1

    # Solicitar segundo n�mero decimal
    li $v0, 4
    la $a0, num2
    syscall

    # Leer segundo n�mero decimal
    li $v0, 5
    syscall
    move $s2, $v0 # Guardar segundo n�mero decimal en $s2

    # Suma de los n�meros
    add $s3, $s1, $s2

    # Imprimir resultado
    li $v0, 4
    la $a0, sum
    syscall

    move $a0, $s3
    li $v0, 1
    syscall

    j fin_programa

resta:
    # Solicitar primer n�mero decimal
    li $v0, 4
    la $a0, num1
    syscall

    # Leer primer n�mero decimal
    li $v0, 5
    syscall
    move $s1, $v0 # Guardar primer n�mero decimal en $s1

    # Solicitar segundo n�mero decimal
    li $v0, 4
    la $a0, num2
    syscall

    # Leer segundo n�mero decimal
    li $v0, 5
    syscall
    move $s2, $v0 # Guardar segundo n�mero decimal en $s2

    sub $s3, $s1, $s2 # Resta de losn�meros

    li $v0, 4
    la $a0, rest
    syscall

    move $a0, $s3
    li $v0, 1
    syscall

    j exit_program

invalid_option:
    li $v0, 4
    la $a0, error_invalid_option
    syscall

    j fin_programa

invalid_decimal:
    li $v0, 4
    la $a0, error_negative_decimal
    syscall

    j exit_program

fin_programa:
    li $v0, 10
    syscall