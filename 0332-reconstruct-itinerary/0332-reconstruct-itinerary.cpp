class Solution {
private:
    vector<string> pathway;
    map<string, map<string, int>> ticketpaths;
    int ticketsremaining;
    
    string ticketsremainingstr(map<string, map<string, int>>& ticketpaths) {
        stringstream ss;
        for (pair<string, map<string, int>> pathways : ticketpaths) {
            ss << pathways.first << ":\n";
            for (pair<string, int> arrival : ticketpaths[pathways.first]) {
                ss << "\t" << arrival.first << arrival.second << "\n";
            }
            ss << "\n";
        }
        ss << "========\n";
        return ss.str();
    }
    
    string pathwaystr(vector<string>& pathway) {
        stringstream ss;
        for (string airport : pathway) {
            ss << airport << " ";
        }
        ss << "\n";
        return ss.str();
    }
    
    bool dfs(string predecessor, string departure) {
        // cout << pathwaystr(this->pathway)  << "\n";
        // cout << this->ticketsremainingstr(this->ticketpaths);
        for (pair<string, char> pathway : this->ticketpaths[departure]) {
            string destination = pathway.first;
            char unused = pathway.second;
            if (!unused) {
                continue;
            }
            this->pathway.push_back(destination);
            this->ticketpaths[departure][destination]--;
            ticketsremaining--;
            if (dfs(departure, destination)) {
                return true;
            }
            ticketsremaining++;
            this->ticketpaths[departure][destination]++;
            this->pathway.pop_back();
        }
        
        return !ticketsremaining;
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Fill in ticket map
        this->ticketsremaining = tickets.size();
        for (vector<string> ticket : tickets) {
            string departure = ticket[0];
            string destination = ticket[1];
            if (this->ticketpaths.find(departure) == this->ticketpaths.end()) {
                this->ticketpaths.insert({departure, map<string, int>()});
            }
            this->ticketpaths[departure][destination]++;
        }
        
        // cout << this->ticketsremainingstr(this->ticketpaths);
        
        string firststation = "JFK";
        this->pathway.push_back(firststation);
        for(pair<string, int> secondstation : this->ticketpaths[firststation]) {
            this->pathway.push_back(secondstation.first);
            this->ticketpaths[firststation][secondstation.first]--;
            ticketsremaining--;
            if (dfs(firststation, secondstation.first)) {
                return this->pathway;
            }
            ticketsremaining++;
            this->ticketpaths[firststation][secondstation.first]++;
            this->pathway.pop_back();
        }
        this->pathway.pop_back();
        
        return this->pathway;
    }
};