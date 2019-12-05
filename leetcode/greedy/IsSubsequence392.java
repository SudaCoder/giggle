package greedy;

/**
 * Created by 杜文丽 on 2019/12/4 10:59
 **/
public class IsSubsequence392 {

    public boolean isSubsequence(String s, String t) {
        boolean isMatch=false;
        int sIndex=0;
        if (s.equals(t)){
            return true;
        }else if (s.equals("")){
            return true;
        }else if (t.equals("")){
            return false;
        }
        for (int i = 0; i <t.length() ; i++) {
            if (isMatch){
                return true;
            }
            if (t.charAt(i)==s.charAt(sIndex)){
                sIndex++;
            }
            if (sIndex>=s.length()){
                isMatch=true;
            }
        }
        return isMatch;
    }
    public static void main(String[] args) {
        IsSubsequence392 test=new IsSubsequence392();
        String s="";
        String t="ahbgdc";
        System.out.println(test.isSubsequence(s,t));
    }
}

/**
 * 暴力解法 超时
 * class Solution{
 *     String s="";
 *     String t="";
 *     boolean isMatch=false;
 *     public void matchIndex(int tIndex){
 *         int sIndex=0;
 *         if (tIndex+s.length()>=t.length()){
 *             return;
 *         }
 *         for (int i = tIndex; i <t.length(); i++) {
 *             if (sIndex>=s.length()){
 *                 break;
 *             }
 *             if (s.charAt(sIndex)==t.charAt(i)){
 *                 sIndex++;
 *             }
 *         }
 *         if (sIndex>=(s.length())){
 *             isMatch=true;
 *         }
 *     }
 *     public boolean isSubsequence(String s, String t) {
 *         this.s=s;
 *         this.t=t;
 *         if (s.equals(t)){
 *             return true;
 *         }
 *         for (int i = 0; i <t.length()-s.length()+1 ; i++) {
 *             matchIndex(i);
 *             if (isMatch){
 *                 return true;
 *             }
 *         }
 *         return isMatch;
 *     }
 *}
 */
