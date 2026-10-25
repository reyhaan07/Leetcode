class Solution {
public:
  int majorityElement(vector<int>& nums) {
 int cand=0, count=0; for (int x:nums) { if (!count) cand=x; count += (x==cand?1:-1); } return cand;
}
};