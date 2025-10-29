package linkedList;
class Node {
    int data;
    Node next;
    Node pre;

    Node(int d) {
        this.data = d;
        this.next = null;
        this.pre = null;
    }
}

class clinkedList {
    Node head;
    int size = 0;
    public void insert(int data) {
        Node nNode = new Node(data);
        if (this.head == null) {
            this.head = nNode;
            size++;
            return;
        }
        if (this.size == 1) {
            this.head.next = nNode;
            nNode.next = this.head;
            size++;
            return;
        }
        Node temp = this.head;
        while(temp.next != this.head) {
            temp = temp.next;
        }
        temp.next = nNode;
        nNode.next = this.head;
        size++;
    }
    public void delete () {
        if (this.head == null) {
            System.out.println("List is empty..");
            return;
        }
        Node temp = this.head;
        while(temp.next.next != this.head) {
            temp = temp.next;
        }
        temp.next.next = null;
        temp.next = null;
        temp.next = this.head;
        
        size--;
    }
    public void size() {
        System.out.println("The size is " + this.size);
    }
    public void display() {
        Node temp = this.head;
        for (int i = 0; i < this.size; i++) {
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
    }

}

public class circularLinkedList {    
    public static void main(String args[]) {
        //main block
        clinkedList l = new clinkedList();
        l.insert(1);
        l.insert(2);
        l.insert(3);
        l.delete();
        l.display();
    }
}