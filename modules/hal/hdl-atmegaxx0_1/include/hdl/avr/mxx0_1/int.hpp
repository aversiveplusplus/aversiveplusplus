/*
Copyright (c) 2015, Xenomorphales
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of Aversive++ nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef HDL_AVR_MEGA_XX0_1_INT_HPP
#define HDL_AVR_MEGA_XX0_1_INT_HPP

#include<base/integer.hpp>
using namespace Aversive::Base;

#define INTERRUPT				\
  __attribute__((signal,section(".text.interrupt")))

namespace HDL {

  namespace Interrupts {

    template<u8 ID>
    struct External {
      static void interrupt(void) INTERRUPT;
    };

    template<u8 ID>
    struct PinChange {
      static void interrupt(void) INTERRUPT;
    };

    template<u8 ID>
    struct TIMER {
      template<u8 OC_ID>
      struct OC {
	static void comp(void) INTERRUPT;
      };
      static void ovf(void) INTERRUPT;
      static void capt(void) INTERRUPT;
    };

    template<u8 ID>
    struct UART {
      static void tx(void) INTERRUPT;
      static void rx(void) INTERRUPT;
      static void dre(void) INTERRUPT;
    };

  }
  
}

#undef INTERRUPT

#endif//HDL_AVR_MEGA_XX0_1_INT_HPP
