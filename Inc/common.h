/*
 * common.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Suspicious Tom
 */

#ifndef COMMON_H_
#define COMMON_H_

/*
 *  Typedef declarations
 */
typedef uint8_t UINT8;
typedef uint32_t UINT32;


/*
 *  Enum declarations
 */
typedef enum {
    OPERATION_FAILED = 0,
    OPERATION_SUCCESS = 1
} OPERATION_RESULT;

/*
 *  Macros for setting and clearing a bit in a register
 */

#define SET_BIT(REG,PIN)        ((REG) |= (PIN))
#define CLEAR_BIT(REG,PIN)      ((REG) &= ~(PIN))

#endif /* COMMON_H_ */
