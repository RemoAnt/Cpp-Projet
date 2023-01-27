#include <iostream>
#include <string>
#include "buildings.hpp"
#include "date.hpp"
#include "game.hpp"
#include "field.hpp"

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
    
    
    //TEST3 : test de ActionBuild avec tous les bâtiments  //NE PAS UTILISER NE MARCHE PLUS
    std::cout << "\nTEST3 : test de ActionBuild avec tous les bâtiments \n         --------------------------- \n" << std::endl;
    Game game(100000, 100, 0, 0, 100, 100, 1, 100, Date(1, 12, 2022), Date(8, 11, 2018)); //1 worker au début
    std::cout << game.getGameState() << std::endl;
    game.ActionBuild("Slum", 1, 100);
    game.ActionBuild("Appartments", 1, 500); //Ne marche pas car pas slum pas encore construit
    std::cout << game.getGameState() << std::endl;

    //game.addWorker("Slum");
    game.newTurn(&game);
    game.ActionBuild("Appartments", 1, 500); //Marche
    for (int i=0; i<3; i++){
        game.newTurn(&game);
    }
    // for(int i=0; i<10; i++){
    //     game.addWorker("Appartments");
    // }
    std::cout << game.getGameState() << std::endl;

    game.ActionBuild("ReligiousBuilding", 1, 500);
    game.ActionBuild("Hotel", 1, 800);
    game.ActionBuild("Hospital", 1, 1000);
    game.ActionBuild("State", 1, 1000); //marche pas 
    game.ActionBuild("Statue", 1, 1000);
   
    for(int i=0; i<7; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;

    }
    
    
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

    

    //TEST5 : implémentation de money et score
    std::cout << "\nTEST5 : implémentation de money et score \n         --------------------------- \n" << std::endl;
    Game game(10000, 100, 0, 0, 100, 100, 1, 100, Date(10, 1, 2022), Date(8, 11, 2018)); //1 worker et 10 000 argent au début

    std::cout << game.getGameState() << std::endl;

    game.newTurn(&game);
    std::cout << game.getGameState() << std::endl;
    game.ActionBuild("ReligiousBuilding Christian", 1, 500);

    for(int i=0; i<5; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }

    game.ActionBuild("ReligiousBuilding Jewish", 1, 500);

    for(int i=0; i<5; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }

    game.ActionBuild("ReligiousBuilding Muslim", 1, 500);

    for(int i=0; i<5; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }

    game.ActionBuild("Slum", 1, 100);

    game.newTurn(&game);
    std::cout << game.getGameState() << std::endl;

    

    //TEST6 : jusqu'à fin de partie avec while 
    std::cout << "\nTEST6 : jusqu'à fin de partie \n         --------------------------- \n" << std::endl;
    Game game;

    while(game.newTurn(&game)){
        std::cout << game.getGameState() << std::endl;
    }

    std::cout << "\n---------------------\n     NEW GAME\n---------------------" << std::endl;
    Game game2(10000000, 1000000, 0, 0, 100, 100, 10, Date(1, 12, 2022), Date(8, 11, 2018)); 
    std::cout << game2.getGameState() << std::endl;

    while(game2.newTurn(&game2)){   //NORMAL SI CA FINIT A 10 STADIUMS AU LIEU DE 5 PCQ Y'EN A 5 DEJA CONSTRUIT ET 5 EN CONSTRUCTION "en trop"(pcq while)
        std::cout << game2.getGameState() << std::endl;
        game2.ActionBuild("Stadium", 1, 5000, 1000);
    }
    

    //TEST7 : partie typique
    std::cout << "\nTEST7 : partie typique \n         --------------------------- \n" << std::endl;
    Game game;
    std::cout << game.getGameState() << std::endl;

    game.ActionBuild("Slum", 1, 100, 100);
    game.newTurn(&game);
    std::cout << game.getGameState() << std::endl;

    game.ActionBuild("DrillingMachine", 1, 150, 100);
    game.ActionBuild("DrillingMachine", 1, 150, 100);
    game.ActionBuild("DrillingMachine", 1, 150, 100);

    game.newTurn(&game);
    game.newTurn(&game);
    game.newTurn(&game);
    game.newTurn(&game);
    std::cout << game.getGameState() << std::endl;

    game.ActionBuild("Statue", 1, 100, 50);

    for(int i=0; i<5; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }
    
    game.ActionBuild("Hotel", 1, 800, 400);
    game.ActionBuild("Hotel", 1, 800, 400);

    for(int i=0; i<5; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }

    game.ActionBuild("Hospital", 1, 1000, 500);
    game.ActionBuild("Stadium", 1, 5000, 1000); //Ne marche pas pas assez d'argent

    for(int i=0; i<5; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }

    game.ActionBuild("Stadium", 1, 5000, 1000);
    
    for(int i = 0; i<5; i++){
        game.ActionBuild("SolarPanel", 1, 175, 10);
    }
    
    for(int i=0; i<3; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }

    game.ActionBuild("Appartments", 1, 500, 300);
    
    for(int i = 0; i<2; i++){
        game.ActionBuild("SolarPanel", 1, 175, 10);
    }

    for(int i=0; i<3; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }
    
    game.ActionBuild("Stadium", 1, 5000, 1000);
    
    for(int i = 0; i<5; i++){
        game.ActionBuild("SolarPanel", 1, 175, 10);
    }

    for(int i=0; i<3; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }

    game.ActionBuild("Stadium", 1, 5000, 1000);
    game.ActionBuild("Stadium", 1, 5000, 1000);

    for(int i=0; i<5; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    }

    game.ActionBuild("Stadium", 1, 5000, 1000);
    game.ActionBuild("Stadium", 1, 5000, 1000); //Le dernier

    for(int i=0; i<6; i++){
        game.newTurn(&game);
        std::cout << game.getGameState() << std::endl;
    } 
    
    game.newTurn(&game); //Fin de partie (5 stadiums construits)

    */
    Game game;
    graphic(&game);
    return 0;

}
