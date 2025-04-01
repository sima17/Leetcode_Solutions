class Solution {
public:
  int t[38];
 int solve(int n){
    if(n==0)
    return 0;
    if(n==1 || n==2)
    return 1;
    if(t[n]!=-1){
       return t[n];
    }
int a=solve(n-1);
int b=solve(n-2);
int c=solve(n-3);
return t[n]=a+b+c;
 }
    int tribonacci(int n) {
        memset(t,-1,sizeof(t));
         return solve(n);
    }
};