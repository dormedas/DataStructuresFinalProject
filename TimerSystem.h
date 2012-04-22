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


#ifndef TIMER_SYSTEM_H
#define TIMER_SYSTEM_H

#include <iostream>
#include <windows.h>

class TimerSystem
{
   private:
      LARGE_INTEGER start, finish, freq;  //For frequency and high speed timers

   public:
      TimerSystem();

      double getTime();  //gets current time since top of frame
      void   startClock();  //Starts the frame counter
};

#endif