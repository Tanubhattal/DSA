class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer(seq.length());
        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
                answer[i] = i % 2;
            } 
            else {
                answer[i] = 1 - (i % 2);
            }
        }
        return answer;
    }
};