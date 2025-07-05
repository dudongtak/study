#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> answer;

int search_idx(int v){
    int s=0,e=answer.size()-1,m;

    while(s<e){
        m=(s+e)/2;
        if(answer[m]>=v)e=m;
        else s=m+1;
    }
    return e;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    vector<int> arr(N);
    
    for(int i=0;i<N;i++)cin>>arr[i];

    answer.push_back(arr[0]);

    for(int i=1;i<N;i++){
        if(arr[i]>answer.back())answer.push_back(arr[i]);
        else{
            int idx=search_idx(arr[i]);
            answer[idx]=arr[i];
        }
    }

    cout<<answer.size();
}