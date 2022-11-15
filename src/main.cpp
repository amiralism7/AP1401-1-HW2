
#include <iostream>
#include <gtest/gtest.h>
#include "trie.h"
#include<string>
#include <initializer_list>

void test(Trie::Node* node){
    std::cout << "----------------------------------" << std::endl;
    // std::cout << "test running" << std::endl;
    // checking the member vals

    std::cout << "node data is: " << (*node).data << std::endl;
    

    // std::cout << "End of test" << std::endl;
    
    // std::cout << str.size() << std::endl;
}

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        
        Trie temp_trie{};

        temp_trie.insert("yy");
        temp_trie.insert("abc");
        temp_trie.insert("ABCD");
        temp_trie.insert("12345");
        temp_trie.insert("1234");

        std::cout << "We are in main()" << std::endl;
        // std::cout << temp_trie.search("1234") << std::endl;
        // temp_trie.bfs(test);

        // Trie temp_trie_copy{temp_trie};
        // temp_trie_copy.bfs(test);
        // std::cout << temp_trie_copy.search("1234") << std::endl;
        

        // Trie temp_trie3{"1, 2", "aaaaa"};
        // std::cout << temp_trie3.search("aaaaa") << std::endl;

        // Trie temp_trie_move{std::move(temp_trie)};
        // std::cout << temp_trie_move.search("1234") << std::endl;

        // Trie temp_trie_eq{};
        // temp_trie_eq = temp_trie;
        // std::cout << temp_trie_eq.search("1234") << std::endl;


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

