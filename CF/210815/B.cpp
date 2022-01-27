#include <iostream>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        char a[101], dict[2] = {'B', 'R'};
        a[0] = 'N';
        int cnt = 0;
        char st;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            if (a[i] != '?') {
                if (cnt) {                    
                    if (a[i] == 'B') {
                        for (int i = (cnt & 1); i < cnt + (cnt & 1); i++)
                            std::cout << dict[i & 1];
                    } else {
                        for (int i = (cnt & 1); i < cnt + (cnt & 1); i++)
                            std::cout << dict[!(i & 1)];
                    }
                    cnt = 0;
                }
                std::cout << a[i];                
            } else {
                if (!cnt) st = a[i - 1];
                ++cnt;                  
            }            
        }
        if (cnt) {
            if (st == 'B')
                for (int i = 1; i <= cnt; i++)
                    std::cout << dict[i & 1];
            if (st == 'R' || st == 'N')
                for (int i = 0; i < cnt; i++)
                    std::cout << dict[i & 1];
        }
        std::cout << std::endl;    
    }
    return 0;
}