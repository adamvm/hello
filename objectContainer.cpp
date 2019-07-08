#include <boost/any.hpp>
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<boost::any> some_values;
    some_values.emplace_back(10);
    some_values.emplace_back("Hello there!");
    some_values.emplace_back(std::string("Wow!"));

    auto& s = boost::any_cast<std::string&>(some_values.back());
    s += " That is great";
    std::cout << s;
}
