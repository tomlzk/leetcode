/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<sstream>
class Solution {
public:
    string countAndSay(int n) 
    {
        vector<string> array;
        int k = 1;
        array.push_back("1");
        for(; k < n; k++)
        {
            string temp = array[k - 1];
            char temp_2 = temp[0];
            int count = 0;
            string arrayk;
            for(int i = 0; i < temp.length(); i++)
            {
                //string now(1, temp[i]);
                char now = temp[i];
                if(temp_2 == now)
                {
                    count++;
                }
                else
                {
                    string number1 = to_string(count);
                    //cout<<number1<<endl;
                    string number2(1, temp_2);
                    temp_2 = now;
                    //cout<<number2<<endl;
                    //cout<<arrayk<<endl;
                    arrayk = arrayk + number1 + number2;
                    //cout<<arrayk<<endl;
                    count = 0;
                    i--;
                }
            }

            if(count > 0)
            {
                string number1 = to_string(count);
                string number2(1, temp[temp.length() - 1]);
                arrayk = arrayk + number1 + number2;
            }
            cout<<arrayk<<endl;
            
            array.push_back(arrayk);
        }

        return array[k - 1];
    }
};
// @lc code=end

