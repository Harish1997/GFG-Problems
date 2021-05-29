class Solution{   
public:
    pair<int, int> get(int a, int b){
        pair<int,int> ret;
        a=a+b;
        b=a-b;
        a=a-b;
        ret.first = a;
        ret.second = b;
        return ret;
    }
};