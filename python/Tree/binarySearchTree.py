class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, root, key):
        if root is None:
            return Node(key)
        if key < root.val:
            root.left = self.insert(root.left, key)
        elif key > root.val:
            root.right = self.insert(root.right, key)
        else:
            print("Duplicates are not allowed in BST")
        return root

    def inOrder(self, root):
        if root is None:
            return
        self.inOrder(root.left)
        print(root.val, end=" ")
        self.inOrder(root.right)

    def height(self, root):
        if root is None:
            return 0
        return max(self.height(root.left), self.height(root.right)) + 1

    def diameter(self, root):
        if root is None:
            return 0
        left_height = self.height(root.left)
        right_height = self.height(root.right)
        dwr = left_height + right_height + 1
        lsd = self.diameter(root.left)
        rsd = self.diameter(root.right)
        return max(dwr, lsd, rsd)

    def maxfromLST(self, root):
        while root.right:
            root = root.right
        return root

    def delete(self, root, key):
        if root is None:
            return root
        if key < root.val:
            root.left = self.delete(root.left, key)
        elif key > root.val:
            root.right = self.delete(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            temp = self.maxfromLST(root.left)
            root.val = temp.val
            root.left = self.delete(root.left, temp.val)
        return root

    def levelorder(self, root):
        if root is None:
            return
        queue = [root]
        while queue:
            curr = queue.pop(0)
            print(curr.val, end=" ")
            if curr.left:
                queue.append(curr.left)
            if curr.right:
                queue.append(curr.right)

# Creating BST
bst = BST()
bst.root = bst.insert(bst.root, 4)
bst.insert(bst.root, 2)
bst.insert(bst.root, 6)
bst.insert(bst.root, 1)
bst.insert(bst.root, 3)
bst.insert(bst.root, 5)
bst.insert(bst.root, 7)

# In-order traversal before deletion
print("Inorder before deletion:")
bst.inOrder(bst.root)

# Deleting node 2
print("\n\nDeleting node 2...")
bst.root = bst.delete(bst.root, 2)

# In-order traversal after deletion
print("\nInorder after deletion:")
bst.inOrder(bst.root)
