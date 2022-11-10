
#include <iostream>
#include <gtest/gtest.h>
#include "trie.h"

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        // debug section
        Trie temp_trie{};
        temp_trie.test_root("str1");
        temp_trie.insert("str1");
        temp_trie.insert("str22");
        std::cout << temp_trie.search("str") << std::endl;




    }   
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}