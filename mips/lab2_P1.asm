.data
    menu: .asciiz "Seleccione una opción:\n1. Calcular complemento (C-1 y C-2) de un número decimal.\n2. Sumar dos números.\n3. Restar dos números.\n4. Salir\n"
    num1: .asciiz "Ingrese un número: "
    num2: .asciiz "Ingrese otro número: "
    complemento1: .asciiz "El complemento (C-1) del número es: "
    complemento2: .asciiz "\nEl complemento (C-2) del número es: "
    sum: .asciiz "La suma es: "
    rest: .asciiz "La resta es: "
    error_invalid_option: .asciiz "Opción inválida.\n"
    error_negative_decimal: .asciiz "Debe ingresar un número decimal positivo.\n"

.text
.globl main
main:
    # Mostrar menú
    li $v0, 4
    la $a0, menu
    syscall

    # Leer opción ingresada
    li $v0, 5
    syscall
    move $s0, $v0 # Guardar la opción en $s0

    # Dependiendo de la opción ingresada se lleva a cabo una acción en particular
    beq $s0, 1, complement
    beq $s0, 2, suma
    beq $s0, 3, resta
    beq $s0, 4, fin_programa

    j invalid_option

complement:
    # Solicitar número decimal
    li $v0, 4
    la $a0, num1
    syscall

    # Leer número decimal
    li $v0, 5
    syscall
    move $s1, $v0 # Guardar número decimal en $s1

    # Verificar si el número es negativo
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
    # Solicitar primer número decimal
    li $v0, 4
    la $a0, num1
    syscall

    # Leer primer número decimal
    li $v0, 5
    syscall
    move $s1, $v0 # Guardar primer número decimal en $s1

    # Solicitar segundo número decimal
    li $v0, 4
    la $a0, num2
    syscall

    # Leer segundo número decimal
    li $v0, 5
    syscall
    move $s2, $v0 # Guardar segundo número decimal en $s2

    # Suma de los números
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
    # Solicitar primer número decimal
    li $v0, 4
    la $a0, num1
    syscall

    # Leer primer número decimal
    li $v0, 5
    syscall
    move $s1, $v0 # Guardar primer número decimal en $s1

    # Solicitar segundo número decimal
    li $v0, 4
    la $a0, num2
    syscall

    # Leer segundo número decimal
    li $v0, 5
    syscall
    move $s2, $v0 # Guardar segundo número decimal en $s2

    sub $s3, $s1, $s2 # Resta de losnúmeros

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