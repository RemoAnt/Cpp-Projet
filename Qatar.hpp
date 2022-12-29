#pragma once

// -------------------  Classes du jeu -------------------------------------------//

class Date {
    public:
        int getDate(); //réfléchir comment
        int getDay(){return day;}
        int getMonth(){return month;}
        int getYear(){return year;}
        int setDate();
        
    private : 
        int day;
        int month; 
        int year;
};

// -------------------  Bâtiments 

//Classes abstraites
class Building { 
    public:
        int buildTimeLeft();
        int generateCo2();
        int build();
        int destroy();

    private:
        static int idBuilding;
        int scoreBuilding; 
        int timeToBuilt;
        int nWorkersNeeded;
};

class Building : public HousingBuilding {
    public:
        int getnWorker(){return nWorker;}
        int sick();

    private: 
        int nWorker;     
};

class Building : public ProductionBuilding {
    public:
        int generateRessource();
};

class Building : public RewardBuilding {
    public:
        int generateScore();
};

//Bâtiments :
//Proba d'être malade gérée dans sick en fct du type de Housing que c'est.
class HousingBuilding : public Slum{ //Bcp de chance d'être malade, et augmente nombre morts. Peu cher, grande capacité.
    public:
        Slum();
        Slum(int x, int y);
        int generateDeath();
};

class HousingBuilding : public Appartments{ //Un peu de chance d'être malade, grande capacité, moyennement cher comparé à capacité.
    public:
        Appartments();
        Appartments(int x, int y);
};

class HousingBuilding : public House{ //Peu de chance d'être malade, cher comparé à petite capacité.
    public:
        House();
        House(int x, int y);
};

//Production :
class DrillingMachine : public ProductionBuilding {
    public:
        int generateRessource();
        int generateDeath();
};

class SolarPanel : public ProductionBuilding {
    public:
        int generateRessource();
};
class WindTurbine : public ProductionBuilding {
    public:
        int generateRessource();
};

//Reward :
class ReligiousBuilding : public RewardBuilding {
    public:
        int generateScore();
     
};
class Hotel : public RewardBuilding {
    public:
        int generateScore();
        //int welcomedTourists();
        int getNRooms{return nRooms;}
    private :
        int nRooms;
};
class Statue : public RewardBuilding {
    public:
        int generateScore();
};
class Hospital : public RewardBuilding {
    public:
        int generateScore();
        int welcomedSicks();
        int getNRooms{return nRooms;}
    private :
        int nRooms;
};
class Stadium : public RewardBuilding {
    public:
        int generateScore();
};
// -------------------  Classes du jeu comprenant les données principales 

class Game {
    public:

        // Fonctions appelées en "temps réel" :
        int calculGameScore();
        int calculPopularity();
        int calculMoney();
        int calculPetrol();
        int calculTimeLeft();
        int calculDeath();
        int refresh();

        // Fonction appelée qu'à la fin
        int fin();        

        //Getters / Setters 
        int getMoney(){return money;}
        int getPetrol(){return petrol;}
        float getPopularity(){return popularity;}
        int getGameScore(){return gameScore;}
        int getnStadium(){return nStadium;}
        int getHiddenDeath(){return hiddenDeath;}
        int getTimeLeft(){return timeLeft;}
        Date getDeadline(){return deadline;}
        Date getCurrentDate(){return currentDate;}


    private :
        int money;
        int petrol; 
        float popularity; //En pourcentage, dépend des bât et en débloquent certains (par exemple au bout de tant d'hôtel, on peut faire une statue)
        int gameScore;
        int nStadium;
        int hiddenDeath;
        int timeLeft;
        Date deadline;
        Date currentDate;
        Building* l_bat[3]; //3 types de bâtiments différents
};



//Rajouter une surcharge de l'opérateur << pour afficher les dates par exemple  

getDate(){
    return day + "/" + month + "/" + year;
}