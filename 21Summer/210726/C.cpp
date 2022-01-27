#include <iostream>
#include <algorithm>
#include <string>
int main() {
    int a, b, c, n;
    std::cin >> a >> b >> c >> n;
    int minn = std::min(a, std::min(b, c));
    std::string s1(minn,'a');
    std::string s2(minn,'a');
    std::string s3(minn,'a');
    a -= minn;
    b -= minn;
    c -= minn;
    s1 += std::string(a, 'b');
    s2 += std::string(a, 'b');
    s2 += std::string(b, 'c');
    s3 += std::string(b, 'c');
    s1 += std::string(c, 'd');
    s3 += std::string(c, 'd');
    if (s1.size() > n || s2.size() > n || s3.size() > n) {
        std::cout << "NO";
        return 0;
    }
    s1 += std::string(n - s1.size(), 'e');
    s2 += std::string(n - s2.size(), 'f');
    s3 += std::string(n - s3.size(), 'g');
    std::cout << s1 << std::endl 
              << s2 << std::endl
              << s3;
    return 0;
}