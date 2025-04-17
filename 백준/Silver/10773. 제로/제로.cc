#include<iostream>
#include<stack>
using namespace std;

int K,num;
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>num;
        if(num==0){
            s.pop();
        }
        else{
            s.push(num);
        }
    }
    
    int answer=0;
    while(!s.empty()){
        answer+=s.top();s.pop();
    }
    cout<<answer;
}