//
//  InputBuffer.h
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/05.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#ifndef InputBuffer_h
#define InputBuffer_h

#include <stdio.h>

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer(void);
void close_input_buffer(InputBuffer* input_buffer);

#endif /* InputBuffer_h */
