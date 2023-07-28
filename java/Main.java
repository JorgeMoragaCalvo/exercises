package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nIngrese un numero: ");
        int num = sc.nextInt();
        if(isArmstrong(num)) System.out.println("El numero " + num + ", es un numero Armstrong");
        else System.out.println("El numero " + num + ", no es un numero Armstrong");

    }
    /*
    public static int digits(int num){
        int count = 0;
        while(num != 0){
            num /= 10;
            count++;
        }
        return count;
    }*/

    public static int digits(int num){
        //String.valueOf() convierte diferentes tipos de datos en cadenas de caracteres (strings).
        return String.valueOf(num).length();
    }

    public static boolean isArmstrong(int num){
        if(num < 10) return true;
        else{
            int d = digits(num);
            int sum = String.valueOf(num)
                    .chars() //Convierte el número en un IntStream de los caracteres que lo componen
                    .map(Character::getNumericValue) //Convierte cada carácter a su valor numérico
                    .map(x -> (int) Math.pow(x, d)) //Eleva cada dígito a la potencia d
                    .sum(); //Suma todos los dígitos elevados a la potencia d

            return num == sum;
        }
    }

    /*
    public static boolean isArmstrong(int num){
        if(num < 10) return true;
        else{
            int i, a, sum = 0, num2, d;
            num2 = num;
            d = digits(num);
            i = d - 1;

            while(i >= 0){
                a = num / ((int) Math.pow(10, i));
                sum += (int) Math.pow(a, d);
                num = num % ((int) Math.pow(10, i));
                i--;
            }
            return num2 == sum;
        }
    }*/
}


