#include <iostream>
#include <string>
#include "excursion.hpp"

using namespace std;
//class Point 
ostream &operator << (ostream &os, const Point &point){
    return os
        << "место - " << point.plase << "\n"
        << "объект - " << point.obgect << "\n"
        << "продолжительность - " << point.time << "\n"
        << "время начала - " << point.time_start << "\n";
        return os;
}

istream &operator >> (istream &is, Point &point){
    cout << "место - ";
    is >> point.plase;
    cout << "объект - ";
    is >> point.obgect;
    cout << "время начала - ";
    is >> point.time_start;
    cout << "продолжительность - ";
    is >> point.time;
    return is;
}

//Rout
ostream& operator << (ostream &os, const Rout &rout){
    for(int pos = 0; pos < rout.number; ++pos){
        os << "пункт №" << pos + 1 << "\n" << rout.arr[pos];
    }
    return os;
}

istream& operator >> (istream &is, Rout &rout){
    cout << "кол-во пунктов - ";
    is >> rout.number;
    rout.arr = new Point[rout.number];
    for(int pos = 0; pos < rout.number; ++pos){
        cout << "пункт №" << pos + 1 << "\n";
        is >> rout.arr[pos];
    }
    return is;
}

//Excursion

ostream& operator << (ostream &os, const Excursion &excursion){
    os << "код - " << excursion.code << "\n"  
        << "название - " << excursion.name  << "\n"
        << "мах кол-во челолвек - "<< excursion.max_count << "\n" 
        << "кол-во проданых билетов - "<< excursion.sell_count << "\n"
         << "дата начала - " << excursion.date_start << "\n\n";
    return excursion.show(os);
}

istream& operator >> (istream &is, Excursion &excursion){
    cout << "название -> ";
    is >> excursion.name;
    cout << "цена -> ";
    is >> excursion.price;
    cout << "кол-во мест -> ";
    is >> excursion.max_count;
    cout << "продано -> ";
    is >> excursion.sell_count;
    return excursion.get(is);
}

//One_day_excursion

ostream &One_day_excursion::show(ostream &os)const{
    os << rout;
    return os;
}
istream &One_day_excursion::get(istream &is){
    is >> rout;
    return is;
}
//Multi_day_excursion

ostream &Multi_day_excursion::show(ostream &os)const{
    cout << "конец - " << date_end << "\n";
    cout << "кол-во дней - " << days_count << "\n";
    for(int pos = 0; pos < days_count; ++pos){
        os << "программа на " << pos+1 << "день:\n";
        os << routs[pos];  
        os << "\n";
    }
    return os;
}

istream &Multi_day_excursion::get(std::istream &is){
    cout << "кол-во дней -> ";
    is >> days_count;
    cout << "конец -> ";
    is >> date_end;
    routs = new Rout[days_count];
    for(int pos = 0; pos < days_count; ++pos){
        cout << "программа на " << pos+1 << "день:\n";
        is >> routs[pos];
        cout << "\n";
    }
    return is;
}

