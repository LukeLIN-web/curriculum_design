package dshomewrok;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class SortingArraylistandlinkedlist {
	    // 交换
	    public static void swap(LinkedList<Integer> list, int i, int j) {
	        int t = list.get(j);
	        list.set(j, list.get(i));
	        list.set(i, t);
	    }
	    // 链表进行quicksort
	    public static void qsort(LinkedList<Integer> list, int left, int right) {
	        if(left < right) {
	            int i = left; // 初始化i，为链表第一个元素（最左边的元素）
	            int j = i + 1; // 初始化j = i + 1
	            int x = list.get(i); // 基准数字

	            while(j <= right) { // 大循环条件，j不能超过链表长度
	                // 如果 j 指向的值大于等于基准数字（如果比基准大，直接跳过）
	                while(j <= right && list.get(j) >= x) j++;
	                // 否则，j 指向的值小于基准，则交换
	                if(j <= right) {
	                    i++; // 交换时，i 首先要向后移动一位
	                    swap(list, i, j); // 交换
	                    j++; // 随后，j向后移动一位
	                }
	            } 
	            swap(list, left, i); // 最后，交换 i 位置的值和基准元素。一趟排序结束。
	            qsort(list, left, i-1);   // 递归排序左边
	            qsort(list, i+1, right);  // 递归排序右边
	        }
	    }
//能够对线性表中存储的数据进行排序
	    public static void quickSort(int[] arr,int low,int high){
	        int i,j,temp,t;
	        if(low>high){
	            return;
	        }
	        i=low;
	        j=high;
	     
	        temp = arr[low];//temp就是基准位
	        while (i<j) {
	            //先看右边，依次往左递减
	            while (temp<=arr[j]&&i<j) {
	                j--;
	            }
	            //再看左边，依次往右递增
	            while (temp>=arr[i]&&i<j) {
	                i++;
	            }
	            //如果满足条件则交换
	            if (i<j) {
	                t = arr[j];
	                arr[j] = arr[i];
	                arr[i] = t;
	            }
	        }
	        //最后将基准与i和j相等位置的数字交换,也就是交换到中间去
	         arr[low] = arr[i];
	         arr[i] = temp;
	        //递归调用左半数组
	        quickSort(arr, low, j-1);
	        //递归调用右半数组
	        quickSort(arr, j+1, high);
	    }

	    public static void main(String[] args) {
	        LinkedList<Integer> list = new LinkedList<Integer>();
	   //     ArrayList<Integer> arrlist = new ArrayList<Integer>(); 
//	        int[] arr = {4,2,5,3,7,9,0,1}; // test case 1
	      int[] arr = {5,4,3,2,1,6,7,9,8,10}; // test case 2
//	        int[] arr = {};// test case3 zero test
	        for(int i = 0; i < arr.length; i++) {
	            list.add(arr[i]);
	        }
	        qsort(list, 0, arr.length-1);
	        System.out.println(list.toString());
	        quickSort(arr, 0, arr.length-1 );
	        System.out.println(Arrays.toString(arr));
	    }
}
