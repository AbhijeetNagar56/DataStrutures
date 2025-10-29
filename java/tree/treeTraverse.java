package tree;
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;
    Node (int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}


class tree {
    Node root;
    tree () {
        this.root = null;
    }

    public void insert (int item) {
        Node nNode = new Node(item);
        if (this.root == null) {
            this.root = nNode;
            return;
        }
        Node temp = this.root;
        while(temp != null){
            if (temp.left == null) {
                temp.left = nNode;
                break;
            } else if (temp.right == null){
                temp.right = nNode;
                break;
            }
            if (temp.left.left == null || temp.left.right == null) {
                temp = temp.left;
            }
            temp = temp.right;
            
        }
        
    }
    public void inorder(Node root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.print(root.data);
        inorder(root.right);
    }
    public void preorder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data);
        inorder(root.left);
        inorder(root.right);
    }
    public void postorder(Node root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        inorder(root.right);
        System.out.print(root.data);
    }

    static void traverse(Node root) {
        if (root == null) {
            return;
        }
        Queue<Node> Que = new LinkedList<>();

        Que.add(root);
        Que.add(null);

        while (!Que.isEmpty()) {
            Node curr = Que.remove();
            if (curr == null) {
                System.out.println();
                if (Que.isEmpty()) {
                    break;
                } else {
                    Que.add(null);
                }
            } else {
                System.out.print(curr.data + " ");
                if (curr.left != null) {
                    Que.add(curr.left);
                }
                if (curr.left != null) {
                    Que.add(curr.right);
                }
            }
        }
    }
}

public class treeTraverse {
    public static void main (String args[]) {
        tree t = new tree();
        t.insert(1);
        t.insert(2);
        t.insert(3);

        t.inorder(t.root);
        t.preorder(t.root);
        t.postorder(t.root);
    }
}