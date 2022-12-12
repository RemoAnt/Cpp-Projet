#pragma once

// -------------------  Classes du jeu -------------------------------------------//

class Date {
    public:
        int get_date(); //réfléchir comment
        int get_day(){return day;}
        int get_month(){return month;}
        int get_year(){return year;}
        int set_date();
        
    private : 
        int day;
        int month; 
        int year;
}

// -------------------  Bâtiments 

//Classes abstraites
class Building { 
    private:
        static int id_building;
        int time_to_built;
        int n_workers_needed;
}

class Building : public Housing {
    private: 
        int n_workers;
        
}

class Building : public Production {
    public:
        int prod_ressource();
}

class Building : public Rewards {

}

//Bâtiments :

class Building : public Mosque {

}

class Building : public Church {


}

class Building : public Synagogue {

}

// -------------------  Classes du jeu comprenant les données principales 

class Game {
    public:

        // Fonctions appelées en "temps réel" :
        int calcul_game_score();
        int calcul_popularity();
        int calcul_money();
        int calcul_petrol();
        int calcul_time_left();
        int calcul_n_death();
        int refresh();

        // Fonction appelée qu'à la fin
        int fin();        

        //Getters / Setters 
        int get_money(){return money;}
        int get_petrol(){return petrol;}
        float get_popularity(){return popularity;}
        int get_game_score(){return game_score;}
        int get_n_stadium(){return n_stadium;}
        int hidden_n_death(){return hidden_n_death;}
        int get_time_left(){return time_left;}
        Date get_deadline(){return deadline;}
        Date get_current_date(){return current date;}


    private :
        int money;
        int petrol; 
        float popularity; //En pourcentage, dépend des bât et en débloquent certains (par exemple au bout de tant d'hôtel, on peut faire une statue)
        int game_score;
        int n_stadium;
        int hidden_n_death;
        int time_left;
        Date deadline;
        Date current_date;
        Batiment* l_bat[3]; //3 types de bâtiments différents
}


//Il faut trouver comment faire une surcharge