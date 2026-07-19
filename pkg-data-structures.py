#stack
class stack:
	max = 10
	top = -1
	def __init__(self):
		self.stack = [None]*self.max
	def isEmpty(self):
		return self.top == -1
	def isFull(self):
		return self.top == self.max-1
	def push(self, item):
		self.top += 1
		self.stack[self.top] = item
	def pop(self):
		item = self.stack[self.top]
		self.stack[self.top] = None
		self.top -= 1
		return item
	def peek(self):
		return self.stack[self.top]
	def __str__(self):
		return str([i for i in self.stack if i!=None])
		


#queue
class queue:
	max = 10
	front = -1
	rear = -1
	def __init__(self):
		self.q = [None]*self.max
	def isFull(self):
		return self.rear == self.max - 1
	def isEmpty(self):
		return self.front == -1
	def enqueue(self, data):
		if self.isFull():
			return "Queue Overflow!"
		if self.isEmpty():
			self.front = 0
		self.rear += 1
		self.q[self.rear] = data
	def dequeue(self):
		if self.isEmpty():
			return "Queue Underflow!"
		item = self.q[self.front]
		self.q[self.front] = None
		if self.front == self.rear:
			self.front = self.rear = -1
		else:
			self.front += 1
		return item

	def peek(self):
		if self.isEmpty():
			return "Queue is Empty"
		return self.q[self.front]
	def noOfElement(self):
		return len([i for i in self.q if i is not None])
	def __str__(self):
		return str([i for i in self.q if i is not None])

#circular queue
class circularQue:
    Max = 5

    def __init__(self):
        self.q = [None] * self.Max
        self.r = -1
        self.f = -1

    def isEmpty(self):
        return self.f == -1

    def isFull(self):
        return (self.r + 1) % self.Max == self.f

    def enqueue(self, data):
        if self.isFull():
            return "No space"
        if self.isEmpty():
            self.f = 0
        self.r = (self.r + 1) % self.Max
        self.q[self.r] = data

    def dequeue(self):
        if self.isEmpty():
            return "Empty Queue"
        item = self.q[self.f]
        self.q[self.f] = None
        if self.f == self.r:
            self.f = self.r = -1
        else:
            self.f = (self.f + 1) % self.Max
        return item

    def peek(self):
        if self.isEmpty():
            return "Queue is Empty"
        return self.q[self.f]

    def __str__(self):
        return str([i for i in self.q if i is not None])
    
     


#linked list
class Node:
    def __init__(self, data=None):
        self.data = data
        self.val = data
        self.next = None

class linkedList:
    def __init__(self):
        self.head = None
        self.current = None
        self.size = 0

    def isEmpty(self):
        return self.head is None

    # Inserting in the starting
    def add(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            self.size += 1
            return
        newNode.next = self.head
        self.head = newNode
        self.size += 1

    # Inserting at the end
    def append(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            self.size += 1
            return
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        temp.next = newNode
        self.size += 1

    # only delete the first occurence of the element
    def delete(self, key):
        if self.head is None:
            print("List is empty")
            return

        if self.head.data == key:
            self.head = self.head.next
            self.size -= 1
            return

        temp = self.head.next
        pre = self.head
        while temp is not None:
            if temp.data == key:
                pre.next = temp.next
                self.size -= 1
                return
            pre = temp
            temp = temp.next
        print("The element is not present")

    def get_size(self):
        return self.size

    def __str__(self):
        s = ''
        temp = self.head
        while temp:
            s += str(temp.data) + '->'
            temp = temp.next
        return s


# Circular LinkedList
class circularLL:
    def __init__(self):
        self.head = None
        self.size = 0

    def isEmpty(self):
        return self.head is None

    def append(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            newNode.next = newNode
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = newNode
            newNode.next = self.head
        self.size += 1

    def delete(self, key):
        if self.head is None:
            return "List is Empty"

        if self.head.data == key:
            if self.head.next == self.head:
                self.head = None
            else:
                temp = self.head
                while temp.next != self.head:
                    temp = temp.next
                temp.next = self.head.next
                self.head = self.head.next
            self.size -= 1
            return

        prev = self.head
        curr = self.head.next
        while curr != self.head:
            if curr.data == key:
                prev.next = curr.next
                self.size -= 1
                return
            prev = curr
            curr = curr.next

        return "Element is not present in the list"

    def __str__(self):
        if self.head is None:
            return ''
        s = ''
        temp = self.head
        while True:
            s += str(temp.data) + '->'
            temp = temp.next
            if temp == self.head:
                break
        return s


#trees
class node:
    def __init__(self, data):
        self.data = data
        self.val = data
        self.left = None
        self.right = None
        self.height = 1

class gbt:
    def __init__(self):
        self.root = None

    def allLeaf(self, r):
        if r is None:
            return
        if r.left is None and r.right is None:
            print(r.val, end=" ")
        self.allLeaf(r.left)
        self.allLeaf(r.right)

    def height(self, r):
        if r is None:
            return 0
        return max(self.height(r.left), self.height(r.right)) + 1

    def diameter(self, r):
        if r is None:
            return 0
        dwr = self.height(r.left) + self.height(r.right) + 1
        lsd = self.diameter(r.left)
        rsd = self.diameter(r.right)
        return max(dwr, lsd, rsd)

    def delete(self, root, key):
        if root is None:
            return None
        if root.val == key:
            if root.left is None and root.right is None:
                return None
            elif root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            temp = root.left
            while temp.right:
                temp = temp.right
            root.val = temp.val
            root.left = self.delete(root.left, temp.val)
            return root
        root.left = self.delete(root.left, key)
        root.right = self.delete(root.right, key)
        return root

    def levelorder(self, root):
        if root is None:
            return
        q = [root, None]
        while q:
            c = q.pop(0)
            if c is None:
                print()
                if not q:
                    break
                q.append(None)
            else:
                print(c.val, end=' ')
                if c.left:
                    q.append(c.left)
                if c.right:
                    q.append(c.right)

    def insert(self, r, key):
        nNode = node(key)
        if self.root is None:
            self.root = nNode
            return
        if r is None:
            return
        q = [r]
        while q:
            temp = q.pop(0)
            if temp.left is None:
                temp.left = nNode
                return
            else:
                q.append(temp.left)
            if temp.right is None:
                temp.right = nNode
                return
            else:
                q.append(temp.right)

    def inOrder(self, root):
        if root is None:
            return
        self.inOrder(root.left)
        print(root.val, end = " ")
        self.inOrder(root.right)
        


class bst:
    def __init__(self):
        self.root = None

    def allLeaf(self, r):
        if(r == None):
            return
        if(r.left == None and r.right == None):
            print(r.val, end=" ")
        self.allLeaf(r.left)
        self.allLeaf(r.right)

    def height(self, r):
        if(r == None):
            return 0
        return max(self.height(r.left), self.height(r.right)) + 1

    def diameter(self, r):
        if(r == None):
            return 0
        dwr = self.height(r.left) + self.height(r.right) + 1
        lsd = self.diameter(r.left)
        rsd = self.diameter(r.right)
        return max(dwr, lsd, rsd)
    

    def maxfromLST(self, root):
        while root.right:
            root = root.right
        return root

    def delete(self, root, key):
        if root is None:
            return root
        if root.val > key:
            root.left = self.delete(root.left, key)
        elif root.val < key:
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
        if(root == None):
            return
        q = [root, None]
        while(q):
            c = q.pop(0)
            if(c == None):
                print()
                if not q:
                    break
                else:
                    q.append(None)
            else:
                print(c.val, end=' ')
                if(c.left):
                    q.append(c.left)
                if(c.right):
                    q.append(c.right)

    def insert(self, r, key):
        nNode = node(key)
        if(r == None):
            self.root = nNode
            return
        if(r.left == None and r.val > key):
            r.left = nNode
        elif(r.right == None and r.val < key):
            r.right = nNode
        else:
            if(r.val > key):
                self.insert(r.left, key)
            elif(r.val < key):
                self.insert(r.right, key)
            else:
                print("Duplicates are not allowed in BST")
                
    def inOrder(self, root):
        if(root == None):
            return
        self.inOrder(root.left)
        print(root.val, end = " ")
        self.inOrder(root.right)


class avl(bst):
    def getHeight(self, root):
        if root is None:
            return 0
        return root.height

    def getBalance(self, root):
        if root is None:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right)

    def rightRotate(self, y):
        x = y.left
        T2 = x.right

        x.right = y
        y.left = T2

        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))
        x.height = 1 + max(self.getHeight(x.left), self.getHeight(x.right))

        return x

    def leftRotate(self, x):
        y = x.right
        T2 = y.left

        y.left = x
        x.right = T2

        x.height = 1 + max(self.getHeight(x.left), self.getHeight(x.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))

        return y

    def insert(self, root, key):
        if root is None:
            return node(key)
        elif key < root.val:
            root.left = self.insert(root.left, key)
        elif key > root.val:
            root.right = self.insert(root.right, key)
        else:
            return root

        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))

        balance = self.getBalance(root)

        if balance > 1 and key < root.left.val:
            return self.rightRotate(root)

        if balance < -1 and key > root.right.val:
            return self.leftRotate(root)

        if balance > 1 and key > root.left.val:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)

        if balance < -1 and key < root.right.val:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root

    def minValueNode(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def delete(self, root, key):
        if root is None:
            return root
        elif key < root.val:
            root.left = self.delete(root.left, key)
        elif key > root.val:
            root.right = self.delete(root.right, key)
        else:
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp
            temp = self.minValueNode(root.right)
            root.val = temp.val
            root.right = self.delete(root.right, temp.val)

        if root is None:
            return root

        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))

        balance = self.getBalance(root)

        if balance > 1 and self.getBalance(root.left) >= 0:
            return self.rightRotate(root)

        if balance < -1 and self.getBalance(root.right) <= 0:
            return self.leftRotate(root)

        if balance > 1 and self.getBalance(root.left) < 0:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)

        if balance < -1 and self.getBalance(root.right) > 0:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root


class hashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hashFunction(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hashFunction(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                self.table[index][i] = (key, value)
                return
        self.table[index].append((key, value))

    def get(self, key):
        index = self.hashFunction(key)
        for k, v in self.table[index]:
            if k == key:
                return v
        return None

    def delete(self, key):
        index = self.hashFunction(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                return

    def __str__(self):
        return str(self.table)



class graph:
    def __init__(self):
        self.adjList = {}

    def addEdge(self, u, v):
        if u not in self.adjList:
            self.adjList[u] = []
        self.adjList[u].append(v)

    def removeEdge(self, u, v):
        if u in self.adjList:
            self.adjList[u].remove(v)
    
    def levelorder(self, start):
        visited = set()
        q = queue()
        q.enqueue(start)
        visited.add(start)

        while not q.isEmpty():
            node = q.dequeue()
            print(node, end=' ')

            for neighbor in self.adjList.get(node, []):
                if neighbor not in visited:
                    visited.add(neighbor)
                    q.enqueue(neighbor)

    def dfs(self, start):
        visited = set()
        self._dfs_helper(start, visited)

    def _dfs_helper(self, node, visited):
        if node not in visited:
            print(node, end=' ')
            visited.add(node)
            for neighbor in self.adjList.get(node, []):
                if neighbor not in visited:
                    self._dfs_helper(neighbor, visited)
    

    def __str__(self):
        return str(self.adjList)


# heap

class heap:
    def __init__(self):
        self.heap = []

    
    def insert(self, key):
        self.heap.append(key)
        self._heapify_up(len(self.heap) - 1)
    def _heapify_up(self, index):
        parent = (index - 1) // 2
        if index > 0 and self.heap[index] < self.heap[parent]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            self._heapify_up(parent)
    
    def extract_min(self):
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)
        return root

    def delete(self, key):
        index = self.heap.index(key)
        self.heap[index] = self.heap[-1]
        self.heap.pop()
        self._heapify_down(index)
    
    def _heapify_down(self, index):
        smallest = index
        left = 2 * index + 1
        right = 2 * index + 2
        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left
        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right
        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self._heapify_down(smallest)

    
    def __str__(self):
        return str(self.heap)
# end of file

