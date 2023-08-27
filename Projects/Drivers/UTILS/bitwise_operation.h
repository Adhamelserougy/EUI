#ifndef UTILS_H_
#define UTILS_H_

#define READ_BIT(reg,bit)  (((reg)>>(bit))&1)
#define SET_BIT(reg,bit)  (reg = (reg) | (1<<(bit)))
#define TOGGLE_BIT(reg,bit)  (reg = (reg) ^ (1<<(bit)))
#define CLEAR_BIT(reg,bit)  (reg = (reg) & (~(1<<(bit))))
#define READ_BITS(reg,offset,num)  ((reg) & ((1 << ((end) - (start) + 1)) - 1) << (start))
#define SET_BITS(reg,start,end)  ((reg) |= ((1 << ((end) - (start) + 1)) - 1) << (start))
#define TOGGLE_BITS(reg,start,end)  ((reg) ^= ((1 << ((end) - (start) + 1)) - 1) << (start))
#define CLEAR_BITS(reg,start,end)  ((reg) &= ((1 << ((end) - (start) + 1)) - 1) << (start))

#endif /* UTILS_H_ */
