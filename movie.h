#include "date.cpp"
#pragma once

class Movie {
public:
    Movie(string new_name, Date new_date) : data(new_name), release_date(new_date), next(NULL) {}
    string data;
    Movie* next;
    Date release_date;
    };



