//681C
#include <iostream>
#include <queue>
#include <string>
 
using namespace std;
 
int n; 
char s[3][15] = {"insert", "getMin", "removeMin"}, temp[15];

vector<int> anss, ansnum;

int main() {
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", temp);
        if (temp[0] == 'i') {
            int x;
            scanf("%d", &x);
            q.push(x);
            anss.push_back(0);
            ansnum.push_back(x);
        } 
        else if (temp[0] == 'g') {
            int x;
            scanf("%d", &x);
            while (!q.empty() && q.top() < x) {
                q.pop();
                anss.push_back(2);
                ansnum.push_back(0);
            }
            if (q.empty() || q.top() > x) {
                q.push(x);
                anss.push_back(0);
                ansnum.push_back(x);
            }
            anss.push_back(1);
            ansnum.push_back(x);
        } 
        else if (temp[0] == 'r') {
            if (q.empty()) {
                anss.push_back(0);
                ansnum.push_back(0);
            } else {
                q.pop();
            }
            anss.push_back(2);
            ansnum.push_back(0);
        }
    }
    printf("%d\n", (int)anss.size());
    for (int i = 0; i < anss.size(); ++i) {
        printf("%s", s[anss[i]]);
        if (s[anss[i]][0] != 'r')
            printf(" %d", ansnum[i]);
        puts("");
    }
    return 0;
}