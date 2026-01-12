#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,d,k,c;

    cin>>n>>d>>k>>c;

    vector<int> sushi;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        sushi.push_back(num);
    }
    vector<int> type(d+1,0);
    queue<int> q;

    int cnt=0;

    for(int i=0;i<k;i++){
        q.push(sushi[i]);
        if(!type[sushi[i]])cnt++;
        type[sushi[i]]++;
    }

    int Max=cnt;

    for(int i=0;i<n;i++){
        int cur=q.front();
        q.pop();
        type[cur]--;
        if(!type[cur])cnt--;

        q.push(sushi[(i+k)%n]);
        if(!type[sushi[(i+k)%n]])cnt++;
        type[sushi[(i+k)%n]]++;

        if(!type[c])Max=max(Max,cnt+1);
        else Max=max(Max,cnt);
    }

    cout<<Max;
}