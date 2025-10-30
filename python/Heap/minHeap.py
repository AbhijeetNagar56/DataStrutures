
class minHeap:
    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i - 1) // 2
    def leftchild(self, i):
        return 2 * i + 1
    def rightchild(self, i):
        return 2 * i + 2
    
    def insert(self, v):
        self.heap.append(v)
        self.heapify_up(len(self.heap) - 1)
    def heapify_up(self, i):
        while i > 0 and self.heap[i] < self.heap[self.parent(i)]:
            self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]
            i = self.parent(i)

    def extract_min(self):
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self.heapify_down(0)
        return root
    def heapify_down(self, i):
        mini = i
        if self.leftchild(i) < len(self.heap) and self.heap[self.leftchild(i)] < self.heap[mini]:
            mini = self.leftchild(i)
        if self.rightchild(i) < len(self.heap) and self.heap[self.rightchild(i)] < self.heap[mini]:
            mini = self.rightchild(i)
        
        if(mini != i):
            self.heap[i], self.heap[mini] = self.heap[mini], self.heap[i]
            self.heapify_down(mini)

    
    def get_min(self):
        return self.heap[0] if self.heap else None
    def size(self):
        return len(self.heap)
    def print_heap(self):
        print(self.heap)
    

a = minHeap()

a.insert(3)
a.insert(1)
a.insert(2)
a.insert(4)
a.insert(0)
a.insert(6)
a.insert(5)
a.print_heap()




def heapSort(a):
    s = []
    for i in range(a.size()):
        m = a.extract_min()
        s.append(m)
    return s


sorteda = heapSort(a)
print(sorteda)
