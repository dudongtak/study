#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),-1);
    for(int i=numbers.size()-2;i>=0;i--){
        if(numbers[i]<numbers[i+1]){
            answer[i]=numbers[i+1];
        }
        else{
            int k=1;
            while(i+k<numbers.size()){
                if(answer[i+k]==-1)break;
                if(answer[i+k]>numbers[i]){
                    answer[i]=answer[i+k];
                    break;
                }
                k++;
            }
        }
    }
    return answer;
}