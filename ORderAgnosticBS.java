package com.Akshit;

public class gggg {
    public static void main(String[]args){
        int[] arr = {2,3,5,7,9,10,15,18,17,15,18};
        int target = 15;
        int ans  = orderagnosticBS(arr,target);
        System.out.println(ans);


    }
    static int orderagnosticBS(int[]arr,int target){
        int start = 0;
        int end = arr.length -1;

        boolean isASc = arr[start]<arr[end];

        while (start <= end){
            int mid = start + (end - start) / 2;

            if (arr[mid]==target) {
                return mid;
            }
            if (isASc){
                if (target < arr[mid]){
                    end = mid-1;
                }else {
                    start = mid+1;
                }


            }else {
                if (target>arr[mid]){
                    start = mid +1;
                }else {
                    end = mid-1;
                    
                }
            }
        }


        return -1;
    }


}
