#include "lab3.h"
#include "testStack.h"

int main (void)
{
	Node *pPillars[3] = {NULL};
	NodeData tempData;
	int game_state = 0, sub_state = 0, option = 0,
		pillars = 3, disks = 3, i = 0, turns = 0,
		moveFrom = 0, moveTo = 0, maxMoves = 0;
	Bool success = true;

	while (game_state >= 0)
	{
		//// GAME SETUP
		if (game_state == 0)
		{
			turns = 0;
			sub_state = 0;
			printf ("Amount of Disks to Use? ");
			disks = getIntInputCheck (1, 1337);

			// Setup Disks at Pillar 0
			for (i = disks - 1; i >= 0; i--)
			{
				tempData.diskSize = (0.5 * (double)i) + 0.5;
				success = push (&pPillars[0], tempData);
				if (success == false)
				{
					printf ("Failure to create disk %d\n", i);
					game_state = -1;
				}
			}
			sub_state = 3;
			game_state = 1;
		}
		//// TURN
		else if (game_state == 1)
		{
			// display main turn menu
			if (sub_state == 0)
			{
				option = display_menu (2, 2, ':', 1, 3, "#", "Lab 3 - Tower of Hanoi", "Turn Menu",
					"Display Pillars#Move Disk#Quit");
				if (option == 1)
				{
					sub_state = 3;
				}
				else if (option == 2)
				{
					sub_state = 1;
				}
				else if (option == 3)
				{
					game_state = -1;
				}
			}
			// display move from menu
			else if (sub_state == 1)
			{
				option = display_menu (2, 2, ':', 1, 5, "#", "Lab 3 - Tower of Hanoi", "Move Disk From...",
					"<- Go Back#Display Pillars#Pillar 1#Pillar 2#Pillar 3");
				if (option == 1)
				{
					sub_state = 0;
				}
				// show pillars
				else if (option == 2)
				{
					printStack (pPillars[0], 1);
					printStack (pPillars[1], 2);
					printStack (pPillars[2], 3);
				}
				// move from pillar 1
				else if (option == 3)
				{
					moveFrom = 0;
					if (!isEmpty (pPillars[moveFrom]))
						sub_state = 2;
					else
						printf ("No disks on this pillar!\n");
				}
				// move from pillar 2
				else if (option == 4)
				{
					moveFrom = 1;
					if (!isEmpty (pPillars[moveFrom]))
						sub_state = 2;
					else
						printf ("No disks on this pillar!\n");
				}
				// move from pillar 3
				else if (option == 5)
				{
					moveFrom = 2;
					if (!isEmpty (pPillars[moveFrom]))
						sub_state = 2;
					else
						printf ("No disks on this pillar!\n");
				}
			}
			// display move to menu
			else if (sub_state == 2)
			{
				option = display_menu (2, 2, ':', 1, 5, "#", "Lab 3 - Tower of Hanoi", "Move Disk To...",
					"<- Go Back#Display Pillars#Pillar 1#Pillar 2#Pillar 3");
				if (option == 1)
				{
					sub_state = 1;
				}
				// show pillars
				else if (option == 2)
				{
					printStack (pPillars[0], 1);
					printStack (pPillars[1], 2);
					printStack (pPillars[2], 3);
				}
				// move to pillar 1
				else if (option == 3)
				{
					moveTo = 0;
					if (isValid (pPillars, moveFrom, moveTo))
						sub_state = 4;
					else
						printf ("Invalid Move!\n");
				}
				// move to pillar 2
				else if (option == 4)
				{
					moveTo = 1;
					if (isValid (pPillars, moveFrom, moveTo))
						sub_state = 4;
					else
						printf ("Invalid Move!\n");
				}
				// move to pillar 3
				else if (option == 5)
				{
					moveTo = 2;
					if (isValid (pPillars, moveFrom, moveTo))
						sub_state = 4;
					else
						printf ("Invalid Move!\n");
				}
			}
			// display pillar info
			else if (sub_state == 3)
			{
				printStack (pPillars[0], 1);
				printStack (pPillars[1], 2);
				printStack (pPillars[2], 3);
				if (isVictory(pPillars))
				{
					game_state = 2;
				}
				else
				{
					pause_clear (1, 1);
					sub_state = 0;
				}
			}
			// perform disk moving
			else if (sub_state == 4)
			{
				// move disk
				success = push (&pPillars[moveTo], popDisk (&pPillars[moveFrom]));
				// cleanup
				if (success)
				{
					turns++;
					printf ("Disk moved!\n");
					sub_state = 3;
				}
				else
				{
					printf ("There was a problem moving the disk, try again.\n");
					sub_state = 1;
				}
			}
		}
		//// Victory Screen
		else if (game_state == 2)
		{
			maxMoves = pow (2, disks) - 1;
			printf ("Congratz, you've won a %d sized Tower of Hanoi game in %d moves!\n",
				disks, turns);
			printf ("A perfect game would have %d moves in it\n", maxMoves);
			game_state = -1;
		}
	}

	return 0;
}