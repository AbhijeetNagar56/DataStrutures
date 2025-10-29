package linkedList;

class Node {
    int data;
    Node next;
    Node (int data) {
        this.data = data;
        this.next = null;
    }
}

class linking {
    Node head;
    int size = 0;
    public void add(int d) {
        Node nnode = new Node(d);
        if(this.head == null) {
            this.head = nnode;
            size++;
            return;
        }
        nnode.next = this.head;
        this.head = nnode;
        size++;
    }
    // public void insert(int d, int index) {
    //     if(index>this.size){
    //         System.out.println("Index Out of range");
    //         return;
    //     }
    //     Node nNode = new Node(d);
    //     if(index==0) {
    //         if(this.head == null) {
    //             this.head = nNode;
    //             size++;
    //             return;
    //         }
    //         nNode.next = this.head;
    //         this.head = nNode;
    //         size++;
    //         return;
    //     }
    //     int count = 0;
    //     Node temp = this.head;
    //     while(count!=index){
    //         temp = temp.next;
    //         count++;
    //     }
    //     nNode.next = temp.next;
    //     temp.next = nNode;
    //     size++;
    // }
    public void printList() {
        Node temp = this.head;
        while(temp!=null){
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
    }
}

public class reversingALL {
    public static void main (String args[]) {
        //main block
        linking l1 = new linking();
        l1.add(1);
        l1.add(4);
        l1.add(8);
        l1.printList();
    }
}