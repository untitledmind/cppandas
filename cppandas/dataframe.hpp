#include <tuple>
#include <vector>
#include <string>
#include <iostream>

template<typename Type, typename... Types>
class DataFrame {
    private:
        std::tuple<std::vector<Types...> > df;
        std::tuple<std::string> colnames;
        int cols;
        unsigned rows;
    public:
        DataFrame() {}
        DataFrame(Types&... t) {}
        DataFrame(std::vector<Types...>& v...) {std::tuple_cat(v);}
        virtual ~DataFrame() {}

        std::vector<Type>& operator[] (int& index_) const {std::get<index_>(df);}
        std::vector<Type>& operator[] (std::string& index_) const {}
        DataFrame<Type> select() const {}
        DataFrame<Type> filter() (bool (*fcn)(Type)) const {}
        void append(std::vector<Type>& df_) {std::tuple_cat(df, df_); ++cols;}
        void size() const {std::cout << "A tibble: " << rows << " x " << cols;}

    template<typename U>
    friend std::ostream& operator<< (std::ostream& os, DataFrame<U>& rhs) {
        for (int j=0; j<cols; ++j)
            os << std::get<j>(colnames) << '\t';
        os << '\n';

        for (int j=0; j<cols; ++j) {
            for (int i=0; i<rows; ++i)
                os << std::get<j>(df[i]) << '\t';
            os << '\n';
        }
        
        return os;
    }
};