package practice;

/**
 * Given two strings .Print all the interleavings of the two strings.
 * Interleaving means that the if B comes after A .It should also come after A in the interleaved string.
 *
 * @author Yaxing Chen (yangcongknight@gmail.com)
 * @complexity O(m*n)
 */
public class StringInterleaving {
    
    private static void interleave(String str1, String str2) {
	System.out.println(str1 + str2);
	for(int i = 0; i < str1.length() - 1; i ++) {
	    StringBuffer interleave = new StringBuffer();
	    interleave.append(str1.substring(0, i + 1));
	    String subStr = str1.substring(i + 1);
	    for(int j = 1; j <= str2.length(); j ++) {
		StringBuffer tmp = new StringBuffer(str2);
		tmp.insert(j, subStr);
		System.out.println(interleave.toString() + tmp.toString());
	    }
	}
    }
    
    public static void printInterleave(String str1, String str2) {
	interleave(str1, str2);
	interleave(str2, str1);
    }
    
    public static void main(String[] args) {
	String str1 = "abc";
	String str2 = "def";
	printInterleave(str1, str2);
    }
    
}