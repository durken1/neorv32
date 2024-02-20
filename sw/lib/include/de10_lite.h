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
inline void __attribute__ ((always_inline)) de10_lite_7seg_write_unsigned_hex(uint32_t wdata) {

//    neorv32_cpu_store_unsigned_word(90000000, wdata);
  uint32_t reg_addr_data = 0x90000000;
  uint32_t reg_addr_setup = 0x90000004;
  uint32_t reg_data = wdata;
  uint32_t reg_setup = 0x00000000;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_setup), [ad] "r" (reg_addr_setup));
  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_data), [ad] "r" (reg_addr_data));
}

/**********************************************************************//**
 * Output value to 7seg display
 *
 * @param[in] wdata Data word (32-bit) to store.
 **************************************************************************/
inline void __attribute__ ((always_inline)) de10_lite_7seg_write_signed_hex(int32_t wdata) {

//    neorv32_cpu_store_unsigned_word(90000000, wdata);
  uint32_t reg_addr_data = 0x90000000;
  uint32_t reg_addr_setup = 0x90000004;
  uint32_t reg_data = wdata;
  uint32_t reg_setup = 0x00000001;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_setup), [ad] "r" (reg_addr_setup));
  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_data), [ad] "r" (reg_addr_data));
}

/**********************************************************************//**
 * Output value to 7seg display
 *
 * @param[in] wdata Data word (32-bit) to store.
 **************************************************************************/
inline void __attribute__ ((always_inline)) de10_lite_7seg_write_unsigned_dec(int32_t wdata) {

//    neorv32_cpu_store_unsigned_word(90000000, wdata);
  uint32_t reg_addr_data = 0x90000000;
  uint32_t reg_addr_setup = 0x90000004;
  uint32_t reg_data = wdata;
  uint32_t reg_setup = 0x00000002;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_setup), [ad] "r" (reg_addr_setup));
  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_data), [ad] "r" (reg_addr_data));
}

/**********************************************************************//**
 * Output value to 7seg display
 *
 * @param[in] wdata Data word (32-bit) to store.
 **************************************************************************/
inline void __attribute__ ((always_inline)) de10_lite_7seg_write_signed_dec(int32_t wdata) {

//    neorv32_cpu_store_unsigned_word(90000000, wdata);
  uint32_t reg_addr_data = 0x90000000;
  uint32_t reg_addr_setup = 0x90000004;
  uint32_t reg_data = wdata;
  uint32_t reg_setup = 0x00000003;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_setup), [ad] "r" (reg_addr_setup));
  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_data), [ad] "r" (reg_addr_data));
}

/**********************************************************************//**
 * Output loading animation to 7seg display
 *
 **************************************************************************/
inline void __attribute__ ((always_inline)) de10_lite_7seg_enable_loading(void) {

//    neorv32_cpu_store_unsigned_word(90000000, wdata);
  uint32_t reg_addr_setup = 0x90000004;
  uint32_t reg_setup = 0x00000004;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_setup), [ad] "r" (reg_addr_setup));
}

/**********************************************************************//**
 * Output loading animation to 7seg display
 *
 **************************************************************************/
inline void __attribute__ ((always_inline)) de10_lite_7seg_disable_loading(void) {

//    neorv32_cpu_store_unsigned_word(90000000, wdata);
  uint32_t reg_addr_setup = 0x90000004;
  uint32_t reg_setup = 0x00000000;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_setup), [ad] "r" (reg_addr_setup));
}

#endif // de10_lite_h