class Solution {
public:
    int hours ;
    int value ;
    vector<int>Piles;
    long long cost_function(int search_number ){
        long long cost = 0 ;
        if (search_number == 0) return (long long)hours + 1;
        for ( int i = 0 ;i < Piles.size() ;i++){
            cost += (Piles[i] + search_number - 1LL) / search_number;
        }
        return cost ;
        
    }
    int minimize(int l , int r){
        if (l>r) return value ;
        int mid = l + (r - l) / 2 ;
        long long cost = cost_function(mid);
        
        if (cost <= hours){
            value = mid ;
            return minimize(l , mid-1);
        }
        else{
            return minimize(mid+1,r) ;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        hours = h;
        Piles = piles ;
        value = 1e9 ;
        return minimize(1 , 1e9);
        
    }
};