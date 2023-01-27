#include <SDL.h>        
#include <SDL_image.h>        
#include <SDL_ttf.h>
#include <string> 
#include "game.hpp"
#include "buildings.hpp"

#define WIDTHSCREEN 1600
#define HEIGHTSCREEN 900
int quit = 0;
SDL_Window * window;
SDL_Renderer *renderer;
SDL_Event event;
//SDL_Surface *tile; 
//SDL_Texture *texture_tile;
TTF_Font* font;
char word[64];
int mx,my,px,py;
enum enum_building
{
    Desert,
    Slum,
    Appartments,
    House,
    DrillingMachine,
    SolarPanel,
    WindTurbine,
    Church,
    Synagogue,
    Mosque,
    Hotel,
    Statue,
    Hospital,
    Stadium
};
enum_building tabBuilding[14][8];

//affichage d'un texte
void myRenderText(char* m,int x,int y)
{
    SDL_Surface* text = TTF_RenderText_Blended(font, m, SDL_Color{ 0, 0, 0, 255 }); 
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer,text);
    SDL_Rect Message_rect = {x, y, text->w, text->h };
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(text);
}

void drawText(Game game)
{
    font = TTF_OpenFont("texture/sans.ttf", 25);
    strcpy(word,("Money : "+ game.getMoney()));
    myRenderText(word,10,30);
    strcpy(word,("Energy : "+game.getEnergy()));
    myRenderText(word,190,30);
    strcpy(word,("Popularity : "+std::to_string(game.getPopularity())).c_str());
    myRenderText(word,370,30);
    strcpy(word,("Nb of stadium : "+game.getnStadium()));
    myRenderText(word,560,30);
    strcpy(word,("Score : "+game.getGameScore()));
    myRenderText(word,800,30);
    int workersav = game.getnWorkersAvailable();
    int workertot = game.getnWorkers();
    strcpy(word,("Workers : "+workersav+std::string("/")+std::to_string(workertot)).c_str());
    myRenderText(word,990,30);
    strcpy(word,("Turn : "+game.getnTurn()));
    myRenderText(word,1170,30);
    strcpy(word,("Current date : " + game.getCurrentDate().toString()).c_str());
    myRenderText(word,1300,10);
    strcpy(word,("Deadline : "+ game.getDeadline().toString()).c_str());
    myRenderText(word,1343,40);
    strcpy(word,"Housing : ");
    myRenderText(word,1410,100);
    strcpy(word,"Production : ");
    myRenderText(word,1410,300);
    strcpy(word,"Others : ");
    myRenderText(word,1410,500);
    TTF_CloseFont(font);
    

}

void drawBuildingText()
{
    font = TTF_OpenFont("texture/sans.ttf", 15);
    strcpy(word,"-Slum (100$/100E)");
    myRenderText(word,1410,150);
    strcpy(word,"-Appartements (500$/300E)");
    myRenderText(word,1410,200);
    strcpy(word,"-House (200$/150E)");
    myRenderText(word,1410,250);
    strcpy(word,"-Drilling machine (150$/100E)");
    myRenderText(word,1410,350);
    strcpy(word,"-Solar panel (175$/10E)");
    myRenderText(word,1410,400);
    strcpy(word,"-Wind turbine (175$/10E)");
    myRenderText(word,1410,450);
    strcpy(word,"-Church (500$/100E)");
    myRenderText(word,1410,550);
    strcpy(word,"-Synagogue (500$/100E)");
    myRenderText(word,1410,580);
    strcpy(word,"-Mosque (500$/100E)");
    myRenderText(word,1410,610);
    strcpy(word,"-Hotel (800$/400E)");
    myRenderText(word,1410,640);
    strcpy(word,"-Hospital (1000$/500E)");
    myRenderText(word,1410,670);
    strcpy(word,"-Statue (1000$/50E)");
    myRenderText(word,1410,700);
    strcpy(word,"-Stadium (5000$/1000E)");
    myRenderText(word,1410,730);
    TTF_CloseFont(font);
}

void drawTexture(std::string file,int x, int y, int w, int h)
{
    strcpy(word,file.c_str());
    SDL_Surface * tile = IMG_Load(word);
    SDL_Texture * texture_tile = SDL_CreateTextureFromSurface(renderer, tile);
    SDL_Rect dstrect = { x, y, w, h };
    SDL_RenderCopy(renderer,texture_tile, NULL, &dstrect);
    SDL_FreeSurface(tile);
    SDL_DestroyTexture(texture_tile);
}

void drawTextureTile(enum_building type,int x, int y, int w, int h)
{
    if (type==0)
        drawTexture("texture/sand.png", x, y, w, h);
    else if (type==1)
        drawTexture("texture/slum.pgn", x, y, w, h);
    else if (type==2)
        drawTexture("texture/app.png", x, y, w, h);
    else if (type==3)
        drawTexture("texture/house.pgn", x, y, w, h);
    else if (type==4)
        drawTexture("texture/drillingmachine.png", x, y, w, h);
    else if (type==5)
        drawTexture("texture/solarpannel.jpg", x, y, w, h);
    else if (type==6)
        drawTexture("texture/windturbine.jpg", x, y, w, h);
    else if (type==7)
        drawTexture("texture/church.jpg", x, y, w, h);
    else if (type==8)
        drawTexture("texture/synagogue.jpeg", x, y, w, h);
    else if (type==9)
        drawTexture("texture/mosque.jpg", x, y, w, h);
    else if (type==10)
        drawTexture("texture/hotel.jpg", x, y, w, h);
    else if (type==11)
        drawTexture("texture/hospital.jpeg", x, y, w, h);
    else if (type==12)
        drawTexture("texture/statue.jpg", x, y, w, h);
    else if (type==13)
        drawTexture("texture/stadium.jpeg", x, y, w, h);
}

void drawTile()
{
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < 14; j++)
            drawTextureTile(tabBuilding[px][py],100*j, 100*i, 100, 100);
    }


    //mise en valeur de la case sélectionée
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 120);
    SDL_Rect select_rect = {px*100,(py+1)*100,100,100}; 
    SDL_RenderFillRect(renderer, &select_rect);

}


void drawGrid()
{
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, WIDTHSCREEN-200, 100, WIDTHSCREEN, 100);
        SDL_RenderDrawLine(renderer, WIDTHSCREEN-200, 300, WIDTHSCREEN, 300);
        SDL_RenderDrawLine(renderer, WIDTHSCREEN-200, 500, WIDTHSCREEN, 500);
                
}

void manageEvent(SDL_Event event,Game* game) //fonction permettant de gérer les différents inputs
{
 switch (event.type)
 {
    case SDL_QUIT:
        quit = 1;
        break;
    case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_CLOSE)
            quit = 1;
        break;
    case  SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState( &mx, &my );
        if (my>100 && mx<1400)
        {
            px = mx/100;
            py = my/100-1;
            break;
        }
        else if (my>100 && mx>1400) 
        {
            if (my>800) //next button
                game->newTurn(game);
            else if (my>150 && my<200)
            {
                if(game->ActionBuild("Slum",1,100,100))
                {
                    enum_building slum = Slum;
                    tabBuilding[px][py]= slum;
                }
            }
            else if (my>200 && my<250)
            {
                if(game->ActionBuild("Appartments", 1, 500, 300))
                {
                    enum_building appartments = Appartments;
                    tabBuilding[px][py]= appartments;
                }    
            }
            else if (my>250 && my<300)
            {
                if(game->ActionBuild("House", 1, 200, 150))
                {
                    enum_building house = House;
                    tabBuilding[px][py]= house;
                } 
            }
            else if (my>350 && my<400)
            {
                if(game->ActionBuild("DrillingMachine", 1, 150, 100))
                {
                    enum_building drillingMachine = DrillingMachine;
                    tabBuilding[px][py]= drillingMachine;
                } 
            }
            else if (my>400 && my<450)
            {
                if(game->ActionBuild("SolarPanel", 1, 175, 10))
                {
                    enum_building solarPanel = SolarPanel;
                    tabBuilding[px][py]= solarPanel;
                } 
            }
            else if (my>450 && my<500)
            {
                if(game->ActionBuild("WindTurbine", 1, 175, 10))
                {
                    enum_building windTurbine = WindTurbine;
                    tabBuilding[px][py]= windTurbine;
                } 
            }
            else if (my>550 && my<580)
            {
                if(game->ActionBuild("ReligiousBuilding Christian", 1, 500, 100))
                {
                    enum_building church = Church;
                    tabBuilding[px][py]= church;
                } 
            }
            else if (my>580 && my<610)
            {
                if(game->ActionBuild("ReligiousBuilding Jewish", 1, 500, 100))
                {
                    enum_building synagogue = Synagogue;
                    tabBuilding[px][py]= synagogue;
                } 
            }
            else if (my>610 && my<640)
            {
                if(game->ActionBuild("ReligiousBuilding Muslim", 1, 500, 100))
                {
                    enum_building mosque = Mosque;
                    tabBuilding[px][py]= mosque;
                } 
            }
            else if (my>640 && my<670)
            {
                if(game->ActionBuild("Hotel", 1, 800, 400))
                {
                    enum_building hotel = Hotel;
                    tabBuilding[px][py]= hotel;
                } 
            }
            else if (my>670 && my<700)
            {
                if(game->ActionBuild("Hospital", 1, 1000, 500))
                {
                    enum_building hospital = Hospital;
                    tabBuilding[px][py]= hospital;
                } 
            }
            else if (my>700 && my<730)
            {
                if(game->ActionBuild("Statue", 1, 1000, 50))
                {
                    enum_building statue = Statue;
                    tabBuilding[px][py]= statue;
                } 
            }
            else if (my>730 && my<760)
            {
                if(game->ActionBuild("Stadium", 1, 5000, 1000))
                {
                    enum_building stadium = Stadium;
                    tabBuilding[px][py]= stadium;
                } 
            }
            

        }
   
 }
}

int graphic(Game* game)
{

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
     
    window = SDL_CreateWindow("QATAR",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTHSCREEN, HEIGHTSCREEN, 0); //création de la fenêtre
    renderer = SDL_CreateRenderer(window, -1, 0); //création du rendu
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    while (!quit) //game loop
    {
        if (SDL_PollEvent(&event))
            manageEvent(event,game);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);


        drawTile();
        //drawText(*game);
        drawBuildingText();
        drawGrid();
        drawTexture("texture/NextButton.png",1400, 800, 200, 100);
        
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
 
    return 0;
}
 

//attention au mvmt de souris trop brusque rique de faire planter 