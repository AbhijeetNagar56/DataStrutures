package stack;

class node {
    int data;
    node next;
    node(int d) {
        this.data = d;
        this.next = null;
    }
}


class stack {
    int top = -1;
    int max = 10;
    node head = null;
    public boolean isFull () {
        return top == max;
    }
    public boolean  isEmpty () {
        return this.top == -1;
    }
    public void push (int data) {
        if (isFull()){
            System.out.println("Cannot add more element..");
            return;
        }
        node nnode = new node(data);
        top++;
        if (this.head==null) {
            this.head = nnode;
            return;
        }
        nnode.next = this.head;
        this.head = nnode;
    }
    public int peek () {
        if (this.head==null) {
            return -1;
        }
        return this.head.data;
    }
    public int pop () {
        if (isEmpty()) {
            return -1;
        }
        int t = this.head.data;
        this.head = this.head.next;
        top--;
        return t;
    }
}

public class stackUsingLL {
    public static void main(String[] args) {
        stack s = new stack();
        s.push(1);
        s.push(2);
        s.push(3);
        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.peek());
    }
}