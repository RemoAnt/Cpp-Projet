#include <iostream>
#include <string>
#include "date.hpp"
#include "buildings.hpp"

//Var global (compteurs)
//cpt housing buildings
extern int cptHousingBuilding;
//cpt production buildings
extern int cptProductionBuilding;
//cpt reward buildings
extern int cptIdReligiousBuilding;
extern int cptIdHotelBuilding;
extern int cptIdStatueBuilding;
extern int cptIdHospitalBuilding;
extern int cptIdStadiumBuilding;

//Building-------------------------------------------------------------------------------------------------

int Building::newTurn(){
    if((timeToBuilt > 0)&(inConstruction == true)){
        std::cout << "Building in construction" << std::endl;
        timeToBuilt--;
        if(timeToBuilt <= 0){
            std::cout << "Building finished" << std::endl;
            inConstruction = false;
        }
    }
    //appeler generate score et C02
    return timeToBuilt;
}
//Habitats
//Constructors
Slum::Slum(){
    this->idBuilding = cptHousingBuilding;
    cptHousingBuilding++;
    this->scoreBuilding = 10;
    this->timeToBuilt = 1; 
    this->nWorker = 3;
    //this->nWorkersMax = 3;
    this->inConstruction = true;
    this->CO2 = 100;
}

Appartments::Appartments(){
    this->idBuilding = cptHousingBuilding;
    cptHousingBuilding++;
    this->scoreBuilding = 10;
    this->timeToBuilt = 3;
    this->nWorker = 5;
    //this->nWorkersMax = 5;
    this->inConstruction = true;
    this->CO2 = 30;
}

House::House(){
    this->idBuilding = cptHousingBuilding;
    cptHousingBuilding++;
    this->scoreBuilding = 50;
    this->timeToBuilt = 2;
    this->nWorker = 2;
    //this->nWorkersMax = 1;
    this->inConstruction = true;
    this->CO2 = 1;
}

//Production
//Constructors

DrillingMachine::DrillingMachine(){
    this->idBuilding = cptProductionBuilding;
    cptProductionBuilding++;
    this->scoreBuilding = 50;
    this->timeToBuilt = 1;
    this->inConstruction = true;
    this->energy = 40;
    this->outcome = 60;
    this->CO2 = 1000;
}

SolarPanel::SolarPanel(){
    this->idBuilding = cptProductionBuilding;
    cptProductionBuilding++;
    this->scoreBuilding = 70;
    this->timeToBuilt = 1;
    this->inConstruction = true;
    this->energy = 40;
    this->outcome = 50;
    this->CO2 = 0;
}

WindTurbine::WindTurbine(){
    this->idBuilding = cptProductionBuilding;
    cptProductionBuilding++;
    this->scoreBuilding = 70;
    this->timeToBuilt = 1;
    this->inConstruction = true;
    this->energy = 40;
    this->outcome = 50;
    this->CO2 = 0;
}

//Reward
//Constructors
ReligiousBuilding::ReligiousBuilding(){}

ReligiousBuilding::ReligiousBuilding(religion religionType){
    this->idBuilding = cptIdReligiousBuilding;
    cptIdReligiousBuilding++;
    this->scoreBuilding = 300;
    this->timeToBuilt = 5;
    this->inConstruction = true;
    this->religionType = religionType;
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

//String Religion

std::string ReligiousBuilding::stringReligion(){
    switch (this->religionType)
    {
    case religion::christianity:
        return "Christianity";
        
    case religion::islam:
        return "Islam";
        
    case religion::judaism:
        return "Judaism";
            
    default:
        return "No religion";
    }
}
//Generate score concrete

int Hotel::generateScore(int popularity){
    return (this->scoreBuilding + popularity);
}

int DrillingMachine::generateDeath(){
    return (150);
}

int Slum::generateDeath(){
    return (215);
}