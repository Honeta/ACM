#include <iostream>
#include <sstream>
int main() {
    int dec[11];
    dec[1] = 1;
    for (int i = 2; i <= 10; i++)
        dec[i] = dec[i - 1] * 10;
    int t;
    std::cin >> t;
    while (t--) {
        int s, n;
        std::cin >> s >> n;        
        while (--n) {
            std::stringstream ss;
            ss << s;
            std::string str;
            ss >> str;
            int x = str.size();
            while (s - dec[x] < n) --x;
            std::cout << dec[x] << ' ';
            s -= dec[x];
        }
        std::cout << s << std::endl;
    }
    return 0;
}