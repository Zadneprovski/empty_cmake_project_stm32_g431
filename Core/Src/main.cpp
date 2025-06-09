#include "main.h"
#include <cassert>
#include <stdio.h>
#include "stm32g4xx.h"
#include "stm32g431xx.h"
#include "clock.h"
#include "trace.hpp"
#include "user_defined_literals.hpp"
#include "IObserver.hpp"
#include "ISubject.hpp"

//#include "IOTest2.hpp"


int main()
{
	setSysTickFrequency(1_kHz);

	MySubject s1;
	MySubject s2;
	MySubject2 s3;

	MyObserver1 o1;
	MyObserver2 o2;

	s1.addObserver(o1);
	s1.addObserver(o2);
	s1.addObserver(s3);

	s2.addObserver(o1);
	s2.addObserver(o2);

	s3.addObserver(o2);

	s1.notifyAll(2);
	s2.notifyAll(10);
	s3.notifyAll(20);

	while (1)
	{
		//static uint32_t prevTicks = getSysTick();
		//auto currentTicks = getSysTick();

//		if (currentTicks - prevTicks > 1000)
		if(1)
		{
//			libzm::trace(currentTicks, "ms");
//			libzm::trace(sysTicks);
			//prevTicks = sysTicks;
		}
	}
	return 0;
}

