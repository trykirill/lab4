#ifndef EXCURSION_HPP
#define EXCURSION_HPP

#include <iostream>
#include <string>

using namespace std;

/**
 *@brief класс пункта в на маршруте экскурсии
 */
class Point{
    protected:
        //!название населённово пункта в котором находится пункт
        string plase;
        //!название объекта 
        string obgect;
        //!время прибытия
        string time_start;
        //!длительность остановки на пункте
        string time;
    public:
        //!конструктор класса
        Point(const string &plase = "",const string &obgect = "", const string &time_start = "", const string &time = ""): plase(plase), obgect(obgect), time_start(time_start), time(time){}
        //! функция возвращает значение параметра plase : string
        string get_place(){return plase;}
        //! функция возвращает значение параметра obgect : string
        string get_obgect(){return obgect;}
        //! функция возвращает значение параметра time_start : string
        string get_time_start(){return time_start;}
        //! функция возвращает значение параметра time : string
        string get_time(){return time;}
        //! перегрузка опретора для ввода класса Point из потока
        friend ostream& operator << (ostream &, const Point &);
        //! перегрузка оператора для чтения класса Point из потока
        friend istream& operator >> (istream &, Point &);
};

/**
 *@brief
 */

class Rout{
    protected:
        //!количество 
        int number;
        //!массив в котором находятся все пункты, которые будут посещены за маршрут
        Point *arr;
    public:
        //!конструктор класса
        Rout(Point *arr = nullptr, int number = 0):number(number), arr(arr){}
        //!перегрузка оперетора вывода класса в поток
        friend ostream& operator << (ostream &, const Rout &);
        //! пререгрузка оператора чтения класса из потока 
        friend istream& operator >> (istream &, Rout &);
        //! деструктор класса - очищается массив пунктов
        ~Rout(){delete[] arr;}
};
/**
 *@brief
 */
class Excursion{
    protected:
        //! виртуальная функция вывода в поток, она нужна для более удобной реализации вывода в поток при перегрузке оператора, 
        virtual ostream& show(ostream&)const = 0;
        //  виртуальная 
        virtual istream& get(istream&) = 0;
        //! название экскурсии
        string name;
        //! код экскурсии
        int code;
        //! цена одного билета
        int price;
        //!максимальное число туристов в группе
        int max_count;
        //!количество проданных билетов
        int sell_count;
        //!дата начала экскурсии
        string date_start;
    public:
        //!
        Excursion(const string &name = "", int code = 0, int price = 0, int max_count = 0, int sell_count = 0, const string & date_start = ""):name(name), code(code), price(price), max_count(max_count), sell_count(sell_count), date_start(date_start){}
        //! фонкция клонирования класса: выделяет память и копирует свои параметры
        virtual Excursion *clone() const = 0;
        //!перегрузка оператора вывода в поток для базового класса
        friend ostream& operator << (ostream &, const Excursion &);
        //!перегрузка оператора чтения из потока для базового класса
        friend istream& operator >> (istream &, Excursion &);
        //!функция, которая помогает определить класс, для базового всегда возвращает 0
        virtual int iam() const = 0;
        //! установит значение кол-ва проданных билетов ранным переданному функции
        void set_sell_count(int new_sell_count){sell_count = new_sell_count;}
        //! метод класса возвращает кол-во проданных билетов 
        int get_sell_count(){return sell_count;}
        //! установит значение  даты начала экскурсии ранным переданному функции
        void set_date_start(string new_date_start){date_start = new_date_start;}
        //! метод класса возвращает дату начала экскурсии 
        string get_date_start(){return date_start;}
        //! метод класса - возвращает код экскурсии
        int get_code(){return code;};
        //! установит значение кода экскурсии  ранным переданному функции
        void set_code(int &new_code){code = new_code;};
        //! метод класса возвращает максимально возможное кол-во проданных билетов билетов 
        int get_max_count(){return max_count;};\
        //! виртуальный деструктор базового класса
        virtual ~Excursion(){};
};

/**
 *@brief класс однодневной экскурсии, является производным классом экскурсии
 */

class One_day_excursion :public Excursion{
    protected:
        //!маршрут экскурсии на день
        Rout rout;
        //! вспомогетельная функция для вывода в поток данных производного класса
        virtual std::ostream& show(std::ostream&)const;
        //! вспомогательная функция для чтения из потока данных производного класса
        virtual std::istream& get(std::istream&);
    public:
        //!конструктор производного класса на основе базового    
        One_day_excursion(const string &name = "", int code = 0, int price = 0, int max_count = 0, int sell_count = 0, const string & date_start = ""): Excursion(name, code, price, max_count, sell_count, date_start){}
         //!функция, которая помогает определить класс, для однодневной экскурсии всегда возвращает 1
        virtual int iam() const {return 1;}
        //! клонирование класса с выделением новой памяти
        virtual One_day_excursion *clone() const{return new One_day_excursion(*this);}
};

/**
 *@brief класс многодневной экскурсии, является производным классом экскурсии
 */
class Multi_day_excursion :public Excursion{
    protected:
        //!дата окончания экскурсии
        string date_end;
        //!количество дней, которые идёт экскурсия
        int days_count;
        //!массив из маршрутов по которым пройдёт экскурсия, каждый элемент соответствует своему дню
        Rout *routs;
        //! вспомогетельная функция для вывода в поток данных производного класса
        virtual std::ostream& show(std::ostream&)const;
        //! вспомогательная функция для чтения из потока данных производного класса
        virtual std::istream& get(std::istream&);
    public:
        //!конструктор производного класса на основе базового
        Multi_day_excursion(const string &name = "", int code = 0, int price = 0, int max_count = 0, int sell_count = 0, const string & date_start = "", const string &date_end = "", int days_count = 0, Rout *routs = nullptr): Excursion(name, code, price, max_count, sell_count, date_start), date_end(date_end), days_count(days_count), routs(routs){}
        //!функция, которая помогает определить класс, для однодневной экскурсии всегда возвращает 1
        virtual int iam() const {return 2;}
        //!деструктор класса - очищает память массива маршрутов
        ~Multi_day_excursion(){delete []routs;} 
        //! клонированик класса с выделением новой памяти
        virtual Multi_day_excursion *clone() const{return new Multi_day_excursion(*this);}
};

#endif
