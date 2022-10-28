class Solution {
public:
    map<int,vector<int>> mp;
    int helper(string &ring,string &key,int x,int y,vector<vector<int>> &dp)
    {
        if(y>=key.size())return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        int n=ring.size();
        vector<int> temp;
        for(int i=0;i<mp[key[y]-'a'].size();i++)
        {
            int dis=abs(mp[key[y]-'a'][i]-x);
            temp.push_back(1+dis+helper(ring,key,mp[key[y]-'a'][i],y+1,dp));      // clockwise position of the characters in ring
            temp.push_back(n-dis+1+helper(ring,key,mp[key[y]-'a'][i],y+1,dp));    // Anti-clockwise position of the character in ring
																				  
        }
        return dp[x][y]=*min_element(temp.begin(),temp.end());                    // We are storing all possible values from each found  
																				  // character position,then returning the best possible outcome.
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(202,vector<int>(202,-1));                          
        for(int i=0;i<ring.size();i++)mp[ring[i]-'a'].push_back(i);               // Storing the positions of the characters in map
        return helper(ring,key,0,0,dp);
    }
};
