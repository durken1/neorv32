/**********************************************************************//**
 * @file neorv32_cpu.h
 * @brief CPU Core Functions HW driver header file.
 **************************************************************************/

#ifndef de10_lite_h
#define de10_lite_h


/**********************************************************************//**
 * Output value to 7seg display
 *
 * @param[in] wdata Data word (32-bit) to store.
 **************************************************************************/
inline void __attribute__ ((always_inline)) de10_lite_7seg_write(uint32_t wdata) {

//    neorv32_cpu_store_unsigned_word(90000000, wdata);
  uint32_t reg_addr = 0x90000000;
  uint32_t reg_data = wdata;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_data), [ad] "r" (reg_addr));
}

#endif // de10_lite_h