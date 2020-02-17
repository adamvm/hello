#include <boost/array.hpp>
#include <boost/thread.hpp>
#include <algorithm>
#include <iostream>

typedef boost::array<char, 4> array4_t;

array4_t &vector_advance(array4_t &val) {
    const auto inc = [](char& c) {c++;};

    std::for_each(val.begin(), val.end(), inc);
    return val;
}

void thFunction() {
    std::cout << "Thread is running" << std::endl;
}

int main() {
    array4_t val = {0, 1, 2, 3};

    array4_t val_res;
    val_res = vector_advance(val);

    static_assert(array4_t::size() == 4, "");
    assert(val[0] == 1);

    static_assert(sizeof(val) == sizeof(char) * array4_t::static_size, "");

    boost::thread t(thFunction);
    t.join();
    
    return 0;
}
