#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<bool> prime(10000,true);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=2;i*i<10000;i++){
        if(!prime[i])continue;
        for(int j=i*2;j<10000;j+=i){
            prime[j]=false;
        }
    }

    int t;
    cin>>t;
    while(t--){
        int before,after;
        cin>>before>>after;
        if(before==after){
            cout<<0<<'\n';
            continue;
        }
        string b=to_string(before),a=to_string(after);
        vector<int> dis(10000,1e9);
        dis[before]=0;
        queue<string> q;
        q.push(b);

        while(!q.empty()){
            string cur=q.front();
            int curI=stoi(cur);
            if(curI==after)break;
            q.pop();

            for(int i=0;i<4;i++){
                for(int j=0;j<10;j++){
                    if(i==0&&j==0)continue;
                    string next=cur;
                    next[i]=j+'0';
                    int nextI=stoi(next);
                    if(!prime[nextI]||dis[nextI]!=1e9)continue;
                    dis[nextI]=dis[curI]+1;
                    q.push(next);
                }
            }
        }
        if(dis[after]!=0)cout<<dis[after]<<'\n';
        else cout<<"Impossible\n";
    }
}