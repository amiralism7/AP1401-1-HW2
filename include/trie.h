#ifndef TRIE_H
#define TRIE_H

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<functional>
#include <initializer_list>
#include"fstream"

class Trie
{
  public:
    class Node
    {
      public:
        std::vector<Node*> children; ////////////
        char data;
        bool is_finished;


        Node(char _data, bool is_finished);
        Node() = default;
    };

    Node* root;



    Trie();
    // Trie::~Trie(){
    //   if(root == nullptr) return;
    //   std::vector<Node*> nodes;
    //   this->bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    //   for(const auto& node : nodes)
    //       delete node;
    // }
    
    void insert(std::string str);
    bool search(std::string query);
    void bfs(std::function<void(Node*& node)> func);
    ~Trie();
    Trie(const Trie& trie); // copy constr
    Trie(std::initializer_list<std::string> strings); // custom constr
    Trie(Trie&& trie); // move constr
    void operator=(const Trie& trie); // op =
    void operator=(Trie&& trie); // op = (move)
    
  private:
};





#endif // TRIE_H