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

  uint32_t reg_addr_setup = 0x90000004;
  uint32_t reg_setup = 0x00000004;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_setup), [ad] "r" (reg_addr_setup));
}

/**********************************************************************//**
 * Output loading animation to 7seg display
 *
 **************************************************************************/
inline void __attribute__ ((always_inline)) de10_lite_7seg_disable_loading(void) {

  uint32_t reg_addr_setup = 0x90000004;
  uint32_t reg_setup = 0x00000000;

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_setup), [ad] "r" (reg_addr_setup));
}

/**********************************************************************//**
 * Send santa directions (aoc 2015) to FPGA
 * 
 * @note To make santa move, toggle needs to be negated value of toggle last
 *       call (1/0)
 *
 **************************************************************************/
inline void __attribute__ ((always_inline)) de10_lite_move_santa(char c, int toggle) {

  uint32_t reg_addr_data = 0x90000008;
  uint32_t reg_data = 0x90000000;
  switch(c)
  {
    case '>':
    reg_data = 0x90000004;
    break;

    case '<':
    reg_data = 0x90000005;
    break;

    case '^':
    reg_data = 0x90000006;
    break;

    case 'v':
    reg_data = 0x90000007;
    break;

  }

  asm volatile ("sw %[da], 0(%[ad])" : : [da] "r" (reg_data), [ad] "r" (reg_addr_data));
}

/**********************************************************************//**
 * Read number of houses from FPGA
 *
 **************************************************************************/
inline uint32_t __attribute__ ((always_inline)) de10_lite_get_n_houses(void) {

  uint32_t reg_addr = 0x90000000;
  uint32_t reg_data;

  asm volatile ("lw %[da], 0(%[ad])" : [da] "=r" (reg_data) : [ad] "r" (reg_addr));

  return reg_data;
}

#endif // de10_lite_h