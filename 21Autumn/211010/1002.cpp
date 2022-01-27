#include <iostream>
#include <algorithm>
#include <math.h>
double a, b, c;
double f(double x) {
    return a * x * x + b * x + c;
}
double f_inv_l(double y) {
    return (-b + sqrt(b * b - 4.0 * a * (c - y))) / (2.0 * a);
}
double f_inv_r(double y) {
    return (-b - sqrt(b * b - 4.0 * a * (c - y))) / (2.0 * a);
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> c;
        double x0, x1, y0, y1, y2;
        std::cin >> x0 >> x1 >> y0 >> y1 >> y2;        
        double x_mid = -b * 0.5 / a;
        double y_max = f(x_mid);
//        std::cout << "y_max = " << y_max << std::endl;
        if (y0 >= y_max) {
            std::cout << "No" << std::endl;
            continue;
        }
        double x_l = f_inv_l(y0), x_r = f_inv_r(y0);
        if (x_l >= x0) {
            std::cout << "No" << std::endl;
            continue;
        }
//        std::cout << "x = " << x << std::endl;
        if (x_r > x0 && x_r < x1) {
            std::cout << "Yes" << std::endl;
            continue;
        }
        double y = f(x1);
//        std::cout << "y = " << y << std::endl;
        if (y > y0 && y <= y2 && x_r > x1 && x_r < x1 + x1 - x0) {
            std::cout << "Yes" << std::endl;
            continue;
        }
        std::cout << "No" << std::endl;
    }
}