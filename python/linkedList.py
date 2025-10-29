class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
class bst:
    def __init__(self):
        self.root = None
    def insert(self, root, key):
        node = Node(key)
        if(self.root == None):
            self.root = Node(key)
            return
        if(root.left == None and root.val > key):
            root.left = Node(key)
        elif(root.right == None and root.val < key):
            root.right = Node(key)
        else:
            if(root.val > key):
                self.insert(root.left, key)
            else:
                self.insert(root.right, key)
    
    def inorder(self, root):
        if(root == None):
            return
        self.inorder(root.left)
        print(root.val, end=" ")
        self.inorder(root.right)


def isIdentical(t1, t2):
    if(t1 == None and t2 == None):
        return True
    if(t1 == None or t2 == None):
        return False
    
    
    return t1.val == t2.val and isIdentical(t1.left, t2.left) and isIdentical(t1.right, t2.right)
    
    



t1 = bst()
t1.insert(t1.root, 1)
t1.insert(t1.root, 0)
t1.insert(t1.root, 2)

t1.inorder(t1.root)

t2 = bst()
t2.insert(t2.root, 1)
t2.insert(t2.root, 0)
t2.insert(t2.root, 2)

t2.inorder(t2.root)

print(isIdentical(t1.root, t2.root))



