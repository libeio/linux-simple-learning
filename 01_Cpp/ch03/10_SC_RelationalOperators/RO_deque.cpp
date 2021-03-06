
#include <deque>
#include <iostream>
#include <string>

int main()
{    
    {
        std::deque<double> c1 {
                                    1.23,
                                    2.71828,
                                    3.1415,
                                    4.78,
                                    5.21,
                                    6.18
                                };
        std::deque<double> c2 {
                                    1.23,
                                    2.71828,
                                    3.1415,
                                    4.78,
                                    5.21,
                                    6.18,
                                };
        if (c1 == c2) {
            std::cout << "c1 == c2." << std::endl;
        }
    }

    {
        std::deque<double> c3 {
                                    1.23,
                                    2.71828,
                                    3.1415,
                                    4.78,
                                    5.21,
                                    6.18
                                };
        std::deque<double> c4 {
                                    1.23,
                                    2.71828,
                                    3.1415,
                                    4.78,
                                    5.21,
                                };
        if (c3 != c4) {
            std::cout << "c3 != c4." << std::endl;
        }
    }
    
    {
        std::deque<std::string> c5 {
            "Thank you for standing behind me",
            "In all that I do",
            "I hope you're as happy with me",
            "as I am with you",
        };
        
        std::deque<std::string> c6 {
            "Thank you for standing behind me",
            "In all that I do",
            "I hope you're as happy with me",
            "As I am with you",
        };
        if (c5 > c6) {
            std::cout << "c5 > c6." << std::endl;
        }
    }
    
    {
        std::deque<std::string> c7 {
            "Thank you for standing behind me",
            "In all that I do",
            "I hope you're as happy with me",
            "As I am with you",
        };
        
        std::deque<std::string> c8 {
            "Thank you for standing behind me",
            "In all that I do",
            "I hope you're as happy with me",
            "as I am with you",
        };
        if (c7 < c8) {
            std::cout << "c7 < c8." << std::endl;
        }
    }
    
    {
        std::deque<std::string> c9 {
            "Thank you for standing behind me",
            "In all that I do",
            "I hope you're as happy with me",
            "as I am with you",
        };
        
        std::deque<std::string> c10 {
            "Thank you for standing behind me",
            "In all that I do",
            "I hope you're as happy with me",
            "As I am with you",
        };
        if (c9 >= c10) {
            std::cout << "c9 >= c10." << std::endl;
        }
    }
    
    {
        std::deque<std::string> c11 {
            "Thank you for standing behind me",
            "In all that I do",
            "I hope you're as happy with me",
            "As I am with you",
        };
        
        std::deque<std::string> c12 {
            "Thank you for standing behind me",
            "In all that I do",
            "I hope you're as happy with me",
            "as I am with you",
        };
        if (c11 <= c12) {
            std::cout << "c11 <= c12." << std::endl;
        }
    }
    
    return 0;
}
