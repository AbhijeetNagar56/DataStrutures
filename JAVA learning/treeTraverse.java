

class Node {
    int val;
    Node left;
    Node right;
    Node(int data) {
        this.val = data;
        this.left = null;
        this.right = null;
    }
}




public class treeTraverse {
    public static void main(String[] args) {
        Node root = new Node(1);
        Node lf = new Node(2);
        Node rt = new Node(3);

        root.left = lf;
        root.right = rt;

        
    }
}