class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int temp=0;
        vector<int> ret;
        for (int i=0;i<A.size();i++){
            ret.push_back(A[i]*A[i]);
        }
       sort(ret.begin(),ret.end());
        return ret;
    }
};
