#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

vector<int> answer;
int n,m,num;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    vector<int> rank(n,0);
    vector<vector<int>> board(n);
    for(int i=0;i<m;i++){
        cin>>num;
        vector<int> arr(num);
        for(int j=0;j<num;j++)cin>>arr[j];
        for(int j=0;j<num-1;j++){
            board[arr[j]-1].push_back(arr[j+1]-1);
            rank[arr[j+1]-1]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++)if(rank[i]==0)q.push(i);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        answer.push_back(cur+1);

        for(auto next:board[cur]){
            rank[next]--;
            if(!rank[next])q.push(next);
        }
    }
    for(int i=0;i<n;i++)if(rank[i]!=0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++)cout<<answer[i]<<"\n";
}