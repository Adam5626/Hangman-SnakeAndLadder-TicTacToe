
#include "hangman.h"
#include "timer.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <vector>

using namespace std;
using namespace sf;

extern vector <int> current_scores;
extern time_t play_time;
namespace Hangman {

	time_t start_time = 0;

	
	string choice_type;
	void run()
	{
		//Adding music
		Music music;
		music.openFromFile("music.ogg");
		music.play();
		game_menu();
	}


	void game_win()
	{
		RenderWindow gamewin(VideoMode(1024, 768), "Hang Man", Style::Close | Style::Resize);
		Sprite win;
		Texture won;
		won.loadFromFile("Win.jpg");
		win.setTexture(won);
		while (gamewin.isOpen())
		{
			Event click;
			while (gamewin.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					gamewin.close();
					break;
				}


				}
			}
			gamewin.draw(win);
			gamewin.display();
		}
	}

	void game_over()
	{
		RenderWindow gameover(VideoMode(1024, 768), "Hang Man", Style::Close | Style::Resize);
		Sprite lost;
		Texture loss;
		loss.loadFromFile("Lost.jpg");
		lost.setTexture(loss);
		while (gameover.isOpen())
		{
			Event click;
			while (gameover.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					gameover.close();
					break;
				}

				}
			}


			gameover.draw(lost);
			gameover.display();

		}
	}


	void hangman_gameplay()
	{
		RenderWindow game_hangman(VideoMode(1024, 768), "Hang Man", Style::Close);

		int max_score = 100; //Score


		//Timer
		Clock timer;
		Time store_time;

		int death = 0;
		int win = 0;
		//Creating background
		Sprite game_bg;
		Texture game_bg_texture;
		game_bg_texture.loadFromFile("Gamebg.jpg");
		game_bg.setTexture(game_bg_texture);

		//Creating buttons
		RectangleShape buttons[5][5];
		RectangleShape Z(Vector2f(70, 60));
		Z.setPosition(550, 590);
		int x = 550;
		int y = 90;


		//Storing all alphabets in an array
		char alphabets[5][5];
		char start = 'A';
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				alphabets[i][j] = start;
				start++;
			}
		}

		//Getting data from file

		int random = 0;
		string store;
		string store1[18];
		string name;
		int length = 0;
		int z = 0;
		if (choice_type == "anime")
		{
			ifstream wordfile("anime.txt");
			while (getline(wordfile, store))
			{
				store1[z] = store;
				z++;
			}
			srand(time(0));
			random = rand() % 10 + 1;
			name = store1[random];
			cout << name;
			length = name.length();
		}

		if (choice_type == "movies")
		{
			ifstream wordfile("movies.txt");
			while (getline(wordfile, store))
			{
				store1[z] = store;
				z++;
			}
			srand(time(0));
			random = rand() % 10 + 1;
			name = store1[random];
			cout << name;
			length = name.length();
		}
		if (choice_type == "books")
		{
			ifstream wordfile("books.txt");
			while (getline(wordfile, store))
			{
				store1[z] = store;
				z++;
			}
			srand(time(0));
			random = rand() % 10 + 1;
			name = store1[random];
			cout << name;
			length = name.length();
		}
		if (choice_type == "countries")
		{
			ifstream wordfile("countries.txt");
			while (getline(wordfile, store))
			{
				store1[z] = store;
				z++;
			}
			srand(time(NULL));
			random = rand() % 10 + 1;
			name = store1[random];
			cout << name;
			length = name.length();
		}

		//Blanks
		Sprite blanks[18];
		Texture blank;
		blank.loadFromFile("Blanks.png");

		Vector2i mousepos;
		int flag = 0;


		for (int i = 0; i < 5; i++)
		{
			x = 550;
			for (int j = 0; j < 5; j++)
			{
				buttons[i][j].setSize(Vector2f(70, 60));
				buttons[i][j].setPosition(x, y);
				buttons[i][j].setFillColor(Color(0, 0, 0, 0));
				x = x + 100;
			}
			y = y + 100;
		}

		//Check for repitition
		int check[20];
		for (int i = 0; i <= length; i++)
		{
			check[i] = 0;
		}

		//Text 
		Font lemon;
		lemon.loadFromFile("LEMONMILK-Regular.otf");

		Text characters[26];
		char start1 = 'A';
		for (int i = 0; i <= 25; i++)
		{
			characters[i].setString(start1);

			start1++;
		}


		//Bodyparts
		Sprite body_face;
		int bodyparts = 0;
		//Face
		Texture face;
		face.loadFromFile("Face.png");
		//Main Body
		Sprite body_main;
		Texture main;
		main.loadFromFile("Mainbody.png");
		//Legs
		Sprite body_leftleg;
		Sprite body_rightleg;
		Texture leftleg;
		Texture rightleg;
		leftleg.loadFromFile("Leftleg.png");
		rightleg.loadFromFile("Rightleg.png");
		//Arms
		Sprite body_leftarm;
		Sprite body_rightarm;
		Texture leftarm;
		Texture rightarm;
		leftarm.loadFromFile("Leftarm.png");
		rightarm.loadFromFile("Rightarm.png");


		while (game_hangman.isOpen())
		{
			Event click;
			while (game_hangman.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					game_hangman.close();
					break;
				}
				case Event::MouseButtonPressed:
				{
					flag = 1;
				}
				}

			}
			//Displaying time
			system("CLS");
			store_time = timer.getElapsedTime();
			cout << store_time.asSeconds() << endl;



			mousepos = Mouse::getPosition(game_hangman);
			int x2 = 30;
			int y2 = 700;
			int wrong = length;

			if (Z.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)))
			{
				if (flag == 1)
				{
					for (int i = 0; i < length; i++)
					{
						if (name[i] == 'Z')
						{
							x2 = x * (x2 + 20) + 30;
							characters[i].setString("Z");
							characters[i].setFont(lemon);
							characters[i].setCharacterSize(30);
							characters[i].setPosition(x2, 700);
						}
						else
						{

							wrong--;
							flag = 0;
						}
						if (wrong == 0)
						{
							death++;
							if (death == 1)
							{
								max_score = max_score - 10;
								body_face.setTexture(face);
							}
							if (death == 2)
							{
								max_score = max_score - 10;
								body_main.setTexture(main);
							}
							if (death == 3)
							{
								max_score = max_score - 10;
								body_leftarm.setTexture(leftarm);
							}
							if (death == 4)
							{
								max_score = max_score - 10;
								body_rightarm.setTexture(rightarm);
							}
							if (death == 5)
							{
								max_score = max_score - 10;
								body_rightleg.setTexture(rightleg);
							}
							if (death == 6)
							{
								max_score = max_score - 10;
								body_leftleg.setTexture(leftleg);
								game_hangman.close();
								game_over();
								break;
							}


						}
					}
					
				}
			}


			x2 = 30;
			y2 = 700;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (buttons[i][j].getGlobalBounds().contains(static_cast<Vector2f>(mousepos)))
					{
						if (flag == 1)
						{
							for (int x = 0; x <= length; x++)
							{


								if (alphabets[i][j] == name[x] && check[x] == 0)
								{

									x2 = x * (x2 + 20) + 30;
									characters[x].setString(name[x]);
									characters[x].setPosition(x2, 700);
									characters[x].setFont(lemon);
									characters[x].setCharacterSize(30);
									game_hangman.draw(characters[x]);
									flag = 0;
									check[x] = 1;
									win++;
									break;
								}
								else
								{
									
									wrong--;
									flag = 0;
								}
								if (wrong == 0)
								{
									death++;
									if (death == 1)
									{
										max_score = max_score - 10;
										body_face.setTexture(face);
									}
									if (death == 2)
									{
										max_score = max_score - 10;
										body_main.setTexture(main);
									}
									if (death == 3)
									{
										max_score = max_score - 10;
										body_leftarm.setTexture(leftarm);
									}
									if (death == 4)
									{
										max_score = max_score - 10;
										body_rightarm.setTexture(rightarm);
									}
									if (death == 5)
									{
										max_score = max_score - 10;
										body_rightleg.setTexture(rightleg);
									}
									if (death == 6)
									{
										max_score = max_score - 10;
										body_leftleg.setTexture(leftleg);
										game_hangman.close();
										game_over();
										break;
									}


								}
							}

						}
					}
				}
			}


			//Win Condition

			if (win == length)
			{

				game_hangman.close();
				game_win();
				break;
			}
			int x1 = 0;


			game_hangman.draw(game_bg);

			for (int i = 0; i < length; i++)
			{

				blanks[i].setTexture(blank);
				blanks[i].setPosition(x1, 0);
				game_hangman.draw(blanks[i]);
				x1 = x1 + 50;
			}
			for (int i = 0; i <= 25; i++)
			{
				game_hangman.draw(characters[i]);
			}
			game_hangman.draw(body_face);
			game_hangman.draw(body_main);
			game_hangman.draw(body_leftarm);
			game_hangman.draw(body_rightarm);
			game_hangman.draw(body_rightleg);
			game_hangman.draw(body_leftleg);
			game_hangman.display();
		}
		
		current_scores.push_back(max_score);

	}
	void game_menu();
	void instruction1();
	void choice();



	void choice()
	{
		RenderWindow win_choice(VideoMode(1024, 768), "Hang Man", Style::Close | Style::Resize);

		//Background

		Sprite background;
		Texture bg;
		bg.loadFromFile("choice.jpg");
		background.setTexture(bg);

		//Anime Button
		RectangleShape anime(Vector2f(200, 55));
		anime.setPosition(410, 140);

		//Movie Button
		RectangleShape movies(Vector2f(220, 60));
		movies.setPosition(410, 280);

		//Books Button
		RectangleShape books(Vector2f(220, 60));
		books.setPosition(420, 575);

		//Countries button
		RectangleShape countries(Vector2f(285, 65));
		countries.setPosition(380, 430);

		//Backbutton
		RectangleShape back(Vector2f(170, 80));
		back.setPosition(50, 640);

		Vector2i mousepos;

		while (win_choice.isOpen())
		{
			Event click;
			while (win_choice.pollEvent(click))
			{
				switch (click.type)
				case Event::Closed:
				{
					win_choice.close();
				}
			}
			mousepos = Mouse::getPosition(win_choice);
			if (anime.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{
				choice_type = "anime";
				win_choice.close();
				hangman_gameplay();
			}
			if (movies.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{
				choice_type = "movies";
				win_choice.close();
				hangman_gameplay();
			}
			if (books.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{
				choice_type = "books";
				win_choice.close();
				hangman_gameplay();
			}
			if (countries.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{
				choice_type = "countries";
				win_choice.close();
				hangman_gameplay();
			}



			if (back.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{

				win_choice.close();
				game_menu();
			}




			win_choice.draw(background);
			win_choice.display();

		}
		time_t end_time;
		end_time = Timer::get_current_time();
	    play_time = end_time - start_time;

	}

	void instruction1()
	{
		RenderWindow win_instructions(VideoMode(1024, 768), "Hang Man", Style::Close | Style::Resize);

		//Backbutton
		RectangleShape back(Vector2f(170, 80));
		back.setPosition(700, 600);

		//Instructions
		Sprite instructions;
		Texture instructions_texture;
		instructions_texture.loadFromFile("instructions.jpg");
		instructions.setTexture(instructions_texture);

	

		Vector2i mousepos;

		while (win_instructions.isOpen())
		{
			Event click;
			while (win_instructions.pollEvent(click))
			{
				switch (click.type)
				case Event::Closed:
				{
					win_instructions.close();
					break;
				}
			}

			mousepos = Mouse::getPosition(win_instructions);
			if (back.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{

				win_instructions.close();
				game_menu();
				break;
			}

			win_instructions.draw(instructions);
			win_instructions.display();
		}
	}

	void  game_menu()
	{
		RenderWindow menu_hangman(VideoMode(1024, 768), "Hang Man", Style::Close);

	

		//Getting mouse position.
		Vector2i mousepos;


		//Creating Menu
		Sprite menu_bg;
		Texture menu;
		menu.loadFromFile("Menu.jpg");
		menu_bg.setTexture(menu);


		//Play Button
		RectangleShape menu_play(Vector2f(150, 80));
		menu_play.setPosition(120, 300);
		menu_play.setFillColor(Color(0, 0, 0, 0));

		//Instructions Button
		RectangleShape instruction(Vector2f(270, 70));
		instruction.setPosition(120, 530);

		//Top Score
		RectangleShape top(Vector2f(270, 70));
		top.setPosition(120, 430);

		

		while (menu_hangman.isOpen())
		{
			Event click;
			while (menu_hangman.pollEvent(click))
			{
				switch (click.type)
				case Event::Closed:
				{
					menu_hangman.close();
					break;
				}


			}
			mousepos = Mouse::getPosition(menu_hangman);
			if (menu_play.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{
				start_time = Timer::get_current_time();
				menu_hangman.close();
				choice();
				break;

			}
			if (instruction.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{
				menu_hangman.close();
				instruction1();
				break;
			}
			menu_hangman.draw(menu_bg);
			menu_hangman.display();
		}

		
	}


}