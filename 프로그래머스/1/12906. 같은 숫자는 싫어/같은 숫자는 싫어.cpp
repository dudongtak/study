#include <vector>
#include <iostream>
#include<queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    deque<int> s;
    
    for(int i=0;i<arr.size();i++){
        q.push(arr[i]);
    }
    
    while(!q.empty()){
        if(s.empty()){
            s.push_back(q.front());
        }
        else{
            if(s.back()!=q.front()){
                s.push_back(q.front());
            }
        }
        q.pop();
    }
    for(int i=0;i<s.size();i++){
        answer.push_back(s[i]);
    }
    return answer;
}