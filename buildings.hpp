#pragma once
#include "date.hpp"


//Classes abstraites
class Building { 
    public:
        int newTurn();
        int generateCo2() {return CO2;}
        virtual int generateScore() {return scoreBuilding;}
        virtual int generateDeath() {return 0;}
        int destroy();
    
        //getters
        int getIdBuilding(){return idBuilding;}
        bool getInConstruction(){return inConstruction;}

    protected:
        int idBuilding;
        int scoreBuilding; 
        int CO2;
        int timeToBuilt; //in turns
        bool inConstruction;
};

class HousingBuilding : public Building {
    public:
        int getNWorker(){return nWorker;}
        int setNWorker(int n){nWorker = n; return n;}
        virtual int generateDeath() {return 0;}
        //int getNWorkersMax(){return nWorkersMax;}

    protected: 
        int nWorker;
        //int nWorkersMax;     
};

class ProductionBuilding : public Building {
    public:
        int generateRessource() {return energy;}
        int generateMoney() {return outcome;}
    
    protected:
        int energy;
        int outcome;
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
        int generateDeath();
};

class SolarPanel : public ProductionBuilding {
    public:
        SolarPanel();
};
class WindTurbine : public ProductionBuilding {
    public:
        WindTurbine();
};

//Reward :
enum religion {christianity, islam, judaism};
class ReligiousBuilding : public Building {
    public:
        ReligiousBuilding();
        ReligiousBuilding(religion religionType);
        std::string stringReligion();

    private:    
        religion religionType;
             
};

class Hotel : public Building {
    public:
        Hotel();
        int generateScore(int popularity); //+ popularité, + de score
};
class Statue : public Building {
    public:
        Statue();
};
class Hospital : public Building {
    public:
        Hospital();
};
class Stadium : public Building {
    public:
        Stadium();
};