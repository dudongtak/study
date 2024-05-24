#include <string>
#include <vector>

using namespace std;
// rt, cf, jm, an 앞에 나오는게 음
//양음, 3210123
//     7654321
//     1234567
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int arr[4]={0,0,0,0};
    for(int i=0;i<survey.size();i++){
        if(survey[i][0]=='R'||survey[i][0]=='T'){
            if(survey[i][0]=='R'){
                int p=choices[i]-4;
                arr[0]+=p;
            }
            else{
                int p=choices[i]-4;
                arr[0]-=p;
            }
        }
        if(survey[i][0]=='C'||survey[i][0]=='F'){
            if(survey[i][0]=='C'){
                int p=choices[i]-4;
                arr[1]+=p;
            }
            else{
                int p=choices[i]-4;
                arr[1]-=p;
            }
        }
        if(survey[i][0]=='J'||survey[i][0]=='M'){
            if(survey[i][0]=='J'){
                int p=choices[i]-4;
                arr[2]+=p;
            }
            else{
                int p=choices[i]-4;
                arr[2]-=p;
            }
        }
        if(survey[i][0]=='A'||survey[i][0]=='N'){
            if(survey[i][0]=='A'){
                int p=choices[i]-4;
                arr[3]+=p;
            }
            else{
                int p=choices[i]-4;
                arr[3]-=p;
            }
        }
    }
    if(arr[0]<=0){
        answer+='R';
    }
    else{
        answer+='T';
    }
    if(arr[1]<=0){
        answer+='C';
    }
    else{
        answer+='F';
    }
    if(arr[2]<=0){
        answer+='J';
    }
    else{
        answer+='M';
    }
    if(arr[3]<=0){
        answer+='A';
    }
    else{
        answer+='N';
    }
    
    return answer;
}