class Solution {
public:
    int strStr(std::string string, std::string substring) {
        int n = string.length();
        int m = substring.length();
        if (m > n) {
            return -1;
        }
        int prime = 31;
        int MOD = 1e9 + 7;
        int substringHash = 0;
        int stringHash = 0;
        int power = 1;

        // Compute hash value of substring
        for (int i = 0; i < m; i++) {
            substringHash = (1LL * substringHash * prime % MOD + substring[i] - 'a' + 1) % MOD;
            stringHash = (1LL * stringHash * prime % MOD + string[i] - 'a' + 1) % MOD;
            if (i < m - 1) {
                power = 1LL * power * prime % MOD;
            }
        }

        // Check if substring is found in string
        for (int i = 0; i < n - m + 1; i++) {
            if (substringHash == stringHash && string.substr(i, m) == substring) {
                return i;
            }
            if (i < n - m) {
                stringHash = ((stringHash - (1LL * (string[i] - 'a' + 1) * power % MOD) % MOD + MOD) % MOD * prime % MOD + (string[i + m] - 'a' + 1)) % MOD;
            }
        }

        return -1;
    }
};