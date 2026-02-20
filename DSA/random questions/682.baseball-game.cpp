/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int prev1=0;
        int prev2=0;

        for(const string& c:operations){
            
            if(c == "C"){
                st.pop();
                
            }
            else if(c=="D"){
                prev1=st.top();
                st.push(prev1*2);
            }
            else if(c=="+"){
                prev1=st.top();
                st.pop();
                if(!st.empty()){
                    prev2=st.top();
                    

                }
                st.push(prev1);
                st.push(prev1+prev2);
            }

            else{
            st.push(stoi(c));}
        

        }
        int s=0;

        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        return s;
    }
};
   
// @lc code=end