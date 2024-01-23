/*
 * ringbuffer.h
 * Circular buffer data structure for my mcu project.
 * Indendet to be lightwight.
 *
 * @created: 2024-01-21
 * @author: cg <chris.goertz@gmx.de>
 *
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_
/* std lib */
#include <stdbool.h>
#include <stdint.h>

#define RINGBUFFER_DEFAULT_SIZE (128U)

/******************************************************************************
 * Ringbuffer type definition
 *****************************************************************************/
typedef struct ringb {
  uint32_t size;   // ringbuffer capacity
  uint8_t *head;   // pointer to next write position
  uint8_t *tail;   // pointer to next read position
  uint8_t *buffer; // data vector
} ringbuffer_t;    // ringbuffer type def

/******************************************************************************
 * function prototypes
 *****************************************************************************/
void ringBuffer_init(ringbuffer_t *rb, uint32_t size);
void ringBuffer_clear(ringbuffer_t *rb);
void ringBuffer_delete(ringbuffer_t *rb);
bool ringBuffer_isEmpty(ringbuffer_t *rb);
uint8_t ringBuffer_first(ringbuffer_t *rb);
uint8_t ringBuffer_last(ringbuffer_t *rb);
uint8_t ringBuffer_at(ringbuffer_t *rb, uint32_t at);
void ringBuffer_push(ringbuffer_t *rb, uint8_t chr);
uint8_t ringBuffer_get(ringbuffer_t *rb);
#endif /* INC_RINGBUFFER_H_ */
