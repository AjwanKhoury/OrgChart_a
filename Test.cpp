#include <iostream>
#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace std; 
using namespace ariel;

TEST_CASE("The Functions at all- add a root and a leaf"){
    OrgChart orgch;
    orgch.add_root("A");
    CHECK_NOTHROW(orgch.add_sub("A", "B"));
    CHECK_NOTHROW(orgch.add_sub("A", "C"));
    CHECK_THROWS(orgch.add_sub("T", "C")); // there's no T at all!
    CHECK_THROWS(orgch.add_sub("G", "B")); // there's no G at all!
    orgch.add_root("B");
    CHECK_NOTHROW(orgch.add_sub("B", "D"));
    CHECK_NOTHROW(orgch.add_sub("B" , "E"));
    orgch.add_root("C");
    CHECK_NOTHROW(orgch.add_sub("C", "F"));
    CHECK_NOTHROW(orgch.add_sub("C", "G"));
    CHECK_THROWS(orgch.add_sub("F", "H")); // there's no F at all!
    CHECK_THROWS(orgch.add_sub("K", "L")); // there's no K at all!
// --------A---------
// ----B ------C-----
// --D--E----F--G----
}

TEST_CASE("Iterators- level Order"){
    OrgChart orgch;
    orgch.add_root("A");
    CHECK_NOTHROW(orgch.add_sub("A", "B"));
    CHECK_NOTHROW(orgch.add_sub("A", "C"));
    CHECK_NOTHROW(orgch.add_sub("A", "D"));
    CHECK_NOTHROW(orgch.add_sub("A", "E"));
    vector<string> level={"A", "B" , "C" , "D"};
    unsigned long i=0;
    // for(auto it=orgch.begin_level_order(); it!=orgch.end_level_order(); ++it){
    //     CHECK_EQ(*it, level.at(it));
    //     i++;
    //     CHECK_THROWS(*it,level.at(it+1));
    // }  
}

TEST_CASE("Iterators- reverse Order"){
    OrgChart orgch;
    orgch.add_root("A");
    CHECK_NOTHROW(orgch.add_sub("A", "B"));
    CHECK_NOTHROW(orgch.add_sub("A", "C"));
    CHECK_NOTHROW(orgch.add_sub("A", "D"));
    CHECK_NOTHROW(orgch.add_sub("A", "E"));
    vector<string> level={"A", "B" , "C" , "D"};
    unsigned long i=0;
    // for(auto it=orgch.begin_reverse_order(); it!=orgch.reverse_order(); ++it){
    //     CHECK_EQ(*it, level.at(it));
    //     i++;
    //     CHECK_THROWS(*it,level.at(it+1));
    // }
}

TEST_CASE("Iterators- preOrder"){
    OrgChart orgch;
    orgch.add_root("A");
    CHECK_NOTHROW(orgch.add_sub("A", "B"));
    CHECK_NOTHROW(orgch.add_sub("A", "C"));
    CHECK_NOTHROW(orgch.add_sub("A", "D"));
    CHECK_NOTHROW(orgch.add_sub("A", "E"));
    vector<string> level={"A", "B" , "C" , "D"};
    unsigned long i=0;
    // for(auto it=orgch.begin_preorder(); it!=orgch.end_preorder(); ++it){
    //     CHECK_EQ(*it, level.at(it));
    //     i++;
    //     CHECK_THROWS(*it,level.at(it+1));
    // }
}