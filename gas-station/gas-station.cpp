class Solution {
/*
    If starts at i and fails at k, then starting from any position
    between i and k will fail. So the next attempt should be k + 1

    Try to travel two circle and every attempt will be tried by this
    way
*/
    
public:
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int tank = 0;
    int start = 0;
    int cur = 0;
    int next = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cur = i % n;
        next = (i + 1) % n;
        tank = tank + gas[cur] - cost[cur];
        if (tank >= 0) {
            if (next == start) {
            return start;
            }
            } else {
            start = next;
            tank = 0;
                }
    }
    return -1;
}
};
