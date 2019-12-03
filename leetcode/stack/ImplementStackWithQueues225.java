package stack;

import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Created by 杜文丽 on 2019/12/2 23:13
 **/
public class ImplementStackWithQueues225 {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;

    /**
     * Initialize your data structure here.
     */
    public ImplementStackWithQueues225() {
        queue1 = new PriorityQueue<>();
        queue2 = new PriorityQueue<>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        queue1.add(x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        if (queue1.isEmpty()){
            while (queue2.size()!=1) {
                queue1.add(queue2.remove());
            }
            return queue2.remove();
        }else{
            while (queue1.size()!=1) {
                queue2.add(queue1.remove());
            }
            return queue1.remove();
        }

    }

    /**
     * Get the top element.
     */
    public int top() {
        if (queue1.isEmpty()){
            while (queue2.size()!=1) {
                queue1.add(queue2.remove());
            }

            queue1.add(queue2.peek());
            return queue2.remove();

        }else {
            while (queue1.size()!=1) {
                queue2.add(queue1.remove());
            }

            queue2.add(queue1.peek());
            return queue1.remove();

        }
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        if (queue1.isEmpty() && queue2.isEmpty()) {
            return true;
        }
        return false;
    }
}
