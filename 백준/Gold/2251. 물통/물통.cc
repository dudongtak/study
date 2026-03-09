#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num[3];
vector<vector<vector<bool>>> v(201,vector<vector<bool>>(201,vector<bool>(201,false)));
vector<bool> ans(201,false);

void dfs(int a,int b,int c){
    if(v[a][b][c])return;
    v[a][b][c]=true;
    if(a==0)ans[c]=true;

    int pour;

    pour=min(num[1]-b,a);
    dfs(a-pour,b+pour,c);
    pour=min(num[2]-c,a);
    dfs(a-pour,b,c+pour);

    pour=min(num[0]-a,b);
    dfs(a+pour,b-pour,c);
    pour=min(num[2]-c,b);
    dfs(a,b-pour,c+pour);

    pour=min(num[0]-a,c);
    dfs(a+pour,b,c-pour);
    pour=min(num[1]-b,c);
    dfs(a,b+pour,c-pour);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>num[0]>>num[1]>>num[2];
    dfs(0,0,num[2]);
    for(int i=0;i<=num[2];i++)if(ans[i])cout<<i<<" ";
}