#include "snake4p.h"
#include "timer.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <SFML/Audio.hpp>
#include <Windows.h>

using namespace std;

extern vector <int> current_scores;
extern time_t play_time;

namespace Snake4p
{

	time_t start_time;

	using namespace sf;
	using namespace std;
	void instructions();
	void game_menu();
	void blue_win();
	void green_win();
	void purple_win();
	void yellow_win();
	void game_win();


	int score1 = 0;
	int score_p1 = 0;
	int score_p2 = 0;
	int score_p3 = 0;
	int score_p4 = 0;


	int run()
	{
		//Music
		Music music;
		music.openFromFile("snake.ogg");
		music.play();

		game_menu();
		return score1;
	}



	void instructions()
	{
		RenderWindow instructions_window(VideoMode(1024, 980), "Snake and Ladder", Style::Close | Style::Resize);

		//Instruction Image
		Sprite instruction_bg;
		Texture instruction_texture;
		instruction_texture.loadFromFile("instructions.png");
		instruction_bg.setTexture(instruction_texture);


		//Back button
		RectangleShape back(Vector2f(180, 70));
		back.setPosition(50, 860);
		Vector2i mousepos;



		while (instructions_window.isOpen())
		{
			Event click;
			while (instructions_window.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					instructions_window.close();
					break;
				}
				}
				mousepos = Mouse::getPosition(instructions_window);
				if (back.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
				{
					instructions_window.close();
					game_menu();
				}

			}

			instructions_window.draw(instruction_bg);
			instructions_window.display();
		}



	}



	void game_menu()
	{
		RenderWindow menu(VideoMode(1024, 980), "Snake and Ladder", Style::Close | Style::Resize);

		
		//Main Menu
		Sprite menu_;
		Texture menu_texture;
		menu_texture.loadFromFile("gamemenu.png");
		menu_.setTexture(menu_texture);
		Vector2i mousepos;


		//Play button
		RectangleShape play(Vector2f(190, 80));
		play.setPosition(400, 400);


		//Instructions Button
		RectangleShape instructions_button(Vector2f(440, 80));
		instructions_button.setPosition(290, 690);


		while (menu.isOpen())
		{
			Event click;
			while (menu.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
					menu.close();
					break;
				}
			}


			mousepos = Mouse::getPosition(menu);

			//If statement to check if mouse position lies in gloabal bounds

			if (play.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{
				start_time = Timer::get_current_time();
				menu.close();
				game_win();
			}
			if (instructions_button.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
			{
				menu.close();
				instructions();

			}

			menu.draw(menu_);
			menu.display();
		}
		time_t end_time;
		end_time = Timer::get_current_time();
		play_time = end_time - start_time;
	}




	void green_win()
	{
		RenderWindow greenwin(VideoMode(1024, 980), "Snake and Ladder", Style::Close | Style::Resize);

		//Main Image
		Sprite main;
		Texture main_tetxure;
		main_tetxure.loadFromFile("greenwin.png");
		main.setTexture(main_tetxure);
		while (greenwin.isOpen())
		{
			Event click;
			while (greenwin.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					greenwin.close();
					break;
				}
				}
			}
			greenwin.draw(main);
			greenwin.display();
		}
	}


	void blue_win()
	{
		RenderWindow bluewin(VideoMode(1024, 980), "Snake and Ladder", Style::Close | Style::Resize);

		//Main Image
		Sprite main;
		Texture main_texture;
		main_texture.loadFromFile("bluewin.png");
		main.setTexture(main_texture);
		while (bluewin.isOpen())
		{
			Event click;
			while (bluewin.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					bluewin.close();
				}
				}
			}
			bluewin.draw(main);
			bluewin.display();
		}
	}

	void purple_win()
	{
		RenderWindow purplewin(VideoMode(1024, 980), "Snake and Ladder", Style::Close | Style::Resize);

		//Main Image
		Sprite main;
		Texture main_tetxure;
		main_tetxure.loadFromFile("purplewin.png");
		main.setTexture(main_tetxure);
		while (purplewin.isOpen())
		{
			Event click;
			while (purplewin.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					purplewin.close();
					break;
				}
				}
			}
			purplewin.draw(main);
			purplewin.display();
		}
	}

	void yellow_win()
	{
		RenderWindow yellowwin(VideoMode(1024, 980), "Snake and Ladder", Style::Close | Style::Resize);

		//Main Image
		Sprite main;
		Texture main_tetxure;
		main_tetxure.loadFromFile("yellowwin.png");
		main.setTexture(main_tetxure);
		while (yellowwin.isOpen())
		{
			Event click;
			while (yellowwin.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					yellowwin.close();
					break;
				}
				}
			}
			yellowwin.draw(main);
			yellowwin.display();
		}
	}



	void game_win()
	{
		RenderWindow game_window(VideoMode(1024, 980), "Snake and Ladder", Style::Close | Style::Resize);
		//Blue piece P1
		Sprite blue;
		Texture blue_texture;
		blue_texture.loadFromFile("blue.png");


		//Green piece P2
		Sprite green;
		Texture green_texture;
		green_texture.loadFromFile("green.png");


		//Yellow piece P3
		Sprite yellow;
		Texture yellow_texture;
		yellow_texture.loadFromFile("yellow.png");


		//Purple piece P4
		Sprite purple;
		Texture purple_texture;
		purple_texture.loadFromFile("purple.png");



		
		int check = 0;
		int flag = 0;
		int check1 = 0;
		int check2 = 0;
		int check3 = 0;
		int win = 0;
		int win1 = 0;
		int win2 = 0;
		int win3 = 0;

		//Main game board
		Sprite board;
		Texture bg_board;
		bg_board.loadFromFile("board4.jpg");
		board.setTexture(bg_board);


		//Making dice button
		CircleShape dice_button(60, 60);
		dice_button.setPosition(Vector2f(70, 820));

		Vector2i mousepos;
		int player = 1;
		int random = 0;
		int x = 0;
		int y = 0;
		int row = 0;


		//Displaying score 1
		Font score_font;
		score_font.loadFromFile("LEMONMILK-Regular.otf");
		Text score;
		score.setFont(score_font);
		score.setPosition(450, 880);
		score.setFillColor(Color(0, 0, 0));
		score.setCharacterSize(50);
		string score1_string;

		//Displaying score 2
		Text score2;
		score2.setFont(score_font);
		score2.setPosition(600, 880);
		score2.setFillColor(Color(0, 0, 0));
		score2.setCharacterSize(50);
		string score2_string;





		//Displaying score 3

		Text score3;
		score3.setFont(score_font);
		score3.setPosition(750, 880);
		score3.setFillColor(Color(0, 0, 0));
		score3.setCharacterSize(50);
		string score3_string;


		//Displaying score 4
		Text score4;
		score4.setFont(score_font);
		score4.setPosition(900, 880);
		score4.setFillColor(Color(0, 0, 0));
		score4.setCharacterSize(50);
		string score4_string;


		Text dice;
		dice.setFont(score_font);
		dice.setPosition(300, 880);
		dice.setFillColor(Color(0, 0, 0));
		dice.setCharacterSize(50);
		string dice_string;


		//Timer
		Clock clock;
		Time compare;
		int a = 0;

		string timer;

		Text t;
		t.setFont(score_font);


		int greatercheck = 0;


		srand(time(0));


		while (game_window.isOpen())
		{
			Event click;
			while (game_window.pollEvent(click))
			{
				switch (click.type)
				{
				case Event::Closed:
				{
					game_window.close();
					break;
				}

				case Event::MouseButtonPressed:
				{
					flag = 1;
					break;
				}

				}
			}
			compare = clock.getElapsedTime();
			system("CLS");
			cout << compare.asSeconds() << endl;


			x = 0;
			y = 0;
			mousepos = Mouse::getPosition(game_window);
			while (flag == 1 && player == 1)
			{


				greatercheck = 0;


				//If statement to check if mouse position lies in gloabal bounds

				if (dice_button.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
				{
					random = rand() % 6 + 1;
					dice_string = to_string(random);
					dice.setString(dice_string);
					if (score_p1 + random > 100)
					{
						greatercheck = 1;
					}
					score_p1 = score_p1 + random;

					if (greatercheck == 0)
					{

						if (score_p1 >= 1 && score_p1 <= 10)
						{
							//Ladders

							if (score_p1 == 1)
							{
								score_p1 = 38;
							}
							else
								if (score_p1 == 4)
								{
									score_p1 = 14;
								}
								else
									if (score_p1 == 9)
									{
										score_p1 = 31;
									}
									else
									{
									snake7:
										x = (x + 85) * score_p1;
										y = 0;
										blue.setPosition(x, y);
										player = 2;
									}
						}


						if (score_p1 >= 11 && score_p1 <= 20)
						{

							//Snakes
							if (score_p1 == 17)
							{
								score_p1 = 7;
								goto snake7;
							}
							else
							{
							snake19:
								y = y - 90;
								x = (x + 85) * (20 - score_p1 + 1);
								blue.setPosition(x, y);
								player = 2;
							}
						}


						if (score_p1 >= 21 && score_p1 <= 30)
						{

							if (score_p1 == 21)
							{
								score_p1 = 42;
							}
							else
								if (score_p1 == 28)
								{
									score_p1 = 84;
								}
								else
								{
								snake24:
									y = y - 180;
									x = (x + 85) * (score_p1 - 21 + 1);
									blue.setPosition(x, y);
									player = 2;
								}
						}

						if (score_p1 >= 31 && score_p1 <= 40)
						{
						snake34:
							y = y - 260;
							x = (x + 85) * (40 - score_p1 + 1);
							blue.setPosition(x, y);
							player = 2;
						}

						if (score_p1 >= 41 && score_p1 <= 50)
						{
							y = y - 320;
							x = (x + 85) * (score_p1 - 41 + 1);
							blue.setPosition(x, y);
							player = 2;
						}
						if (score_p1 >= 51 && score_p1 <= 60)
						{
							if (score_p1 == 54)
							{
								score_p1 = 34;
								goto snake34;
							}
							else
								if (score_p1 == 51)
								{
									score_p1 = 67;
								}
								else
								{
								snake60:
									y = y - 400;
									x = (x + 85) * (60 - score_p1 + 1);
									blue.setPosition(x, y);
									player = 2;
								}
						}
						if (score_p1 >= 61 && score_p1 <= 70)
						{
							if (score_p1 == 64)
							{

								score_p1 = 60;
								goto snake60;
							}
							else if (score_p1 == 62)
							{
								score_p1 = 19;
								goto snake19;
							}
							else
							{
								y = y - 480;
								x = (x + 85) * (score_p1 - 61 + 1);
								blue.setPosition(x, y);
								player = 2;
							}
						}
						if (score_p1 >= 71 && score_p1 <= 80)
						{
							if (score_p1 == 71)
							{
								score_p1 = 91;
							}
							else
								if (score_p1 == 80)
								{
									score_p1 = 100;
								}
								else
								{
								snake73:
								snake75:
								snake79:
									y = y - 550;
									x = (x + 85) * (80 - score_p1 + 1);
									blue.setPosition(x, y);
									player = 2;
								}
						}
						if (score_p1 >= 81 && score_p1 <= 90)
						{
							if (score_p1 == 87)
							{

								score_p1 = 24;
								goto snake24;
							}
							else
							{
								y = y - 640;
								x = (x + 85) * (score_p1 - 81 + 1);
								blue.setPosition(x, y);
								player = 2;
							}
						}
						if (score_p1 >= 91 && score_p1 <= 100)
						{
							if (score_p1 == 93)
							{
								score_p1 = 73;
								goto snake73;
							}
							else if (score_p1 == 95)
							{
								score_p1 = 75;
								goto snake75;
							}
							else if (score_p1 == 98)
							{
								score_p1 = 79;
								goto snake79;
							}
							y = y - 710;
							x = (x + 85) * (100 - score_p1 + 1);
							blue.setPosition(x, y);
							player = 2;
						}

						score1_string = to_string(score_p1);
						score.setString(score1_string);

						blue.setTexture(blue_texture);
						flag = 0;
						if (score_p1 == 100)
						{
							win = 1;
						}
					}
				}
			}
			if (win == 1)
			{
				current_scores.push_back(score_p2);
				current_scores.push_back(score_p2);
				current_scores.push_back(score_p3);
				current_scores.push_back(score_p4);
				game_window.close();
				score1 = score_p1;
				blue_win();

			}


			while (flag == 1 && player == 2)
			{
				greatercheck = 0;
				if (player == 2)
				{
					y = 0;
					x = 0;

					//If statement to check if mouse position lies in gloabal bounds

					if (dice_button.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
					{
						random = rand() % 6 + 1;
						dice_string = to_string(random);
						dice.setString(dice_string);
						if (score_p2 + random > 100)
						{
							greatercheck = 1;
						}
						score_p2 = score_p2 + random;


						if (greatercheck == 0)
						{



							if (score_p2 >= 1 && score_p2 <= 10)
							{

								if (score_p2 == 1)
								{
									score_p2 = 38;
								}
								else if (score_p2 == 4)
								{
									score_p2 = 14;
								}
								else if (score_p2 == 9)
								{
									score_p2 = 31;
								}
								else
								{
								snake7p2:
									x = (x + 85) * score_p2;
									y = 0;
									green.setPosition(x, y);
									player = 3;
								}
							}


							if (score_p2 >= 11 && score_p2 <= 20)
							{
								if (score_p2 == 17)
								{
									score_p2 = 7;
									goto snake7p2;
								}
								else
								{
								snake19p2:
									y = y - 90;
									x = (x + 85) * (20 - score_p2 + 1);
									green.setPosition(x, y);
									player = 3;
								}
							}


							if (score_p2 >= 21 && score_p2 <= 30)
							{
								if (score_p2 == 21)
								{
									score_p2 = 42;
								}
								else if (score_p2 == 28)
								{
									score_p2 = 84;
								}
								else
								{
								snake24p2:
									y = y - 180;
									x = (x + 85) * (score_p2 - 21 + 1);
									green.setPosition(x, y);
									player = 3;
								}
							}

							if (score_p2 >= 31 && score_p2 <= 40)
							{
							snake34p2:
								y = y - 260;
								x = (x + 85) * (40 - score_p2 + 1);
								green.setPosition(x, y);
								player = 3;
							}

							if (score_p2 >= 41 && score_p2 <= 50)
							{
								y = y - 320;
								x = (x + 85) * (score_p2 - 41 + 1);
								green.setPosition(x, y);
								player = 3;
							}
							if (score_p2 >= 51 && score_p2 <= 60)
							{
								if (score_p2 == 51)
								{
									score_p2 = 67;
								}
								else
									if (score_p2 == 54)
									{
										score_p2 = 34;
										goto snake34p2;

									}

									else
									{
									snake60p2:
										y = y - 400;
										x = (x + 85) * (60 - score_p2 + 1);
										green.setPosition(x, y);
										player = 3;
									}
							}
							if (score_p2 >= 61 && score_p2 <= 70)
							{
								if (score_p2 == 64)
								{
									score_p2 = 60;
									goto snake60p2;

								}
								else if (score_p2 == 62)
								{
									score_p2 = 19;
									goto snake19p2;


								}
								else
								{
									y = y - 480;
									x = (x + 85) * (score_p2 - 61 + 1);
									green.setPosition(x, y);
									player = 3;
								}
							}
							if (score_p2 >= 71 && score_p2 <= 80)
							{
								if (score_p2 == 71)
								{
									score_p2 = 91;
								}
								else
									if (score_p2 == 80)
									{
										score_p2 = 100;
									}
									else
									{
									snake73p2:
									snake75p2:
									snake79p2:
										y = y - 550;
										x = (x + 85) * (80 - score_p2 + 1);
										green.setPosition(x, y);
										player = 3;
									}
							}
							if (score_p2 >= 81 && score_p2 <= 90)
							{
								if (score_p2 == 87)
								{
									score_p2 = 24;
									goto snake24p2;
								}
								else
								{

									y = y - 640;
									x = (x + 85) * (score_p2 - 81 + 1);
									green.setPosition(x, y);
									player = 3;
								}
							}
							if (score_p2 >= 91 && score_p2 <= 100)
							{
								if (score_p2 == 93)
								{
									score_p2 = 73;
									goto snake73p2;
								}
								else if (score_p2 == 95)
								{
									score_p2 = 75;
									goto snake75p2;
								}
								else if (score_p2 == 98)
								{
									score_p2 = 75;
									goto snake79p2;
								}
								else
								{
									y = y - 710;
									x = (x + 85) * (100 - score_p2 + 1);
									green.setPosition(x, y);
									player = 3;
								}
							}
							if (score_p2 == 100)
							{
								win1 = 1;
							}
							score2_string = to_string(score_p2);
							score2.setString(score2_string);

							green.setTexture(green_texture);
							flag = 0;
						}

						if (win1 == 1)
						{
							current_scores.push_back(score_p2);
							current_scores.push_back(score_p2);
							current_scores.push_back(score_p3);
							current_scores.push_back(score_p4);
							game_window.close();
							score1 = score_p2;
							green_win();

						}
					}
				}
			}







			while (flag == 1 && player == 3)
			{
				greatercheck = 0;

				if (player == 3)
				{
					y = 0;
					x = 0;

					//If statement to check if mouse position lies in gloabal bounds

					if (dice_button.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
					{
						random = rand() % 6 + 1;
						dice_string = to_string(random);
						dice.setString(dice_string);
						if (score_p3 + random > 100)
						{
							greatercheck = 1;
						}
						score_p3 = score_p3 + random;


						if (greatercheck == 0)
						{

							if (score_p3 >= 1 && score_p3 <= 10)
							{

								if (score_p3 == 1)
								{
									score_p3 = 38;
								}
								else if (score_p3 == 4)
								{
									score_p3 = 14;
								}
								else if (score_p3 == 9)
								{
									score_p3 = 31;
								}
								else
								{
								snake7p3:
									x = (x + 85) * score_p3;
									y = 0;
									yellow.setPosition(x, y);
									player = 4;
								}
							}


							if (score_p3 >= 11 && score_p3 <= 20)
							{
								if (score_p3 == 17)
								{
									score_p3 = 7;
									goto snake7p3;
								}
								else
								{
								snake19p3:
									y = y - 90;
									x = (x + 85) * (20 - score_p3 + 1);
									yellow.setPosition(x, y);
									player = 4;
								}
							}


							if (score_p3 >= 21 && score_p3 <= 30)
							{
								if (score_p3 == 21)
								{
									score_p3 = 42;
								}
								else if (score_p3 == 28)
								{
									score_p3 = 84;
								}
								else
								{
								snake24p3:
									y = y - 180;
									x = (x + 85) * (score_p3 - 21 + 1);
									yellow.setPosition(x, y);
									player = 4;
								}
							}

							if (score_p3 >= 31 && score_p3 <= 40)
							{
							snake34p3:
								y = y - 260;
								x = (x + 85) * (40 - score_p3 + 1);
								yellow.setPosition(x, y);
								player = 4;
							}

							if (score_p3 >= 41 && score_p3 <= 50)
							{
								y = y - 320;
								x = (x + 85) * (score_p3 - 41 + 1);
								yellow.setPosition(x, y);
								player = 4;
							}
							if (score_p3 >= 51 && score_p3 <= 60)
							{
								if (score_p3 == 51)
								{
									score_p3 = 67;
								}
								else
									if (score_p3 == 54)
									{
										score_p3 = 34;
										goto snake34p3;

									}

									else
									{
									snake60p3:
										y = y - 400;
										x = (x + 85) * (60 - score_p3 + 1);
										yellow.setPosition(x, y);
										player = 4;
									}
							}
							if (score_p3 >= 61 && score_p3 <= 70)
							{
								if (score_p3 == 64)
								{
									score_p3 = 60;
									goto snake60p3;

								}
								else if (score_p3 == 62)
								{
									score_p3 = 19;
									goto snake19p3;


								}
								else
								{
									y = y - 480;
									x = (x + 85) * (score_p3 - 61 + 1);
									yellow.setPosition(x, y);
									player = 4;
								}
							}
							if (score_p3 >= 71 && score_p3 <= 80)
							{
								if (score_p3 == 71)
								{
									score_p3 = 91;
								}
								else
									if (score_p3 == 80)
									{
										score_p3 = 100;
									}
									else
									{
									snake73p3:
									snake75p3:
									snake79p3:
										y = y - 550;
										x = (x + 85) * (80 - score_p3 + 1);
										yellow.setPosition(x, y);
										player = 4;
									}
							}
							if (score_p3 >= 81 && score_p3 <= 90)
							{
								if (score_p3 == 87)
								{
									score_p3 = 24;
									goto snake24p3;
								}
								else
								{

									y = y - 640;
									x = (x + 85) * (score_p3 - 81 + 1);
									yellow.setPosition(x, y);
									player = 4;
								}
							}
							if (score_p3 >= 91 && score_p3 <= 100)
							{
								if (score_p3 == 93)
								{
									score_p3 = 73;
									goto snake73p3;
								}
								else if (score_p3 == 95)
								{
									score_p3 = 75;
									goto snake75p3;
								}
								else if (score_p3 == 98)
								{
									score_p3 = 75;
									goto snake79p3;
								}
								else
								{
									y = y - 710;
									x = (x + 85) * (100 - score_p3 + 1);
									yellow.setPosition(x, y);
									player = 4;
								}
							}
							if (score_p2 == 100)
							{
								win2 = 1;
							}
							score3_string = to_string(score_p3);
							score3.setString(score3_string);

							yellow.setTexture(yellow_texture);
							flag = 0;
						}

						if (win2 == 1)
						{
							current_scores.push_back(score_p2);
							current_scores.push_back(score_p2);
							current_scores.push_back(score_p3);
							current_scores.push_back(score_p4);
							game_window.close();
							score1 = score_p3;
							yellow_win();

						}
					}
				}
			}




			while (flag == 1 && player == 4)
			{
				greatercheck = 0;

				if (player == 4)
				{
					y = 0;
					x = 0;

					//If statement to check if mouse position lies in gloabal bounds

					if (dice_button.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
					{
						random = rand() % 6 + 1;
						dice_string = to_string(random);
						dice.setString(dice_string);
						if (score_p4 + random > 100)
						{
							greatercheck = 1;
						}
						score_p4 = score_p4 + random;


						if (greatercheck == 0)
						{

							if (score_p4 >= 1 && score_p4 <= 10)
							{

								if (score_p4 == 1)
								{
									score_p4 = 38;
								}
								else if (score_p4 == 4)
								{
									score_p4 = 14;
								}
								else if (score_p4 == 9)
								{
									score_p4 = 31;
								}
								else
								{
								snake7p4:
									x = (x + 85) * score_p4;
									y = 0;
									purple.setPosition(x, y);
									player = 1;
								}
							}


							if (score_p4 >= 11 && score_p4 <= 20)
							{
								if (score_p4 == 17)
								{
									score_p3 = 7;
									goto snake7p4;
								}
								else
								{
								snake19p4:
									y = y - 90;
									x = (x + 85) * (20 - score_p4 + 1);
									purple.setPosition(x, y);
									player = 1;
								}
							}


							if (score_p4 >= 21 && score_p4 <= 30)
							{
								if (score_p4 == 21)
								{
									score_p4 = 42;
								}
								else if (score_p4 == 28)
								{
									score_p4 = 84;
								}
								else
								{
								snake24p4:
									y = y - 180;
									x = (x + 85) * (score_p4 - 21 + 1);
									purple.setPosition(x, y);
									player = 1;
								}
							}

							if (score_p4 >= 31 && score_p4 <= 40)
							{
							snake34p4:
								y = y - 260;
								x = (x + 85) * (40 - score_p4 + 1);
								purple.setPosition(x, y);
								player = 1;
							}

							if (score_p4 >= 41 && score_p4 <= 50)
							{
								y = y - 320;
								x = (x + 85) * (score_p4 - 41 + 1);
								purple.setPosition(x, y);
								player = 1;
							}
							if (score_p4 >= 51 && score_p4 <= 60)
							{
								if (score_p4 == 51)
								{
									score_p4 = 67;
								}
								else
									if (score_p4 == 54)
									{
										score_p4 = 34;
										goto snake34p4;

									}

									else
									{
									snake60p4:
										y = y - 400;
										x = (x + 85) * (60 - score_p4 + 1);
										purple.setPosition(x, y);
										player = 1;
									}
							}
							if (score_p4 >= 61 && score_p4 <= 70)
							{
								if (score_p4 == 64)
								{
									score_p4 = 60;
									goto snake60p4;

								}
								else if (score_p4 == 62)
								{
									score_p4 = 19;
									goto snake19p4;


								}
								else
								{
									y = y - 480;
									x = (x + 85) * (score_p4 - 61 + 1);
									purple.setPosition(x, y);
									player = 1;
								}
							}
							if (score_p4 >= 71 && score_p4 <= 80)
							{
								if (score_p4 == 71)
								{
									score_p4 = 91;
								}
								else
									if (score_p4 == 80)
									{
										score_p4 = 100;
									}
									else
									{
									snake73p4:
									snake75p4:
									snake79p4:
										y = y - 550;
										x = (x + 85) * (80 - score_p4 + 1);
										purple.setPosition(x, y);
										player = 1;
									}
							}
							if (score_p4 >= 81 && score_p4 <= 90)
							{
								if (score_p4 == 87)
								{
									score_p4 = 24;
									goto snake24p4;
								}
								else
								{

									y = y - 640;
									x = (x + 85) * (score_p4 - 81 + 1);
									purple.setPosition(x, y);
									player = 1;
								}
							}
							if (score_p4 >= 91 && score_p4 <= 100)
							{
								if (score_p4 == 93)
								{
									score_p4 = 73;
									goto snake73p4;
								}
								else if (score_p4 == 95)
								{
									score_p4 = 75;
									goto snake75p4;
								}
								else if (score_p4 == 98)
								{
									score_p4 = 75;
									goto snake79p4;
								}
								else
								{
									y = y - 710;
									x = (x + 85) * (100 - score_p4 + 1);
									purple.setPosition(x, y);
									player = 1;
								}
							}
							if (score_p4 == 100)
							{
								win3 = 1;
							}
							score4_string = to_string(score_p4);
							score4.setString(score4_string);

							purple.setTexture(purple_texture);
							flag = 0;
						}

						if (win3 == 1)
						{
							current_scores.push_back(score_p2);
							current_scores.push_back(score_p2);
							current_scores.push_back(score_p3);
							current_scores.push_back(score_p4);
							game_window.close();
							score1 = score_p4;
							purple_win();

						}
					}
				}
			}


			game_window.draw(board);
			game_window.draw(blue);
			game_window.draw(green);
			game_window.draw(yellow);
			game_window.draw(purple);
			game_window.draw(score);
			game_window.draw(score2);
			game_window.draw(score3);
			game_window.draw(score4);
			game_window.draw(dice);
			game_window.display();
		}


	}
}