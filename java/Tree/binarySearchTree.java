
class node {
    int val;
    node left;
    node right;
    node(int data) {
        this.val = data;
        this.left = this.right = null; 
    }
}

// binary tree
class tree {
    node root;
    tree (int rootVal) {
        this.root =  new node(rootVal);
    }

    // adding an element assuming root is not null
    public void insert(node root, int key) {
        if(root.left == null && root.val > key) {
            root.left = new node(key);
        } else if (root.right == null && root.val < key){
            root.right = new node(key);
        } else {
            if (root.left.left == null || root.left.right == null) {
                insert(root.left, key);
            } else {
                insert(root.right, key);
            }
        }
        System.out.println(key + " inserted successfully");
    }

    // deleting an element
    public void delete(node root, int key) {
        if(root.val == key) {
            if (root.left == null && root.right == null) {
                root = null;
            } else if (root.left == null || root.right == null) {
                root = root.left != null ? root.left : root.right;
            } else {
                node curr = root;
                while(curr.left != null) {
                    curr = curr.left;
                }
                root.val = curr.val;
                delete(curr, key);
            }
        } else {
            delete(root.left, key);
            delete(root.right, key);
        }
    }

    // DFS traversal 
    public void inorder(node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    // BFS traversal
    public void levelOrder(node root) {
        node que[] = new node[100];
        int front = -1, rear = -1; 
        que[++rear] = root;
        while (rear > front) {
            node curr = que[++front];
            System.out.print(curr.val + " ");
            if (curr.left != null) que[++rear] = curr.left;
            if (curr.right != null) que[++rear] = curr.right;
        }
        System.out.println();
    }

    // height
    public int height(node root) {
        if (root == null) return 0;
        int lt = height(root.left);
        int rt = height(root.right);
        return 1 + (lt > rt ? lt : rt);
    }

    public int diameter(node root) {
        if (root == null) return 0;
        int lt = height(root.left);
        int rt = height(root.right);
        int rootDiameter = lt + rt + 1;
        int leftDiameter = diameter(root.left);
        int rightDiameter = diameter(root.right);

        return rootDiameter > leftDiameter ? rootDiameter > rightDiameter ? rootDiameter :rightDiameter : leftDiameter;
    }
}




public class binarySearchTree {
    public static void main(String[] args) {
        tree T1 = new tree(2);
        T1.insert(T1.root, 1);
        T1.insert(T1.root, 3);

        T1.inorder(T1.root);
        T1.levelOrder(T1.root);

        System.out.println("The height is " + T1.height(T1.root));
        System.out.println("The diameter is " + T1.diameter(T1.root));

    }
}
