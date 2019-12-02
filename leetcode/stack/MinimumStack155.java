package stack;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 杜文丽 on 2019/11/29 11:04
 **/
public class MinimumStack155 {
    private List<Integer> mystack;
    private List<Integer> mymin;
    /** initialize your data structure here. */
    public MinimumStack155() {
        this.mystack=new ArrayList<>();
        this.mymin=new ArrayList<>();
    }

    public void push(int x) {
        if (mystack.isEmpty()){
            mystack.add(x);
            mymin.add(x);
        }else{
            mystack.add(x);
            if (x<mymin.get(mymin.get(mymin.size()-1))){
                mymin.add(x);
            }
        }
    }

    public void pop() {
        if (!mystack.isEmpty()){
            if (mymin.get(mymin.size()-1).equals(mystack.get(mystack.size()-1))){
                mymin.remove(mymin.size()-1);
            }
            mystack.remove(mystack.size()-1);
        }
    }

    public int top() {
        if (mystack.isEmpty()){
            return 0;
        }
        return mystack.get(mystack.size()-1);
    }

    public int getMin() {
        if (mystack.isEmpty()){
            return 0;
        }
        return mymin.get(mymin.size()-1);
    }

    public static void main(String[] args) {
        MinimumStack155 obj = new MinimumStack155();
        obj.push(5);
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
