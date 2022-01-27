#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
int b[1001], n;
double cal(int x, int y) {return sqrt(abs(x - y));}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;        
        for (int i = 0; i < n; i++) 
            std::cin >> b[i];
        std::sort(b, b + n);
        for (int k = 1; k <= 4; k++)
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (cal(i, b[i]) + cal(j, b[j]) > cal(i, b[j]) + cal(j, b[i]))
                        std::swap(b[i], b[j]);
        for (int i = 0; i < n; i++)
            std::cout << b[i] << ' ';
        std::cout << std::endl;
    }
    return 0;
}