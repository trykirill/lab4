#ifndef EXCURSION_HPP
#define EXCURSION_HPP

#include <iostream>
#include <string>

using namespace std;

class Point{
    private:
        string plase;
        string obgect;
        string time_start;
        string time;
    public:
        Point(const string &plase = "",const string &obgect = "", const string &time_start = "", const string &time = ""): plase(plase), obgect(obgect), time_start(time_start), time(time){}
        string get_place(){return plase;}
        string get_obgect(){return obgect;}
        string get_time_start(){return time_start;}
        string get_time(){return time;}
        friend ostream& operator << (ostream &, const Point &);
        friend istream& operator >> (istream &, Point &);
};

class Rout{
    protected:
        int number;
        Point *arr;
    public:
        Rout(Point *arr = nullptr, int number = 0):number(number), arr(arr){}
        friend ostream& operator << (ostream &, const Rout &);
        friend istream& operator >> (istream &, Rout &);
        ~Rout(){delete[] arr;}
};

class Excursion{
    protected:
        virtual ostream& show(ostream&)const = 0;
        virtual istream& get(istream&) = 0;

        string name;
        int code;
        int price;
        int max_count;
        int sell_count;
        string date_start;
    public:
        Excursion(const string &name = "", int code = 0, int price = 0, int max_count = 0, int sell_count = 0, const string & date_start = ""):name(name), code(code), price(price), max_count(max_count), sell_count(sell_count), date_start(date_start){}
        virtual Excursion *clone() const = 0;
        friend ostream& operator << (ostream &, const Excursion &);
        friend istream& operator >> (istream &, Excursion &);
        virtual int iam() const = 0;

        void set_sell_count(int new_sell_count){sell_count = new_sell_count;}
        int get_sell_count(){return sell_count;}
        void set_date_start(string new_date_start){date_start = new_date_start;}
        string get_date_start(){return date_start;}
        int get_code(){return code;};
        void set_code(int &new_code){code = new_code;};
        int get_max_count(){return max_count;};
        virtual ~Excursion(){};
};

class One_day_excursion :public Excursion{
    protected:
        Rout rout;
        virtual std::ostream& show(std::ostream&)const;
        virtual std::istream& get(std::istream&);
    public:
        One_day_excursion(const string &name = "", int code = 0, int price = 0, int max_count = 0, int sell_count = 0, const string & date_start = ""): Excursion(name, code, price, max_count, sell_count, date_start){}
        virtual int iam() const {return 1;}
        virtual One_day_excursion *clone() const{return new One_day_excursion(*this);}
};

class Multi_day_excursion :public Excursion{
    protected:
        string date_end;
        int days_count;
        Rout *routs;

        virtual std::ostream& show(std::ostream&)const;
        virtual std::istream& get(std::istream&);
    public:
        Multi_day_excursion(const string &name = "", int code = 0, int price = 0, int max_count = 0, int sell_count = 0, const string & date_start = "", const string &date_end = "", int days_count = 0, Rout *routs = nullptr): Excursion(name, code, price, max_count, sell_count, date_start), date_end(date_end), days_count(days_count), routs(routs){}
        virtual int iam() const {return 2;}
        ~Multi_day_excursion(){delete []routs;} 
        virtual Multi_day_excursion *clone() const{return new Multi_day_excursion(*this);}
};

#endif
