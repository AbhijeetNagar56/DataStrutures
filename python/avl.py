class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.height = 1  # New node has height 1


class AVL:
    def __init__(self):
        self.root = None  # Root of the AVL Tree

    def height(self, node):
        return node.height if node else 0

    def balance(self, node):
        return self.height(node.left) - self.height(node.right) if node else 0

    def leftrotate(self, z):
        y = z.right
        T2 = y.left

        y.left = z
        z.right = T2

        z.height = max(self.height(z.left), self.height(z.right)) + 1
        y.height = max(self.height(y.left), self.height(y.right)) + 1

        return y

    def rightrotate(self, z):
        y = z.left
        T3 = y.right

        y.right = z
        z.left = T3

        z.height = max(self.height(z.left), self.height(z.right)) + 1
        y.height = max(self.height(y.left), self.height(y.right)) + 1

        return y

    def insert(self, root, key):
        if root is None:
            return Node(key)

        if key < root.val:
            root.left = self.insert(root.left, key)
        elif key > root.val:
            root.right = self.insert(root.right, key)
        else:
            return root  # No duplicates allowed

        # Update height of the current node
        root.height = max(self.height(root.left), self.height(root.right)) + 1

        # Get balance factor
        bf = self.balance(root)

        # Left Heavy (Right Rotation)
        if bf > 1:
            if key < root.left.val:  # Left-Left Case
                return self.rightrotate(root)
            else:  # Left-Right Case
                root.left = self.leftrotate(root.left)
                return self.rightrotate(root)

        # Right Heavy (Left Rotation)
        if bf < -1:
            if key > root.right.val:  # Right-Right Case
                return self.leftrotate(root)
            else:  # Right-Left Case
                root.right = self.rightrotate(root.right)
                return self.leftrotate(root)

        return root

    def insert_key(self, key):
        self.root = self.insert(self.root, key)

    def min_value_node(self, node):
        """Finds the node with the minimum value (leftmost node)"""
        while node.left:
            node = node.left
        return node

    def delete(self, root, key):
        if root is None:
            return root

        # Standard BST deletion
        if key < root.val:
            root.left = self.delete(root.left, key)
        elif key > root.val:
            root.right = self.delete(root.right, key)
        else:
            # Node with one child or no child
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left

            # Node with two children: Get inorder successor (smallest in right subtree)
            temp = self.min_value_node(root.right)
            root.val = temp.val  # Copy successor value to current node
            root.right = self.delete(root.right, temp.val)  # Delete successor

        if root is None:
            return root

        # Update height
        root.height = max(self.height(root.left), self.height(root.right)) + 1

        # Get balance factor
        bf = self.balance(root)

        # Left Heavy
        if bf > 1:
            if self.balance(root.left) >= 0:  # Left-Left Case
                return self.rightrotate(root)
            else:  # Left-Right Case
                root.left = self.leftrotate(root.left)
                return self.rightrotate(root)

        # Right Heavy
        if bf < -1:
            if self.balance(root.right) <= 0:  # Right-Right Case
                return self.leftrotate(root)
            else:  # Right-Left Case
                root.right = self.rightrotate(root.right)
                return self.leftrotate(root)

        return root

    def delete_key(self, key):
        self.root = self.delete(self.root, key)

    def levelorder(self, root):
        if not root:
            return
        queue = [root]

        while queue:
            level_size = len(queue)
            for _ in range(level_size):
                node = queue.pop(0)
                print(node.val, end=" ")

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            print()  # New line for each level


# Driver Code
avl_tree = AVL()

for i in range(1, 8):  # Inserting values 1 to 7
    avl_tree.insert_key(i)

print("Level Order Traversal of AVL Tree:")
avl_tree.levelorder(avl_tree.root)

print("\nDeleting node 4:")
avl_tree.delete_key(4)
avl_tree.levelorder(avl_tree.root)

print("\nDeleting node 2:")
avl_tree.delete_key(2)
avl_tree.levelorder(avl_tree.root)
