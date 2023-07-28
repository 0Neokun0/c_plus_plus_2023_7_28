#include <iostream>
#include <vector>
#include <algorithm>

int global_x {1000};

// Capture by value
// The global variable global_x cannot be captured because it is not
// within the reaching scope of the lambda. It can however still be accessed
// from within the lambda using normal name loopup rules.

void test1()
{
    std::cout << "\n---Test1-------------" << std::endl;

    int local_x{100};

    auto l = [local_x] () {
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();
}

void test2()
{
    std::cout << "\n---Test2---------------" << std::endl;

    int x {100};

    auto l = [x] () mutable {
        x += 100;
        std::cout << x << std::endl;
    };
    l();
    std::cout << x << std::endl;

    l();
    std::cout << x << std::endl;
}

void test3()
{
    std::cout << "\n---Test3----------------" << std::endl;

    int x{100};
    
    auto l =[&x] () mutable {
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl;
}

int main () {

    test1();
    test2();
    test3();

    return 0;
}