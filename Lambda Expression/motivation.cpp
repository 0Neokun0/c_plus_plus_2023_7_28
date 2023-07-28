// Function Objects
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Square_Functor
{
    void operator()(int x)
    {
        std::cout << x * x << " ";
    }
};

template <typename T>
struct Displayer
{
    void operator()(const T &data)
    {
        std::cout << data << " ";
    }
};

class Multiplier
{
};
int main()
{

    std::cout << "\nTest1 =========================" << std::endl;
    Square_Functor square;
    square(4); // square.operator()(4) displays 16

    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100);     // displays 100
    d2("Frank"); // displays Frank

    std::cout << "\nTest2===========================" << std::endl;
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<std::string> vec2{"Larry", "Moe", "Curly"};

    std::for_each(vec1.begin(), vec1.end(), square);
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), d2);
    std::cout << std::endl;

    std::cout << "\nTest3=============================" << std::endl;
    std::for_each(vec1.begin(), vec1.end(), [](int x)
                  { std::cout << x * x << " "; }); // 1 4 9 16 25
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x)
                  { std::cout << x * 10 << " "; }); // 10 20 30 40 50
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), [](std::string s)
                  { std::cout << s << " "; }); // :arry Moe Curly
    std::cout << std::endl;

    return 0;
}