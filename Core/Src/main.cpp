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

#include "IOTest2.hpp"





int main()
{
	setSysTickFrequency(1_kHz);
	test();
//	MySubject s;
//	MyObserver1 o1;
//	MyObserver2 o2;
//
//	s.addObserver(o1);
//	s.addObserver(o2);

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
//			s.notify(2);
		}
	}
	return 0;
}

