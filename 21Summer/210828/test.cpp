//check
#include <iostream>
#include <string>
int main() {
    std::string s;
    std::cin >> s;
    long long sum = 0;
    for (long long i = 0; i < s.size(); i++) s[i] == '1' ? sum += (i + 1) * (i + 1) : sum -= (i + 1) * (i + 1);
    std::cout << sum << std::endl;
    return 0;
}