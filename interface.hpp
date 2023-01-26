#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "clutch_table.hpp"
#include "excursion.hpp"
#include <iostream>
#include <string>

void getInt(int &val, const char *txt);
void getDate(string &date, const char *txt);


int menu(Clutch_Table &table);
void announce_new_excursion(Clutch_Table &);
void cancel_excursion(Clutch_Table &);
void lssue_waiver(Clutch_Table &);
void lssue_ticket(Clutch_Table &);
void print_excursion(Clutch_Table &);

#endif
