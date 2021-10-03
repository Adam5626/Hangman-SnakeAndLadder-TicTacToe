#include "tictactoe.h"
#include <iostream>
#include <vector>
#include "timer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>

using namespace sf;
using namespace std;

extern vector <int> current_scores;
extern time_t play_time;
namespace Tic
{
    time_t start_time;

    int check = 0;
    int score_p1 = 0;
    int score_p2 = 0;
    int moves1 = 0;
    int moves2 = 0;
    int score=0;
    int score_win = 0;


    void gamewindow()  //Function for game window
    {
        int win = 0;
        int count = 0;
        int grid1[3][3] = {};
        int flag = 0;



        RenderWindow gamewin(VideoMode(1200, 720), "TIC TAC TOE", Style::Close);

        //Timer
        Clock timer;
        Time compare;



        //Creating game background
        Texture gamebg;
        gamebg.loadFromFile("background.jpg");
        Sprite gamebackground;
        gamebackground.setTexture(gamebg);

        //Creating Grid
        Texture gridtex;
        gridtex.loadFromFile("grid.png");
        Sprite grid;
        grid.setTexture(gridtex);

        //Creating gridbuttons
        int x, y;
        x = 0;
        y = 0;

        Vector2i mousepos;



        //Circles
        Sprite circle[3][3];
        Texture crcl;
        crcl.loadFromFile("circle.png");


        //Cross
        Sprite cross[3][3];
        Texture crss;
        crss.loadFromFile("cross.png");
        int x1 = 0;
        int y1 = 0;

        //Players
        Sprite players;
        Texture player;
        player.loadFromFile("players.png");
        players.setTexture(player);




        //Win
        Sprite winhorizontal[3][3];
        Texture winhor;
        winhor.loadFromFile("winrow.png");

        Sprite winvertical[3][3];
        Texture winver;
        winver.loadFromFile("wincol.png");

        Sprite windiagonal[3][3];
        Texture windig;
        windig.loadFromFile("windig.png");


        Sprite windiagonal1[3][3];
        Texture windig1;
        windig1.loadFromFile("windig2.png");

        Sprite winplayer1;
        Texture winp1;
        winp1.loadFromFile("winp1.png");



        Sprite winplayer2;
        Texture winp2;
        winp2.loadFromFile("winp2.png");




        int x3 = 0, y3 = 20;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                winvertical[i][j].setPosition(x3, y3);

                x3 = x3 + 70;
            }

        }
        int x4 = 0;
        int y4 = 0;


        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                winhorizontal[i][j].setPosition(x4, y4);

            }
            y4 = y4 + 200;
        }




        RectangleShape gridbutton[3][3];
        y = 50;



        int z = 0;


        for (int i = 0; i < 3; i++)
        {
            x = 340;
            for (int j = 0; j < 3; j++)
            {

                gridbutton[i][j].setSize(Vector2f(170, 190));
                gridbutton[i][j].setPosition(Vector2f(x, y));
                gridbutton[i][j].setFillColor(Color(0, 0, 0, 0));
                x = x + 200;
            }
            y = y + 200;
        }






        count = 1;


        while (gamewin.isOpen())
        {
            Event gameevnt;
            while (gamewin.pollEvent(gameevnt))
            {
                switch (gameevnt.type)
                {
                case Event::Closed:
                    gamewin.close();

                case Event::MouseButtonPressed:

                    if (check == 0)
                    {

                        flag = 1;
                        count++;
                    }
                }
            }

            compare = timer.getElapsedTime();
            system("CLS");
            cout << compare.asSeconds();

            mousepos = Mouse::getPosition(gamewin);


            y1 = -130;
            for (int i = 0; i < 3; i++)
            {
                x1 = -200;
                for (int j = 0; j < 3; j++)
                {

                    if (gridbutton[i][j].getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && grid1[i][j] != 1 && grid1[i][j] != 2)
                    {

                        if (flag == 1)
                        {

                            if (count % 2 == 0)
                            {
                                circle[i][j].setTexture(crcl);
                                circle[i][j].setPosition(x1, y1);
                                flag = 0;
                                grid1[i][j] = 1;
                                moves1++;

                            }
                            else if (count % 2 != 0)
                            {
                                cross[i][j].setPosition(x1, y1);
                                cross[i][j].setTexture(crss);
                                flag = 0;
                                grid1[i][j] = 2;
                                moves2++;

                            }
                        }
                    }

                    x1 = x1 + 200;
                }

                y1 = y1 + 200;

            }

            for (int i = 0; i < 3; i++)
            {

                //Rows
                if (grid1[i][z] == 1 && grid1[i][z + 1] == 1 && grid1[i][z + 2] == 1)
                {

                    winhorizontal[i][z].setTexture(winhor);
                    winplayer1.setTexture(winp1);
                    check = 1;
                   



                }
                else  if (grid1[i][z] == 2 && grid1[i][z + 1] == 2 && grid1[i][z + 2] == 2)
                {

                    winhorizontal[i][z].setTexture(winhor);
                    winplayer2.setTexture(winp2);
                    check = 1;

                }
                //Columns
                if (grid1[z][i] == 1 && grid1[z + 1][i] == 1 && grid1[z + 2][i] == 1)
                {

                    winvertical[i][z].setTexture(winver);
                    winplayer1.setTexture(winp1);
                    check = 1;


                }
                else  if (grid1[z][i] == 2 && grid1[z + 1][i] == 2 && grid1[z + 2][i] == 2)
                {

                    winvertical[i][z].setTexture(winver);
                    winplayer2.setTexture(winp2);
                    check = 1;

                }
                //Diagonal main
                else if (grid1[0][0] == 1 && grid1[1][1] == 1 && grid1[2][2] == 1)
                {

                    windiagonal[i][z].setTexture(windig);
                    winplayer1.setTexture(winp1);
                    check = 1;
                }
                else if (grid1[0][0] == 2 && grid1[1][1] == 2 && grid1[2][2] == 2)
                {

                    windiagonal[i][z].setTexture(windig);
                    winplayer2.setTexture(winp2);
                    check = 1;
                }
                //Diagonal sec
                else if (grid1[0][2] == 1 && grid1[1][1] == 1 && grid1[2][0] == 1)
                {

                    windiagonal1[i][z].setTexture(windig1);
                    winplayer1.setTexture(winp1);
                    check = 1;
                }
                else if (grid1[0][2] == 2 && grid1[1][1] == 2 && grid1[2][0] == 2)
                {

                    windiagonal1[i][z].setTexture(windig1);
                    winplayer2.setTexture(winp2);
                    check = 1;
                }


            }



            if (count == 10 && check!=1)
            {
                cout << "Draw";
                break;
            }

            gamewin.draw(gamebackground);
            gamewin.draw(grid);

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    gamewin.draw(gridbutton[i][j]);
                    gamewin.draw(circle[i][j]);
                    gamewin.draw(cross[i][j]);

                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    gamewin.draw(winhorizontal[i][j]);
                    gamewin.draw(winvertical[i][j]);
                    gamewin.draw(windiagonal[i][j]);
                    gamewin.draw(windiagonal1[i][j]);

                }
            }
            gamewin.draw(players);
            gamewin.draw(winplayer1);
            gamewin.draw(winplayer2);

            gamewin.display();


        }
        score_p1 = (9 - moves1) * 10;
        score_p2 = (9 - moves2) * 10;
        current_scores.push_back(score_p1);
        current_scores.push_back(score_p2);
       
    
    }
    void menuwindow()  //Function for menu window
    {
        RenderWindow mywin(VideoMode(1280, 720), "TIC TAC TOE", Style::Close);

        //Making menu

        //Adding menu audio
        Music music;
        music.openFromFile("tic.ogg");
        music.play();

        //Making background for menu
        //Adding background
        Sprite background;
        Texture starry;
        starry.loadFromFile("background.jpg");
        background.setTexture(starry);

        //Adding game logo
        Sprite logo;
        Texture logotex;
        logotex.loadFromFile("main.png");
        logo.setTexture(logotex);

        //Play button

        //Displayng
        Sprite play;
        Texture playtex;
        playtex.loadFromFile("play.png");
        play.setTexture(playtex);

        //Interactive
        RectangleShape playbutton(Vector2f(260.0f, 115.0f));
        playbutton.setFillColor(Color(0, 0, 0, 0));
        playbutton.setPosition(Vector2f(510.0f, 310.0f));
        //Getting bounds of button
        FloatRect bounds;
        bounds = playbutton.getGlobalBounds();
        Vector2i mousepos;



        while (mywin.isOpen())
        {
            mousepos = Mouse::getPosition(mywin);
            Event  evnt;
            while (mywin.pollEvent(evnt))
            {
                switch (evnt.type)
                {
                case Event::Closed:
                    mywin.close();

                case Event::MouseButtonPressed:

                    switch (evnt.key.code)
                case Mouse::Left:
                    if (bounds.contains(static_cast<Vector2f>(mousepos)))
                    {
                        start_time = Timer::get_current_time();
                        mywin.close();
                        gamewindow();
                    }
                }
            }
            mywin.clear();
            mywin.draw(background);
            mywin.draw(logo);
            mywin.draw(play);
            mywin.draw(playbutton);

            mywin.display();


        }
        time_t end_time;
        end_time = Timer::get_current_time();
        play_time = end_time - start_time;
    }
    int run()
    {
        menuwindow();
        return score;
       
    }



}