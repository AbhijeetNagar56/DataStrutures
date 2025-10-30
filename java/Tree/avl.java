package tree;

class Node {
    int val;
    Node left;
    Node right;
    int ht;
    Node (int x){
        this.val = x;
        this.left = this.right = null;
        this.ht = 1;
    }
}
class avlTree {
    Node Root = null;
    public int height(Node n){
        if(n == null) return 0;
        return n.ht;
    }

    public int balanceFactor(Node n){
        if(n == null) return 0;
        return height(n.left) - height(n.right);
    }

    public Node rightrotate(Node n){
        Node x = n.left;
        Node t2 = x.right;

        x.right = n;
        n.left = t2;

        n.ht = 1 + Math.max(height(n.left), height(n.right));
        x.ht = 1 + Math.max(height(x.left), height(x.right));
        
        return x;
    }

    public Node leftrotate(Node n){
        Node x = n.right;
        Node t2 = x.left;

        x.left = n;
        n.right = t2;

        n.ht = 1 + Math.max(height(n.left), height(n.right));
        x.ht = 1 + Math.max(height(x.left), height(x.right));
        return x;
    }

    public Node insert(Node n, int key){
        if(n == null) {
            this.Root = new Node(key);
            return this.Root;
        }
        if(key < this.Root.val){
            n.left = insert(n.left, key);
        } else if (key > this.Root.val){
            n.right = insert(n.right, key);
        } else {
            return n;
        }

        n.ht = 1 + Math.max(height(n.left), height(n.right));
        int bf = balanceFactor(n);
        // Rotation wala part
        if (bf > 1 && key < n.left.val)
            return rightrotate(n);

        // Right Right Case (RR Rotation)
        if (bf < -1 && key > n.right.val)
            return leftrotate(n);

        // Left Right Case (LR Rotation)
        if (bf > 1 && key > n.left.val) {
            n.left = leftrotate(n.left);
            return rightrotate(n);
        }

        // Right Left Case (RL Rotation)
        if (bf < -1 && key < n.right.val) {
            n.right = rightrotate(n.right);
            return leftrotate(n);
        }

        return n;
    }

    public void dis(Node r){
        if(r == null) return;
        dis(r.left);
        System.out.print(r.val + " ");
        dis(r.right);
    }

}



public class avl {
    public static void main(String args[]){

        avlTree at = new avlTree();
        at.insert(at.Root, 1);
        at.insert(at.Root, 3);
        at.insert(at.Root, 5);
        at.insert(at.Root, 2);

        at.dis(at.Root);
    }
}


