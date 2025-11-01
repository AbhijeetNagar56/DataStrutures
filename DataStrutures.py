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
		if(self.isFull):
			return "Queue Overflow!"
		if(self.isEmpty):
			self.front = 0
		self.rear += 1
		self.q[self.rear] = data
	def dequeue(self):
		if(self.isEmpty):
			return "Queue Underflow!"
		item = self.q[self.front]
		self.q[self.front] = None
		if(self.front == self.rear):
			self.front = self.rear = -1
		else:
			self.front += 1
		return item

	def peek(self):
		if(self.isEmpty):
			return "Queue is Empty"
		return self.q[self.front]
	def noOfElement(self):
		return len([i for i in self.q if i!=None])
	def __str__(self):
		return str([i for i in self.q if i!=0])

#circular queue
class circularQue:
	Max = 5
	r = f = -1
	def __init__(self):
		self.q = [None]*self.Max
	def isEmpty(self):
		return self.f == -1
	def isFull(self):
		return (self.r+1) % self.Max == self.f
	def enqueue(self, data):
		if(self.isFull):
			return "No space"
		if(self.isEmpty):
			self.f = 0
		self.r = (self.r + 1) % self.Max
		self.q[self.r] = data
	def dequeue(self):
		if(self.isEmpty):
			return "Empty Queue"
		item = self.q[self.f]
		self.q[self.f] = None
		if((self.f+1) % self.Max == self.r):
			self.f = self.r = -1
		else:
			self.f = (self.f + 1) % self.Max 
	    return item # type: ignore
    def  peek(self):
        if (self.isEmpty):
            return ("Queue is Empty")
        return self.q[self.f]
    def __str__(self):
        return str([i for i in self.q if i!=0])
    
     


#linked list
class Node:
	def __init__(self, data=None):
		self.data = data
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
        if self.head None:
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
        while temp.next != None:
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

		while temp != None:
            if(temp.data == key):
                pre.next = temp.next
                self.size -= 1
                return

            pre = temp
            temp = temp.next
        print("The element is not present")

	def size(self):
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

        elif self.head.next is None:
            self.head.next = newNode
            newNode.next = self.head

        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
                
            newNode.next = self.head
            temp.next = newNode
        self.size += 1
		
	
	def delete(self, key):
        if self.head is None:
            return "List is Empty"
        
        if self.head.data == key:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = self.head.next
            self.size -= 1
            return

        temp = self.head.next
        pre = self.head

        while temp.next != self.head:
            if temp.data == key:
                pre.next = temp.next
                self.size -= 1
                return               
            pre = temp
            temp = temp.next
        print("Element is not present in the list")
		
	def __str__(self):
        s = ''
		temp = self.head
		while temp.next != self.head:
			s += str(temp.data) + '->'
			temp = temp.next
		return s + str(temp.data)
		
	


#trees
class node:
	def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
            self.height = None
        

class gbt:
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
    


    def delete(self, root, key):
        if root is None:
            return "key is not in tree"
        if root.data == key:
            # delete the node
            if root.left == None and root.right == None:
                root == None
            elif root.left == None or root.right == None:
                if root.left is None:
                    root.data = root.left.data
                    root.left = None
                else:
                    root.data = root.right.data
                    root.right = None
            else:
                # leftmost node
                temp = root
                while temp.next:
                    temp = temp.left
                root.data = temp.data
                temp = None
        delete(root.left, key)
        delete(root.right, key)
  
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
        if(r.left == None):
            r.left = nNode
        elif(r.right == None):
            r.right = nNode
        else:
            if r.left.left == None or r.left.right == None:
                self.insert(r.left, key)   
            else:
                self.insert(r.right, key)

    def inOrder(self, root):
        if(root == None):
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
    

