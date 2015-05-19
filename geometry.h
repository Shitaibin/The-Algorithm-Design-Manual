/*    geometry.h
 *  
 *    Header file for geometric data types
 *
 *    by: Steven Skiena
 *    2015-05-19 23:26
 *    Altered by James Shi
 */


#define PI      3.1415926 /* ratio of circumference to diameter */
#define EPSILON 0.000001  /* a quantity small enough to be zero */

typedef struct {
  double a;   /* x-coefficient */
  double b;   /* y-coefficient */
  double c;   /* constant term */
} line;

#define DIMENSION 2 /* dimension of points */
#define X   0 /* x-coordinate index */
#define Y   1 /* y-coordinate index */

typedef double point[DIMENSION];

#define MAXPOLY   200 /* maximum number of points in a polygon */

typedef struct {
  int n;      /* number of points in polygon */
  point p[MAXPOLY]; /* array of points in polygon */
} polygon;


typedef struct {
  point p1,p2;    /* endpoints of line segment */
} segment;

typedef point triangle[3];  /* triangle datatype */

typedef struct {
  int n;      /* number of triangles in triangulation */
  int t[MAXPOLY][3];  /* indicies of vertices in triangulation */
} triangulation;

typedef struct {
  point c;    /* center of circle */
  double r;   /* radius of circle */
} circle;


/*  Comparison macros   */

#define max(A, B)   ((A) > (B) ? (A) : (B))
#define min(A, B)   ((A) < (B) ? (A) : (B))
