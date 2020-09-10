#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 20;
struct node{
    int lchild,rchild;
} tnode[maxn];
bool notroot[maxn] = {false};
int n,num = 0;
void print(int id){
    printf("%d",id);
    num++;
    if(num < n)
        printf(" ");
    else
    {
        printf("\n");
    }
}
void inorder(int root){
    if(root == -1)
        return ;
    inorder(tnode[root].lchild);
    print(root);
    inorder(tnode[root].rchild);
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        print(cur);
        if(tnode[cur].lchild != -1)
            q.push(tnode[cur].lchild);
        if(tnode[cur].rchild != -1)
            q.push(tnode[cur].rchild);
    }
}
void postorder(int root){
    if(root == -1) return;
    postorder(tnode[root].lchild);
    postorder(tnode[root].rchild);
    swap(tnode[root].lchild,tnode[root].rchild);
}
int str_to_num(char c){
    if(c == '-') return -1;
    else{
        notroot[c-'0'] = true;
        return c-'0';
    }
}
int findroot(){
    for(int i=0;i<n;i++){
        if(notroot[i] == false)
            return i;
    }
}
int main(){
    char lchild,rchild;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%*c%c %c",&lchild,&rchild);
        tnode[i].lchild = str_to_num(lchild);
        tnode[i].rchild = str_to_num(rchild);
    }
    int root = findroot();
    postorder(root);
    bfs(root);
    num = 0;
    inorder(root);
    system("pause");
    return 0;
}
