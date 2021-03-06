/*
 * qspi-descr.h
 *
 * Copyright (c) 2017, 2018, 2020 Lix N. Paulian (lix@paulian.net)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Created on: 1 Jan 2017 (LNP)
 */

#ifndef QSPI_DESCR_H_
#define QSPI_DESCR_H_

#include "stdint.h"

namespace os
{
  namespace driver
  {
    namespace stm32f7
    {

#define MANUF_ID_MICRON 0x20
#define MANUF_ID_WINBOND 0xEF

      typedef struct qspi_device_s
      {
        uint16_t device_ID;
        uint16_t sector_size;
        const char* device_name;

        // following parameters used only in fast read mode
        uint32_t alt_bytes;       // optional alt bytes
        uint32_t alt_bytes_mode;  // none, one, two or four lines
        uint32_t alt_bytes_size;  // 8, 16 or 32 bits
        uint8_t dummy_cycles;     // dummy cycles
        uint8_t alt_bytes_cycles; // alt bytes cycles to subtract from dummy cycles
        bool DDR_support;         // dual data rate (not used for now)
      } qspi_device_t;

      typedef struct qspi_manuf_s
      {
        uint8_t manufacturer_ID;
        const char* manufacturer_name;
        const qspi_device_t* devices;
        class qspi_intern*
        (*qspi_factory) ();
      } qspi_manuf_t;

      extern const qspi_manuf_t qspi_manufacturers[];

    } /* namespace stm32f7 */
  } /* namespace driver */
} /* namespace os */

#endif /* QSPI_DESCR_H_ */
