class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // runtime 36ms storage 16mb
		vector<string> result;
        // game plan: 
        // 1. parse input, map # of visits to a vector of all related domains
        // 2. Iterate through each input, for each visit, add an instance of each of the subdomains of the current address
        // 3. Count each subdomain using multiset.count(item)
            // Might need to maintain a set of all unique addresses
        //multiset<string> numOccurrences;
        map<string, int> numOccurrences;
        set<string> unique;
        for (int i = 0; i < cpdomains.size(); ++i)
        {
            stringstream s(cpdomains[i]);
            int numVisits(0);
            vector<string> domains;
            string currentDomain;
            s >> numVisits;
            // build array of domains
            while (getline(s, currentDomain, '.'))
            {
                if (currentDomain[0] == ' ')
                {
                    currentDomain.erase(0, 1);
                }
                domains.push_back(currentDomain);
            }
            
            for (int i = 0; i < domains.size(); ++i)
            {
                currentDomain = domains[i];    
                for (int j = i + 1; j < domains.size(); ++j)
                {
                    currentDomain += "." + domains[j];

                }
                unique.insert(currentDomain);
                numOccurrences[currentDomain] += numVisits;
                
            }
        }
        // create the domain array (array of strings), iterate through array and add the numbers that way. 
        string finalStr("");
        for (string domain : unique)
        {
            finalStr += std::to_string(numOccurrences[domain]);
            finalStr += " " + domain;
            result.push_back(finalStr);
            finalStr = "";
        }
        return result;
    }
};