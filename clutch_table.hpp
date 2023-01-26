#ifndef CLUTCH_TABLE_HPP
#define CLUTCH_TABLE_HPP

#include "excursion.hpp"
#include <string>
#include <list>
#include <iostream>

const int TABLE_LEN = 20;

using namespace std;

/**
 *@brief класс таблицы смешанной сцеплением
 */
class Clutch_Table{
    protected:
        //! массив списков, индекс списока в таблице соотвецтв
        list<Excursion *> table[TABLE_LEN];
    public:
        //вставка в таблицу по коду и дате
        void insert(int code, string date, Excursion*);
        //! удаление экскурсии в таблице по её коду и времени начала
        void erase(int code, string date);
        //! поиск экскурсии в таблице по её коду и времени начала возвращает true при нахождении
        bool find(int code, string date); 
        //! метод, который возвращает экскурсию по её коду и времени начала
        Excursion *get_item(int code, string date);
        //!перегрузка оператора вывода в поток для смешанной таблицы
        friend ostream &operator << (ostream&, const Clutch_Table&);
        //! деструктор таблицы - последовательно стирает списки
        ~Clutch_Table();
};

//!функция нахождения индекса 
int hax(int code);

#endif


