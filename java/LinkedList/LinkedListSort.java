package linkedList;


// class Node {
//     int data;
//     Node next;
//     Node pre;

//     Node(int d) {
//         this.data = d;
//         this.next = null;
//         this.pre = null;
//     }
// }

// class Linking {
//     Node head;
//     public void insert(int data, int index) {
//         if(index == 0) {
//             addInTheBegining(data);
//             return;
//         }
//         Node nNode = new Node(data);
//         Node temp = this.head;
//         int count = 1;
//         while(count != index) {
//             temp = temp.next;
//             count++;
//         }
//         nNode.next = temp.next;
//         temp.next = nNode;
//     }
//     public void addInTheBegining(int item) {
//         Node newNode = new Node(item);
//         if(this.head == null) {
//             this.head = newNode;
//             return;
//         }
//         newNode.next = this.head;
//         this.head = newNode;
        
//     }
//     public void addInTheEnd(int item) {
//         Node newNode = new Node(item);
//         if(this.head == null) {
//             this.head = newNode;
//             return;
//         }
//         Node current = this.head;
//         while (current.next!=null) {
//             current = current.next;
//         }
//         current.next = newNode;
        
//     }

//     public void  delete (int key) {
//         Node temp = this.head;
//         while(temp.next != null){
//             if (temp.next.data == key) {
//                 temp.next = temp.next.next;
//                 System.out.println("The element " + key + " deleted");
//                 break;
//             }
//             temp = temp.next;
//         }
//         System.out.println("Not present in this list");
        
//     }
//     public void display() {
//         Node current = this.head;
//         while (current!=null) {
//             System.out.print(current.data + "->");
//             current = current.next;
//         }
//     }

    
// }




// public class sortingInLL {
//     public static void main(String[] args) {
//         Linking l = new Linking();
//         l.addInTheEnd(1);
//         l.addInTheEnd(7);
//         l.addInTheEnd(5);
//         l.addInTheEnd(0);
//         l.addInTheEnd(9);
//         Linking after = new Linking();
//         while(l.head!=null){
//             Node t = l.head;
//             int min  = l.head.data;
//             while(t.next!=null) {
//                 if(min>t.data) {
//                     min = t.data;
//                 }
//             }
//             l.delete(min);
//             after.addInTheEnd(min);
//         }
//         after.display();
//     }
// }



import java.util.Collections;
import java.util.LinkedList;

public class LinkedListSort {
    public static void main(String[] args) {
        // Create a LinkedList
        LinkedList<Integer> list = new LinkedList<>();

        // Add elements to the LinkedList
        list.add(42);
        list.add(10);
        list.add(5);
        list.add(32);
        list.add(18);

        // Print original list
        System.out.println("Original LinkedList: " + list);

        // Sort the LinkedList
        Collections.sort(list);

        // Print sorted list
        System.out.println("Sorted LinkedList: " + list);
    }
}
