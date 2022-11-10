#include "trie.h"


Trie::Node::Node(char _data, bool _is_finished):
data{_data},
is_finished{_is_finished}
{
    std::cout <<"Node Constructor Called" << std::endl;
}


Trie::Trie()
{
    std::cout << "Trie Constructor Called" << std::endl;

    root = new Node {'\0', false};

    
}

void Trie::insert(std::string str)
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "insert running" << std::endl;
    Node* father{root};


    // number of childs for node father
    // (*father).children.size(); 


    // pointer to access data of 0th child of father
    // ((*father).children[0]);

    // Node of 0th child of father
    // (*((*father).children[0]));

    // to access the data
    // (*((*father).children[0])).data ;     //Data

    // to access ith child of father and assign it to son
    // Node* son{(*father).children[i]};   //Initialize
    
    
    
    char charac {str[0]};
    for (size_t i{0}; i < str.size(); i++){
        charac = str[i];
        // flag to check if the word is found
        bool flag{false};
        size_t index{0};
        size_t num_child{(*father).children.size()};

        // checking childern to see if they match charac
        if ((*father).children.size()>0){
            //loop through existing children
            for (size_t j{0} ; j < num_child ; j++){
                Node* son{(*father).children[j]};
                if (charac == (*(son)).data){
                    flag = true;
                    index = j;
                }
            }
        }

        if (flag == false){
            // adding a new child to father and changing father for next iter
            Node* add_child{new Node {charac, false}};
            (*father).children.push_back(add_child);
            (*father).is_finished = false;
            father = (*father).children[num_child];
        }
        else{
            // changing father for next iter
            (*father).is_finished = false;
            father = (*father).children[index];
        } 
    }
    (*father).is_finished = true;
    

    //////////////Test
    // Node* father2{root};
    
    // std::cout << "root" << std::endl;
    // for (size_t j{0} ; j < (*father2).children.size() ; j++){
    //     std::cout << "child number " << j << " is:   ";
    //     std::cout << (*((*father2).children[j])).data << std::endl;
    // }
    // father2 = (*father2).children[2];
    // std::cout << "s" << std::endl;
    // for (size_t j{0} ; j < (*father2).children.size() ; j++){
    //     std::cout << "child number " << j << " is:   ";
    //     std::cout << (*((*father2).children[j])).data << std::endl;
    // }
    // father2 = (*father2).children[0];
    // std::cout << "t" << std::endl;
    // for (size_t j{0} ; j < (*father2).children.size() ; j++){
    //     std::cout << "child number " << j << " is:   ";
    //     std::cout << (*((*father2).children[j])).data << std::endl;
    // }
    // father2 = (*father2).children[0];
    // std::cout << "r" << std::endl;
    // for (size_t j{0} ; j < (*father2).children.size() ; j++){
    //     std::cout << "child number " << j << " is:   ";
    //     std::cout << (*((*father2).children[j])).data << std::endl;
        
    // }

    std::cout << "End of insert" << std::endl;
}


bool Trie::search(std::string query){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "search running" << std::endl;
    Node* father{root};
    // flag to check if the word is found, if a word was missing, it becomes false
    bool main_flag{true};
    size_t index{0};

    char charac {query[0]};
    for (size_t i{0}; i < query.size(); i++){
        charac = query[i];
        // flag to check if the word is found
        bool flag{false};

        size_t num_child{(*father).children.size()};
        // checking childern to see if they match charac
        if ((*father).children.size()>0){
            //loop through existing children
            for (size_t j{0} ; j < num_child ; j++){
                Node* son{(*father).children[j]};
                if (charac == (*(son)).data){
                    flag = true;
                    index = j;
                }
            }
        }

        if (flag == false){
            // adding a new child to father and changing father for next iter
            main_flag = false;
            break;
        }else{
            father = (*father).children[index];
        }
        
    }

    if ((*father).is_finished == false){
        main_flag = false;
    }

    return main_flag;

}








void Trie::test_root(std::string str){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "test_root running" << std::endl;
    // checking the member vals

    std::cout <<"is data root == /0: " << ((*root).data == '\0') << std::endl;

    (*root).is_finished = false;
    std::cout <<"is_finished root: " << (*root).is_finished << std::endl;

    // adding some test letters to root as children
    

    std::cout << "End of test_root" << std::endl;
    
    // std::cout << str.size() << std::endl;
}


