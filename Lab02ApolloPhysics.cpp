/*************************************************************
 * 1. Name:
 *    -Matt Benson-
 * 2. Assignment Name:
 *    Lab 02: Apollo 11
 * 3. Assignment Description:
 *    Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *    -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *    -total time in hours: reading the assignment, submitting, and writing code-
 *****************************************************************/

#define _USE_MATH_DEFINES
#include <iostream>    // For CIN & COUT
#include <cmath>       // For M_PI
#include <numbers>     // For math
#include <cassert>     // For asserts

using namespace std;

#define WEIGHT   15103.000           // Weight in KG
#define GRAVITY     -1.625           // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000           // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
* COMPUTE DISTANCE
* Apply inertia to compute a new position using the distance equation.
* The equation is:
*     s = s + v t + 1/2 a t^2
* INPUT
*     s : original position, in meters
*     v : velocity, in meters/second
*     a : acceleration, in meters/second^2
*     t : time, in seconds
* OUTPUT
*     s : new position, in meters
**************************************************/
double computeDistance(double initialS, double v, double a, double t)
{
   double s;
   s = initialS + (v * t) + (0.5 * a * t * t);
   return s;
}

/**************************************************
* COMPUTE ACCELERATION
* Find the acceleration given a thrust and mass.
* This will be done using Newton's second law of motion:
*     f = m * a
* INPUT
*     f : force, in Newtons (kg * m / s^2)
*     m : mass, in kilograms
* OUTPUT
*     a : acceleration, in meters/second^2
***************************************************/
double computeAcceleration(double f, double m)
{
   double a;
   assert(m != 0.0);
   a = f / m;
   return a;
}

/***********************************************
* COMPUTE VELOCITY
* Starting with a given velocity, find the new
* velocity once acceleration is applied.This is
* called the Kinematics equation.The
* equation is :
*v = v + a t
* INPUT
* v : velocity, in meters / second
* a : acceleration, in meters / second ^ 2
* t : time, in seconds
* OUTPUT
* v : new velocity, in meters / second
* **********************************************/
double computeVelocity(double initialV, double a, double t)
{
   double v;
   v = initialV + a * t;
   return v;
}

/***********************************************
* COMPUTE VERTICAL COMPONENT
* Find the vertical component of a velocity or acceleration.
* The equation is:
*     cos(a) = y / total
* This can be expressed graphically:
*      x
*    +-----
*    |   /
*  y |  / total
*    |a/
*    |/
* INPUT
*     a : angle, in radians
*     total : total velocity or acceleration
* OUTPUT
*     y : the vertical component of the total
***********************************************/
double computeVerticalComponent(double a, double total)
{
   double y;
   y = total * cos(a);
   return y;
}

/***********************************************
* COMPUTE HORIZONTAL COMPONENT
* Find the horizontal component of a velocity or acceleration.
* The equation is:
*     sin(a) = x / total
* This can be expressed graphically:
*      x
*    +-----
*    |   /
*  y |  / total
*    |a/
*    |/
* INPUT
*     a : angle, in radians
*     total : total velocity or acceleration
* OUTPUT
*     x : the vertical component of the total
***********************************************/
double computeHorizontalComponent(double a, double total)
{
   double x;
   x = total * sin(a);
   return x;
}

/************************************************
* COMPUTE TOTAL COMPONENT
* Given the horizontal and vertical components of
* something (velocity or acceleration), determine
* the total component. To do this, use the Pythagorean Theorem:
*    x^2 + y^2 = t^2
* where:
*      x
*    +-----
*    |   /
*  y |  / total
*    | /
*    |/
* INPUT
*    x : horizontal component
*    y : vertical component
* OUTPUT
*    total : total component
*************************************************/
double computeTotalComponent(double x, double y)
{
   double total;
   total = sqrt((x * x) + (y * y));
   return total;
}

/*************************************************
* RADIANS FROM DEGEES
* Convert degrees to radians:
*     radians / 2pi = degrees / 360
* INPUT
*     d : degrees from 0 to 360
* OUTPUT
*     r : radians from 0 to 2pi
**************************************************/
double computeRadians(double d)
{
   double r;
   r = (2.0 * M_PI) * (d / 360.0);
   return r;
}

/**************************************************
* PROMPT
* A generic function to prompt the user for a double
* INPUT
*      message : the message to display to the user
* OUTPUT
*      response : the user's response
***************************************************/
double prompt(const char* message)
{
   double response;
   cout << message;
   cin >> response;
   return response;
}

/****************************************************************
* MAIN
* Prompt for input, compute new position, and display output
****************************************************************/
int main()
{
   // Prompt for input and variables to be computed.
   double dx       = prompt("What is your horizontal velocity (m/s)? ");
   double dy       = prompt("What is your vertical velocity (m/s)? ");
   double y        = prompt("What is your altitude (m)? ");
   double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");

   // Output to display 10 second run time.
   for (int i = 1; i < 6; i++)
   {
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);
      cout << "   " << i << "s " << "- "
           << "x,y:("   << x  << ", " << y << ")m   "
           << "dx,dy:(" << dx << ", " << dy << ")m/s   "
           << "speed:"  << speed   << "m/s   "
           << "angle:(" << degrees << ")deg";
   }
   // Prompt for the new angle.
   cout << "\nWhat is the new angle of the LM where 0 is up (degrees)? \n";
   for (int i = 6; i < 11; i++)
   {
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);
      cout << "   " << i << "s " << "- "
           << "x,y:("   << x  << ", " << y << ")m   "
           << "dx,dy:(" << dx << ", " << dy << ")m/s   "
           << "speed:"  << speed   << "m/s   "
           << "angle:(" << degrees << ")deg";
   }
}

// Example
//cout << "\tNew position:   (" << x << ", " << y << ")m\n";
//cout << "\tNew velocity:   (" << dx << ", " << dy << ")m/s\n";
//cout << "\tTotal velocity:  " << v << "m/s\n\n";