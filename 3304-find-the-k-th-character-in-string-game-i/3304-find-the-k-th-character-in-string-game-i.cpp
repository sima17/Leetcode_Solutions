class Solution {
public:
    char kthCharacter(int k) {
        int index=k-1;
        int increment =0;
        while(index>0){
            int p=1;
            while(p*2<=index){
                p*=2;
            }
            increment++;
            index-=p;
        }
        return 'a'+(increment%26);
    }
};