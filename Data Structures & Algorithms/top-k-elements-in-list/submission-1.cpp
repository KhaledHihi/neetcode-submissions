class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {

        // if (1 <= nums.size() <= std::pow(10, 4))
        //     return;
        std::vector<int> result;
        std::vector<int> counted;
        std::map<int, int> tmp;

            int count = 0;
            for(size_t i = 0;i < nums.size(); i++)
            {
                int n = 0;
                for (int b = 0; b < counted.size(); b++)
                    if (counted[b] == nums[i])
                        n = 1;
                if (n)
                    continue;
                counted.push_back(nums[i]);
                for (size_t j = i;j < nums.size(); j++)
                {
                    if(nums[i] == nums[j])
                        n++;
                }
                tmp[nums[i]] = n;
            }

            std::multimap<int, int> valueSortedMap;

            // Populate the flipped map
            for (const auto& [key, val] : tmp) {
                valueSortedMap.insert({val, key});
            }

            
            std::map<int, int>::const_iterator it;
            for (it = valueSortedMap.begin(); it != valueSortedMap.end(); ++it) {
                // it->first accesses the Key, it->second accesses the Value
                std::cout << it->first << ": " << it->second << std::endl;
            }

            int size = valueSortedMap.size();
            for (int i = k; i > 0; i--)
            {
                result.push_back(valueSortedMap.rbegin()->second);
                valueSortedMap.erase(--valueSortedMap.end());
            }
        return result;
    }
};