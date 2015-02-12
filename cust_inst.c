#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "altera_avalon_performance_counter.h"
#include "alt_types.h"
#include "sys/alt_timestamp.h"

int main()
{
		int dataa,datab,result,result2=0;
		int a3,a2,a1,a0,b3,b2,b1,b0;
		dataa = 0x67E31C1F;
		datab = 0xE318CC55;
		PERF_RESET (PERFORMANCE_COUNTER_0_BASE);
		PERF_START_MEASURING (PERFORMANCE_COUNTER_0_BASE);

		PERF_BEGIN (PERFORMANCE_COUNTER_0_BASE, 1);

		result = ALT_CI_BIT_TRIM_0(dataa,datab);
		//result = ALT_CI_BIT_INVERSE_0(dataa,datab);

		PERF_END (PERFORMANCE_COUNTER_0_BASE, 1);

		PERF_BEGIN (PERFORMANCE_COUNTER_0_BASE, 2);

		a3= (dataa & 0xFF000000) >> 24;
		b2 = (datab & 0xFF0000) >> 16;
		a1 = (dataa & 0xFF00) >> 8;
		b0 = (datab & 0xFF);
		result2 = (a3<<24) | (b2<<16) | (a1<<8) | (b0);


		PERF_END (PERFORMANCE_COUNTER_0_BASE, 2);

		PERF_STOP_MEASURING (PERFORMANCE_COUNTER_0_BASE);
		//perf_print_formatted_report((void *)PERFORMANCE_COUNTER_0_BASE,ALT_CPU_FREQ,1,"1st_test");
		printf("\n Result = %d Result2 = %d", result, result2);
		printf("\n Custom Instruction Clock Cycles: %lld \n", perf_get_section_time((void *)PERFORMANCE_COUNTER_0_BASE,1));
		printf("\n Software Instruction Clock Cycles: %lld \n", perf_get_section_time((void *)PERFORMANCE_COUNTER_0_BASE,2));
	 	return 0;
}



