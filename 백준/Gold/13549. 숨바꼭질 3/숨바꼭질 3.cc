#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int N,K;
int inf=100001;
vector<int> line(100001,inf);

void dijkstra(){
    deque<int> dq;
    
    line[N]=0;
    dq.push_front(N);

    while(!dq.empty()){
        int cur=dq.front();
        dq.pop_front();

        if(cur*2<=100000&&line[cur*2]>line[cur]){
            line[cur*2]=line[cur];
            dq.push_front(cur*2);
        }
        if(cur-1>=0&&line[cur-1]>line[cur]){
            line[cur-1]=line[cur]+1;
            dq.push_back(cur-1);
        }
        if(cur+1<=100000&&line[cur+1]>line[cur]){
            line[cur+1]=line[cur]+1;
            dq.push_back(cur+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>K;
    dijkstra();

    cout<<line[K];
}