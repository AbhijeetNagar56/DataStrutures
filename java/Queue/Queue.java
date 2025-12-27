

class queue {
    int front, rear, capacity;
    int queue[];
    public queue() {
        
    }
}
public class Queue {
    public static void main(String args[]) {
        queue q = new queue();
        q.capacity = 1000;
        q.front = q.rear = 0;
        q.queue = new int[q.capacity];
    }
}