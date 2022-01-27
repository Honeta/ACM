#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> f(s.size(), std::vector<int>(9));
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            if(s[i] == '1') f[i][1] = 1;
            continue;
        }
        if (s[i] == '1')
        {
            f[i][1] = f[i-1][1] + 1;
            f[i][8] = f[i-1][8];
            f[i][0] = f[i-1][0];
            f[i][7] = f[i-1][7];
        }            
        else if (s[i] == '8')
        {
            if(f[i-1][1])
            {
                f[i][1] = f[i-1][1];
                f[i][8] = std::max(f[i-1][1] + 1, f[i-1][8] + 1);            
                f[i][0] = f[i-1][0];
                f[i][7] = f[i-1][7];
            } 
        }                   
        else if (s[i] == '0')
        {
            if(f[i-1][8])
            {
                f[i][1] = f[i-1][1];
                f[i][8] = f[i-1][8]; 
                f[i][0] = std::max(f[i-1][8] + 1, f[i-1][0] + 1);
                f[i][7] = f[i-1][7];
            }
        }                    
        else
        {
            if(f[i-1][0])
            {
                f[i][1] = f[i-1][1];
                f[i][8] = f[i-1][8];
                f[i][0] = f[i-1][0];
                f[i][7] = std::max(f[i-1][0] + 1, f[i-1][7] + 1);
            }
        }                    
    }
    std::cout << f[s.size() - 1][7];
    return 0;
}