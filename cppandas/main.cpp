#include "dataframe.hpp"

int main()
{
    std::vector<int> a = {1,2,3};
    std::vector<double> b = {4.,5.,6.};
    std::vector<float> c = {-2.,-4.,-7.};
    DataFrame<int, double, float> df(a,b,c);

    // df.append(a);
    return 0;
}