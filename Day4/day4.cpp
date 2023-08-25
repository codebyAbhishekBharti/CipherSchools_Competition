#include "bits/stdc++.h"
using namespace std;
class ksum {
    vector<pair<int, vector<int>>> v;
    void generateSubsequences(int i, int sum, vector<int>& nums, vector<int>& seq) {
        if (i == nums.size()) {
            v.push_back(make_pair(sum, seq));
            return;
        }
        generateSubsequences(i + 1, sum, nums, seq);
        seq.push_back(nums[i]);
        generateSubsequences(i + 1, sum + nums[i], nums, seq);
        seq.pop_back();
    }
public:
    int findksum(vector<int>& nums, int k) {
        vector<int> currSeq;
        generateSubsequences(0, 0, nums, currSeq);
        sort(v.begin(), v.end(), greater<pair<int, vector<int>>>());
        return k <= v.size() ? v[k - 1].first : -1;
    }
};
int main() {
    ksum ksum;
    int n,k;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    cin >> k;
    int res = ksum.findksum(num,k);
    cout << res<<endl;
    return 0;
}
