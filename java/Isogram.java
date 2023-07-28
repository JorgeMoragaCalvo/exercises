package main;

import java.util.stream.Stream;

public class Isogram {
    public static void main(String[] args) {
        String str = "i so gram";

        if(isIsogram(str)) System.out.println("La palabra " + str + ", es un isograma");
        else System.out.println("La palabra " + str + ", no es un isograma");
    }

    public static boolean isIsogram(String str){
        //Stream.of crea un stream a partir de una matriz de caracteres generada mediante la
        //separación de la cadena en espacios y guiones.
        return Stream.of(str.split("-|\\s+"))
                .flatMapToInt(CharSequence::chars)//para convertir el stream de caracteres en un IntStream, permite trabajar con los valores enteros de los caracteres Unicode.
                .filter(c -> c != ' ')//filtro de los espacios en blanco
                .distinct()//elimina los elementos duplicados
                .count() == str.replaceAll("-", "").replaceAll(" ", "").length();
                //count para contar la cantidad de caracteres no duplicados. Si la cantidad es igual a la longitud
                // de la cadena original después de eliminar los espacios y guiones, significa que es un isograma.
    }

    /*
    public static boolean isIsogram(String str){
        int size = str.length();
        while(size > 0){
            for(int i = size - 2; i >= 0; i--){
                if((str.charAt(size - 1) == str.charAt(i)) && (str.charAt(size - 1) != '-' &&
                        str.charAt(size - 1) != ' ')) return false;
            }
            size--;
        }
        return true;
    }*/
}
