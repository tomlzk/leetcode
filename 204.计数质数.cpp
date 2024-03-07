/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start

#include<iostream>
using namespace std;
#include<vector>

//埃氏筛
// class Solution {
// public:
//     int countPrimes(int n) {
//         vector<int> isPrime(n, 1);
//         int ans = 0;
//         for (int i = 2; i < n; ++i) {
//             if (isPrime[i]) {
//                 ans += 1;
//                 if ((long long)i * i < n) {
//                     for (int j = i * i; j < n; j += i) {
//                         isPrime[j] = 0;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


//线性筛
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        return primes.size();
    }
};
// @lc code=end
