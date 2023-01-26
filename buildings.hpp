#pragma once
#include "date.hpp"


//Classes abstraites
class Building { 
    public:
        int newTurn();
        int generateCo2();
        int generateScore();
        int destroy();
    
        //getters
        int getIdBuilding(){return idBuilding;}
        bool getInConstruction(){return inConstruction;}

    protected:
        int idBuilding;
        int scoreBuilding; 
        int timeToBuilt; //in turns
        bool inConstruction;
};

class HousingBuilding : public Building {
    public:
        int sick();
        int getNWorker(){return nWorker;}
        int setNWorker(int n){nWorker = n; return n;}
        int getNWorkersMax(){return nWorkersMax;}

    protected: 
        int nWorker;
        int nWorkersMax;     
};

class ProductionBuilding : public Building {
    public:
        int generateRessource();
    
};

class RewardBuilding : public Building {
    public:
        int generateScore();
};

//Habitats :
//Proba d'être malade gérée dans sick en fct du type de Housing que c'est.
class Slum : public HousingBuilding{ //Bcp de chance d'être malade, et augmente nombre morts. Peu cher, grande capacité.
    public:
        Slum();
        int generateDeath();
};

class Appartments : public HousingBuilding{ //Un peu de chance d'être malade, grande capacité, moyennement cher comparé à capacité.
    public:
        Appartments();
};

class House : public HousingBuilding{ //Peu de chance d'être malade, cher comparé à petite capacité.
    public:
        House();
};

//Production :
class DrillingMachine : public ProductionBuilding {
    public:
        DrillingMachine();
        int generateRessource();
        int generateDeath();
};

class SolarPanel : public ProductionBuilding {
    public:
        SolarPanel();
        int generateRessource();
};
class WindTurbine : public ProductionBuilding {
    public:
        WindTurbine();
        int generateRessource();
};

//Reward :
class ReligiousBuilding : public RewardBuilding {
    public:
        int generateScore();
        ReligiousBuilding();
     
};
class Hotel : public RewardBuilding {
    public:
        Hotel();
        int generateScore();
};
class Statue : public RewardBuilding {
    public:
        Statue();
        int generateScore();
};
class Hospital : public RewardBuilding {
    public:
        Hospital();
        int generateScore();
        int welcomedSicks();
        int getNRooms(){return nRooms;}
    private :
        int nRooms;
};
class Stadium : public RewardBuilding {
    public:
        Stadium();
        int generateScore();
};