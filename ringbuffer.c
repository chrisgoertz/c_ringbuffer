/*
 * ringbuffer.c
 *
 *  Created on: Jan 21, 2024
 *      Author: chris
 */

#include "ringbuffer.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

/******************************************************************************
 * Initialize and clear the ringbuffer.
 * @param rb: ringbuffer_t*
 * @param size: uint32_t desired size of the buffer vector.
 *              Pass 0 to use default size.
 *****************************************************************************/
void ringBuffer_init(ringbuffer_t *rb, uint32_t size) {
  if (0 == size) {
    rb->size = RINGBUFFER_DEFAULT_SIZE;
  } else {
    rb->size = size;
  }
  rb->buffer = malloc(sizeof(uint8_t) * rb->size);
  ringBuffer_clear(rb);
}

/******************************************************************************
 * Free allocated memory for the buffer.
 * @param rb: ringbuffer_t*
 *****************************************************************************/
void ringBuffer_delete(ringbuffer_t *rb) { free(rb->buffer); }

/******************************************************************************
 * clear the ringbuffer.
 * @param rb: ringbuffer_t*
 *****************************************************************************/
void ringBuffer_clear(ringbuffer_t *rb) {
  memset(rb->buffer, 0, rb->size);
  rb->head = rb->buffer;
  rb->tail = rb->buffer;
}

/******************************************************************************
 * return true, if RingBuffer is empty.
 * @param rb: ringbuffer_t*
 * @return bool true if empty
 *****************************************************************************/
bool ringBuffer_isEmpty(ringbuffer_t *rb) {
  // if head pointer is pointing the same address as tail pointer,
  // there is no data to read anymore.
  if (rb->head == rb->tail) {
    return true;
  }
  // otherwise, the buffer is not empty so return false.
  return false;
}

/******************************************************************************
 * Get first element from ringbuffer.
 * @param rb: ringbuffer_t*
 * @return uint8_t copy of first element.
 *****************************************************************************/
uint8_t ringBuffer_first(ringbuffer_t *rb) { return (rb->buffer[0]); }

/******************************************************************************
 * Get last element from ringbuffer.
 * @param rb: ringbuffer_t*
 * @return uint8_t copy of last element.
 *****************************************************************************/
uint8_t ringBuffer_last(ringbuffer_t *rb) {
  return (rb->buffer[RINGBUFFER_DEFAULT_SIZE - 1]);
}

/******************************************************************************
 * Get element at index.
 * @param rb: ringbuffer_t*
 * @param at: uint32_t index
 * @return uint8_t copy of element at index.
 *****************************************************************************/
uint8_t ringBuffer_at(ringbuffer_t *rb, uint32_t at) {
  return (rb->buffer[at]);
}

/******************************************************************************
 * Push new element on ringbuffer.
 * @param rb: ringbuffer_t*
 * @param chr: uint8_t element to push.
 *****************************************************************************/
void ringBuffer_push(ringbuffer_t *rb, uint8_t chr) {
  // write byte to buffer head position.
  *(rb->head) = chr;
  // increment head position.
  rb->head++;
  // test if head position is exceeding buffer size.
  if (rb->head >= rb->buffer + rb->size) {
    // head pointer is exceeding buffer size.
    // reset pointer to buffer beginning.
    rb->head = rb->buffer;
  }
}

/******************************************************************************
 * Read one byte from RingBuffer
 * @param rb: ringbuffer_t*
 * @return uint8_t: byte
 *****************************************************************************/
uint8_t ringBuffer_get(ringbuffer_t *rb) {
  // copy buffer data from tail position
  // to the stack.
  uint8_t data = *(rb->tail);
  // increment tail position.
  rb->tail++;
  // test if tail position is exceeding buffer size.
  if (rb->tail >= rb->buffer + rb->size) {
    // tail pointer is exceeding buffer size.
    // reset pointer to buffer beginning.
    rb->tail = rb->buffer;
  }
  return data;
}
