class Solution {
public:
    int subtractProductAndSum(int n) {
        if(n<10)
        return 0;
        int temp,mut=1,sum=0;
        if (n>=10){
           while(n!=0){
               temp=n%10;
                mut*=temp;
                sum+=temp;
                n/=10;
           }
        }
        return mut-sum;
    }
    
};