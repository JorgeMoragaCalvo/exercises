package main;

public class Kadane {
    public static void main(String[] args) {
        int[] arr = {-2, -3, 4, 1, -2, 1, 5, -3};
        //maxSubArraySum(arr);
        System.out.println("El maximo subarreglo es: " + maxSubArraySum(arr));
    }

    public static int maxSubArraySum(int[] arr){
        int max_so_far = Integer.MIN_VALUE;
        int max_ending_here = 0;

        for (int array : arr) {
            max_ending_here = max_ending_here + array;
            if (max_so_far < max_ending_here) max_so_far = max_ending_here;
            if (max_ending_here < 0) max_ending_here = 0;
        }
        return max_so_far;
    }
}
