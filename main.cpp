#include <iostream>
#include <string>
#include "buildings.hpp"
#include "date.hpp"
#include "game.hpp"

//Main-------------------------------------------------------------------------------------------------
int main(){

    //TEST1 : Build et addWorker pour slum et appart //
    /*
    Date deadline = Date(1, 12, 2022);
    Date currentDate = Date(8, 11, 2018);
    Game game(100, 100, 100, 100, 100, 100, 1, 100, deadline, currentDate);
    std::cout << game.getGameState() << std::endl;
    game.build("Slum");
    for(int i=0; i<3; i++){
        game.addWorker("Slum");
    }
    game.build("Slum");
    for(int i=0; i<3; i++){
        game.addWorker("Slum");
    }
    game.addWorker("Slum"); //Worker en trop
    game.build("Slum");

    game.build("Appartments");
    for(int i=0; i<10; i++){
        game.addWorker("Appartments");
    }
    game.build("Appartments");
    game.addWorker("Appartments");


   
    std::cout << game.getGameState() << std::endl;

    game.addWorker("Slum");
    game.addWorker("Slum");
    game.addWorker("Appartments");

    std::cout << game.getGameState() << std::endl;
    */
    /*
    //TEST2 : test de checknworkers et worker qui revient arpès bon nombre de tours//
    Game game(100, 100, 100, 100, 100, 100, 1, 100, Date(1, 12, 2022), Date(8, 11, 2018)); //1 worker au début
    if(game.checkWorkers(1)){
        game.build("Slum");
    } else {
        std::cout << "Not enough workers(checkWorker false)" << std::endl;
    }

    std::cout << game.getGameState() << std::endl;

    //Ne marche pas car pas de constructeur disponible
    if(game.checkWorkers(1)){
        game.build("Appartments");
    } else {
        std::cout << "Not enough workers (checkWorker false)" << std::endl;
    }

    game.newTurn(&game);

    std::cout << game.getGameState() << std::endl;

    //Constructeur a fini slum, donc dispo pour bosser là
    if(game.checkWorkers(1)){                                                     //
        game.build("Appartments");                                                // Remplacé par ActionBuild
    } else {                                                                      //
        std::cout << "Not enough workers (checkWorker false)" << std::endl;       //
    }                                                                             //

    std::cout << game.getGameState() << std::endl;

    for (int i=0; i<3; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }
    */
    
    //TEST3 : test de ActionBuild avec tous les bâtiments 
    std::cout << "\nTEST3 : test de ActionBuild avec tous les bâtiments \n         --------------------------- \n" << std::endl;
    Game game(100, 100, 100, 100, 100, 100, 1, 100, Date(1, 12, 2022), Date(8, 11, 2018)); //1 worker au début
    std::cout << game.getGameState() << std::endl;
    game.ActionBuild("Slum", 1);
    game.ActionBuild("Appartments", 1); //Ne marche pas 
    std::cout << game.getGameState() << std::endl;

    game.addWorker("Slum");
    game.ActionBuild("Appartments", 1); //Marche
    for (int i=0; i<3; i++){
        game.newTurn(&game);
    }
    for(int i=0; i<10; i++){
        game.addWorker("Appartments");
    }
    std::cout << game.getGameState() << std::endl;

    game.ActionBuild("ReligiousBuilding", 1);
    game.ActionBuild("Hotel", 1);
    game.ActionBuild("Hospital", 1);
    game.ActionBuild("State", 1); //marche pas 
    game.ActionBuild("Statue", 1);
   
    for(int i=0; i<10; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;

    }
    /*

    //TEST4: test de redéfinition des opérateurs + et > pour la classe Date
    
    Date date1 = Date(9, 10, 2019);
    Date date2 = Date(9, 5, 2019);
    
    if(date1>date2){
        std::cout << "Date 1 > Date 2" << std::endl;
    } else {
        std::cout << "Date 1 < Date 2" << std::endl;
    }
    

    date2 = date2 + 7;
    std::cout << "Date 2 est maintenant : " + date2.toString() << std::endl;

    if(date1>date2){
        std::cout << "Date 1 > Date 2" << std::endl;
    } else {
        std::cout << "Date 1 < Date 2" << std::endl;
    }

    for(int i = 0; i<10; i++){
        date2 = date2 + 10;
        std::cout << "Date 2 est maintenant : " + date2.toString() << std::endl;
    }
    for(int i=0; i<13; i++){
        date2 = date2 + 30;
        std::cout << "Date 2 est maintenant : " + date2.toString() << std::endl;
    }
    
    date2 = date2 + 365;
    std::cout << "Date 2 est maintenant : " + date2.toString() << std::endl; //Ne marche pas pour plus de 30j

    */
    return 0;

}
