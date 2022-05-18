#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

namespace ariel{
    class OrgChart{
        private:
            struct Node{
                Node *root;
                vector<Node> *leaf;
                string data;
                Node(const string &value, Node *node, vector<Node> *children):data(value), root(node), leaf(children){}
            };

        public:
            Node *root;
            OrgChart();
            ~OrgChart();
            OrgChart &add_root(const string &root); 
            OrgChart &add_sub(const string &parent, const string &child); 
            friend ostream &operator<<(ostream &os, const OrgChart &orgin);
            class Iterator{
                public:
                    Iterator(Node *node, const string &t); 
                    Iterator &operator++();
                    bool operator==(const Iterator &otherIterator);
                    bool operator!=(const Iterator &otherIterator);
                    string operator*();
                    string *operator->();
            };
            Iterator begin_level_order();
            Iterator begin_reverse_order();
            Iterator begin_preorder();
            Iterator end_level_order();
            Iterator reverse_order();
            Iterator end_preorder();
            Iterator begin();
            Iterator end();
    };
}