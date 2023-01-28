#include <iostream>
#include <string>
#include "buildings.hpp"
#include "date.hpp"
#include "game.hpp"


//Var global (compteurs)
//cpt housing buildings
int cptHousingBuilding = 0;
//cpt production buildings
int cptProductionBuilding = 0;
//cpt reward buildings
int cptIdReligiousBuilding = 0;
int cptIdHotelBuilding = 0;
int cptIdStatueBuilding = 0;
int cptIdHospitalBuilding = 0;
int cptIdStadiumBuilding = 0;

//Game-------------------------------------------------------------------------------------------------

Game::Game(){
    this->money = 1000;
    this->energy = 1000;
    this->popularity = 0;
    this->gameScore = 0;
    this->nStadium = 0;
    this->hiddenDeath = 0;
    this->deadline = Date(10,10,2020);
    this->currentDate = Date(1,1,2018);
    this->nWorkers = 1;
    this->nWorkersAvailable = 1;
    this-> nTurn = 0;
}
Game::Game(int money, int energy, float popularity, int gameScore, int nStadium, int hiddenDeath, int nWorkers, Date deadline, Date currentDate){
    this->money = money;
    this->energy = energy;
    this->popularity = popularity;
    this->gameScore = gameScore;
    this->nStadium = nStadium;
    this->hiddenDeath = hiddenDeath;
    this->deadline = deadline;
    this->currentDate = currentDate;
    this->nWorkers = nWorkers;
    this->nWorkersAvailable = nWorkers;
    this-> nTurn = 0;
}

std::string Game::getGameState(){
    std::string gameState = "\nMoney : " + std::to_string(money) + "\nEnergy : " + std::to_string(energy) + "\nN Workers : " + 
    std::to_string(nWorkers) + "\nN Workers Available : " + std::to_string(nWorkersAvailable) +
    "\nPopularity : " + std::to_string(popularity) + "\nGame Score : " + std::to_string(gameScore) + "\nNumber of Stadium : " + 
    std::to_string(nStadium) + "\nHidden Death : " + std::to_string(hiddenDeath) +
    "\nDeadline : " + deadline.toString() + "\nCurrent Date : " + currentDate.toString() + "\n\nBuildings : -------";

    //Récaptitulatif des bâtiments
    for(int i=0; i<cptHousingBuilding; i++){
        if(typeid(*LHousingBuilding.at(i)) == typeid(Slum))
            gameState += "\nSlum, ID : " + std::to_string(i) + ", " + std::to_string(LHousingBuilding.at(i)->getNWorker()) + " workers";
        else if(typeid(*LHousingBuilding.at(i)) == typeid(Appartments))
            gameState += "\nAppartments, ID : " + std::to_string(i) + ", " + std::to_string(LHousingBuilding.at(i)->getNWorker()) + " workers";
        else if(typeid(*LHousingBuilding.at(i)) == typeid(House))
            gameState += "\nHouse, ID : " + std::to_string(i) + ", " + std::to_string(LHousingBuilding.at(i)->getNWorker()) + " workers";
    }
    
    for(int i=0; i<cptProductionBuilding; i++){
        if(typeid(*LProductionBuilding.at(i)) == typeid(DrillingMachine))
            gameState += "\nDrilling Machine, ID : " + std::to_string(i);
        else if(typeid(*LProductionBuilding.at(i)) == typeid(SolarPanel))
            gameState += "\nSolar Panel, ID : " + std::to_string(i);
        else if(typeid(*LProductionBuilding.at(i)) == typeid(WindTurbine))
            gameState += "\nWind Turbine, ID : " + std::to_string(i);
    }

    gameState += "\n-" + std::to_string(cptIdHotelBuilding) + " Hotel";
    gameState += "\n-" + std::to_string(cptIdHospitalBuilding) + " Hospital";
    for(int i=0; i<int(LReligiousBuilding.size()); i++){
        gameState += "\nReligious building number " + std::to_string(i) + " : " + LReligiousBuilding.at(i)->stringReligion();        
    }
    gameState += "\n-" + std::to_string(cptIdStatueBuilding) + " Statue";
    gameState += "\n-" + std::to_string(cptIdStadiumBuilding) + " Stadium";


    gameState += "\nTURN" + std::to_string(nTurn) + "\n\n";
    return gameState;
}

int Game::checkMoney(int n){
    if(money >= n){
        return 1;
    } else {
        std::cout << "Not enough money" << std::endl;
        return 0;
    }
}

int Game::checkWorkers(int n){
    if(nWorkersAvailable >= n){
        return 1;
    } else {
        std::cout << "Not enough workers available" << std::endl;
        return 0;
    }
}

int Game::checkEnergy(int n){
    if(energy >= n){
        return 1;
    } else {
        std::cout << "Not enough energy" << std::endl;
        return 0;
    }
}

int Game::build(std::string typeBuilding){
    //Building housing building
    if(typeBuilding == "Slum"){
        std::cout << "Building a " + std::to_string(cptHousingBuilding) + " Slum" << std::endl;
        Slum* p = new Slum;
        nWorkersAvailable--;
        money -= 100;
        energy -= 100;

        LHousingBuilding.push_back(p);

        return 1;
    } else if(typeBuilding == "Appartments"){
        std::cout << "Building a " + std::to_string(cptHousingBuilding) + " Appartments" << std::endl;
        Appartments* p = new Appartments;
        nWorkersAvailable--;
        money -= 500;
        energy -= 300;
        
        LHousingBuilding.push_back(p);

        return 1;
    } else if(typeBuilding == "House"){
        std::cout << "Building a " + std::to_string(cptHousingBuilding) + " House" << std::endl;
        House* p = new House;
        nWorkersAvailable--;
        money -= 200;
        energy -= 150;
        
        LHousingBuilding.push_back(p);

        return 1;
    }
    //Building production building
    else if(typeBuilding == "DrillingMachine"){
        std::cout << "Building a " + std::to_string(cptProductionBuilding) + " Drilling Machine" << std::endl;
        DrillingMachine* p = new DrillingMachine;
        nWorkersAvailable--;
        money -= 150;
        energy -= 100;
        
        LProductionBuilding.push_back(p);

        return 1;
    }else if(typeBuilding == "SolarPanel"){
        std::cout << "Building a " + std::to_string(cptProductionBuilding) + " Solar Panel" << std::endl;
        SolarPanel* p = new SolarPanel;
        nWorkersAvailable--;
        money -= 175;
        energy -= 10;
        
        LProductionBuilding.push_back(p);

        return 1;
    }else if(typeBuilding == "WindTurbine"){
        std::cout << "Building a " + std::to_string(cptProductionBuilding) + " Wind Turbine" << std::endl;
        WindTurbine* p = new WindTurbine;
        nWorkersAvailable--;
        money -= 175;
        energy -= 10;
        
        LProductionBuilding.push_back(p);

        return 1;
    }
    //Building reward building
    else if (typeBuilding == "ReligiousBuilding Jewish"){
        std::cout << "Building a " + std::to_string(cptIdReligiousBuilding) + " Religious Building" << std::endl;
        ReligiousBuilding* p = new ReligiousBuilding(judaism);
        nWorkersAvailable--;
        money -= 500;
        energy -= 100;
        
        LReligiousBuilding.push_back(p);

        return 1;
    }else if (typeBuilding == "ReligiousBuilding Christian"){
        std::cout << "Building a " + std::to_string(cptIdReligiousBuilding) + " Religious Building" << std::endl;
        ReligiousBuilding* p = new ReligiousBuilding(christianity);
        nWorkersAvailable--;
        money -= 500;
        energy -= 100;
        
        LReligiousBuilding.push_back(p);

        return 1;
    }else if (typeBuilding == "ReligiousBuilding Muslim"){
        std::cout << "Building a " + std::to_string(cptIdReligiousBuilding) + " Religious Building" << std::endl;
        ReligiousBuilding* p = new ReligiousBuilding(islam);
        nWorkersAvailable--;
        money -= 500;
        energy -= 100;
        
        LReligiousBuilding.push_back(p);

        return 1;
    }else if (typeBuilding == "Hotel"){
        std::cout << "Building a " + std::to_string(cptIdHotelBuilding) + " Hotel" << std::endl;
        Hotel* p = new Hotel;
        nWorkersAvailable--;
        money -= 800;
        energy -= 400;
        
        LHotelBuilding.push_back(p);

        return 1;
    }else if(typeBuilding == "Statue"){
        std::cout << "Building a " + std::to_string(cptIdStatueBuilding) + " Statue" << std::endl;
        Statue* p = new Statue;
        nWorkersAvailable--;
        money -= 1000;
        energy -= 50;
        
        LStatueBuilding.push_back(p);

        return 1;
    }else if(typeBuilding == "Hospital"){
        std::cout << "Building a " + std::to_string(cptIdHospitalBuilding) + " Hospital" << std::endl;
        Hospital* p = new Hospital;
        nWorkersAvailable--;
        money -= 1000;
        energy -= 500;
        
        LHospitalBuilding.push_back(p);

        return 1;
    }else if(typeBuilding == "Stadium"){
        std::cout << "Building a " + std::to_string(cptIdStadiumBuilding) + " Stadium" << std::endl;
        Stadium* p = new Stadium;
        nWorkersAvailable--;
        money -= 5000;
        energy -= 1000;
        
        LStadiumBuilding.push_back(p);

        return 1;
    
    
    }else {
        std::cout << "Building type not found" << std::endl;
        return 0;
    }
}

/*int Game::addWorker(std::string typeHousing){ //Avec la fonction faite comme ça, on estime que le joueur crée un nouveau bât que s'il est plein
    if(typeHousing == "Slum"){
        if(LHousingBuilding.at(cptHousingBuilding-1)->getNWorker() < LHousingBuilding.at(cptHousingBuilding-1)->getNWorkersMax()){
            std::cout << "Adding a worker to a slum" << std::endl;
            LHousingBuilding.at(cptHousingBuilding-1)->setNWorker(LHousingBuilding.at(cptHousingBuilding-1)->getNWorker() + 1);
            nWorkers += 3;
            nWorkersAvailable += 3;
            return 1;
        } else {
            std::cout << "No more place in this slum" << std::endl;
            return 0;
        }
    } else if(typeHousing == "Appartments"){
        std::cout << "Adding a worker to a group of appartments" << std::endl;
        if(LHousingBuilding.at(cptHousingBuilding-1)->getNWorker() < LHousingBuilding.at(cptHousingBuilding-1)->getNWorkersMax()){
            LHousingBuilding.at(cptHousingBuilding-1)->setNWorker(LHousingBuilding.at(cptHousingBuilding-1)->getNWorker() + 1);
            nWorkers += 5;
            nWorkersAvailable += 5;
            return 1;
        } else {
            std::cout << "No more place in this group of appartments" << std::endl;
            return 0;
        }
    } else if(typeHousing == "House"){
        std::cout << "Adding a worker to a house" << std::endl;
        if(LHousingBuilding.at(cptHousingBuilding-1)->getNWorker() < LHousingBuilding.at(cptHousingBuilding-1)->getNWorkersMax()){
            LHousingBuilding.at(cptHousingBuilding-1)->setNWorker(LHousingBuilding.at(cptHousingBuilding-1)->getNWorker() + 1);
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
}*/

int Game::ActionBuild(std::string typeBuilding, int w, int m, int e){
    if(checkWorkers(w)&&checkMoney(m)&&checkEnergy(e)){
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
            if(LStadiumBuilding.at(i)->getInConstruction()){
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

int Game::calculPopularity(){
    return (cptIdReligiousBuilding*10 + cptIdStadiumBuilding*50 + cptIdStatueBuilding*30 + cptIdHotelBuilding*10);
}

int Game::calculMoney(){
    int moneyTurn = 0;
    for(int i = 0; i<cptProductionBuilding; i++){
        moneyTurn += (LProductionBuilding.at(i))->generateMoney();
    }
    moneyTurn += popularity*10; //coeff à changer pour jeu équilibré  ??
    return moneyTurn;
}

int Game::calculGameScore(){
    int scoreTurn = 0;
    //Score des bâtiments de production de de logement
    for(int i = 0; i<cptHousingBuilding; i++){
        scoreTurn += (LHousingBuilding.at(i))->generateScore();
    }
    for(int i = 0; i<cptProductionBuilding; i++){
        scoreTurn += (LProductionBuilding.at(i))->generateScore();
    }
    
    //Si 3 religions, + de score
    int verif = 0;
    for(int i=0; i<cptIdReligiousBuilding; i++){
        if(LReligiousBuilding.at(i)->stringReligion() == "Christianity"){
            for(int j=0; j<cptIdReligiousBuilding; j++){
                if(LReligiousBuilding.at(j)->stringReligion() == "Islam"){
                    for(int k=0; k<cptIdReligiousBuilding; k++){
                        if(LReligiousBuilding.at(k)->stringReligion() == "Judaism"){
                            std::cout << "Score +1500 for having 3 religions" << std::endl;
                            scoreTurn += 1500;  //Si on a les 3 religions : 1500 au lieu de 3*300 = 900
                            verif = 1;
                        }
                    }
                }
            }
        }
    }
    //Sinon 300 par bâtiment religieux
    if(verif == 0){
        for(int i=0; i<cptIdReligiousBuilding; i++){
            scoreTurn += (LReligiousBuilding.at(i))->generateScore();
        }
    }

    //Autres bâtiments	:
    for(int i=0; i<cptIdStatueBuilding; i++){
        scoreTurn += (LStatueBuilding.at(i))->generateScore();
    }
    for(int i=0; i<cptIdHospitalBuilding; i++){
        scoreTurn += (LHospitalBuilding.at(i))->generateScore();
    }
    for(int i=0; i<cptIdHotelBuilding; i++){
        scoreTurn += (LHotelBuilding.at(i))->generateScore(popularity);
    }
    for(int i=0; i<cptIdStadiumBuilding; i++){
        scoreTurn += (LStadiumBuilding.at(i))->generateScore();
    }

    std::cout << "Score + " << scoreTurn << std::endl;
    return scoreTurn;

}

int Game::calculEnergy(){
    int energy = 0;
    for(int i=0; i<cptProductionBuilding; i++){
        energy += (LProductionBuilding.at(i))->generateRessource();
    }
    return energy;
}

std::string Game::fin(){
    std::string ret ="";
    std::cout << "Dear Qatar Prince,\n" << std::endl;
    ret+= "Dear Qatar Prince,\n";
    std::cout << "Your score : *" << gameScore << "*, great but..." << std::endl;
    ret+= "Your score : *" + std::to_string(gameScore) + "*, great but...\n";
    int C02 = 0;
    for(int i=0; i<cptProductionBuilding; i++){
        C02 += (LProductionBuilding.at(i))->generateCo2();
    }
    for(int i=0; i<cptHousingBuilding; i++){
        C02 += (LHousingBuilding.at(i))->generateCo2();
    }
    std::cout << "C02 in order to get to your goals : " << C02 << std::endl;
    ret += "C02 in order to get to your goals : " + std::to_string(C02)+"YNY";

    if(C02 < 2000){
        std::cout << "You are a good citizen, you have a good score and you have a low C02 impact, congratulations !" << std::endl;
        ret += "You are a good citizen, you have a good score and you have a low C02 impact, congratulations !\n";
    }
    
    int nDeaths = 0;
    for(int i=0; i<cptHousingBuilding; i++){
        nDeaths += (LHousingBuilding.at(i))->generateDeath(); 
    }
    for(int i=0; i<cptProductionBuilding; i++){
        nDeaths += (LProductionBuilding.at(i))->generateDeath();
    }
    if(cptIdHospitalBuilding != 0) nDeaths = (int)nDeaths/(2*cptIdHospitalBuilding);
    if(nDeaths > 0) 
    {
        std::cout << "Unfortunately, you have engranged this number of deaths : " << nDeaths << std::endl;
        ret += "Unfortunately, you have engranged this number of deaths : " + std::to_string(nDeaths)+"AZE";
    }
    return ret;
}

bool Game::newTurn(Game* pgame){
    //New turn de tous les bâtiments	----------
    //verif nstadium et deadline
    if(verifEndGame()){
        fin();
        return false;
    }
    //Housing buildings :
    int temp;
    bool btemp;
    for(int i=0; i<cptHousingBuilding; i++){
        btemp = LHousingBuilding.at(i)->getInConstruction(); //En construction tour d'avant ?
        temp = LHousingBuilding.at(i)->newTurn(); //Retourne nTurnLeft
        
        if (temp>0){
            if(typeid(*LHousingBuilding.at(i)) == typeid(Slum)){
                std::cout << std::to_string(temp) + " turn left before the end of the construction of the slum" << std::endl;
            }else if (typeid(*LHousingBuilding.at(i)) == typeid(Appartments)){
                std::cout << std::to_string(temp) + " turn left before the end of the construction of the group of appartments" << std::endl;
            }else if (typeid(*LHousingBuilding.at(i)) == typeid(House)){
                std::cout << std::to_string(temp) + " turn left before the end of the construction of the house" << std::endl;
            }
            
        }
        else if(btemp){
            if(typeid(*LHousingBuilding.at(i)) == typeid(Slum)){
                std::cout << "Slum built" << std::endl;
            }else if (typeid(*LHousingBuilding.at(i)) == typeid(Appartments)){
                std::cout <<"Group of appartments built" << std::endl;
            }else if (typeid(*LHousingBuilding.at(i)) == typeid(House)){
                std::cout << "House built" << std::endl;
            }
            nWorkers += LHousingBuilding.at(i)->getNWorker();
            nWorkersAvailable += LHousingBuilding.at(i)->getNWorker() + 1;   //3 workers + 1 worker for the construction
        }
    }
   
    //Production buildings :
    for(int i=0; i<cptProductionBuilding; i++){
        btemp = LProductionBuilding.at(i)->getInConstruction();
        temp = LProductionBuilding.at(i)->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the drilling machine" << std::endl;
        }
        else if(btemp){
            std::cout << "Drilling machine built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptProductionBuilding; i++){
        btemp = LProductionBuilding.at(i)->getInConstruction();
        temp = LProductionBuilding.at(i)->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the solar panel" << std::endl;
        }
        else if(btemp){
            std::cout << "Solar panel built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptProductionBuilding; i++){
        btemp = LProductionBuilding.at(i)->getInConstruction();
        temp = LProductionBuilding.at(i)->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the wind turbine" << std::endl;
        }
        else if(btemp){
            std::cout << "Wind turbine built" << std::endl;
            nWorkersAvailable++;
        }
    }
    //Reward buildings :    
    for(int i=0; i<cptIdHotelBuilding; i++){
        btemp = LHotelBuilding.at(i)->getInConstruction();
        temp = LHotelBuilding.at(i)->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the hotel" << std::endl;
        }
        else if(btemp){
            std::cout << "Hotel built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdHospitalBuilding; i++){
        btemp = LHospitalBuilding.at(i)->getInConstruction();
        temp = LHospitalBuilding.at(i)->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the hospital" << std::endl;
        }
        else if(btemp){
            std::cout << "Hospital built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdStatueBuilding; i++){
        btemp = LStatueBuilding.at(i)->getInConstruction();
        temp = LStatueBuilding.at(i)->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the statue" << std::endl;
        }
        else if(btemp){
            std::cout << "Statue built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for (int i=0; i<cptIdReligiousBuilding; i++){
        btemp = LReligiousBuilding.at(i)->getInConstruction();
        temp = LReligiousBuilding.at(i)->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the religious building" << std::endl;
        }
        else if(btemp){
            std::cout << "Religious building built" << std::endl;
            nWorkersAvailable++;
        }
    }
    for(int i=0; i<cptIdStadiumBuilding; i++){
        btemp = LStadiumBuilding.at(i)->getInConstruction();
        temp = LStadiumBuilding.at(i)->newTurn();
        if (temp>0){
            std::cout << std::to_string(temp) + " turn left before the end of the construction of the stadium" << std::endl;
        }
        else if(btemp){
            std::cout << "Stadium built" << std::endl;
            nWorkersAvailable++;
        }
    }
    
    //Actualisation de la date (+15j par tour, à changer on verra)
    
    currentDate = currentDate + 15;

    //Actualisation des scores	----------------
    money += calculMoney();
    popularity = calculPopularity();
    gameScore += calculGameScore();
    energy += calculEnergy();
    
    //Nouveau tour
    nTurn++;

    std::cout << "\nNEW TURN : " + std::to_string(nTurn) << std::endl;

    return true;
}