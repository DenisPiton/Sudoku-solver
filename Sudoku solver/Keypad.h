#pragma once
#include <iostream>
#include "sfml/Graphics.hpp"
#include "coord.h"
#include "grid.h" 
using namespace sf;
class Button {
	Font font;
	RectangleShape butt;
	Text txt;
	Color color1;
	Color color2 = Color::Blue;
	Color color3 = Color::Green;

public:
	int value;
	Button(int x, int y, int width, int height, Color color, String text)
	{
		butt.setPosition(x, y);
		butt.setSize(Vector2f(width, height));
		color1 = color;
		butt.setFillColor(color1);
		txt.setString(text);
		txt.setPosition(x, y);
		txt.setFillColor(Color::White);
		txt.setCharacterSize(20);
		font.loadFromFile("Font.otf");
		txt.setFont(font);

	}
	Button() {
		butt.setSize(Vector2f(100, 50));
		color1 = Color::Blue;
		butt.setFillColor(color1);
		txt.setFillColor(Color::White);
		txt.setCharacterSize(20);
		font.loadFromFile("Font.otf");
		txt.setFont(font);

	}
	void setPos(int x, int y) {
		butt.setPosition(x, y);
		txt.setPosition(x, y);
	}
	void setText(String text, int valuse) {
		txt.setString(text);
		value = valuse;
	}
	void printButton(RenderWindow& win) {
		win.draw(butt);
		win.draw(txt);
	}
	void mousePresBut(RenderWindow& win, Event& event, int& container) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.key.code == Mouse::Left) {
				if (butt.getGlobalBounds().contains(Mouse::getPosition(win).x, Mouse::getPosition(win).y))
				{
					butt.setFillColor(color3);
					container = value;
					std::cout << container;
				}

			}
		}
		else {
			if (butt.getGlobalBounds().contains(Mouse::getPosition(win).x, Mouse::getPosition(win).y))
			{
				butt.setFillColor(color2);
			}
			else {
				butt.setFillColor(color1);
			}
		}

	}
};

class Input_Button {
	Font font;
	
	
	Color color1;
	Color color2 = Color::Blue;
	Color color3 = Color::Green;
	sudoku::Coord coord;


public:
	int value;
	Text txt;
	RectangleShape butt;
	Input_Button(int x, int y, int width, int height, Color color, String text)
	{
		butt.setPosition(x, y);
		butt.setSize(Vector2f(width, height));
		color2 = color;
		butt.setFillColor(color2);
		txt.setString(text);
		txt.setPosition(x, y);
		txt.setFillColor(Color::White);
		txt.setCharacterSize(20);
		font.loadFromFile("Font.otf");
		txt.setFont(font);

	}
	Input_Button() {
		butt.setSize(Vector2f(50, 50));
		color1 = Color::White;
		butt.setFillColor(color1);
		txt.setFillColor(Color::Black);
		txt.setCharacterSize(20);
		font.loadFromFile("Font.otf");
		txt.setFont(font);

	}
	void setCoord(int x, int y) {
		this->coord.first = x;
		this->coord.second = y;
	}

	void setPos(int x, int y) {
		butt.setPosition(x, y);
		txt.setPosition(x, y);
	}
	void setText(String text, int valuse) {
		txt.setString(text);
		value = valuse;
	}
	void printButton(RenderWindow& win) const {
		win.draw(butt);
		win.draw(txt);	
	}
	void mousePresBut(RenderWindow& win, Event& event, int container, sudoku::Grid& grid) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.key.code == Mouse::Left) {
				if (butt.getGlobalBounds().contains(Mouse::getPosition(win).x, Mouse::getPosition(win).y))
				{
					butt.setFillColor(color3);
					value = container;
					std::cout << container;
					txt.setString(std::to_string(value));
					txt.setFillColor(Color::Black);
					grid.update(coord, value);
					std::cout << grid;	
				}

			}
		}
		else {
			if (butt.getGlobalBounds().contains(Mouse::getPosition(win).x, Mouse::getPosition(win).y))
			{
				butt.setFillColor(color1);
			}
			else {
				butt.setFillColor(color2);
			}
		}

	}
};