#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int n,m;
vector<string> board;
typedef long long ll;
ll Max=-1;

bool check(ll num){
    ll n=sqrt(num);
    return n*n==num;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    board.resize(n);
    for(int i=0;i<n;i++)cin>>board[i];

    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            for(int dx=-n;dx<=n;dx++){
                for(int dy=-m;dy<=m;dy++){
                    if(dx==0&&dy==0)continue;

                    int cx=x,cy=y;
                    string str="";

                    while(cx>=0&&cy>=0&&cx<n&&cy<m){
                        str+=board[cx][cy];
                        ll num=stoll(str);

                        if(check(num))Max=max(Max,num);

                        cx+=dx;cy+=dy;
                    }
                }
            }
        }
    }
    cout<<Max;
}