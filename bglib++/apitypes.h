
#ifndef APITYPES_H_
#define APITYPES_H_

#include <cstdint>

typedef struct bd_addr_t
{
    uint8_t addr[6];

}bd_addr;

typedef bd_addr hwaddr;
typedef struct
{
    uint8_t len;
    uint8_t data[];
}uint8array;

typedef struct
{
    uint8_t len;
    int8_t data[];
}string;


#endif
