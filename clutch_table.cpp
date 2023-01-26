#include <iostream>
#include "clutch_table.hpp"
#include "excursion.hpp"

using namespace std;

int hex(int code){
    return code % TABLE_LEN;
}

void Clutch_Table::insert(int code, string date, Excursion *excursion){
    (table[hex(code)]).push_back(excursion);
}

void Clutch_Table::erase(int code, string date){
    int pos = hex(code);
    auto it = table[pos].begin();
    for(auto item : table[pos]){
        if(item->get_code() == code && item->get_date_start() == date){
            (table[pos]).erase(it);
            delete item;
            return;
        }
        ++it;
    }
    return;
}

bool Clutch_Table::find(int code, string date){
    int pos = hex(code); 
    for(auto item : table[pos]){
        if(item->get_code() == code && item->get_date_start() == date){
            return true;
        }
    }
    return false;
}
 
ostream& operator << (ostream &os, const Clutch_Table &clutch_table){
    os << "Таблица смешанная сцеплением:\n";
    for(int pos = 0; pos < TABLE_LEN; ++pos){
        os << "[" << pos<< "]  ";
        for(auto item : clutch_table.table[pos]){
            os << "{" << item->get_code() << ", " << item->get_date_start() << "} -> "; 
        }
        os << "nullptr\n";
    }
    return os;
}

Excursion *Clutch_Table::get_item(int code, string date){
    int pos = hex(code); 
    for(auto item : table[pos]){
        if(item->get_code() == code && item->get_date_start() == date){
            return item;
        }
    }
    return nullptr;
}

Clutch_Table::~Clutch_Table(){
    for(int pos = 0; pos < TABLE_LEN; ++pos){
        for(auto item : table[pos]){
            delete item;
        }
    }
}
