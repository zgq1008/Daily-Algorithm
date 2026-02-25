class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romanmap={
            {'I',1},{'V',5},{'X',10},{'L',50},
            {'C',100},{'D',500},{'M',1000}
        };
        //使用哈希表进行键对值的映射
        int sum=0;
        for (int i=0;s[i]!='\0';i++)
        {
            if(romanmap[s[i]]<romanmap[s[i+1]])
            {
                sum-=romanmap[s[i]];
            }
            else
            {
                sum+=romanmap[s[i]];
            }
        }
        return sum;
    }
};