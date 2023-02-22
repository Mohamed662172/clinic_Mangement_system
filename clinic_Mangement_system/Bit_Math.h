
  
#ifndef __Bit_Math__
#define __Bit_Math__

#define SetBit(Reg, BitNum) (Reg |= (1 << BitNum))
#define ClearBit(Reg, BitNum) (Reg &= (1 << BitNum))
#define ToggelBit(Reg, BitNum) (Reg ^= (1 << BitNum))
#define GetBit(Reg, BitNum) ((Reg >> BitNum) & 1)


#endif