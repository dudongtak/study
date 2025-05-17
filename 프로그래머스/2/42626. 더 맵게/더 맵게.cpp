#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=0;i<scoville.size();i++)pq.push(scoville[i]);
    
    while(pq.top()<K){
        if(pq.size()==1){
            return -1;
        }
        int Min1=pq.top();
        pq.pop();
        int Min2=pq.top();
        pq.pop();
        
        pq.push(Min1+Min2*2);
        answer++;
    }
    return answer;
}