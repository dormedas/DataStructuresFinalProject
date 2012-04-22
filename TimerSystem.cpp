/* ***  Modified by:      Wei Kian Chen on January 25, 2012
     *  Author:           Anthony Blake
     *  Class:            SWE 281-01
     *  Date Assigned:    February 7, 2011
     *  Due Date:         February 14, 2011
     *
     *  Description:
     *      This class is to simulate a stopwatch for processes.  At the
     *  beginning of the program, the stopwatch must be initiated.  Then,
     *  use the startClock to start the stop watch and use the getTime to
     *  get the amount of time elapsed since the clock started.
     *  
     *  e.g.
     *  TimerSystem timer;
     *
     *  timer.startClock();
     *  cout << "Hello, World!\n";
     *  cout << "Time elapsed:  " << timer.getTime() << endl;
     *
     *  Certification of Authenticity:	
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/


#include "TimerSystem.h"

/*      Pre:  None
 *     Post:  The private members are initialized
 *  Purpose:  Default constructor for the TimerSystem
******************************************************************************/
TimerSystem::TimerSystem()
{
   QueryPerformanceFrequency(&freq);
   start.QuadPart  = 0;
   finish.QuadPart = 0;
}


/*      Pre:  The stopwatch must be initialized and started
 *     Post:  The elapse time is returned to the caller
 *  Purpose:  Gets time in seconds since the stopwatch has started
 ******************************************************************************/
double TimerSystem::getTime()
{
   QueryPerformanceCounter(&finish);  //get end cpu cycles

  // return the amount of time elapsed
   return static_cast<double>(finish.QuadPart - start.QuadPart) / static_cast<double>(freq.QuadPart);
}


/*      Pre:  The stopwatch must be initialized
 *     Post:  The start private member is reset
 *  Purpose:  To start the stopwatch
 ******************************************************************************/
void TimerSystem::startClock()
{
   //get the top of the frames CPU count
   QueryPerformanceCounter(&start);
}


