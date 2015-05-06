/*    stack.h
 *
 *    Header file for queue implementation
 *    
 *    by: Steven Skiena
 *
 *    2015-05-06 12:56
 *    Altered by James Shi
 */

#define STACKSIZE   1000

typedef struct{
  int s[STACKSIZE+1];
  int top;
  int count;
} stack;
