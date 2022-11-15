#include "trie.h"


Trie::Node::Node(char _data, bool _is_finished):
data{_data},
is_finished{_is_finished}
{
    // std::cout <<"Node Constructor Called" << std::endl;
}


Trie::Trie(): root{new Node {'\0', false}}
{
    // std::cout << "Trie Constructor Called" << std::endl;
}

void Trie::insert(std::string str)
{
    // std::cout << "----------------------------------" << std::endl;
    // std::cout << "insert running" << std::endl;
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
            // (*father).is_finished = false;
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

    // std::cout << "End of insert" << std::endl;
}


bool Trie::search(std::string query){
    // std::cout << "----------------------------------" << std::endl;
    // std::cout << "search running" << std::endl;
    Node* father{root};
    // flag to check if the word is found, if a word was missing, it becomes false
    bool main_flag{true};
    size_t index{0};

    char charac {query[0]};
    for (size_t i{0}; i < query.size(); i++){
        charac = query[i];
        // flag to check if the word is found.
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



void Trie::bfs(std::function<void(Node*& node)> func){
    // std::cout << "------------------------" << std::endl;
    // std::cout << "bfs running" << std::endl;
    // initializing
    std::vector<Node*> fathers;
    std::vector<Node*> sons;
    fathers.push_back(root);
    size_t num_fathers{};
    size_t num_child{};
    Node* father{root};
    size_t layer{};
    func(root);
    // looping in depth
    while (true){
        if (fathers.size() == 0)
            break;
        layer++;
        num_fathers = fathers.size();
        // looping in breadth
        for (size_t i{0}; i<num_fathers; i++){
            father = fathers[i];
            num_child = (*father).children.size();
            // applying the func on all of the nodes in the current layer
            for (size_t j{0}; j<num_child; j++){
                sons.push_back((*father).children[j]);
                func(((*father).children[j]));
            }

        }
        // Test
        // std::cout << std::endl;
        // std::cout << "sons.size() in layer " << layer << " is:" << std::endl;
        // std::cout << sons.size() << std::endl;
        // std::cout << "*********************************************" << std::endl;
        
        fathers = sons;
        sons = {};

    }


}

Trie::~Trie()
{   
    // std::cout << "*********************************************" << std::endl;
    // std::cout << "destructor is called:" << std::endl;
    if(root == nullptr) return;
    std::vector<Node*> nodes;
    this->bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    for(const auto& node : nodes)
        delete node;
}






Trie::Trie(const Trie& trie):
root{new Node {'\0', false}}
{
    std::vector<Node*> fathers;
    std::vector<Node*> self_fathers;
    std::vector<Node*> sons;
    std::vector<Node*> self_sons;
    fathers.push_back(trie.root);
    self_fathers.push_back(root);
    size_t num_fathers{};
    size_t num_child{};
    Node* father{trie.root};
    Node* self_father{root};
    Node* son{};
    Node* self_son{};
    size_t layer{};

    while (true){
        if (fathers.size() == 0)
            break;
        layer++;
        num_fathers = fathers.size();
        // looping in breadth
        for (size_t i{0}; i<num_fathers; i++){
            father = fathers[i];
            self_father = self_fathers[i];
            num_child = (*father).children.size();
            // applying the func on all of the nodes in the current layer
            for (size_t j{0}; j<num_child; j++){
                son = (*father).children[j];
                sons.push_back(son);
                // adding the children to fathers
                self_son = new Node {(*son).data, (*son).is_finished};
                self_sons.push_back(self_son);
                (*self_father).children.push_back(self_son);
            }
        }
        // Test
        // std::cout << std::endl;
        // std::cout << "sons.size() in layer " << layer << " is:" << std::endl;
        // std::cout << sons.size() << std::endl;
        // std::cout << "*********************************************" << std::endl;
        
        fathers = sons;
        self_fathers = self_sons;
        sons = {};
        self_sons = {};
    }

}



Trie::Trie(std::initializer_list<std::string> strings): root{new Node {'\0', false}}
{
    std::cout << "Custom constr called" << std::endl;
    
    for (auto str : strings){
        Node* father{root};
        
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
                // (*father).is_finished = false;
                father = (*father).children[num_child];
            }
            else{
                // changing father for next iter
                (*father).is_finished = false;
                father = (*father).children[index];
            } 
        }
        (*father).is_finished = true;
    }
    
    
}   

Trie::Trie(Trie&& trie): root{trie.root}
{
    // std::cout << "move constr called" << std::endl;
    trie.root = nullptr;
}

void Trie::operator=(const Trie& trie){
    std::cout << "op= called" << std::endl;
    
    std::vector<Node*> fathers;
    std::vector<Node*> self_fathers;
    std::vector<Node*> sons;
    std::vector<Node*> self_sons;
    fathers.push_back(trie.root);
    self_fathers.push_back(root);
    size_t num_fathers{};
    size_t num_child{};
    Node* father{trie.root};
    Node* self_father{root};
    Node* son{};
    Node* self_son{};
    
    while (true){
        if (fathers.size() == 0)
            break;
        
        num_fathers = fathers.size();
        // looping in breadth
        for (size_t i{0}; i<num_fathers; i++){
            father = fathers[i];
            self_father = self_fathers[i];
            num_child = (*father).children.size();
            // applying the func on all of the nodes in the current layer
            for (size_t j{0}; j<num_child; j++){
                son = (*father).children[j];
                sons.push_back(son);
                // adding the children to fathers
                self_son = new Node {(*son).data, (*son).is_finished};
                self_sons.push_back(self_son);
                (*self_father).children.push_back(self_son);
            }
        }
        
        fathers = sons;
        self_fathers = self_sons;
        sons = {};
        self_sons = {};
    }

}

void Trie::operator=(Trie&& trie){
    root = trie.root;
    trie.root = nullptr;
}