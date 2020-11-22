class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> flag;
        int max = 0;
        for (int i = 0; i < candies.size(); i++) {
            if (max < candies[i])
                max = candies[i];
        }
        for (int j = 0; j < candies.size(); j++) {
            if ((candies[j] + extraCandies) >= max)
                flag.push_back(true);
            else flag.push_back(false);
        }
        return flag;
    }
};