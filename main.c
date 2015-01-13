//Garret Meier
//CS 229 Spring 2015
//Programming Project 0
//Knight's Tour

#include <stdio.h>

int isValidMove(int* move, int* currentSpace ,int length,int* completedMoves);
void takeMove(int* move, int* currentSpace);
void tryMoves(int* currentSpace, int length, int* xMoves, int* yMoves, int moves, int movesTaken, int maxMoves, int* completedMoves,int* currentMoves);
void printArray(int* array,int length);

int main()
{
	//we're gonna assume it's a square for now :)
	int length = 5;


	//int dif[] = [-11,-9,-3,7,11,9,3,7];
	int xMove[8] = {-2,-2,-1,-1, 1, 1, 2, 2};
	int yMove[8] = { 1,-1,-2, 2,-2, 2,-1, 1};
	int moves = 8;

	int x = 0;
	int y = 0;

	for (y = 0; y < length; y = y + 1)
	{

		for (x = 0; x < length; x = x + 1)
		{	
			int startSpace[2] = {x,y};
			int movesTaken = 1;
			int maxMoves = length * length;
			int completedMoves[maxMoves];
			int orderedMoves[maxMoves];
			int j = 0;
			
			for (j=0;j< maxMoves; j = j + 1)
			{
				completedMoves[j] = -1;
				orderedMoves[j] = -1;
			} 

			completedMoves[getSpaceNumber(x,y,length)-1] = 0;
			orderedMoves[0] =  getSpaceNumber(x,y,length);

			tryMoves(startSpace,length,xMove,yMove,moves,movesTaken,maxMoves,completedMoves,orderedMoves);

		}

	}
	printf("%i\n",total);
	return 0;

}

//try all the moves 
void tryMoves(int* currentSpace, int length, int* xMoves, int* yMoves, int moves, int movesTaken, int maxMoves, int* currentCompleteMoves, int* currentMoves,int* total)
{
	
	if (movesTaken >= maxMoves)
	{
		printArray(currentMoves,maxMoves);
		return;
	}

	int i = 0;
	for (i=0; i < moves; i = i+1)
	{
		int current[2] = {currentSpace[0],currentSpace[1]};
		int move[2] = {xMoves[i],yMoves[i]};

		if (isValidMove(move,current,length,currentCompleteMoves) == 1)
		{
			int orderedMoves[maxMoves]; 
			int completedMoves[maxMoves];
			int j=0;
			for (j=0; j<maxMoves; j=j+1){
					orderedMoves[j] = currentMoves[j];
					completedMoves[j] = currentCompleteMoves[j];
			}
			takeMove(move,current);
			int spaceNumber = getSpaceNumber(current[0],current[1],length);
			completedMoves[spaceNumber-1] = 0;
			orderedMoves[movesTaken] = spaceNumber;			
			int nextMovesTaken = movesTaken + 1;

			tryMoves(current,length,xMoves,yMoves,moves,nextMovesTaken,maxMoves,completedMoves,orderedMoves);
		}
	}

	//no valid moves
	return;	
}

//Let's see if the move in question is legit
int isValidMove(int* move, int* currentSpace ,int length, int* completedMoves)
{
	int xPos = currentSpace[0] + move[0];

	if (xPos >= 0 && xPos < length){
		int yPos = currentSpace[1] + move[1];

		if (yPos >= 0 && yPos < length){
			if (completedMoves[getSpaceNumber(xPos,yPos,length)-1] != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

//take the move on the current space
void takeMove(int* move, int* currentSpace)
{
	currentSpace[0] += move[0];
	currentSpace[1] += move[1];
}

void printArray(int* array, int length){
	int i=0;
	for (i=0; i<length;i=i+1)
	{
		printf("%i,",array[i]);
	}
	printf("\n");
}

int getSpaceNumber(int x,int y,int length){
	return y*length + x+1;
}