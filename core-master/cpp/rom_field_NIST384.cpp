#include "arch.h"
#include "fp_NIST384.h"

namespace NIST384 {

/* Curve NIST384 */

#if CHUNK==16

#error Not supported

#endif

#if CHUNK==32

using namespace B384_29;

// Base Bits= 29
const BIG Modulus= {0x1FFFFFFF,0x7,0x0,0x1FFFFE00,0x1FFFEFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x7F};
const BIG ROI= {0x1FFFFFFE,0x7,0x0,0x1FFFFE00,0x1FFFEFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x1FFFFFFF,0x7F};
const BIG R2modp= {0x0,0x8000,0x1FF80000,0x1FFFFF,0x2000000,0x0,0x0,0x1FFFFFFC,0xF,0x100,0x400,0x0,0x0,0x0};
const chunk MConst= 0x1;
#endif

#if CHUNK==64

using namespace B384_56;

// Base Bits= 56
const BIG Modulus= {0xFFFFFFFFL,0xFFFF0000000000L,0xFFFFFFFFFEFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFL};
const BIG ROI= {0xFFFFFFFEL,0xFFFF0000000000L,0xFFFFFFFFFEFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFFFL,0xFFFFFFFFFFFFL};
const BIG R2modp= {0xFE000000010000L,0xFFFFFFL,0x2L,0xFFFFFFFE00L,0x1000000020000L,0x0L,0x0L};
const chunk MConst= 0x100000001L;

#endif

}
