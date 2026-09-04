/*On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n - 1.

Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time for the function with ID i.
Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]*/

/*Dùng stack, đẩy start_A vào, (B(C(D))), end = lấy start_A ra, B ra, tính tổng rồi đẩy tiếp, cũng ghi kết quả ra
*/

#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
class Solution {
    void parseLog(const string& log, int& id, string& type, int& time) {
        string id_text, time_text;
        stringstream ss(log);
        getline(ss, id_text, ':');
        getline(ss, type, ':');
        getline(ss, time_text);
        id = stoi(id_text);
        time = stoi(time_text);
    }

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st; // {id, start_time}
        vector<int> result(n, 0);
        for(const string& log : logs) {
            int id, time;
            string type;
            parseLog(log, id, type, time);
            if (type == "start") {
                st.push({id, time});
            } else {
                auto [start_id, start_time] = st.top();
                st.pop();
                result[start_id] += time - start_time + 1;
                if (!st.empty()) {
                    result[st.top().first] -= time - start_time + 1;
                }
            }
        }
        return result;
    }
};