#pragma once

// -------------------  Classes du jeu -------------------------------------------//

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
        
    private : 
        int day;
        int month; 
        int year;
};

// -------------------  Bâtiments 

//Classes abstraites
class Building { 
    public:
        template <class T>
        int newTurn(T* pgame);
        int generateCo2();
        int generateScore();
        int destroy();

        //getters
        int getIdBuilding(){return idBuilding;}

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
        int getNRooms(){return nRooms;}
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
        int getNRooms(){return nRooms;}
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
        //Constructeurs
        Game();
            //Sert à faire des tests en initialisant à un moment donné sans avoir joué
        Game(int money, int petrol, float popularity, int gameScore, int nStadium, int hiddenDeath, int timeLeft, int nWorkers, Date deadline, Date currentDate);
        // Fonctions appelées en pendant le jeu :
        int calculGameScore();
        int calculPopularity();
        int calculMoney();
        int calculPetrol();
        int calculTimeLeft();
        int calculDeath();
        void newTurn(Game* pgame);

        //Actions du joueur
        int checkWorkers(int n); //Vérifie s'il reste assez de travailleurs disponibles
        int build(std::string typeBuilding);
        int destroy(std::string typeBuilding);
        int addWorker(std::string typeHousing);

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
        int getnWorkers(){return nWorkers;}
        int getnWorkersAvailable(){return nWorkersAvailable;}
        int setnWorkersAvailable(int n){nWorkersAvailable = n; return nWorkersAvailable;}
        std::string getGameState();


   
        int money;
        int petrol; 
        float popularity; //En n spectateurs ?, dépend des bât et en débloquent certains (par exemple au bout de tant d'hôtel, on peut faire une statue)
        int gameScore;
        int nStadium;
        int hiddenDeath;
        int timeLeft;
        int nWorkers;
        int nWorkersAvailable;
        int nTurn;
        Date deadline;
        Date currentDate;
        Slum* LSlumBuilding[20];
        Appartments* LAppartmentsBuilding[20]; 
        House* LHouseBuilding[20];
        ProductionBuilding LProductionBuilding[20];
        RewardBuilding LRewardBuilding[20];
};



//Rajouter une surcharge de l'opérateur << pour afficher les dates par exemple  
