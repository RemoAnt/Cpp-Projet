#include <iostream>
#include <string>
#include "date.hpp"

Date::Date() {}
Date::Date(int month, int day, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

//Redéfinition d'opérateur pour Date ( > et +)
bool operator>(Date date1, Date date2){
    if(date1.getYear() > date2.getYear()){
        return true;
    }
    else if(date1.getYear() == date2.getYear()){
        if(date1.getMonth() > date2.getMonth()){
            return true;
        }
        else if(date1.getMonth() == date2.getMonth()){
            if(date1.getDay() == date2.getDay()){
                return false; 
            }
            else if(date1.getDay() > date2.getDay()){
                return true;
            }
        }
    }
    return false;
}

Date operator+(Date date1, int n){  //ATTENTION : sûrement problème si on ajoute + de 30 jours
    Date date2;
    date2.setDay(date1.getDay() + n);
    date2.setMonth(date1.getMonth());
    date2.setYear(date1.getYear());

    
    if(date2.getMonth()==1 || date2.getMonth()==3 || date2.getMonth()==5 || date2.getMonth()==7 || date2.getMonth()==8 || date2.getMonth()==10 || date2.getMonth()==12){
        if(date2.getDay() > 31){
            date2.setDay(date2.getDay() - 31);
            date2.setMonth(date2.getMonth() + 1);
        }
    }
    
    else if(date2.getMonth()==4 || date2.getMonth()==6 || date2.getMonth()==9 || date2.getMonth()==11){
        if(date2.getDay() > 30){
            date2.setDay(date2.getDay() - 30);
            date2.setMonth(date2.getMonth() + 1);
        }
    }
    
    else if(date2.getMonth()==2){
        if(date2.getDay() > 28){
            date2.setDay(date2.getDay() - 28);
            date2.setMonth(date2.getMonth() + 1);
        }
    }

    if (date2.getMonth() > 12){
        date2.setMonth(date2.getMonth() - 12);
        date2.setYear(date2.getYear() + 1);
    }
    return date2;
}
