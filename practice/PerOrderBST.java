package interview;

import java.util.LinkedList;
import java.util.List;

/**
 * 
 * Recover a BST(int) from it's preoder traverse array
 * 
 * @author Yaxing Chen (yangcongknight@gmail.com)
 * @complexity O(N)
 */
public class PerOrderBST {
    
    static class Node {
	int value;
	Node left = null;
	Node right = null;
	
	public Node(int value) {
	    this.value = value;
	}
    }
    
    /**
     * use a node stack
     * 1. put 1st ele in stack
     * 2. if next ele is less than stack head, make it as left node of stack head and push it into stack.
     * 3. else unstack head node
     * 4. if next stack value is greater than cur ele, make cur ele as unstacked node's right node. push cur ele into stack.
     * 5. else loop 3
     * 6. loop 2
     * 
     * correction:
     * based on BST preorder attribute, 
     * when encounter an ele(Ea) that is greater than the former one(Eb), 
     * meanning it's the right sub root of the node(Ec) which is the first one less than it.
     * 
     * And all node between Ea and Ec has been finished reconstruct. therefore, they can be all pulled out of stack.
     *  
     * @complexity O(N)
     * @param int[] preorder
     * @return Node root
     */
    public static Node recoverBstFast(int[] preorder) {
	List<Node> stack = new LinkedList<Node>();
	Node root = new Node(preorder[0]);
	stack.add(root);
	for(int i = 1; i < preorder.length; i ++) {
	    int curValue = preorder[i];
	    Node tmp = new Node(curValue);
	    if(curValue < stack.get(0).value) {
		stack.get(0).left = tmp;
	    }
	    else {
		Node head = stack.remove(0);
		while(!stack.isEmpty()) {
		    if(head.value < curValue 
			    && stack.get(0).value > curValue) {
			head.right = tmp;
			head = null;
			break;
		    }
		    head = stack.remove(0);
		}
		if(head != null) {
		    head.right = tmp;
		}
	    }
	    stack.add(0, tmp);
	}
	return root;
    }
    
    /**
     * recover BST from it's preorder array
     * recursive algo
     * O(nlogn)
     * @param preorder
     * @param iStart
     * @param iEnd
     * @return
     */
    public static Node recoverBst(int[] preorder, int iStart, int iEnd) {
	if(iStart > iEnd) {
	    return null;
	}
	Node root = new Node(preorder[iStart ++]);
	int iRightRoot = iEnd + 1;
	for(int i = iStart; i <= iEnd; i ++) {
	    if(preorder[i] > root.value) {
		iRightRoot = i;
		break;
	    }
	}
	root.left = recoverBst(preorder, iStart, iRightRoot - 1);
	root.right = recoverBst(preorder, iRightRoot, iEnd);
	return root;
    }
    
    public static void insertBst(Node root, int value) {
	if(value < root.value) {
	    if(root.left == null) {
		root.left = new Node(value);
	    }
	    else {
		insertBst(root.left, value);
	    }
	}
	else if(value > root.value) {
	    if(root.right == null) {
		root.right = new Node(value);
	    }
	    else {
		insertBst(root.right, value);
	    }
	}
    }
    
    public static void printBstInOrder(Node root) {
	if(root == null) {
	    return;
	}
	printBstInOrder(root.left);
	System.out.println(root.value);
	printBstInOrder(root.right);
    }
    
    public static void printBstPreOrder(Node root) {
	if(root == null) {
	    return;
	}
	System.out.println(root.value);
	printBstPreOrder(root.left);
	printBstPreOrder(root.right);
    }
    
    public static void main(String[] args) {
	Node root = new Node(50);
	insertBst(root, 20);
	insertBst(root, 21);
	insertBst(root, 18);
	insertBst(root, 19);
	insertBst(root, 15);
	insertBst(root, 60);
	insertBst(root, 55);
	insertBst(root, 100);
	printBstInOrder(root);
	
	System.out.println();
	
	int[] preorder = {50, 20, 18, 15, 19, 21, 60, 55, 100};
	//int[] preorder = {50};
	Node newRoot = recoverBst(preorder, 0, preorder.length - 1);
	printBstInOrder(newRoot);
	
	System.out.println();
	
	newRoot = recoverBstFast(preorder);
	printBstInOrder(newRoot);
    }
    
}