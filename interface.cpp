#include <iostream>
#include "excursion.hpp"
#include "clutch_table.hpp"
#include "interface.hpp"
#include <string>

int menu(Clutch_Table &table){
	int mode;
    do{
        cout << "[1] Объявить новый экскурсионный маршрут\n"
        	<< "[2] Отменить экскурсию по указанному туристическому маршруту для указанной даты\n"
            << "[3] Оформить покупку\n"
            << "[4] Оформить отказ\n"
            << "[5] Вывести все экскурсии\n"
            << "[6] Вывести информацию о конкретной экскурсии\n";
    	getInt(mode, "Выбирите действие -> ");
	    if(mode == 1){
            announce_new_excursion(table);
	    }
    	else if(mode == 2){ 
            cancel_excursion(table);
	    }
    	else if(mode == 3){
            lssue_ticket(table); 
    	}
        else if(mode == 4){
            lssue_waiver(table);
        }
        else if(mode == 5){
            cout << table;         
        }
        else if(mode == 6){
            print_excursion(table);
        }
	}while(mode != -1);
	return 0;
}

void announce_new_excursion(Clutch_Table &table){
    int code, table_type;
    Excursion *new_excursion = nullptr;
    string date;
    getInt(code, "код -> ");
    getDate(date, "дата -> ");
    if(table.find(code, date)){
        cout << "экскурсия с таким кодом и временем уже существует!\n";
        return;
    }
    cout << "[1]Однодневная\n"
        <<"[2]Многодневная\n"
        <<"тип экскурсии -> ";
    cin >> table_type;
    if(table_type == 1){
        new_excursion = new One_day_excursion; 
    }
    else if(table_type == 2){
        new_excursion = new Multi_day_excursion;
    }
    else{
        cout << "нет такого варианта ответа!\n";
        return;
    }
    cin >> (*new_excursion);
    new_excursion->set_code(code);
    new_excursion->set_date_start(date);
    table.insert(code, date, new_excursion);
    return;
}

void cancel_excursion(Clutch_Table &table){
    int code;
    string date;
    getInt(code, "код -> ");
    getDate(date, "дата -> ");
    if(table.find(code, date) == false){
        cout << "экскурсии с таким кодом и временем не существует!\n";
        return;
    }
    table.erase(code, date);
    return;
    
}

void lssue_waiver(Clutch_Table &table){
     int code;
    string date;
    getInt(code, "код -> ");
    getDate(date, "дата -> ");
    if(table.find(code, date) == false){
        cout << "экскурсии с таким кодом и временем не существует!\n";
        return;
    }
    Excursion *tmp = table.get_item(code, date);
    int sell_now = tmp->get_sell_count();
    if(sell_now == 0){
        cout << "никто не купил билет на эту экскурсию(\n";
        return;
    }
    tmp->set_sell_count(--sell_now);
    cout << "отказ успешно оформлен\n";
    return;   
}

void lssue_ticket(Clutch_Table &table){
    int code;
    string date;
    getInt(code, "код -> ");
    getDate(date, "дата -> ");
    if(table.find(code, date) == false){
        cout << "экскурсии с таким кодом и временем не существует!\n";
        return;
    }
    Excursion *tmp = table.get_item(code, date);
    int sell_now = tmp->get_sell_count();
    if(sell_now == tmp->get_max_count()){
        cout << "все билеты уже скуплены(\n";
        return;
    }
    tmp->set_sell_count(++sell_now);
    cout << "билет успешно приобретён\n";
    return;  
}

void print_excursion(Clutch_Table &table){
    int code;
    string date;
    getInt(code, "код -> ");
    getDate(date, "дата -> ");
    if(table.find(code, date) == false){
        cout << "экскурсии с таким кодом и временем не существует!\n";
        return;
    }
    cout << *table.get_item(code, date);
}

void getInt(int &val, const char *txt){
	int flag = 1;
	const char * err = "";
	do{
		cout << err;
		cout << txt;
		cin >> val;
		if(std::cin.eof()){
			val =  -1;
			return;
		}
		if(std::cin.good()){
			flag = 0;
		}
		else{
            std::cin.clear();
			cin.ignore(1000, '\n');
		}
		err = "wronge data!\n";
	} while(flag);
}

void getDate(string &date, const char *text){
    cout << text;
    cin >> date;
    return;
}
