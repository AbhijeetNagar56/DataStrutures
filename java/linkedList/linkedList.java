package linkedList;
import java.util.Scanner;

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

class Linking {
    Node head;
    public void insert(int data, int index) {
        if(index == 0) {
            addInTheBegining(data);
            return;
        }
        Node nNode = new Node(data);
        Node temp = this.head;
        int count = 1;
        while(count != index) {
            temp = temp.next;
            count++;
        }
        nNode.next = temp.next;
        temp.next = nNode;
    }
    public void addInTheBegining(int item) {
        Node newNode = new Node(item);
        if(this.head == null) {
            this.head = newNode;
            return;
        }
        newNode.next = this.head;
        this.head = newNode;
        
    }
    public void addInTheEnd(int item) {
        Node newNode = new Node(item);
        if(this.head == null) {
            this.head = newNode;
            return;
        }
        Node current = this.head;
        while (current.next!=null) {
            current = current.next;
        }
        current.next = newNode;
        
    }

    public void  delete (int key) {
        Node temp = this.head;
        while(temp.next != null){
            if (temp.next.data == key) {
                temp.next = temp.next.next;
                System.out.println("The element " + key + " deleted");
                break;
            }
            temp = temp.next;
        }
        System.out.println("Not present in this list");
        
    }
    public void display() {
        Node current = this.head;
        while (current!=null) {
            System.out.print(current.data + "->");
            current = current.next;
        }
    }

    
}

public class linkedList {    
    public void nu() {
        
    }
    public static void main(String args[]) {
        //main block
        Scanner In = new Scanner(System.in);
        Linking l = new Linking();
        
        while (true) { 
            System.out.println("\nEnter Operation:");
            System.out.println("1 for insert with index");
            System.out.println("2 for adding in the begining");
            System.out.println("3 for adding in the end");
            System.out.println("4 for delete with data");
            System.out.println("5 for diplay");
            System.out.println("6 for exit");

            int op = In.nextInt();
            if (op == 1) {
                System.out.println("Enter the index:");
                int i = In.nextInt();
                System.out.println("Enter the data:");
                int d = In.nextInt();
                l.insert(d, i);
            } else if (op == 2) {
                System.out.println("Enter the data:");
                int d = In.nextInt();
                l.addInTheBegining(d);
            } else if (op == 3) {
                System.out.println("Enter the data:");
                int d = In.nextInt();
                l.addInTheEnd(d);
            } else if (op == 4) {
                System.out.println("Enter the data which you want to remove :");
                int d = In.nextInt();
                l.delete(d);
            } else if (op==5){
                l.display();
            } else if (op == 6) {
                System.exit(0);
            } else {
                System.out.println("Enter a valid Number!");
            }
            
            In.close();
        }
        
    }
}