#include <iostream>
#include <cmath>
#include <iomanip>
const double pi = 3.1415926536;
double getvol(long long left, long long right, long long h, long long r)
{
    if(left >= r && right <= h + r)
        return pi * r * r * (right - left);
    if(right <= r)
    {
        return pi / 3 * ((3 * right * right * r - right * right * right) - (3 * left * left * r - left * left * left));
    }         
    if(left >= h + r)
    {
        return pi / 3 * (((h + r) * right * right * 3 - right * right * right - (h * h + 2 * h * r) * right * 3) - ((h + r) * left * left * 3 - left * left * left - (h * h + 2 * h * r) * left * 3));
    }
    if(left < r && right > h + r)
        return getvol(left, r, h, r) + getvol(r, h + r, h, r) + getvol(h + r, right, h, r);
    if(left < r)
        return getvol(left, r, h, r) + getvol(r, right, h, r);
    return getvol(left, h + r, h, r) + getvol(h + r, right, h, r);
}
int main()
{
    long long h,r,d;
    std::cin >> h >> r >> d;
    long long i;
    for(i = 0; i < (h + 2 * r) / d; i++)
        std::cout << std::fixed << std::setprecision(10) << getvol(i * d, (i + 1) * d, h, r) << std::endl;
    if((h + 2 * r) % d != 0)
        std::cout << std::fixed << std::setprecision(10) << getvol(i * d, h + r * 2, h, r) << std::endl;
    return 0;
}