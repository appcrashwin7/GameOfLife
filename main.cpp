#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "gameOfLife.hpp"

gameOflife gmOflife;

sf::Vector3f pos = { -10,-10,-40 };

void drawCells()
{
	for (size_t x = 0; x < xSize; x++)
	{
		for (size_t y = 0; y < ySize; y++)
		{
			for (size_t z = 0; z < zSize; z++)
			{
				if (gmOflife.getCellinfo(x,y,z) == true)
				{
					glLoadIdentity();

					glTranslatef(pos.x, pos.y, pos.z);
					glTranslatef(1 * x, 1 * y, 1 * z);
					glDrawArrays(GL_QUADS, 0, 24);
				}
			}
		}
	}
}

void main()
{
	gmOflife.initialize();

	sf::ContextSettings openGlSet;
	openGlSet.antialiasingLevel = 0;
	openGlSet.majorVersion = 4;
	openGlSet.minorVersion = 3;
	openGlSet.depthBits = 24;

	sf::RenderWindow window(sf::VideoMode(1280, 1024), "Game of life 3d", sf::Style::Fullscreen, openGlSet);
	window.setFramerateLimit(10);
	
	sf::Clock clock;

	GLfloat cube[] = {
	0, 0, 0,
	0, 0, -1,
	-1, 0, -1,
	-1, 0, 0,

	0, 0, -1,
	0, -1, -1,
	-1, -1, -1,
	-1, 0, -1,

	0, -1, -1,
	0, -1, 0,
	-1, -1, 0,
	-1, -1, -1,

	0, 0, 0,
	0, -1, 0,
	-1, -1, 0,
	-1, 0, 0,

	0, 0, -1,
	0, -1, -1,
	0, -1, 0,
	0, 0, 0,

	-1, 0, -1,
	-1, -1, -1,
	-1, -1, 0,
	-1, 0, 0,
	};

	glEnable(GL_DEPTH_TEST);
	glDepthMask(true);
	glClearDepth(1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat ratio = static_cast<float>(window.getSize().x / window.getSize().y);
	glFrustum(-ratio, ratio, -1, 1, 1, 600);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,3*sizeof(GLfloat),cube);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Resized)
			{
				glViewport(0, 0, window.getSize().x, window.getSize().y);
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			pos.x += 0.1f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			pos.x -= 0.1f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			pos.z += 0.1f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			pos.z -= 0.1f;
		}

		gmOflife.checkCells();

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glColor3f(1, 0, 0);
		drawCells();

		window.display();
	}

	return;
}