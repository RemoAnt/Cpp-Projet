#include <iostream>
#include <string>
#include "Qatar.hpp"

//Global variables:-------------------------------------------------------------------------------------------------
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

//Date-------------------------------------------------------------------------------------------------
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



//-------------------------------------------------------------------------------------------------
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

//Production
//Constructors

DrillingMachine::DrillingMachine(){
    this->idBuilding = cptIdDrillingMachineBuilding;
    cptIdDrillingMachineBuilding++;
    this->scoreBuilding = 50;
    this->timeToBuilt = 1;
    this->inConstruction = true;
}

SolarPanel::SolarPanel(){
    this->idBuilding = cptIdSolarPanelBuilding;
    cptIdSolarPanelBuilding++;
    this->scoreBuilding = 70;
    this->timeToBuilt = 1;
    this->inConstruction = true;
}

WindTurbine::WindTurbine(){
    this->idBuilding = cptIdWindTurbineBuilding;
    cptIdWindTurbineBuilding++;
    this->scoreBuilding = 70;
    this->timeToBuilt = 1;
    this->inConstruction = true;
}

//Reward
//Constructors
ReligiousBuilding::ReligiousBuilding(){
    this->idBuilding = cptIdReligiousBuilding;
    cptIdReligiousBuilding++;
    this->scoreBuilding = 300;
    this->timeToBuilt = 5;
    this->inConstruction = true;
}

Hotel::Hotel(){
    this->idBuilding = cptIdHotelBuilding;
    cptIdHotelBuilding++;
    this->scoreBuilding = 300;
    this->timeToBuilt = 3;
    this->inConstruction = true;
}

Statue::Statue(){  
    this->idBuilding = cptIdStatueBuilding;
    cptIdStatueBuilding++;
    this->scoreBuilding = 700;
    this->timeToBuilt = 4;
    this->inConstruction = true;
}

Hospital::Hospital(){
    this->idBuilding = cptIdHospitalBuilding;
    cptIdHospitalBuilding++;
    this->scoreBuilding = 300;
    this->timeToBuilt = 3;
    this->inConstruction = true;
}

Stadium::Stadium(){
    this->idBuilding = cptIdStadiumBuilding;
    cptIdStadiumBuilding++;
    this->scoreBuilding = 1000;
    this->timeToBuilt = 6;
    this->inConstruction = true;
}

//-------------------------------------------------------------------------------------------------
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
    //Production buildings :
    for(int i=0; i<cptIdDrillingMachineBuilding; i++){
        temp = LDrillingMachineBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the drilling machine" << std::endl;
        }
    }
    for(int i=0; i<cptIdSolarPanelBuilding; i++){
        temp = LSolarPanelBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the solar panel" << std::endl;
        }
    }
    for(int i=0; i<cptIdWindTurbineBuilding; i++){
        temp = LWindTurbineBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the wind turbine" << std::endl;
        }
    }
    //Reward buildings :    
    for(int i=0; i<cptIdHotelBuilding; i++){
        temp = LHotelBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the hotel" << std::endl;
        }
    }
    for(int i=0; i<cptIdHospitalBuilding; i++){
        temp = LHospitalBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the hospital" << std::endl;
        }
    }
    for(int i=0; i<cptIdStatueBuilding; i++){
        temp = LStatueBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the statue" << std::endl;
        }
    }
    for (int i=0; i<cptIdReligiousBuilding; i++){
        temp = LReligiousBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the religious building" << std::endl;
        }
    }
    for(int i=0; i<cptIdStadiumBuilding; i++){
        temp = LStadiumBuilding[i]->newTurn(pgame);
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the stadium" << std::endl;
        }
    }
    //Actualisation des scores	----------------
    nTurn++;
}
