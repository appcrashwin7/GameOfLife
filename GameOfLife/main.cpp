#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

const size_t cellsX = 1280 / 10;
const size_t cellsY = 1020 / 10;

sf::RenderWindow window;
sf::RectangleShape cell;
bool cells[cellsX][cellsY] = {false};

void drawCells()
{
	for (size_t x = 0; x < cellsX; x++)
	{
		for (size_t y = 0; y < cellsY; y++)
		{
			if (cells[x][y] == true)
			{
				cell.setPosition(sf::Vector2f(x * 10, y * 10));
				window.draw(cell);
			}
		}
	}
}

void initialize()
{
	for (size_t x = 20; x < 30; x++)
	{
		for (size_t y = 20; y < 31; y++)
		{
			cells[x][y] = true;
		}
	}

	return;
}

void checkCeller(size_t x,size_t y, int &var)
{
	if (cells[x][y] == true)
	{
		var++;
	}
}

int howManyNeighbours(size_t x, size_t y)
{
	int neighb = 0;
	if (x == 0 && y == 0)
	{
		checkCeller(x + 1, y, neighb);
		checkCeller(x + 1, y + 1, neighb);
		checkCeller(x, y + 1, neighb);

		return neighb;
	}
	else if (x == (cellsX-1)&& y == 0)
	{
		checkCeller(x-1, y, neighb);
		checkCeller(x - 1, y + 1, neighb);
		checkCeller(x, y + 1, neighb);

		return neighb;
	}
	else if(x == 0 && y == (cellsY - 1))
	{
		checkCeller(x, y - 1, neighb);
		checkCeller(x + 1, y - 1, neighb);
		checkCeller(x + 1, y, neighb);

		return neighb;
	}
	else if (x == 0)
	{
		checkCeller(x, y - 1, neighb);
		checkCeller(x, y + 1,neighb);

		for (size_t iy = y - 1; iy < y + 2; iy++)
		{
			checkCeller(x + 1, iy, neighb);
		}

		return neighb;
	}
	else if (y == 0)
	{
		checkCeller(x - 1, y, neighb);
		checkCeller(x + 1, y, neighb);

		for (size_t ix = x - 1; ix < x + 2; ix++)
		{
			checkCeller(ix, y + 1, neighb);
		}
		return neighb;
	}

	
	if (x == (cellsX - 1) && y == (cellsY - 1))
	{
		checkCeller(x - 1, y, neighb);
		checkCeller(x - 1, y - 1, neighb);
		checkCeller(x, y - 1, neighb);

		return neighb;
	}
	else if(x == (cellsX - 1))
	{
		checkCeller(x, y - 1, neighb);
		checkCeller(x, y + 1, neighb);

		for (size_t iy = y - 1; iy < y + 2; iy++)
		{
			checkCeller(x - 1, iy, neighb);
		}
		return neighb;
	}
	else if(y == (cellsY - 1))
	{
		checkCeller(x - 1, y, neighb);
		checkCeller(x + 1, y, neighb);

		for (size_t ix = x - 1; ix < x + 2; ix++)
		{
			checkCeller(ix, y - 1, neighb);
		}
		return neighb;
	}

	//normal check
	for (size_t ix = x - 1; ix < x + 2; ix++)
	{
		checkCeller(ix, y - 1, neighb);//DOWN
	}
	for (size_t ix = x - 1; ix < x + 2; ix++)
	{
		checkCeller(ix, y + 1, neighb);//UP
	}
	checkCeller(x - 1, y, neighb);
	checkCeller(x + 1, y, neighb);

	return neighb;
}

void checkCell(size_t x, size_t y)
{
	int neighbours = howManyNeighbours(x, y);

	if (cells[x][y] == false)
	{
		if (neighbours == 3)
		{
			cells[x][y] = true;
		}
		return;
	}
	else
	{
		if (neighbours > 3)
		{
			cells[x][y] = false;
			return;
		}
		else if(neighbours < 4 && neighbours > 1)
		{
			cells[x][y] = true;
			return;
		}
		else if(neighbours <= 1)
		{
			cells[x][y] = false;
			return;
		}
	}
	return;
}


void checkCells()
{
	for (size_t x = 0; x < cellsX; x++)
	{
		for (size_t y = 0; y < cellsY; y++)
		{
			checkCell(x, y);
		}
	}
}
int main()
{
	cell.setFillColor(sf::Color::Red);
	cell.setSize(sf::Vector2f(10, 10));
	window.create(sf::VideoMode(1280, 1024), "Game Of Life",sf::Style::Fullscreen);
	window.setFramerateLimit(10);
	
	initialize();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == true)
		{
			return EXIT_SUCCESS;
		}
		window.clear();
		drawCells();
		window.display();

		//Sleep(5000);
		checkCells();
	}

	return EXIT_SUCCESS;
}