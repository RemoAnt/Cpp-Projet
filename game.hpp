#pragma once
#include "buildings.hpp"
#include "date.hpp"
#include <vector>

// -------------------  Classes du jeu comprenant les données principales 

class Field {
    //Tableau x y de bâtiments
};

class Game {
    public:
        //Constructeurs
        Game();
            //Sert à faire des tests en initialisant à un moment donné sans avoir joué
        Game(int money, int petrol, float popularity, int gameScore, int nStadium, int hiddenDeath, int timeLeft, int nWorkers, Date deadline, Date currentDate);
        // Fonctions appelées en pendant le jeu :
        bool verifEndGame(); //Vérifie si le jeu est fini (deadline ou 5 stadiums)
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
        //int addWorker(std::string typeHousing); //Fonctionnalité abandonnée mais implémentée. On la trouvait inutile pour le jeu
        
        int ActionBuild(std::string typeBuilding, int n);

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
        std::string getGameState(); //Dans l'invite de commande


    private:
        int money;
        int petrol; 
        int electricity;
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

        //Liste des bâtiments
        std::vector<Slum*> LSlumBuilding;
        std::vector<Appartments*> LAppartmentsBuilding; 
        std::vector<House*> LHouseBuilding;
        std::vector<DrillingMachine*> LDrillingMachineBuilding;
        std::vector<SolarPanel*> LSolarPanelBuilding;
        std::vector<WindTurbine*> LWindTurbineBuilding;
        std::vector<ReligiousBuilding*> LReligiousBuilding;
        std::vector<Hotel*> LHotelBuilding;
        std::vector<Statue*> LStatueBuilding;
        std::vector<Hospital*> LHospitalBuilding;
        std::vector<Stadium*> LStadiumBuilding; // A 5 stadium construit, fin de la partie
        
};