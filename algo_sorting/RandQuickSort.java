package sorting;

/**
 * Randomized Quick Sort
 * @complexity O(nlogn), worst case(prob: 1/(2^n)): O(n^2)</br>
 * 
 * @author Yaxing Chen
 *
 */
public class RandQuickSort {
    
    public static void randQuickSort(int[] array, int left, int right) {
	if(left >= right) {
	    return;
	}
	int leftPos = left;
	int rightPos = right;
	int pivot = left + (int)Math.round(Math.random() * (right - left));
	while(left < right) {
	    while(array[left] <= array[pivot] && pivot > left) {
		left ++;
	    }
	    swap(array, left, pivot);
	    pivot = left;
	    while(array[right] >= array[pivot] && pivot < right) {
		right --;
	    }
	    swap(array, right, pivot);
	    pivot = right;
	}
	randQuickSort(array, leftPos, pivot - 1);
	randQuickSort(array, pivot + 1, rightPos);
    }
    
    private static void swap(int[] array, int x, int y) {
	int tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
    }
    
    public static void main(String[] args) {
	int[] originArray = {6,2,1,10,9,5};
	randQuickSort(originArray, 0, originArray.length - 1);
	for(int i = 0; i < originArray.length; i ++) {
	    System.out.print(originArray[i] + " ");
	}
	System.out.println();
    }
    
}
