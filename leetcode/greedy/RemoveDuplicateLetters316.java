package greedy;

import java.util.*;

/**
 * Created by 杜文丽 on 2019/12/5 17:26
 * 卧槽卧槽 题解牛逼！！！
 **/
public class RemoveDuplicateLetters316 {
    public String removeDuplicateLetters(String s) {
        Stack<Character> stack=new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            Character c=s.charAt(i);
            if(stack.contains(c))
                continue;
            while(!stack.isEmpty()&&stack.peek()>c&&s.indexOf(stack.peek(),i)!=-1)
                stack.pop();
            stack.push(c);
        }
        char chars[]=new char[stack.size()];
        for (int i = 0; i < stack.size(); i++) {
            chars[i]=stack.get(i);
        }
        return new String(chars);

    }

    public static void main(String[] args) {
        RemoveDuplicateLetters316 test = new RemoveDuplicateLetters316();
        System.out.println(test.removeDuplicateLetters("mitnlruhznjfyzmtmfnstsxwktxlboxutbic"));
        //System.out.println("bbbcc".substring(0,4));
    }
}

/**
 * 暴力破解 超时了
 * public class RemoveDuplicateLetters316 {
 *     Set<Character> chars = new HashSet<>();
 *     Set<String> res = new HashSet<>();
 *     public void subDeal(char c, Set<Character> tmpChars, String currStr,String s) {
 *         if (tmpChars.isEmpty()) {
 *             res.add(currStr);
 *             return;
 *         }
 *         if (tmpChars.contains(c)) {
 *             currStr += c;
 *             s=s.replace(c+"","");
 *             tmpChars.remove(c);
 *             if (tmpChars.isEmpty()){
 *                 res.add(currStr);
 *                 return;
 *             }
 *             for (int i = 0; i <s.length() ; i++) {
 *                 subDeal(s.charAt(i), new HashSet<>(tmpChars), currStr,s.substring(i));
 *             }
 *         }
 *
 *     }
 *
 *     public String removeDuplicateLetters(String s) {
 *         if (s.length() <= 1) {
 *             return s;
 *         }
 *         for (int i = 0; i < s.length(); i++) {
 *             chars.add(s.charAt(i));
 *         }
 *         for (int i = 0; i < s.length(); i++) {
 *             Set<Character> tmpChars = new HashSet<>(chars);
 *             String currStr = "";
 *             subDeal(s.charAt(i), tmpChars, currStr,s.substring(i));
 *         }
 *         List<String> resList=new ArrayList<>();
 *         for (String str:res
 *              ) {
 *             resList.add(str);
 *         }
 *         Collections.sort(resList);
 *         return resList.get(0);
 *     }
 *
 *     public static void main(String[] args) {
 *         RemoveDuplicateLetters316 test = new RemoveDuplicateLetters316();
 *         System.out.println(test.removeDuplicateLetters("bbcaac"));
 *         //System.out.println("bbbcc".substring(1));
 *     }
 * }
 * 
 * */

/**
 * 解法2 也超时 列举出所有 再验证
 * public class RemoveDuplicateLetters316 {
 *     Set<Character> chars = new HashSet<>();
 *     //List<Character> characterList;
 *     List<Boolean> charUsed;
 *     List<String> resList=new ArrayList<>();
 *     public void subDeal(String res,Set<Character> mychars) {
 *         if (res.length()>=chars.size()){
 *             resList.add(res);
 *             return;
 *         }
 *         List<Character> characterList=new ArrayList<>(mychars);
 *         for (int i = 0; i <characterList.size() ; i++) {
 *             res+=characterList.get(i);
 *             mychars.remove(characterList.get(i));
 *             subDeal(res,new HashSet<>(mychars));
 *             mychars.add(characterList.get(i));//回溯
 *             res=res.substring(0,res.length()-1);
 *         }
 *
 *     }
 *
 *     public boolean subCheck(String s,String res){
 *         boolean ok=false;
 *         int index=0;
 *         for (int i = 0; i <s.length() ; i++) {
 *             if (index<res.length()&&s.charAt(i)==res.charAt(index)){
 *                 index++;
 *             }
 *             if (index>=res.length()){
 *                 ok=true;
 *             }
 *         }
 *         if (index>=res.length()){
 *             ok=true;
 *         }
 *         return ok;
 *     }
 *     public String removeDuplicateLetters(String s) {
 *         if (s.length() <= 1) {
 *             return s;
 *         }
 *         for (int i = 0; i < s.length(); i++) {
 *             chars.add(s.charAt(i));
 *         }
 *         //characterList=new ArrayList<>(chars);
 *         charUsed=new ArrayList<>();
 *         for (int i = 0; i <chars.size() ; i++) {
 *             charUsed.add(false);
 *         }
 *         subDeal("",new HashSet<>(chars));
 *         List<String> res=new ArrayList<>();
 *
 *         Collections.sort(res);
 *         for (int i = 0; i <resList.size() ; i++) {
 *             if (subCheck(s,resList.get(i))){
 *                 return resList.get(i);
 *             }
 *         }
 *         return res.get(0);
 *     }
 *
 *     public static void main(String[] args) {
 *         RemoveDuplicateLetters316 test = new RemoveDuplicateLetters316();
 *         System.out.println(test.removeDuplicateLetters("mitnlruhznjfyzmtmfnstsxwktxlboxutbic"));
 *         //System.out.println("bbbcc".substring(0,4));
 *     }
 * }
 */

/**
 * 在上种方法上进行优化，一直取最小值，再验证，一直到验证通过 才返回
 * public class RemoveDuplicateLetters316 {
 *     Set<Character> chars = new HashSet<>();
 *     //List<Character> characterList;
 *     List<Boolean> charUsed;
 *     String s="";
 *     List<String> resList=new ArrayList<>();
 *     public String subDeal(String res,Set<Character> mychars) {
 *         if (res.length()>=chars.size()){
 *             if (subCheck(s,res)){
 *                 return res;
 *             }else {
 *                 return "";
 *             }
 *         }
 *         List<Character> characterList=new ArrayList<>(mychars);
 *         Collections.sort(characterList);
 *         String result="";
 *         for (int i = 0; i <characterList.size() ; i++) {
 *             res+=characterList.get(i);
 *             mychars.remove(characterList.get(i));
 *             result=subDeal(res,new HashSet<>(mychars));
 *             if (!result.equals("")){
 *                 return result;
 *             }
 *             mychars.add(characterList.get(i));//回溯
 *             res=res.substring(0,res.length()-1);
 *         }
 *         return result;
 *     }
 *
 *     public boolean subCheck(String s,String res){
 *         boolean ok=false;
 *         int index=0;
 *         for (int i = 0; i <s.length() ; i++) {
 *             if (index<res.length()&&s.charAt(i)==res.charAt(index)){
 *                 index++;
 *             }
 *             if (index>=res.length()){
 *                 ok=true;
 *             }
 *         }
 *         if (index>=res.length()){
 *             ok=true;
 *         }
 *         return ok;
 *     }
 *     public String removeDuplicateLetters(String s) {
 *         if (s.length() <= 1) {
 *             return s;
 *         }
 *         this.s=s;
 *         for (int i = 0; i < s.length(); i++) {
 *             chars.add(s.charAt(i));
 *         }
 *         //characterList=new ArrayList<>(chars);
 *         charUsed=new ArrayList<>();
 *         for (int i = 0; i <chars.size() ; i++) {
 *             charUsed.add(false);
 *         }
 *
 *         return subDeal("",new HashSet<>(chars));
 *
 *
 *     }
 *
 *     public static void main(String[] args) {
 *         RemoveDuplicateLetters316 test = new RemoveDuplicateLetters316();
 *         System.out.println(test.removeDuplicateLetters("mitnlruhznjfyzmtmfnstsxwktxlboxutbic"));
 *         //System.out.println("bbbcc".substring(0,4));
 *     }
 * }
 */