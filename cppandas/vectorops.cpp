#ifndef VECTOROPS_HPP
#define VECTOROPS_HPP

#include <vector>
#include <iostream>
#include <cmath>

namespace vecop {
    template<typename Type>
    Type sum(std::vector<Type>& vec) {
        Type result;
        for (Type& i : vec)
            result += i;
        return result;
    }

    template<typename Type>
    std::vector<Type> cumsum(std::vector<Type>& vec) {
        std::vector<Type> result;
        Type rsum;
        for (Type& i : vec) {
            rsum += i;
            result.push_back(rsum);
        }
        return result;
    }

    template<typename Type>
    std::vector<Type> cumprod(std::vector<Type>& vec) {
        std::vector<Type> result;
        int size = vec.size();
        Type rsum = vec[0];
        result.push_back(rsum);
        for (int i=1; i<size; ++i) {
            rsum *= vec[i];
            result.push_back(rsum);
        }
        return result;
    }

    template<typename Type>
    Type mean(std::vector<Type>& vec) {
        return sum(vec) / vec.size();
    }

    template<typename Type>
    Type stdev(std::vector<Type>& vec) {
        Type mu = mean(vec);
        Type rsum;
        for (Type& i : vec) {
            Type diff = i - mu;
            rsum += diff * diff;
        }
        return sqrt(rsum / (vec.size() - 1));   // Basel correction
    }

    // template<typename Type>
    // Type variance(std::vector<Type>& vec) {
    //     Type mu = mean(vec);
    //     Type rsum;
    //     for (Type& i : vec) {
    //         Type diff = i - mu;
    //         rsum += diff * diff;
    //     }
    //     return rsum / (vec.size() - 1);     // Basel correction
    // }

    template<typename Type>
    Type variance(std::vector<Type>& vec) {
        Type sum;
        Type sumsq;
        for (Type& i : vec) {
            sum += i;
            sumsq += i*i;
        }
        int n = vec.size();
        return (sumsq - (sum * sum) / n) / (n - 1);
    }

    template<typename Type>
    Type kurtosis(std::vector<Type>& vec) {

    }

    template<typename Type>
    Type min(std::vector<Type>& vec) {
        Type result = vec[0];
        int size = vec.size();
        for (int i=1; i<size; ++i)
            if (vec[i] < result)
                result = vec[i];
        return result;
    }

    template<typename Type>
    Type max(std::vector<Type>& vec) {
        Type result = vec[0];
        int size = vec.size();
        for (int i=1; i<size; ++i)
            if (vec[i] > result)
                result = vec[i];
        return result;
    }

    template<typename Type>
    std::vector<Type> head(std::vector<Type>& vec, int& num) {
        std::vector<Type> result;
        for (int i=0; i < num; ++i)
            result.push_back(vec[i]);
        return result;
    }

    template<typename Type>
    std::vector<Type> tail(std::vector<Type>& vec, int& num) {
        std::vector<Type> result;
        Type end = vec.size();
        for (int i = end - num; i < end; ++i)
            result.push_back(vec[i]);
        return result;
    }

    template<typename Type>
    void print(std::vector<Type> vec) {
        for (Type& i : vec)
            std::cout << '[' << i << "] ";
        std::cout << '\n';
    }

}
template<typename Type>
std::ostream& operator<< (std::ostream& os, std::vector<Type> vec) {
    for (Type& i : vec)
        os << '[' << i << "] ";
    os << '\n';
    return os;
}


#endif

int main()
{
    std::vector<double> myvec = {1,2,3,4,5,6,1,2,3,1,2,6,3,4,-3,-5};
    int bob = 5;
    std::vector<double> head5 = vecop::head(myvec, bob);
    std::vector<double> tail5 = vecop::tail(myvec, bob);
    std::cout << myvec;
    std::cout << "Sum = " << vecop::sum(myvec) << '\n';
    std::cout << "Cum sum = ";
    std::vector<double> cumsum = vecop::cumsum(myvec);
    vecop::print(cumsum);
    std::cout << "Cum prod = " << vecop::cumprod(myvec);
    std::cout << "Mean = " << vecop::mean(myvec) << '\n';
    std::cout << "Stdev = " << vecop::stdev(myvec) << '\n';
    std::cout << "Variance = " << vecop::variance(myvec) << '\n';
    std::cout << "Min = " << vecop::min(myvec) << '\n';
    std::cout << "Max = " << vecop::max(myvec) << '\n';
    std::cout << "Head(5) = ";
    vecop::print(head5);
    std::cout << "Tail(5) = ";
    vecop::print(tail5);

    return 0;
}