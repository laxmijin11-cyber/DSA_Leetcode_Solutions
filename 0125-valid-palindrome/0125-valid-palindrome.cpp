class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned="";
        for(char ch:s){
            if(isalnum(ch)){
                cleaned+=tolower(ch); 
            }
        }
        int n=cleaned.length();
        for(int i=0;i<n/2;i++){
            if(cleaned[i]!=cleaned[n-1-i]){
                return false;
            }
        }
        return true;
    }
};

//upper to lower===toLowerCase()
//remove all alpha numeric pairs===regex==(" ")
// s.replaceAll("[^a-z0-9]","")----^ is not operator.
