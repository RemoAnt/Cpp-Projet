#pragma once

class Date {
    public:
        //Constructors
        Date();
        Date(int month, int day, int year);
        //Getter
        std::string toString(){return std::to_string(month) + " / " + std::to_string(day) + " / " + std::to_string(year);} //réfléchir comment
        int getDay(){return day;}
        int getMonth(){return month;}
        int getYear(){return year;}
        int setDate();
        void setDay(int day){this->day = day;}
        void setMonth(int month){this->month = month;}
        void setYear(int year){this->year = year;}
        
    private : 
        int day;
        int month; 
        int year;
};

//Redéfinition d'opérateur pour Date ( > et +)
bool operator>(Date date1, Date date2);
Date operator+(Date date1, int n);