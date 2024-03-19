#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(sequence.size());
    int start=0;
    int end=0;
    k-=sequence[end++];
    while(true){
        if(end==sequence.size()&&start==sequence.size())break;
        if(k==0){
            if(answer[1]-answer[0]>end-1-start){
                answer[0]=start;
                answer[1]=end-1;
            }
        }
        if(k>=0&&end<sequence.size()){
            k-=sequence[end++];
        }
        else{
            k+=sequence[start++];
        }
    }
    return answer;
}