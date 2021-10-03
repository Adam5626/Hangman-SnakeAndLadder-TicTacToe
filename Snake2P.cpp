#include "snake2p.h"
#include "timer.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <SFML/Audio.hpp>


using namespace std;

extern time_t play_time;
extern vector <int> current_scores;

namespace Snake2p
{
	time_t start_time;

	using namespace sf;
	using namespace std;


	void instructions();
	void game_menu();
	void blue_win();
	void green_win();
	void game_win();

	int score1 = 0;
	int score_p1 = 0;
	int score_p2 = 0;

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




		
		int store = 0;
		int end_row1 = 10;
		int end_row2 = 11;
		int check = 0;
		int flag = 0;
		int check1 = 0;
		int win = 0;
		int win1 = 0;
		//Main game board
		Sprite board;
		Texture bg_board;
		bg_board.loadFromFile("board.jpg");
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
		score.setPosition(615, 880);
		score.setFillColor(Color(0, 0, 0));
		score.setCharacterSize(50);
		string score1_string;

		//Displaying score 2
		Text score2;
		score2.setFont(score_font);
		score2.setPosition(878, 880);
		score2.setFillColor(Color(0, 0, 0));
		score2.setCharacterSize(50);
		string score2_string;


		Text dice;
		dice.setFont(score_font);
		dice.setPosition(350, 880);
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
			cout << compare.asSeconds() << endl;



			x = 0;
			y = 0;
			mousepos = Mouse::getPosition(game_window);
			while (flag == 1 && player == 1)
			{



				if (dice_button.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
				{
					random = rand() % 6 + 1;
					dice_string = to_string(random);
					dice.setString(dice_string);
					while (score_p1 + random > 100)
					{
						random = rand() % 6 + 1;
					}
					score_p1 = score_p1 + random;



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
			if (win == 1)
			{

				game_window.close();
				current_scores.push_back(score_p1);
				current_scores.push_back(score_p2);
				blue_win();

			}


			while (flag == 1 && player == 2)
			{
				if (player == 2)
				{
					y = 0;
					x = 0;
					if (dice_button.getGlobalBounds().contains(static_cast<Vector2f>(mousepos)) && Mouse::isButtonPressed(Mouse::Left))
					{
						random = rand() % 6 + 1;
						dice_string = to_string(random);
						dice.setString(dice_string);
						while (score_p2 + random > 100)
						{
							random = rand() % 6 + 1;
						}
						score_p2 = score_p2 + random;




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
								player = 1;
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
								player = 1;
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
								player = 1;
							}
						}

						if (score_p2 >= 31 && score_p2 <= 40)
						{
						snake34p2:
							y = y - 260;
							x = (x + 85) * (40 - score_p2 + 1);
							green.setPosition(x, y);
							player = 1;
						}

						if (score_p2 >= 41 && score_p2 <= 50)
						{
							y = y - 320;
							x = (x + 85) * (score_p2 - 41 + 1);
							green.setPosition(x, y);
							player = 1;
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
									player = 1;
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
								player = 1;
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
									player = 1;
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
								player = 1;
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
								player = 1;
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
						current_scores.push_back(score_p1);
						current_scores.push_back(score_p2);
						game_window.close();
						green_win();

					}
				}
			}

			


			game_window.draw(board);
			game_window.draw(blue);
			game_window.draw(green);
			game_window.draw(score);
			game_window.draw(score2);
			game_window.draw(dice);
			game_window.draw(t);
			game_window.display();
		}


	}
}