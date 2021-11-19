#include "test.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

// add name of function to list and add declaration to test.h
std::vector<int (*)()> all_test_funcs{ test1 };

int Test::run() {
    return m_test_func();
}

Test::Test(int (*func)()) {
    m_test_func = func;
}

Tests::Tests(std::vector<int (*)()> test_funcs) {
    for (size_t i = 0; i < test_funcs.size(); i++)
    {
        Test test(test_funcs.at(i));
        m_tests.push_back(test);
    }
}

void Tests::run() {
    for (size_t i = 0; i < m_tests.size(); i++)
    {
        if (m_tests.at(i).run()) {
            std::cout << "\033[1;31m Failed\033[0m" << std::endl;
        } else {
            std::cout << "\033[1;32m Succeded\033[0m" << std::endl;
        }
    }
    
}

int main() {
    Tests tests(all_test_funcs);
    tests.run();
    return 0;
}