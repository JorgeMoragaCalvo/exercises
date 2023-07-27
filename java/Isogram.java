package main;

public class Isogram {
    public static void main(String[] args) {
        String str = "i so gram";

        if(isIsogram(str)) System.out.println("La palabra " + str + ", es un isograma");
        else System.out.println("La palabra " + str + ", no es un isograma");
    }

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
    }
}
