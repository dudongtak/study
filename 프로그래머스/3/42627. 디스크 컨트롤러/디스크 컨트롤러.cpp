#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, idx = 0, cnt = jobs.size();
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    while(idx < cnt || !pq.empty()) {
        while(idx < cnt && jobs[idx][0] <= time) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
        if(!pq.empty()) {
            time += pq.top().first;
            answer += (time - pq.top().second);
            pq.pop();
        } else {
            time = jobs[idx][0];
        }
    }
    return answer / cnt;
}
