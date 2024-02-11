// Sudoku solver.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Grid.h"
#include "sudoku_solver.h"
#include "sudoku_validator.h"
#include "Keypad.h"
#include "SFML/Graphics.hpp"

class Inter_grid {
public:
    std::vector<Input_Button> butt1;
    std::vector<Input_Button> butt2;
    std::vector<Input_Button> butt3;
    std::vector<Input_Button> butt4;
    std::vector<Input_Button> butt5;
    std::vector<Input_Button> butt6;
    std::vector<Input_Button> butt7;
    std::vector<Input_Button> butt8;
    std::vector<Input_Button> butt9;
    Inter_grid() 
    {
        butt1.resize(9);
		butt2.resize(9);
		butt3.resize(9);
		butt4.resize(9);
		butt5.resize(9);
		butt6.resize(9);
		butt7.resize(9);
		butt8.resize(9);
        butt9.resize(9);
        for (int i = 0; i < 9; i++)
        {
            butt1[i].setPos(i * 100 + 100, 200);
            butt2[i].setPos(i * 100 + 100, 300);
            butt3[i].setPos(i * 100 + 100, 400);
            butt4[i].setPos(i * 100 + 100, 500);
            butt5[i].setPos(i * 100 + 100, 600);
            butt6[i].setPos(i * 100 + 100, 700);
            butt7[i].setPos(i * 100 + 100, 800);
            butt8[i].setPos(i * 100 + 100, 900);
            butt9[i].setPos(i * 100 + 100, 1000);

			butt1[i].setCoord(0, i);
            butt2[i].setCoord(1, i);
            butt3[i].setCoord(2, i);
            butt4[i].setCoord(3, i);
            butt5[i].setCoord(4, i);
            butt6[i].setCoord(5, i);
            butt7[i].setCoord(6, i);
            butt8[i].setCoord(7, i);
            butt9[i].setCoord(8, i);
            
        }
    }
    void print(RenderWindow& win)
    {
        for (int i = 0; i < 9; i++) {
			
            butt1[i].printButton(win);
            butt2[i].printButton(win);
            butt3[i].printButton(win);
            butt4[i].printButton(win);
            butt5[i].printButton(win);
            butt6[i].printButton(win);
            butt7[i].printButton(win);
            butt8[i].printButton(win);
            butt9[i].printButton(win);

        }
    }
    std::vector<Input_Button> operator[](int i)
    {
        if (i == 0) {
			return butt1;
        }
        if (i == 1) {
            return butt2;
        }
        if (i == 2) {
            return butt3;
        }
        if (i == 3) {
            return butt4;
        }
        if (i == 4) {
            return butt5;
        }
        if (i == 5) {
            return butt6;
        }
        if (i == 6) {
            return butt7;
        }
        if (i == 7) {
            return butt8;
        }
        if (i == 8) {
            return butt9;
        }
        

    }
};
void event_cheker(std::vector<std::vector<Input_Button>>& butt, sf::Event& event, sudoku::Grid& grid, int cont, RenderWindow& win) {
    for (int i = 0; i<9;i++)
    {
        for (int j = 0; j < 9; j++)
        {
			butt[i][j].mousePresBut(win, event, cont, grid);
        }
        /*butt[i].mousePresBut(win, event, cont, grid);*/
        
    }
    /*for (int i = 0; i < 9; i++)
    {
        butt[1][i].mousePresBut(win, event, cont, grid);
		butt[2][i].mousePresBut(win, event, cont, grid);
        butt[3][i].mousePresBut(win, event, cont, grid);
        butt[4][i].mousePresBut(win, event, cont, grid);
        butt[5][i].mousePresBut(win, event, cont, grid);
        butt[6][i].mousePresBut(win, event, cont, grid);
        butt[7][i].mousePresBut(win, event, cont, grid);
        butt[8][i].mousePresBut(win, event, cont, grid);
        butt[0][i].mousePresBut(win, event, cont, grid);
    }*/
    
    
}
int main()
{
    sudoku::Grid grid({ {
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }},
       {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }}
   } });

    //sudoku::solve(&grid);

    //std::cout << "Solution is valid? --> ";
    //std::cout << sudoku::is_valid_solution(grid) << std::endl;

    //std::cout << grid << std::endl;

    int c = 0;

	
    Button button1(100, 100, 100, 50, sf::Color::Blue, "1");
    button1.setText("1", 1);
    Button button2(200, 100, 100, 50, sf::Color::Blue, "1");
    button2.setText("2", 2);
    Button button3(300, 100, 100, 50, sf::Color::Blue, "1");
    button3.setText("3", 3);
    Button button4(400, 100, 100, 50, sf::Color::Blue, "1");
    button4.setText("4", 4);
    Button button5(500, 100, 100, 50, sf::Color::Blue, "1");
    button5.setText("5", 5);
    Button button6(600, 100, 100, 50, sf::Color::Blue, "1");
    button6.setText("6", 6);
    Button button7(700, 100, 100, 50, sf::Color::Blue, "1");
    button7.setText("7", 7);
    Button button8(800, 100, 100, 50, sf::Color::Blue, "1");
    button8.setText("8", 8);
    Button button9(900, 100, 100, 50, sf::Color::Blue, "1");
    button9.setText("9", 9);


    /*Input_Button butt_test(100, 200, 50, 50, sf::Color::White, "");
    butt_test.setCoord(0, 0);*/

    std::vector<std::vector<Input_Button>> butt_massive(9, std::vector<Input_Button>(9));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
			butt_massive[j][i].setCoord(i, j);
            butt_massive[i][j].setPos(i * 100 + 100, j * 100 + 200);
        }
            
    }


	/*std::vector<Input_Button> butt_massive(9);
    for (int i = 0; i < 9; i++)
    {
		butt_massive[i].setCoord(0,i);
        butt_massive[i].setPos(i * 100 + 100, 200);
    }*/

	Inter_grid intergrid;

    sf::RenderWindow win(sf::VideoMode(1100, 1100), "Calc");
    sf::Event event;
    win.setFramerateLimit(120);
    while (win.isOpen())
    {
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)win.close();
            
            button1.mousePresBut(win, event, c);
            button2.mousePresBut(win, event, c);
            button3.mousePresBut(win, event, c);
            button4.mousePresBut(win, event, c);
            button5.mousePresBut(win, event, c);
            button6.mousePresBut(win, event, c);
            button7.mousePresBut(win, event, c);
            button8.mousePresBut(win, event, c);
            button9.mousePresBut(win, event, c);
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    butt_massive[i][j].mousePresBut(win, event, c, grid);
                }

            }
            
            
			/*butt_test.mousePresBut(win, event, c, grid);*/
			
        }
        win.clear();
        button1.printButton(win);
        button2.printButton(win); 
        button3.printButton(win);
        button4.printButton(win);
        button5.printButton(win);
        button6.printButton(win);
        button7.printButton(win);
        button8.printButton(win);
        button9.printButton(win);
		/*intergrid.print(win);*/
        /*for (int i = 0; i < 9; i++)
        {
			butt_massive[i].printButton(win);
        }*/
        /*win.draw(butt_massive[0][0].butt);
		win.draw(butt_massive[0][0].txt);*/
        /*for (int i = 0; i < 9; i++) {
            for (auto j : butt_massive[i]) {
                j.printButton(win);
            }
        }*/
		
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
				butt_massive[i][j].printButton(win);
            }
        }

		win.display();


    }



}




