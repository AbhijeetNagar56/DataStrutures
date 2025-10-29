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

class doubleLinked {
    Node head;
    Node tail;
    public void append(int data) {
        Node nNode = new Node(data);
        if(this.head == null) {
            this.head = nNode;
            return;
        }
        Node temp = this.head;
        while(temp.next != null) {
            temp = temp.next;
        }
        temp.next = nNode;
        nNode.pre = temp;
        this.tail = nNode;
    }
    public void delete () {
        if(this.head == null) {
            System.out.println("List is empty..");
            return;
        }
        this.tail = this.tail.pre;
        this.tail.next = null;
    }

    public void frontdis() {
        Node temp = this.head;
        while(temp != null) {
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.println();
    }
    public void backdis() {
        Node temp = this.tail;
        while(temp != null) {
            System.out.print("<-" + temp.data);
            temp = temp.pre;
        }
        System.out.println();
    }
    

}



public class doublyLinkedList {
    public static void main(String[] args) {
        //main block...
        doubleLinked l = new doubleLinked();
        l.append(1);
        l.append(2);
        l.append(3);
        l.delete();
        l.frontdis();
        l.backdis();
    }
}
