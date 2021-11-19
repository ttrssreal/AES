#pragma once
#include "aes.h"
#include <string>
#include <vector>
#include "util.h"
#include "keySchedule.h"

int test1();

class Test {
public:
    int run();
    Test(int (*funcs)());

private:
    int (*m_test_func)();
};

class Tests {
public:
    void run();
    Tests(std::vector<int (*)()> funcs);
private:
    std::vector<Test> m_tests;
};