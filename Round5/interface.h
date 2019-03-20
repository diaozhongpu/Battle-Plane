/* interface.h
 * This name doesn't mean this library is something about C interface.
 * but the interface of our game when we log in and out.
 * this library contains functions that produce option menus in this game,
 * which help the player start game, choose game mode and level, exit ,check their record ,etc. 
 * by pressing 'w' 's' on the keyboard to select and press space to decide
 * then the function returns a value for the next process
 * though many implemments should belong to icons.h
 * split it out may make it esaier to use these functions
 * 
 * but to use this interface,you need icons.h
 *
 * Author :
 * thanks to friends on csdn who taught me this 
 * in fact this interface is kind of aukaurd but i wannt to make this game only in gcc
 * so i didn't make any other special things because most of them needs more than gcc
 */

#ifndef _interface_h
#define _interface_h

#include<windows.h>
#include<stdio.h>

/* Function Prototype: Startgame(int width,int height)
 * Usage : Startgame(width,height);
 * this fuction produces an interface and get instuctions from the user
 * to decide whether to start the game or not by returning different values
 * return 2 as New game
 * return 4 as Reload
 * return 6 as Exit
 * switch your choice by pressing 'w' and 's' on the keyboard to move the pointer
 * make your decision by pressing space when that option is pointed
 */

int Startgame(int width,int height);

/* Function Prototype: Modechoose(int width,int height)
 * Usage : Modechoose(width,height);
 * this fuction produces an interface and get instuctions from the user
 * to decide which playing mode to play by returning different values 
 * return 0 as Adventure
 * return 2 as Challenge
 * return 4 as Classical
 * return 6 as War
 * return 10 as back
 * switch your choice by pressing 'w' and 's' on the keyboard to move the pointer
 * make your decision by pressing space when that option is pointed
 */

int Modechoose(int width,int height);

/* Function Prototype: Levelchoose(int width,int height)
 * Usage : Levelchoose(width,height);
 * this fuction produces an interface and get instuctions from the user
 * to set initial level by returning different values
 * return 2 as easy
 * return 4 as normal
 * return 6 as hard
 * return 10 as back
 * switch your choice by pressing 'w' and 's' on the keyboard to move the pointer
 * make your decision by pressing space when that option is pointed
 */

int Levelchoose(int width,int height);

/* Function Prototype: Pausegame(int with,int height)
 * Usage : Pausegame(width,height);
 * this fuction produces an interface and get instuctions from the user
 * to decide whether to restart the game or not by returning different values
 * return 2 as Renew
 * return 4 as Continue
 * return 6 as Quit
 * switch your choice by pressing 'w' and 's' on the keyboard to move the pointer
 * make your decision by pressing space when that option is pointed
 */

int Pausegame(int with,int height);

/* Function Prototype: Completed(int width,int height)
 * Usage : Completed(width,height);
 * this fuction produces an interface and get instuctions from the user
 * to decide whether to play the next level or not by returning different values
 * return 2 as Next Level
 * return 4 as Load
 * return 6 as Quit
 * switch your choice by pressing 'w' and 's' on the keyboard to move the pointer
 * make your decision by pressing space when that option is pointed
 */

int Completed(int width,int height);

/* Function Prototype: Gameover(int width,int height)
 * Usage : Gameover(width,height);
 * this fuction produces an interface and get instuctions from the user
 * to decide whether to restart the game or not by returning different values
 * return 2 as Renew
 * return 4 as Revive
 * return 6 as Quit
 * switch your choice by pressing 'w' and 's' on the keyboard to move the pointer
 * make your decision by pressing space when that option is pointed
 */

int Gameover(int width,int height);



#endif
