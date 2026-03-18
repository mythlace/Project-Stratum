/**
 * @file sdram_test.c
 *
 * @date Mar 6, 2026
 * @author mdev 
 */


#include "sdram_test.h"
#include <stdio.h>

/**
 * Note: This code assumes SDRAM is accessed as a 32-bit wide memory region.
 * base must be 32-bit aligned and size must be a multiple of 4 bytes.
 */

static mem_status_t sdram_data_bus_test(volatile uint32_t *base){
	// Walking 1
	for(uint32_t pattern = 1; pattern != 0; pattern <<= 1){
		*base = pattern;
		if(*base != pattern){
			printf("[e] SDRAM Data bus test (walking 1) failed.\n ");
			printf("    Expected: 0x%08lX got 0x%08lX\n", pattern, *base);
			return MEM_STATUS_PROBE_FAIL;
		}
	}

	// Walking 0
	for(uint32_t pattern = 1; pattern != 0; pattern <<= 1){
		uint32_t anti_pattern = ~pattern;
		*base = anti_pattern;
		if(*base != anti_pattern){
			printf("[e] SDRAM Data bus test (walking 0) failed.\n ");
			printf("    Expected: 0x%08lX got 0x%08lX\n", anti_pattern, *base);
			return MEM_STATUS_PROBE_FAIL;
		}
	}

	return MEM_STATUS_PROBE_OK;
}

static mem_status_t sdram_address_bus_test(volatile uint32_t *base, uint32_t words){

	const uint32_t pattern = 0xAAAAAAAA;
	const uint32_t anti_pattern = 0x55555555;

	// Write patterns to powers of 2
	for(uint32_t offset = 1; offset < words; offset <<= 1) {
		base[offset] = pattern;
	}

	// Write anti-pattern to base address
	base[0] = anti_pattern;

	// Check for line stuck high
	for (uint32_t offset = 1; offset < words; offset <<= 1) {
		if(base[offset] != pattern) {
			printf("[e] SDRAM Address bus test failed. Address line stuck high detected\n");
			printf("    0x%08X: Expected 0x%08lX got 0x%08lX\n", (uintptr_t)(&base[offset]), pattern, base[offset]);
			return MEM_STATUS_PROBE_FAIL;
		}
	}

	// Restore the base pattern
	base[0] = pattern;

	// Check for shorted address lines
	for (uint32_t offset = 1; offset < words; offset <<= 1) {
		base[offset] = anti_pattern;

		if (base[0] != pattern){
			printf("[e] SDRAM Address bus test failed. Address lines short detected\n");
			printf("    0x%08X: Expected 0x%08lX got 0x%08lX\n", (uintptr_t)(&base[0]), pattern, base[0]);
			return MEM_STATUS_PROBE_FAIL;
		}
		// Verify other addresses are unchanged
		for (uint32_t offset2 = 1; offset2 < words; offset2 <<= 1){
			if ((offset2 != offset) && (base[offset2] != pattern)){
				printf("[e] SDRAM Address bus test failed. Address lines short detected\n");
				printf("    0x%08X: Expected 0x%08lX got 0x%08lX\n", (uintptr_t)(&base[offset]), pattern, base[offset2]);
				return MEM_STATUS_PROBE_FAIL;
			}
		}
		// Restore pattern
		base[offset] = pattern;
	}

	return MEM_STATUS_PROBE_OK;
}


static mem_status_t sdram_pattern_test(volatile uint32_t *base, uint32_t words){
	// Data pattern test
	const uint32_t test_patterns[] = {
		0x00000000,
		0xFFFFFFFF,
		0x55555555,
		0xAAAAAAAA,
		0x12345678,
		0x87654321,
	};

	uint32_t step = words / (sizeof(test_patterns)/sizeof(test_patterns[0]));
	if (step == 0) {
		step = 1;
	}

	for (uint32_t tp_idx = 0; tp_idx < (sizeof(test_patterns)/sizeof(test_patterns[0])); tp_idx++){
		uint32_t test_pattern = test_patterns[tp_idx];

		// Write test pattern
		for (uint32_t offset = 0; offset < words; offset += step) {
			base[offset] = test_pattern;
		}

		// Verify test pattern
		for (uint32_t offset = 0; offset < words; offset += step) {
			if(base[offset] != test_pattern) {
				printf("[e] SDRAM pattern test failed\n");
				printf("    At 0x%08X: Expected: 0x%08lX got 0x%08lX\n", (uintptr_t)(&base[offset]), test_pattern, base[offset]);
				return MEM_STATUS_PROBE_FAIL;
			}
		}
	}

	return MEM_STATUS_PROBE_OK;
}

static mem_status_t sdram_increment_test(volatile uint32_t *base, uint32_t words){
	for(uint32_t offset = 0; offset < words; offset++){
		base[offset] = offset;
	}

	for(uint32_t offset = 0; offset < words; offset++){
		if (base[offset] != offset){
			printf("[e] SDRAM increment test failed\n");
			printf("    At 0x%08X: Expected: 0x%08lX got 0x%08lX\n", (uintptr_t)(&base[offset]), offset, base[offset]);
			return MEM_STATUS_PROBE_FAIL;
		}
	}

	return MEM_STATUS_PROBE_OK;
}

static mem_status_t sdram_basic_march_test(volatile uint32_t *base, uint32_t words){
	for (uint32_t offset = 0; offset < words; offset++){
		base[offset] = 0;
	}

	for (uint32_t offset = 0; offset < words; offset++){
		if(base[offset] != 0){
			printf("[e] SDRAM march test (step 1) failed\n");
			printf("    At 0x%08X: Expected: 0x00000000 got 0x%08lX\n", (uintptr_t)(&base[offset]), base[offset]);
			return MEM_STATUS_PROBE_FAIL;
		}
		base[offset] = 0xFFFFFFFF;
	}

	for (uint32_t offset = 0; offset < words; offset++){
		if(base[offset] != 0xFFFFFFFF){
			printf("[e] SDRAM march test (step 2) failed\n");
			printf("    At 0x%08X: Expected: 0xFFFFFFFF got 0x%08lX\n", (uintptr_t)(&base[offset]), base[offset]);
			return MEM_STATUS_PROBE_FAIL;
		}
		base[offset] = 0;
	}

	for (uint32_t offset = 0; offset < words; offset++){
		if(base[offset] != 0){
			printf("[e] SDRAM march test (step 3) failed\n");
			printf("    At 0x%08X: Expected: 0x00000000 got 0x%08lX\n", (uintptr_t)(&base[offset]), base[offset]);
			return MEM_STATUS_PROBE_FAIL;
		}
	}
	return MEM_STATUS_PROBE_OK;
}

mem_status_t sdram_test(uint32_t base, uint32_t size){
	volatile uint32_t *base_mem = (volatile uint32_t *)base;

	uint32_t words = size / sizeof(uint32_t);
	mem_status_t mem_status;
	printf("[i] Testing SDRAM at 0x%08lX\n", base);

	mem_status = sdram_data_bus_test(base_mem);
	if(mem_status != MEM_STATUS_PROBE_OK) return mem_status;

	mem_status = sdram_address_bus_test(base_mem, words);
	if(mem_status != MEM_STATUS_PROBE_OK) return mem_status;

	mem_status = sdram_pattern_test(base_mem, words);
	if(mem_status != MEM_STATUS_PROBE_OK) return mem_status;

	mem_status = sdram_increment_test(base_mem, words);
	if(mem_status != MEM_STATUS_PROBE_OK) return mem_status;

	mem_status = sdram_basic_march_test(base_mem, words);
	if(mem_status != MEM_STATUS_PROBE_OK) return mem_status;

	printf("[i] SDRAM test complete\n");

	return MEM_STATUS_PROBE_OK;
}
