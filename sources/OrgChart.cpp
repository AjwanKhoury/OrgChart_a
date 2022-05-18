#include <iostream>
#include "OrgChart.hpp"
using namespace std;

using namespace ariel;
    
    OrgChart::OrgChart(){}
    OrgChart::~OrgChart(){}
    OrgChart& OrgChart:: add_root(const string &root){ 
        return *this;
    }
    OrgChart& OrgChart:: add_sub(const string &parent, const string &child){ 
        return *this;
    }
    OrgChart::Iterator OrgChart::begin_level_order(){
        return Iterator(root, "n");
    }
    OrgChart::Iterator OrgChart::begin_preorder(){
        return Iterator(root, "n");
    }
    OrgChart::Iterator OrgChart::begin_reverse_order(){
        return Iterator(root,"n");
    }
    OrgChart::Iterator OrgChart::end_level_order(){
        return Iterator(root,"n");
    }
    OrgChart::Iterator OrgChart::end_preorder(){
        return Iterator(root,"n");
    }
    OrgChart::Iterator OrgChart::reverse_order(){
        return Iterator(root,"n");
    }
    OrgChart::Iterator OrgChart::begin(){
        return Iterator(root,"n");
    }
    OrgChart::Iterator OrgChart::end(){
        return Iterator(root,"n");
    }
    string* OrgChart::Iterator::operator->(){
        string *t;
        return t;
    }
    string OrgChart:: Iterator::operator*(){
        return "T";
    }
    bool OrgChart::Iterator::operator!=(const Iterator &otherIterator){
        return false;
    }
    bool OrgChart::Iterator::operator==(const Iterator &otherIterator){
        return true;
    }
    OrgChart::Iterator &OrgChart::Iterator::operator++(){
        return *this;
    }   
    ostream & ariel::operator<<(ostream& out, const OrgChart &org){
        return out;
    }
    OrgChart::Iterator::Iterator(Node* node, const string &method){}
