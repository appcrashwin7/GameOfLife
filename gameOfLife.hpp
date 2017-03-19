#pragma once

const size_t xSize = 12;
const size_t ySize = 12;
const size_t zSize = 12;

class gameOflife
{
public:
	void initialize()
	{
		for (size_t x = 0; x < 10; x++)
		{
			for (size_t y = 0; y < 10; y++)
			{
				for (size_t z = 0; z < 10; z++)
				{
					cells[x][y][z] = true;
				}
			}
		}
	}

	bool getCellinfo(size_t x,size_t y,size_t z)
	{
		return cells[x][y][z];
	}

	void checkCells()
	{
		for (size_t x = 0; x < xSize; x++)
		{
			for (size_t y = 0; y < ySize; y++)
			{
				for (size_t z = 0; z < zSize; z++)
				{
					checkCell(x, y, z);
				}
			}
		}
	}
private:
	bool cells[xSize][ySize][zSize] = { false };

	void checkCell(size_t x, size_t y, size_t z)
	{
		unsigned neighbours = howManyNeighbours(x, y, z);

		if (cells[x][y][z] == false)
		{
			if (neighbours == 3)
			{
				cells[x][y][z] = true;
			}
			return;
		}
		else
		{
			if (neighbours > 1 && neighbours < 4)
			{
				cells[x][y][z] = true;
				return;
			}
			cells[x][y][z] = false;
		}
		return;
	}
	inline void checkCellCondiction(size_t x, size_t y, size_t z, unsigned &var)
	{
		if (cells[x][y][z] == true)
		{
			var += 1;
		}
	}
	unsigned howManyNeighbours(size_t x, size_t y, size_t z)
	{
		unsigned howMany = 0;

		//down corners
		if (x == 0 && y == 0 && z == 0)
		{
			checkCellCondiction(x + 1, 0, 0, howMany);
			checkCellCondiction(x + 1, 0, z + 1, howMany);
			checkCellCondiction(0, 0, z + 1, howMany);

			checkCellCondiction(0, y + 1, 0, howMany);
			checkCellCondiction(x + 1, y + 1, 0, howMany);
			checkCellCondiction(x + 1, y + 1, z + 1, howMany);
			checkCellCondiction(0, y + 1, z + 1, howMany);

			return howMany;
		}
		if (x == (xSize - 1) && y == 0 && z == 0)
		{
			checkCellCondiction(x - 1, 0, 0, howMany);
			checkCellCondiction(x - 1, 0, z + 1, howMany);
			checkCellCondiction(x, 0, z + 1, howMany);

			checkCellCondiction(x, y + 1, 0, howMany);
			checkCellCondiction(x - 1, y + 1, 0, howMany);
			checkCellCondiction(x - 1, y + 1, z + 1, howMany);
			checkCellCondiction(x, y + 1, z + 1, howMany);

			return howMany;
		}
		if (x == (xSize - 1) && y == 0 && z == (zSize - 1))
		{
			checkCellCondiction(x, 0, z - 1, howMany);
			checkCellCondiction(x - 1, 0, z - 1, howMany);
			checkCellCondiction(x - 1, 0, z, howMany);

			checkCellCondiction(x, y + 1, z, howMany);
			checkCellCondiction(x, y + 1, z - 1, howMany);
			checkCellCondiction(x - 1, y + 1, z - 1, howMany);
			checkCellCondiction(x - 1, y + 1, z, howMany);

			return howMany;
		}
		if (x == 0 && y == 0 && z == (zSize - 1))
		{
			checkCellCondiction(0, 0, z - 1, howMany);
			checkCellCondiction(x + 1, 0, z - 1, howMany);
			checkCellCondiction(x + 1, 0, z, howMany);

			checkCellCondiction(0, y + 1, z, howMany);
			checkCellCondiction(0, y + 1, z - 1, howMany);
			checkCellCondiction(x + 1, y + 1, z - 1, howMany);
			checkCellCondiction(x + 1, y + 1, z, howMany);

			return howMany;
		}

		//up corners
		if (x == 0 && y == (ySize - 1) && z == 0)
		{
			checkCellCondiction(x + 1, y, z, howMany);
			checkCellCondiction(x + 1, y, z + 1, howMany);
			checkCellCondiction(x, y, z + 1, howMany);

			checkCellCondiction(x, y - 1, z, howMany);
			checkCellCondiction(x + 1, y - 1, z, howMany);
			checkCellCondiction(x + 1, y - 1, z + 1, howMany);
			checkCellCondiction(x, y - 1, z + 1, howMany);

			return howMany;
		}
		if (x == (xSize - 1) && y == (ySize - 1) && z == 0)
		{
			checkCellCondiction(x - 1, y, z, howMany);
			checkCellCondiction(x - 1, y, z + 1, howMany);
			checkCellCondiction(x, y, z + 1, howMany);

			checkCellCondiction(x, y - 1, z, howMany);
			checkCellCondiction(x - 1, y - 1, z, howMany);
			checkCellCondiction(x - 1, y - 1, z + 1, howMany);
			checkCellCondiction(x, y - 1, z + 1, howMany);

			return howMany;
		}
		if (x == (xSize - 1) && y == (ySize - 1) && z == (zSize - 1))
		{
			checkCellCondiction(x, y, z - 1, howMany);
			checkCellCondiction(x - 1, y, z - 1, howMany);
			checkCellCondiction(x - 1, y, z, howMany);

			checkCellCondiction(x, y - 1, z, howMany);
			checkCellCondiction(x, y - 1, z - 1, howMany);
			checkCellCondiction(x - 1, y - 1, z - 1, howMany);
			checkCellCondiction(x - 1, y - 1, z, howMany);

			return howMany;
		}
		if (x == 0 && y == (ySize - 1) && z == (zSize - 1))
		{
			checkCellCondiction(x, y, z - 1, howMany);
			checkCellCondiction(x + 1, y, z - 1, howMany);
			checkCellCondiction(x + 1, y, z, howMany);

			checkCellCondiction(x, y - 1, z, howMany);
			checkCellCondiction(x, y - 1, z - 1, howMany);
			checkCellCondiction(x + 1, y - 1, z - 1, howMany);
			checkCellCondiction(x + 1, y - 1, z, howMany);

			return howMany;
		}

		//down lines
		if (z == 0 && y == 0)
		{
			checkCellCondiction(x - 1, y, z, howMany);
			checkCellCondiction(x + 1, y, z, howMany);

			for (size_t i = (x - 1); i < x + 2; i++)
			{
				for (size_t j = y; j < (y + 2); j++)
				{
					checkCellCondiction(i, j, z + 1, howMany);
				}
			}

			for (size_t i = (x - 1); i < (x + 2); i++)
			{
				checkCellCondiction(i, y + 1, z, howMany);
			}

			return howMany;
		}
		if (x == 0 && y == 0)
		{
			checkCellCondiction(x, y, z - 1, howMany);
			checkCellCondiction(x, y, z + 1, howMany);

			for (size_t i = (z - 1); i < (z + 2); i++)
			{
				for (size_t j = y; j < (y + 2); j++)
				{
					checkCellCondiction(x + 1, j, z, howMany);
				}
			}

			for (size_t i = (z - 1); i < (z + 2); i++)
			{
				checkCellCondiction(x, y + 1, i, howMany);
			}

			return howMany;
		}
		if (x == (xSize - 1) && y == 0)
		{
			checkCellCondiction(x, y, z - 1, howMany);
			checkCellCondiction(x, y, z + 1, howMany);

			for (size_t i = (z - 1); i < (z + 2); i++)
			{
				for (size_t j = y; j < (y + 2); j++)
				{
					checkCellCondiction(x - 1, j, i, howMany);
				}
			}

			for (size_t i = (z - 1); i < (z + 2); i++)
			{
				checkCellCondiction(x, y + 1, i, howMany);
			}

			return howMany;
		}
		if (z == (zSize - 1) && y == 0)
		{
			checkCellCondiction(x - 1, y, z, howMany);
			checkCellCondiction(x + 1, y, z, howMany);

			for (size_t i = (x - 1); i < (x + 2); i++)
			{
				for (size_t j = y; j < (y + 2); j++)
				{
					checkCellCondiction(i, j, z + 1, howMany);
				}
			}

			for (size_t i = (x - 1); i < (x + 2); i++)
			{
				checkCellCondiction(i, y + 1, z, howMany);
			}

			return howMany;
		}

		//back lines
		if (x == 0 && z == 0 && y < (ySize - 1))
		{
			checkCellCondiction(x, y - 1, z, howMany);
			checkCellCondiction(x, y + 1, z, howMany);

			for (size_t i = (y - 1); i < y + 2; i++)
			{
				checkCellCondiction(x, i, z + 1, howMany);
				checkCellCondiction(x + 1, i, z + 1, howMany);
				checkCellCondiction(x + 1, i, z, howMany);
			}

			return howMany;
		}
		if (x == (xSize - 1) && z == 0 && y < (ySize - 1))
		{
			checkCellCondiction(x, y - 1, z, howMany);
			checkCellCondiction(x, y + 1, z, howMany);

			for (size_t i = (y - 1); i < y + 2; i++)
			{
				checkCellCondiction(x - 1, i, z, howMany);
				checkCellCondiction(x - 1, i, z + 1, howMany);
				checkCellCondiction(x, i, z + 1, howMany);
			}

			return howMany;
		}
		if (x == (xSize - 1) && z == (zSize - 1) && y < (ySize - 1))
		{
			checkCellCondiction(x, y - 1, z, howMany);
			checkCellCondiction(x, y + 1, z, howMany);

			for (size_t i = (y - 1); i < y + 2; i++)
			{
				checkCellCondiction(x, i, z - 1, howMany);
				checkCellCondiction(x - 1, i, z - 1, howMany);
				checkCellCondiction(x - 1, i, z, howMany);
			}

			return howMany;
		}
		if (z == (zSize - 1) && x == 0 && y < (ySize - 1))
		{
			checkCellCondiction(x, y - 1, z, howMany);
			checkCellCondiction(x, y + 1, z, howMany);

			for (size_t i = (y - 1); i < (y + 2); i++)
			{
				checkCellCondiction(x, i, z + 1, howMany);
				checkCellCondiction(x + 1, i, z + 1, howMany);
				checkCellCondiction(x + 1, i, z, howMany);
			}

			return howMany;
		}

		//up lines
		if (x == 0 && z == 0 && y == (ySize - 1))
		{
			checkCellCondiction(x, y, y - 1, howMany);

			for (size_t i = (y - 1); i<(ySize); i++)
			{
				checkCellCondiction(x, i, z + 1, howMany);
				checkCellCondiction(x + 1, i, z + 1, howMany);
				checkCellCondiction(x + 1, i, z, howMany);
			}

			return howMany;
		}
		if (x == (xSize - 1) && z == 0 && y == (ySize - 1))
		{
			checkCellCondiction(x, y, y - 1, howMany);

			for (size_t i = (y - 1); i<(ySize); i++)
			{
				checkCellCondiction(x, i, z + 1, howMany);
				checkCellCondiction(x - 1, i, z + 1, howMany);
				checkCellCondiction(x - 1, i, z, howMany);
			}

			return howMany;
		}
		if (x == (xSize - 1) && z == (zSize - 1) && y == (ySize - 1))
		{
			checkCellCondiction(x, y, y - 1, howMany);

			for (size_t i = (y - 1); i<(ySize); i++)
			{
				checkCellCondiction(x, i, z + 1, howMany);
				checkCellCondiction(x - 1, i, z + 1, howMany);
				checkCellCondiction(x - 1, i, z, howMany);
			}

			return howMany;
		}
		if (x == 0 && z == (zSize - 1) && y == (ySize - 1))
		{
			checkCellCondiction(x, y, y - 1, howMany);

			for (size_t i = (y - 1); i<(ySize); i++)
			{
				checkCellCondiction(x, i, z - 1, howMany);
				checkCellCondiction(x + 1, i, z - 1, howMany);
				checkCellCondiction(x + 1, i, z, howMany);
			}

			return howMany;
		}

		//walls
		if (x > 0 && z == 0)
		{
			checkCellCondiction(x + 1, y, z, howMany);
			checkCellCondiction(x - 1, y, z, howMany);

			for (size_t i = (x - 1); i < (x + 2); i++)
			{
				checkCellCondiction(i, y, z + 1, howMany);

				for (size_t j = z; j < (z + 2); j++)
				{
					checkCellCondiction(i, y - 1, j, howMany);
					checkCellCondiction(i, y + 1, j, howMany);
				}
			}
			return howMany;
		}
		if (z > 0 && x == 0)
		{
			checkCellCondiction(x, y, z - 1, howMany);
			checkCellCondiction(x, y, z + 1, howMany);

			for (size_t i = (z - 1); i < (z + 2); i++)
			{
				checkCellCondiction(x + 1, y, i, howMany);

				for (size_t j = x; j < (x + 2); j++)
				{
					checkCellCondiction(j, y - 1, i, howMany);
					checkCellCondiction(j, y + 1, i, howMany);
				}
			}
			return howMany;
		}
		if (x == (xSize - 1) && z > 0)
		{
			checkCellCondiction(x, y, z - 1, howMany);
			checkCellCondiction(x, y, z + 1, howMany);

			for (size_t i = (z - 1); i < (z + 2); i++)
			{
				checkCellCondiction(x - 1, y, i, howMany);

				for (size_t j = x - 1; j < (x + 1); j++)
				{
					checkCellCondiction(j, y - 1, i, howMany);
					checkCellCondiction(j, y + 1, i, howMany);
				}
			}
			return howMany;
		}
		if (z == (zSize - 1) && x > 0)
		{
			checkCellCondiction(x - 1, y, z, howMany);
			checkCellCondiction(x + 1, y, z, howMany);

			for (size_t i = (x - 1); i < (x + 2); i++)
			{
				checkCellCondiction(x, y, z - 1, howMany);

				for (size_t j = (z - 1); i < (z + 1); i++)
				{
					checkCellCondiction(i, y - 1, j, howMany);
					checkCellCondiction(i, y + 1, j, howMany);
				}
			}
			return howMany;
		}

		//up && down walls
		if (y == 0)
		{
			checkCellCondiction(x + 1, y, z, howMany);
			checkCellCondiction(x - 1, y, z, howMany);

			for (size_t i = (x - 1); i < (x + 2); i++)
			{
				checkCellCondiction(i, y, z + 1, howMany);
				checkCellCondiction(i, y, z - 1, howMany);
				for (size_t j = (z - 1); j < (z + 2); j++)
				{
					checkCellCondiction(i, y + 1, j, howMany);
				}
			}
			return howMany;
		}
		if (y == (ySize - 1))
		{
			checkCellCondiction(x + 1, y, z, howMany);
			checkCellCondiction(x - 1, y, z, howMany);

			for (size_t i = (x - 1); i < (x + 2); i++)
			{
				checkCellCondiction(i, y, z + 1, howMany);
				checkCellCondiction(i, y, z - 1, howMany);
				for (size_t j = (z - 1); j < (z + 2); j++)
				{
					checkCellCondiction(i, y - 1, j, howMany);
				}
			}
			return howMany;
		}

		//normal check

		checkCellCondiction(x - 1, y, z, howMany);
		checkCellCondiction(x + 1, y, z, howMany);

		for (size_t i = (x - 1); i < (x + 2); i++)
		{
			checkCellCondiction(i, y, z - 1, howMany);
			checkCellCondiction(i, y, z + 1, howMany);

			for (size_t j = (z - 1); j < (z + 2); j++)
			{
				checkCellCondiction(i, y + 1, j, howMany);
				checkCellCondiction(i, y - 1, j, howMany);
			}
		}

		return howMany;
	}

};