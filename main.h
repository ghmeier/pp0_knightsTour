//Garret Meier
//CS 229 Spring 2015
//Programming Project 0
//Knight's Tour

#ifndef MAIN_H
#define MAIN_H

int isValidMove(int* move, int* currentSpace ,int length,int* completedMoves);
void takeMove(int* move, int* currentSpace);
void tryMoves(int* currentSpace, int length, int* xMoves, int* yMoves, int moves, int movesTaken, int maxMoves, int* completedMoves,int* currentMoves);
void printArray(int* array,int length);
int getSpaceNumber(int x, int y, int length);

#endif