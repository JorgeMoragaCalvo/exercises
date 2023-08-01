# exercises
To use the calculator in C program, follow these steps to compile and run the program (write in the command line):  
Step 1:  
gcc -c binary_conversion.c -o binary_conversion.o  
gcc -c octal_conversion.c -o octal_conversion.o  
gcc -c menu.c -o menu.o  

Step 2:  
gcc binary_conversion.o octal_conversion.o menu.o -o calculator  

Step 3:  
./calculator
