// Given a vector of domains and their visit counts,
// compute visit counts for each domain and subdomains
// O(n) time and space

#include <unordered_map>
#include <iostream>
#include <string>

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        std::unordered_map<string, int> domain_to_count;
        
        for (std::string cpdomain : cpdomains)
        {
            size_t n = cpdomain.size();
            int count_num;
            std::string count_string;
            std::string full_domain;
            std::string current_domain ;
            
            // computing the count for current cpdomain
            int i = 0;
            while (cpdomain[i] != ' ' && i < n)
            {
                count_string.push_back(cpdomain[i]);
                ++i;
            }
            count_num = std::stoi(count_string);
            // we are on the ' ' char right now, so move ahead 1
            ++i;
            
            // finding the full domain from current cpdomain
            while (i < n)
            {
                full_domain.push_back(cpdomain[i]);
                ++i;
            }
            
            // incrementing the count for full domain
            domain_to_count[full_domain] += count_num;
            size_t m = full_domain.size();
            
            // finding the domaing of the highest level, e.g. "com"
            i = m - 1;
            std::string highest_level_domain;
            while (i > -1 && full_domain[i] != '.')
            {
                highest_level_domain.insert(0, std::string(1,full_domain[i]));
                --i;
            }
            --i;
            
            // incrementing count of highest level domain
            if (highest_level_domain != ""){                
                domain_to_count[highest_level_domain] += count_num;
                
                std::string middle_level_domain = highest_level_domain;
                middle_level_domain.insert(0,  std::string(1, '.'));
                while (i > -1 && full_domain[i] != '.')
                {
                    middle_level_domain.insert(0, std::string(1,full_domain[i]));
                    --i;
                }
                if (middle_level_domain != "" && middle_level_domain != full_domain)
                {
                    domain_to_count[middle_level_domain] += count_num;
                }
            } 
        }
        
        std::vector<string> res;
        
        for (auto const& [key, val] : domain_to_count)
        {
            res.push_back(std::to_string(val) + " " + key);
        }
        
        return res;
    }
};