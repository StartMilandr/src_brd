#include "brdUtils.h"

void Delay(uint32_t ticks)
{
	uint32_t i;
	for(i = 0; i < ticks; i++){}
}

uint32_t BRD_IsGT(uint32_t value, uint32_t level)
{
  return value > level;
}

uint32_t BRD_IsLT(uint32_t value, uint32_t level)
{
  return value < level;
}

uint32_t BRD_IsEQ(uint32_t value, uint32_t level)
{
  return value == level;
}

uint32_t BRD_IsNE(uint32_t value, uint32_t level)
{
  return value != level;
}

uint32_t Pseudo_Rand(uint32_t addr)
{
  uint32_t hash = 0;
  uint32_t i = 0;
  uint8_t* key = (uint8_t *)&addr;

  for (i = 0; i < 4; i++)
  {
    hash += key[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }

  for (i = 0; i < 256; i++)
  {
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }

  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return hash;
}
