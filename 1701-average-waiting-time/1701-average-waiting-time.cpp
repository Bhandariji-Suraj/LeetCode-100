class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long total_waiting_time = 0;
        int current_time=0;
        
        for(int i=0;i<customers.size();i++)
        {
            int arrival = customers[i][0];
            int time = customers[i][1];
            
            
            if(current_time < arrival)
            {
                current_time = arrival;
            }
            int waiting_time = current_time -arrival + time;
            total_waiting_time += waiting_time; 
            current_time += time;
            
        }
        double avg = (double)total_waiting_time / customers.size();
        return avg;
        
    }
};