#include <iostream>
#include <string>
#include "Qatar.hpp"

//Global variables:-------------------------------------------------------------------------------------------------
//cpt housing buildings
int cptIdSlumBuilding = 0;
int cptIdAppartmentsBuilding = 0;
int cptIdHouseBuilding = 0;
//cpt production buildings

//cpt reward buildings


//Date-------------------------------------------------------------------------------------------------
Date::Date() {}
Date::Date(int month, int day, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}
//Building-------------------------------------------------------------------------------------------------
template <class T>
int Building::newTurn(T* pgame){
    if((timeToBuilt > 0)&(inConstruction == true)){
        std::cout << "Building in construction" << std::endl;
        timeToBuilt--;
        if(timeToBuilt <= 0){
            std::cout << "Building finished" << std::endl;
            inConstruction = false;
            pgame->setnWorkersAvailable(pgame->getnWorkersAvailable() + 1); //toujours un pour l'instant
        }
    }
    //appeler generate score et C02
    return timeToBuilt;
}
//Habitats
//Constructors
Slum::Slum(){
    this->idBuilding = cptIdSlumBuilding;
    cptIdSlumBuilding++;
    this->scoreBuilding = 10;
    this->timeToBuilt = 1; 
    this->nWorker = 0;
    this->nWorkersMax = 3;
    this->inConstruction = true;
}

Appartments::Appartments(){
    this->idBuilding = cptIdAppartmentsBuilding;
    cptIdAppartmentsBuilding++;
    this->scoreBuilding = 10;
    this->timeToBuilt = 3;
    this->nWorker = 0;
    this->nWorkersMax = 5;
    this->inConstruction = true;
}

House::House(){
    this->idBuilding = cptIdHouseBuilding;
    cptIdHouseBuilding++;
    this->scoreBuilding = 50;
    this->timeToBuilt = 2;
    this->nWorker = 0;
    this->nWorkersMax = 1;
    this->inConstruction = true;
}

//Game-------------------------------------------------------------------------------------------------
Game::Game(int money, int petrol, float popularity, int gameScore, int nStadium, int hiddenDeath, int nWorkers, int timeLeft, Date deadline, Date currentDate){
    this->money = money;
    this->petrol = petrol;
    this->popularity = popularity;
    this->gameScore = gameScore;
    this->nStadium = nStadium;
    this->hiddenDeath = hiddenDeath;
    this->timeLeft = timeLeft;
    this->deadline = deadline;
    this->currentDate = currentDate;
    this->nWorkers = nWorkers;
    this->nWorkersAvailable = nWorkers;
    this-> nTurn = 0;
}

std::string Game::getGameState(){
    std::string gameState = "\nMoney : " + std::to_string(money) + "\nPetrol : " + std::to_string(petrol) + "\nN Workers : " + 
    std::to_string(nWorkers) + "\nN Workers Available : " + std::to_string(nWorkersAvailable) +
    "\nPopularity : " + std::to_string(popularity) + "\nGame Score : " + std::to_string(gameScore) + "\nNumber of Stadium : " + 
    std::to_string(nStadium) + "\nHidden Death : " + std::to_string(hiddenDeath) + "\nTime Left : " + std::to_string(timeLeft) + " jours"
    "\nDeadline : " + deadline.toString() + "\nCurrent Date : " + currentDate.toString() + "\n\nBuildings : -------";

    //Récaptitulatif des bâtiments
    for(int i=0; i<cptIdSlumBuilding; i++){
        gameState += "\nSlum number " + std::to_string(i) + " : " + std::to_string(LSlumBuilding[i]->getNWorker()) + " / " + 
        std::to_string(LSlumBuilding[i]->getNWorkersMax()) + " workers";        
    }
    for(int i=0; i<cptIdAppartmentsBuilding; i++){
        gameState += "\nAppartments number " + std::to_string(i) + " : " + std::to_string(LAppartmentsBuilding[i]->getNWorker()) + " / " + 
        std::to_string(LAppartmentsBuilding[i]->getNWorkersMax()) + " workers";        
    }
    for(int i=0; i<cptIdHouseBuilding; i++){
        gameState += "\nHouse number " + std::to_string(i) + " : " + std::to_string(LHouseBuilding[i]->getNWorker()) + " / " + 
        std::to_string(LHouseBuilding[i]->getNWorkersMax()) + " workers";        
    }

    gameState += "\n\n";
    return gameState;
}

int Game::checkWorkers(int n){
    if(nWorkersAvailable >= n){
        return 1;
    } else {
        std::cout << "Not enough workers available" << std::endl;
        return 0;
    }
}
int Game::build(std::string typeBuilding){
    //Building housing building
    if(typeBuilding == "Slum"){
        std::cout << "Building a " + std::to_string(cptIdSlumBuilding) + " Slum" << std::endl;
        Slum* p = new Slum;
        nWorkersAvailable--;

        LSlumBuilding[cptIdSlumBuilding-1] = p;

        return 1;
    } else if(typeBuilding == "Appartments"){
        std::cout << "Building a " + std::to_string(cptIdAppartmentsBuilding) + " Appartments" << std::endl;
        Appartments* p = new Appartments;
        nWorkersAvailable--;
        
        LAppartmentsBuilding[cptIdAppartmentsBuilding-1] = p;

        return 1;
    } else if(typeBuilding == "House"){
        std::cout << "Building a " + std::to_string(cptIdHouseBuilding) + " House" << std::endl;
        House* p = new House;
        nWorkersAvailable--;
        
        LHouseBuilding[cptIdHouseBuilding-1] = p;

        return 1;
    }
    //Building production building

    //Building reward building
    
    
    
    {
        std::cout << "Building type not found" << std::endl;
        return 0;
    }
}

int Game::addWorker(std::string typeHousing){ //Avec la fonction faite comme ça, on estime que le joueur crée un nouveau bât que s'il est plein
    if(typeHousing == "Slum"){
        std::cout << "Adding a worker to a slum" << std::endl;
        if(LSlumBuilding[cptIdSlumBuilding-1]->getNWorker() < LSlumBuilding[cptIdSlumBuilding-1]->getNWorkersMax()){
            LSlumBuilding[cptIdSlumBuilding-1]->setNWorker(LSlumBuilding[cptIdSlumBuilding-1]->getNWorker() + 1);
            nWorkers++;
            nWorkersAvailable++;
            return 1;
        } else {
            std::cout << "No more place in this slum" << std::endl;
            return 0;
        }
    } else if(typeHousing == "Appartments"){
        std::cout << "Adding a worker to a group of appartments" << std::endl;
        if(LAppartmentsBuilding[cptIdAppartmentsBuilding-1]->getNWorker() < LAppartmentsBuilding[cptIdAppartmentsBuilding-1]->getNWorkersMax()){
            LAppartmentsBuilding[cptIdAppartmentsBuilding-1]->setNWorker(LAppartmentsBuilding[cptIdAppartmentsBuilding-1]->getNWorker() + 1);
            nWorkers++;
            nWorkersAvailable++;
            return 1;
        } else {
            std::cout << "No more place in this group of appartments" << std::endl;
            return 0;
        }
    } else if(typeHousing == "House"){
        std::cout << "Adding a worker to a house" << std::endl;
        if(LHouseBuilding[cptIdHouseBuilding-1]->getNWorker() < LHouseBuilding[cptIdHouseBuilding-1]->getNWorkersMax()){
            LHouseBuilding[cptIdHouseBuilding-1]->setNWorker(LHouseBuilding[cptIdHouseBuilding-1]->getNWorker() + 1);
            nWorkers++;
            nWorkersAvailable++;
            return 1;
        } else {
            std::cout << "No more place in this house" << std::endl;
            return 0;
        }

    } else {
        std::cout << "Building type not found" << std::endl;
        return 0;
    }
}

void Game::newTurn(Game* pgame){
    //New turn de tous les bâtiments	----------
    //Housing buildings :
    int temp;
    for(int i=0; i<cptIdSlumBuilding; i++){
        temp = LSlumBuilding[i]->newTurn(pgame); //Retourne nTurnLeft
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the slum" << std::endl;
        }
    }
    for(int i=0; i<cptIdAppartmentsBuilding; i++){
        temp = LAppartmentsBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the group of appartments" << std::endl;
        }
    }
    for(int i=0; i<cptIdHouseBuilding; i++){
        temp = LHouseBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the house" << std::endl;
        }
    }

    nTurn++;
}
