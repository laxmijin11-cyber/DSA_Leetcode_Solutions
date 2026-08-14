class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int maxLen=0;
        int left=0;

        for(int right=0;right<s.length();right++){
            //duplicates found
              while(window.find(s[right])!=window.end()){
                window.erase(s[left]);
                left++;
              }
              // duplicate not found
              maxLen=max(maxLen,right-left+1);
              window.insert(s[right]);
        }
        return maxLen;
    }
};

//duplicate
//Fixed Size



// sliding window problem
//size of window or subarray-->target sum
//size of the window given 
