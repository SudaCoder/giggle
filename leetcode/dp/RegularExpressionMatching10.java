package dp;

/**
 * Created by 杜文丽 on 8/14/2019 4:06 PM
 **/
public class RegularExpressionMatching10 {
    public static void main(String[] args) {

    }
}
class Solution10 {
    public boolean isMatch(String s, String p) {
        int slen=s.length();
        int plen=p.length();
        boolean[][] dp=new boolean[slen+1][plen+1];
        dp[0][0]=true;
        for (int i = 1; i <slen ; i++) {
           dp[i][0]=false;
        }
        for (int i = 1; i <plen ; i++) {
            //空串可能与模式串相匹配 出现.*的时候
            dp[0][i]=dp[0][i-2]&&p.charAt(i-1)=='*'&&i>1;
        }
        for (int i = 1; i <=slen ; i++) {
            for (int j = 1; j <=plen ; j++) {
                if (p.charAt(j-1)=='*'){
                    dp[i][j]=dp[i][j-2]||((p.charAt(j-2)==s.charAt(i-1))||p.charAt(j-2)=='.')&&dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j-1]&&(p.charAt(j-1)=='.'||p.charAt(j-1)==s.charAt(i-1));
                }
            }
        }
        return dp[slen][plen];
    }
}