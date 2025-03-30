#include <vector>
#include<map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> pokemon;
    for(int i=0;i<nums.size();i++){
        pokemon[nums[i]]++;
    }
    int kind=pokemon.size();
    if(kind>nums.size()/2){
        answer=nums.size()/2;
    }
    else{
        answer=kind;
    }
    return answer;
}