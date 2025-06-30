#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

char op[]={'D','S','L','R'};
//D는 2배 후 9999넘으면 %10000
//S는 n-1 만약 n이 0이면 9999
//L은 왼쪼긍로 회전
//R은 오른쪽으로 회전
int T;

int opD(int n){
    n*=2;
    if(n>9999)return n%10000;
    return n;
}

int opS(int n){
    n--;
    if(n==-1)return 9999;
    return n;
}

int opL(int n){
    int tmp=n*10/10000;
    n=n*10%10000+tmp;
    return n;
}

int opR(int n){
    int tmp=n%10*1000;
    n=n/10+tmp;
    return n;
}

string bfs(int s,int t){
    queue<pair<int,string>> q;
    vector<bool> visit(10000,false);
    visit[s]=true;
    q.push({s,""});

    while(q.front().first!=t){
        int cur=q.front().first;
        string str=q.front().second;
        q.pop();

        int nextD=opD(cur);
        if(!visit[nextD]){
            visit[nextD]=true;
            q.push({nextD,str+"D"});
        }
        int nextS=opS(cur);
        if(!visit[nextS]){
            visit[nextS]=true;
            q.push({nextS,str+"S"});
        }
        int nextL=opL(cur);
        if(!visit[nextL]){
            visit[nextL]=true;
            q.push({nextL,str+"L"});
        }
        int nextR=opR(cur);
        if(!visit[nextR]){
            visit[nextR]=true;
            q.push({nextR,str+"R"});
        }
    }
    return q.front().second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>T;

    while(T--){
        int A,B;
        cin>>A>>B;

        cout<<bfs(A,B)<<"\n";
    }
}