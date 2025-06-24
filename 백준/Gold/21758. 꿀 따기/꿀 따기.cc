#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int answer=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    vector<int> honey(N);
    vector<int> sum(N+1,0);

    for(int i=0;i<N;i++){
        cin>>honey[i];
        sum[i+1]=sum[i]+honey[i];
    }

    //벌 - 벌 - 꿀통
    for(int i=1;i<N-1;i++)answer=max(answer,2*sum[N]-honey[0]-sum[i+1]-honey[i]);
    //벌 - 꿀통 - 벌
    for(int i=1;i<N-1;i++)answer=max(answer,sum[i+1]-honey[0]+sum[N-1]-sum[i]);
    //꿀통 - 벌 - 벌
    for(int i=1;i<N-1;i++)answer=max(answer,sum[N-1]+sum[i]-honey[i]);
    cout<<answer;
}