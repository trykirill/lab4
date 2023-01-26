#ifndef CLUTCH_TABLE_HPP
#define CLUTCH_TABLE_HPP

#include "excursion.hpp"
#include <string>
#include <list>
#include <iostream>

const int TABLE_LEN = 20;

using namespace std;

class Clutch_Table{
    protected:
        list<Excursion *> table[TABLE_LEN];
    public:
        int hax(int code);
        void insert(int code, string date, Excursion*);
        void erase(int code, string date);
        bool find(int code, string date); 
        Excursion *get_item(int code, string date);
        friend ostream &operator << (ostream&, const Clutch_Table&);
        ~Clutch_Table();
};

#endif


