#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct ddl{
    std::string what;
    int when;
};
bool cmp(ddl x, ddl y)
{
    return x.when < y.when;
}
int main()
{
    int n,m;
    std::vector<ddl> v[1001];
    std::cin >> n >> m;
    for(int t = 1; t <= m; t++)
    {
        int op,arg1,arg3;
        std::string arg2;
        std::cin >> op;
        switch (op)
        {
            case 1:                
                std::cin >> arg1 >> arg2 >> arg3;
                v[arg1].push_back({arg2, arg3});
                std::sort(v[arg1].begin(), v[arg1].end(), cmp);
                break;
            case 2:
                std::cin >> arg1;
                int i;
                for(i = 0; i != v[arg1].size(); i++)
                    if(v[arg1][i].when >= t)
                    {
                        std::cout << v[arg1][i].what << std::endl;
                        break;
                    }
                if(i == v[arg1].size())
                    std::cout << "Happy" <<std::endl;
                break;
            case 3:
                std::cin >> arg1 >> arg2;
                for(int i = 0; i != v[arg1].size(); i++)
                    if(v[arg1][i].what == arg2)
                    {
                        std::cout << (v[arg1][i].when >= t ? "OK" : "GG") << std::endl;
                        break;
                    }
                break;
        }
    }
    return 0;
}