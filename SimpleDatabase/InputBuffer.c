//
//  InputBuffer.c
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/05.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#include "InputBuffer.h"
#include <stdlib.h>

InputBuffer* new_input_buffer(void) {
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}
