
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <random>

#include <cmath>

int main()
{
    std::vector<double> v { 10, 30, 40, 55, 60 };   // 定义了 [10,30), [30,40), [40,55),[55,60) 四个区间
    std::vector<double> w { 6, 12, 9, 6, 0 };       // 每个区间节点上对应的权值
    std::piecewise_linear_distribution<> d { std::begin(v), std::end(v), std::begin(w) };
    
    // Output the interval boundaries and the interval probabilities
    auto values = d.intervals();
    std::cout << "Sample values: ";
    std::copy(std::begin(values), std::end(values), std::ostream_iterator<double>{std::cout, " "});
    
    std::cout << " probability densities: ";
    auto probs = d.densities();
    std::copy(std::begin(probs), std::end(probs), std::ostream_iterator<double>{ std::cout, " " });
    std::cout << std::endl;
    
    std::random_device rd;
    std::default_random_engine rng { rd() };
    std::map<int, size_t> results;
    
    // Generate a lot of random values...
    for (size_t i{}; i < 20000; i++) {
        ++results[static_cast<int>(std::round(d(rng)))];
    }
    
    // Plot the integer values
    auto max_count = std::max_element(std::begin(results), std::end(results),
                                      [](const std::pair<int, size_t>& pr1, const std::pair<int, size_t>& pr2){
                                          return pr1.second < pr2.second;
                                      })->second;
    
    std::for_each(std::begin(results), std::end(results), [max_count](const std::pair<int, size_t>& pr){
        if (! (pr.first % 10)) {
            std::cout << pr.first << "-|";
        } else {
            std::cout << std::setw(4) << " |";
        }
        std::cout << std::string(pr.second * 80 / max_count, '*') << std::endl;
    });
    
    return 0;
}