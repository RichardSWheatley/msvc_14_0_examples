// must be compiled with -std=c++11 flag

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>

class SortedSearch {
public:
    static int countNumbers(const std::vector<int>& sortedVector, int lessThan) {
        // in this case, auto is a std::iterator
        auto low = std::lower_bound (sortedVector.begin(), sortedVector.end(),lessThan); //          ^
        
        // when subtracting two std::iterators of the same type, the results is a std::int
        return low - sortedVector.begin();
    }
    
    
};

void write_vec(const vector<int>& vec) {
    for (vector<int>::const_iterator iter = vec.begin();
        iter != vec.end(); ++iter) {
        std::cout << *iter << ", ";
    }
}

int main() { 
    std::vector<int> myVec { 1, 3, 5, 7 };
    std::vector<int> data;
    for (int x=0;x<60000;x++)
        data.push_back(rand());

    std::sort(data.begin(), data.end());

    std::cout << "full vector : ";
    write_vec(data);
    std::cout << endl;

    float average = accumulate( data.begin(), data.end(), 0.0)/data.size();

    std::cout << SortedSearch::countNumbers(data, (int)average);
}
