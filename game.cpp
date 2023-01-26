#include <iostream>
#include <string>
#include "buildings.hpp"
#include "date.hpp"
#include "game.hpp"


//Var global (compteurs)
//cpt housing buildings
int cptIdSlumBuilding = 0;
int cptIdAppartmentsBuilding = 0;
int cptIdHouseBuilding = 0;
//cpt production buildings
int cptIdDrillingMachineBuilding = 0;
int cptIdSolarPanelBuilding = 0;
int cptIdWindTurbineBuilding = 0;
//cpt reward buildings
int cptIdReligiousBuilding = 0;
int cptIdHotelBuilding = 0;
int cptIdStatueBuilding = 0;
int cptIdHospitalBuilding = 0;
int cptIdStadiumBuilding = 0;

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
    gameState += "\n-" + std::to_string(cptIdDrillingMachineBuilding) + " Drilling Machine";
    gameState += "\n-" + std::to_string(cptIdSolarPanelBuilding) + " Solar Panel";
    gameState += "\n-" + std::to_string(cptIdWindTurbineBuilding) + " Wind Turbine";
    gameState += "\n-" + std::to_string(cptIdHotelBuilding) + " Hotel";
    gameState += "\n-" + std::to_string(cptIdHospitalBuilding) + " Hospital";
    gameState += "\n-" + std::to_string(cptIdReligiousBuilding) + " Religious building";
    gameState += "\n-" + std::to_string(cptIdStatueBuilding) + " Statue";
    gameState += "\n-" + std::to_string(cptIdStadiumBuilding) + " Stadium";


    gameState += "\nTURN" + std::to_string(nTurn) + "\n\n";
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
    else if(typeBuilding == "DrillingMachine"){
        std::cout << "Building a " + std::to_string(cptIdDrillingMachineBuilding) + " Drilling Machine" << std::endl;
        DrillingMachine* p = new DrillingMachine;
        nWorkersAvailable--;

        LDrillingMachineBuilding[cptIdDrillingMachineBuilding-1] = p;

        return 1;
    }else if(typeBuilding == "SolarPanel"){
        std::cout << "Building a " + std::to_string(cptIdSolarPanelBuilding) + " Solar Panel" << std::endl;
        SolarPanel* p = new SolarPanel;
        nWorkersAvailable--;

        LSolarPanelBuilding[cptIdSolarPanelBuilding-1] = p;

        return 1;
    }else if(typeBuilding == "WindTurbine"){
        std::cout << "Building a " + std::to_string(cptIdWindTurbineBuilding) + " Wind Turbine" << std::endl;
        WindTurbine* p = new WindTurbine;
        nWorkersAvailable--;

        LWindTurbineBuilding[cptIdWindTurbineBuilding-1] = p;

        return 1;
    }
    //Building reward building
    else if (typeBuilding == "ReligiousBuilding"){
        std::cout << "Building a " + std::to_string(cptIdReligiousBuilding) + " Religious Building" << std::endl;
        ReligiousBuilding* p = new ReligiousBuilding;
        nWorkersAvailable--;

        LReligiousBuilding[cptIdReligiousBuilding-1] = p;

        return 1;
    }else if (typeBuilding == "Hotel"){
        std::cout << "Building a " + std::to_string(cptIdHotelBuilding) + " Hotel" << std::endl;
        Hotel* p = new Hotel;
        nWorkersAvailable--;

        LHotelBuilding[cptIdHotelBuilding-1] = p;

        return 1;
    }else if(typeBuilding == "Statue"){
        std::cout << "Building a " + std::to_string(cptIdStatueBuilding) + " Statue" << std::endl;
        Statue* p = new Statue;
        nWorkersAvailable--;

        LStatueBuilding[cptIdStatueBuilding-1] = p;

        return 1;
    }else if(typeBuilding == "Hospital"){
        std::cout << "Building a " + std::to_string(cptIdHospitalBuilding) + " Hospital" << std::endl;
        Hospital* p = new Hospital;
        nWorkersAvailable--;

        LHospitalBuilding[cptIdHospitalBuilding-1] = p;

        return 1;
    }else if(typeBuilding == "Stadium"){
        std::cout << "Building a " + std::to_string(cptIdStadiumBuilding) + " Stadium" << std::endl;
        Stadium* p = new Stadium;
        nWorkersAvailable--;

        LStadiumBuilding[cptIdStadiumBuilding-1] = p;

        return 1;
    
    
    }else {
        std::cout << "Building type not found" << std::endl;
        return 0;
    }
}

int Game::addWorker(std::string typeHousing){ //Avec la fonction faite comme ça, on estime que le joueur crée un nouveau bât que s'il est plein
    if(typeHousing == "Slum"){
        if(LSlumBuilding[cptIdSlumBuilding-1]->getNWorker() < LSlumBuilding[cptIdSlumBuilding-1]->getNWorkersMax()){
            std::cout << "Adding a worker to a slum" << std::endl;
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

int Game::ActionBuild(std::string typeBuilding, int n){
    if(checkWorkers(n)){
        if(build(typeBuilding)){
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

bool Game::verifEndGame(){
    if(cptIdStadiumBuilding >= 4){
        for(int i =0; i<5; i++){
            if(LStadiumBuilding[i]->getInConstruction()){
                return false;
            }
        }
        std::cout << "\n-----------------------\n5/5 stadiums built. You win !\n-----------------------" << std::endl;
        return true;
    }
    if(currentDate > deadline){
        std::cout << "\n-----------------------\nDeadline reached. You lose !\n-----------------------" << std::endl;
        return true;
    }
    return false;
}
void Game::newTurn(Game* pgame){
    //New turn de tous les bâtiments	----------
    //verif nstadium et deadline

    //Housing buildings :
    int temp;
    for(int i=0; i<cptIdSlumBuilding; i++){
        temp = LSlumBuilding[i]->newTurn(); //Retourne nTurnLeft
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the slum" << std::endl;
        }
        else{
            std::cout << "Slum built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdAppartmentsBuilding; i++){
        temp = LAppartmentsBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the group of appartments" << std::endl;
        }
        else{
            std::cout << "Group of appartments built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdHouseBuilding; i++){
        temp = LHouseBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the house" << std::endl;
        }
        else{
            std::cout << "House built" << std::endl;
            nWorkersAvailable++;
        }
    }
    //Production buildings :
    for(int i=0; i<cptIdDrillingMachineBuilding; i++){
        temp = LDrillingMachineBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the drilling machine" << std::endl;
        }
        else{
            std::cout << "Drilling machine built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdSolarPanelBuilding; i++){
        temp = LSolarPanelBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the solar panel" << std::endl;
        }
        else{
            std::cout << "Solar panel built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdWindTurbineBuilding; i++){
        temp = LWindTurbineBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the wind turbine" << std::endl;
        }
        else{
            std::cout << "Wind turbine built" << std::endl;
            nWorkersAvailable++;
        }
    }
    //Reward buildings :    
    for(int i=0; i<cptIdHotelBuilding; i++){
        temp = LHotelBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the hotel" << std::endl;
        }
        else{
            std::cout << "Hotel built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdHospitalBuilding; i++){
        temp = LHospitalBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the hospital" << std::endl;
        }
        else{
            std::cout << "Hospital built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdStatueBuilding; i++){
        temp = LStatueBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the statue" << std::endl;
        }
        else{
            std::cout << "Statue built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for (int i=0; i<cptIdReligiousBuilding; i++){
        temp = LReligiousBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the religious building" << std::endl;
        }
        else{
            std::cout << "Religious building built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdStadiumBuilding; i++){
        temp = LStadiumBuilding[i]->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the stadium" << std::endl;
        }
        else{
            std::cout << "Stadium built" << std::endl;
            nWorkersAvailable++;
        }
    }
    
    //Actualisation des scores	----------------
    nTurn++;
}