class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;
        set<int> available_servers;
        for (int i = 0; i < k; ++i) {
            available_servers.insert(i);
        }
        vector<int> request_count(k, 0);
        int max_requests = 0;
        for (int i = 0; i < arrival.size(); ++i) {
            long long curr_time = arrival[i];
            long long duration = load[i];
            while (!busy_servers.empty() && busy_servers.top().first <= curr_time) {
                available_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }
            if (available_servers.empty()) {
                continue;
            }
            int target = i % k;
            auto it = available_servers.lower_bound(target);
            if (it == available_servers.end()) {
                it = available_servers.begin();
            }
            int server_id = *it;
            available_servers.erase(it);
            busy_servers.push({curr_time + duration, server_id});
            request_count[server_id]++;
            max_requests = max(max_requests, request_count[server_id]);
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                result.push_back(i);
            }
        }
        return result;
    }
};