#include <iostream>
#include <string>
#include "date.hpp"
#include "buildings.hpp"

//Var global (compteurs)
//cpt housing buildings
extern int cptIdSlumBuilding;
extern int cptIdAppartmentsBuilding;
extern int cptIdHouseBuilding;
//cpt production buildings
extern int cptIdDrillingMachineBuilding;
extern int cptIdSolarPanelBuilding;
extern int cptIdWindTurbineBuilding;
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
    this->idBuilding = cptIdSlumBuilding;
    cptIdSlumBuilding++;
    this->scoreBuilding = 10;
    this->timeToBuilt = 1; 
    this->nWorker = 3;
    //this->nWorkersMax = 3;
    this->inConstruction = true;
}

Appartments::Appartments(){
    this->idBuilding = cptIdAppartmentsBuilding;
    cptIdAppartmentsBuilding++;
    this->scoreBuilding = 10;
    this->timeToBuilt = 3;
    this->nWorker = 5;
    //this->nWorkersMax = 5;
    this->inConstruction = true;
}

House::House(){
    this->idBuilding = cptIdHouseBuilding;
    cptIdHouseBuilding++;
    this->scoreBuilding = 50;
    this->timeToBuilt = 2;
    this->nWorker = 2;
    //this->nWorkersMax = 1;
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