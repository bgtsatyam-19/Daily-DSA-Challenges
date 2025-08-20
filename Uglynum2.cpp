#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int nthuglynumber(int n){
        vector<int> ugly(n);
        ugly[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            int nextval=min(ugly[i2]*2, min(ugly[i3]*3, ugly[i5]*5));
            ugly[i] = nextval;
            if(nextval == ugly[i2]*2) i2++;
            if(nextval == ugly[i3]*3) i3++;
            if(nextval == ugly[i5]*5) i5++;
        }
        return ugly[n-1];
    }
};
int main(){
    solution obj;
    int n=10;
    cout<<obj.nthuglynumber(n)<<endl;
    return 0;
}