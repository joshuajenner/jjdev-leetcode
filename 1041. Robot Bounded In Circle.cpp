#include <string>
using namespace std;

// On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

// The north direction is the positive direction of the y - axis.
// The south direction is the negative direction of the y - axis.
// The east direction is the positive direction of the x - axis.
// The west direction is the negative direction of the x - axis.
// The robot can receive one of three instructions:

// "G" : go straight 1 unit.
// "L" : turn 90 degrees to the left(i.e., anti - clockwise direction).
// "R" : turn 90 degrees to the right(i.e., clockwise direction).
// The robot performs the instructions given in order, and repeats them forever.

// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

bool isRobotBounded(string instructions);

bool isRobotBounded(string instructions)
{
	int direction = 0;
	int position[2] = { 0, 0 };

	for (char instruction : instructions)
	{
		if (instruction == 'G')
		{
			moveForward(position, direction);
		}
		else if (instruction == 'L')
		{
			direction = wrap(direction - 1, 0, 3);
		}
		else if (instruction == 'R')
		{
			direction = wrap(direction + 1, 0, 3);
		}
	}

	if ((position[0] == 0 && position[1] == 0) || direction != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void moveForward(int currentPosition[2], int direction)
{
	switch (direction) {
	case 0:
		currentPosition[1] += 1;
		break;
	case 1:
		currentPosition[0] += 1;
		break;
	case 2:
		currentPosition[1] -= 1;
		break;
	case 3:
		currentPosition[0] -= 1;
		break;
	}	
}

int wrap(int value, int min, int max)
{
	if (value > max) {
		return min;
	}
	if (value < min) {
		return max;
	}
	return value;
}