package practice;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

/**
 * 
 * Given an array of intergers. 
 * Write a program to print all the permutations of the numbers in the array. 
 * The output should be sorted in a non-increasing order. 
 * 
 * @author Yaxing Chen (yangcongknight@gmail.com)
 * @complexity O(n!)
 */
public class OrderedPermutation {
    
    /**
     * print all permutations of an integer list in DESCENDING order
     * @param numbers
     * @param iStart
     * @complexity O(n!)
     */
    public static void orderPermutation(List<Integer> numbers, int iStart) {
	if(iStart == numbers.size() - 1) {
	    System.out.println(numbers);
	    return;
	}
	for(int i = iStart; i < numbers.size(); i ++) {
	    List<Integer> tmp = new LinkedList<Integer>(numbers);
	    removeInsert(tmp, i, iStart);
	    orderPermutation(tmp, iStart < numbers.size() - 1 ? iStart + 1 : iStart);
	}
    }
    
    /**
     * tool method
     * sort integer list based on dictionary order
     * @param numbers
     * @return
     */
    private static List<Integer> dicSort(List<Integer> numbers) {
	List<String> tmp = new LinkedList<String>();
	for(Integer num : numbers) {
	    tmp.add(num.toString());
	}
	numbers.clear();
	Collections.sort(tmp);
	for(int i = tmp.size() - 1; i >= 0; i --) {
	    numbers.add(Integer.parseInt(tmp.get(i)));
	}
	return numbers;
    }
    
    /**
     * tool method
     * remove element from x and insert it into position y
     * @param array
     * @param x
     * @param y
     */
    private static void removeInsert(List<Integer> array, int x, int y) {
	int tmp = array.get(x);
	array.remove(x);
	array.add(y, tmp);
    }
    
    public static void main(String[] args) {
	List<Integer> numbers = new LinkedList<Integer>();
	numbers.add(12);
	numbers.add(4);
	numbers.add(66);
	numbers.add(8);
	numbers.add(9);
	orderPermutation(dicSort(numbers), 0);
    }
    
}
