class Solution {
public:
    string defangIPaddr(string address) {
        string adrs;
        for(auto x: address){
            if(x=='.'){
                adrs +="[.]";
            }
            else adrs +=x;
        }
        return adrs;
    }
};