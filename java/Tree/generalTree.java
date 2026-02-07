import java.util.Queue;
import java.util.LinkedList;

class Node {
    int val;
    Node right;
    Node left;
    Node(int data) {
        this.val = data;
        this.left = this.right = null; 
    }
}

// binary tree
class tree {
    Node root;

    // adding an element assuming root is not null
    void insert(Node root, int key) {
        Node newNode = new Node(key);
        if (root == null) {
            root = newNode;
            return;
        }
    
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()) {
            Node curr = q.poll();

            if (curr.left == null) {
                curr.left = newNode;
                return;
            } else {q.add(curr.left);}
            if (curr.right == null) {
                curr.right = newNode;
                return;
            } else {q.add(curr.right);}
        }
        
    }

    // deleting an element
    void delete(Node root, int key) {
        
    }

    // DFS traversal 
    void inOrder(Node root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.print(root.val + " ");
        inOrder(root.right);
    }

    void preOrder(Node root) {
        if (root == null) return;
        System.out.print(root.val + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

    void postOrder(Node root) {
        if (root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.val + " ");
    }
    

    // BFS traversal
    void levelOrder(Node root) {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()) {
            Node curr = q.poll();
            if (curr.left != null) q.add(curr.left);
            if (curr.right != null) q.add(curr.right);
        }
        System.out.println();
    }

    // height
    int height(Node root) {
        if (root == null) return 0;
        int lt = height(root.left);
        int rt = height(root.right);
        return 1 + (lt > rt ? lt : rt);
    }

    int diameter(Node root) {
        if (root == null) return 0;
        int lt = height(root.left);
        int rt = height(root.right);
        int rootDiameter = lt + rt + 1;
        int leftDiameter = diameter(root.left);
        int rightDiameter = diameter(root.right);

        return rootDiameter > leftDiameter ? rootDiameter > rightDiameter ? rootDiameter :rightDiameter : leftDiameter;
    }
}


public class generalTree {
    public static void main(String[] args) {
        tree T1 = new tree();
        T1.insert(T1.root, 1);
        T1.insert(T1.root, 2);
        T1.insert(T1.root, 3);

        T1.inOrder(T1.root);
        T1.levelOrder(T1.root);

        System.out.println("The height is " + T1.height(T1.root));
        System.out.println("The diameter is " + T1.diameter(T1.root));

    }
}
