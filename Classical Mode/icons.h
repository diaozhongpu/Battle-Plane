/*
 * File : iocns.h
 * ------------------
 * This file contains the interface of icons.c ,
 * which contains functions that draw icons in the battleplane game 
 * these icons are presented with updated informations in a loop 
 * 
 * attention that if you print an "Invalid Value" somewhere
 * that means you had made a invalid call with invalid type value somewhere
 */
 
#ifndef _icons_h
#define _icons_h 

#include<stdio.h>


/*
 * Function : gotoXY = set the cursor to coordinate (x,y)
 * Usage : gotoXY(x,y)
 * --------------------------------------------
 * this funtion helps reset the cursor at (x,y)
 * remember it is commom sense that 0 is the first row
 * corresponding to the first element's index in an array is 0
 */

void gotoXY(int x, int y);

/* 
 * Function : StartAmi = start game amination
 * Usage : StartAmi(width,height)
 * ------------------------------------------
 * this function prints a series of character icons and words in the domain restricted by width and height
 * make sure that width >=30 ,height >=20
 * related to this game as a brief introduction of the background of the game
 */ 

void StartAmi(int width,int height);

/* 
 * Function : Warning
 * Usage : Warning(width,height)
 * ------------------------------------------
 * this function prints a warning icon at the center of the domain restricted by width and height
 * make sure that width >= 15 ,height >=5
 * this icon is used before the last offensive of a level
 */ 

void Warning(int width,int height);

/* 
 * Function : Levelicon
 * Usage : Levelicon(width,height)
 * ------------------------------------------
 * this function prints a Level icon"Level num" at the center of the domain restricted by width and height
 * make sure that width >= 15 ,height >=5
 * this icon is used at the start of a level
 */ 

void Levelicon(int width,int height,int num);

/* 
 * Function : Character
 * Usage : Character(x,y,ch)
 * ------------------------------------------
 * this function prints charactor icons at the the coordinate(x,y)
 * ch can be 'B','A','t','L','e','P','l','N','E',
 * the last row of charator icon is printed at the y th line 
 */ 

void Character(int x,int y,char ch);

/*
 * Function : DrawBPL = Draw the Battle PLane
 * Usage : DrawBPL(x,y,type) 
 * ------------------------------------------------------------------------
 * This function draws a battleplane at the coordinate(x,y) of certain type(0~3)
 * (x,y)is the center of the battleplane which is presented as 0
 * the battleplane features like this:
 * 
 * type 0:   A
 *          /0\
 *          '^'
 * type 1:  _ _
 *         /,0,\
 *
 * type 2:  = =
 *          |0|
 *          ^ ^
 *
 * type 3:   |
 *          |0| 
 *          -H-
 */
 
void DrawBPL(int x,int y,int type);
 
/*
 * Function : DrawEPL = Draw the Enemy PLane
 * Usage : DrawEPL(x,y,type)
 * -----------------------------------------------------------------------------
 * This function draws an enemyplane at the coordinate(x,y) of certain type(0~3)
 * (x,y)is the center of the enemyplane which is presented as 0
 * type 0 : 
 *   
 *   <[0]>
 *
 * type 1 : 
 *    
 *   ([0])
 *
 * type 2 :
 *
 *   /!0!\
 *     V
 * 
 * type 4 :
 * 
 *    _W_
 *   \_0_/
 *    ^ ^
 * 
 */
 
void DrawEPL(int x,int y,int type);

/*
 * Function : DrawBUL = Draw a BULlet
 * Usage : DrawBUL(x,y,type)
 * --------------------------------------------------------------------
 * This function draws a bullet at the coordinate(x,y) of certain type(0~3)
 * type 0:  o
 * type 1:  *
 * type 2:  @
 * type 3:  :
 *           
 */
 
void DrawBUL(int x,int y,int type);

/*
 * Function : DrawLR = Draw a LaseR
 * Usage : DrawLR(x,y,type)
 * --------------------------------------------------------------------
 * This function draws a laser at x from y to the distance of certian type(0~2) 
 * 
 *  type 0: |          type 1: *          type 2: $ 
 *          |                  *                  $
 *          |                  *                  $
 *          |                  *                  $
 *          |                  *                  $
 */
 
void DrawLR(int x,int y,int type);

/*
 * Function : DrawBag = Draw a Bag
 * Usage : DrawBag(x,y,type)
 * ---------------------------------------------------------------------
 * This function draws a bag at the coordinate(x,y) of certain type(0~5)
 * type 0 : healthbag featuring as "+";
 * type 1 : bombbag featuring as "B"
 * type 2 : laserbag featuring as "L"
 * type 3 : firepower enhancebag featuring as "E" 
 * type 4 : speed enhancebag featuring as "S"
 * type 5 : shieldbag featuring as "D"
 */
 
void DrawBag(int x,int y,int type);

/*
 * Function : DrawB = Draw a Bomb
 * Usage : DrawB(x,y)
 * -------------------------------------------------
 * This function draws a bomb at the coordinate(x,y) of certain type(0~5)
 * (x,y)is the front end of the bomb featuring as
 *  type 0 : A     type 1 : 'H'    type 2 : I   type 3 : A   type 4 : =    type 5 : \|/
 *           M               U              V            T            |            --*-- 
 *                                                                    ^             /|\
 */

void DrawB(int x,int y,int type);

/*
 * Function : DrawBoos = Draw the Boss
 * Usage : DrawBoss(x,y)
 * ----------------------------------------------------------
 * This function draws the boss plane at the coordinate(x,y)
 * (x,y)is the center of the boss which is presented as 0
 * be sure there are at last 29 columns and 8 rows to print the boos
 * see it by call DrawBoss(15,3)
 */

void DrawBoss(int x,int y);

/*
 * Function : DrawMTX = Draw the Matrix
 * Usage : DrawMTX(x,y)
 * ----------------------------------------------------------
 * This function draws the matrix at the coordinate(x,y)
 * (x,y)is the center of the matrixs which is presented as 0
 * be sure there are at last 7 columns and 7 rows to print the boos
 * see it by call DrawMTX(4,6)
 */

void DrawMTX(int x,int y);

/*
 * Function : PrintInfor = Print necessary updated Informations
 * Usage : PrintInfor(health,bombnum,score,level,y)
 * --------------------------------------------------------------------------------------
 * This funtion prints two lines of information including health,bombnum,score and level
 * at the y row and the follow row like this:
 *
 * Health : point    Bombnum : num
 * Score  : point     Level  : point
 */

void PrintInfor(int health,int bombnum,int score,int level,int y);

/*
 * Function : DrawLine
 * Usage : DrawLine(x,y,length,ch,type)
 *-------------------------------------------------------------------------------------
 * if type is R(row) ,this function prints a line of ch in length at the t th row from x to x + length
 * like this:(assume that ch = '-')
 *  -----------------
 * if type is C(column),this function prints a line of ch in length at the t th column from y to y + length
 * like this:(assume that ch = '|')
 *  |
 *  |
 *  |
 *  | 
 *  |
 */

void DrawLine(int x,int y,int length,char ch,char type);

/*
 * Function : BBExplode = BomB Explode
 * Usage : BBExplode(x,y,type)
 * -----------------------------------------------------------------------------
 * This function draws an bomb's explosion animation at the coordinate(x,y) of certain type(0~4) coresponding to bomb type
 * (x,y)is the center of the explosion
 * call it to see what every type looks like
 */

void BBExplode(int x,int y,int type);

/*
 * Function : PLExplode = PLane Explode
 * Usage : PLExplode(x,y,type)
 * -----------------------------------------------------------------------------
 * This function draws a plane's explosion at the coordinate(x,y) of certain type(0~2)
 * (x,y)is the center of the explosion
 * call it to see what every type looks like
 */

void PLExplode(int x,int y,int type);

/*
 * Function : SpecialEffects
 * Usage : SpecialEffects(x,y,type)
 * -----------------------------------------------------------------------------
 * This function draws Special Effects that aren't included in former functoins
 *  at the coordinate(x,y) of certain type(0~2)
 * type 0 : shield
 * type 1 : super shield
 * type 2 : Energe gathering(for the charge  boss's nucleus cannon)
 * (x,y)is the center of the special effects
 * call it to see what every type looks like
 */


void SpecialEffects(int x,int y,int type);



#endif
