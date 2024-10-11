class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival=times[targetFriend][0];
        sort(times.begin(),times.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied_chairs;
        priority_queue<int,vector<int>,greater<int>>available_chairs;
        int chairs=0;
        for(int i=0;i<times.size();i++){
            int arrivalTime=times[i][0];
            int departureTime=times[i][1];
            int required_chair;
            while(!occupied_chairs.empty() && occupied_chairs.top().first<=arrivalTime){
                available_chairs.push(occupied_chairs.top().second);
                occupied_chairs.pop();
            }
            if(available_chairs.empty()){
                    required_chair=chairs++;
            }else{
                required_chair=available_chairs.top();
                available_chairs.pop();
            }
            
            if(arrivalTime==targetArrival){
                return required_chair;
            }
            occupied_chairs.push({departureTime,required_chair});           
        }
        
        return chairs;
        
        
    }
};