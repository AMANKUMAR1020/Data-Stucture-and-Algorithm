import java.util.*;

class Queue {
    private int size;
    private int ind;
    private ArrayList<Integer> qu = new ArrayList<>();

    public Queue(int size) {
        this.size = size;
        this.ind = 0; // start empty
    }

    public int front() {
        if (ind > 0) {
            return qu.get(0);
        } else {
            return -1; // queue empty
        }
    }

    public int rear() {
        if (ind > 0) {
            return qu.get(ind - 1);
        } else {
            return -1; // queue empty
        }
    }

    public void push(int val) {
        if (ind < size) {
            qu.add(val);
            ind++;
            System.out.println(val + " is added :)");
        } else {
            System.out.println("Overflow!");
        }
    }

    public void pop() {
        if (ind > 0) {
            int removed = qu.get(0);
            qu.remove(0);
            ind--;
            System.out.println(removed + " is removed :))");
        } else {
            System.out.println("Underflow!");
        }
    }

    public void display() {
        if (ind == 0) {
            System.out.println("Queue is empty.");
        } else {
            System.out.println("Queue: " + qu);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Queue q = new Queue(5);

        q.push(10);
        q.push(20);
        q.push(30);
        q.display();

        System.out.println("Front: " + q.front());
        System.out.println("Rear: " + q.rear());

        q.pop();
        q.display();
    }
}
