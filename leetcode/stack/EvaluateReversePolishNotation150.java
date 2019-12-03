package stack;

import java.util.Stack;

/**
 * Created by 杜文丽 on 2019/12/3 22:45
 **/
public class EvaluateReversePolishNotation150 {
    private Stack<String> myStack=new Stack<>();
    public int evalRPN(String[] tokens) {
        for (int i = 0; i <tokens.length ; i++) {
            switch (tokens[i]){
                case "+":
                    String num2=myStack.peek();
                    myStack.pop();
                    String num1=myStack.peek();
                    myStack.pop();
                    myStack.push(String.valueOf(Integer.valueOf(num1)+Integer.valueOf(num2)));
                    break;
                case "-":
                    num2=myStack.peek();
                    myStack.pop();
                    num1=myStack.peek();
                    myStack.pop();
                    myStack.push(String.valueOf(Integer.valueOf(num1)-Integer.valueOf(num2)));
                    break;
                case "*":num2=myStack.peek();
                    myStack.pop();
                    num1=myStack.peek();
                    myStack.pop();
                    myStack.push(String.valueOf(Integer.valueOf(num1)*Integer.valueOf(num2)));
                    break;
                case "/":
                    num2=myStack.peek();
                    myStack.pop();
                    num1=myStack.peek();
                    myStack.pop();
                    myStack.push(String.valueOf(Integer.valueOf(num1)/Integer.valueOf(num2)));
                    break;
                default:myStack.push(tokens[i]);
            }
        }
        return Integer.valueOf(myStack.peek());
    }
}
