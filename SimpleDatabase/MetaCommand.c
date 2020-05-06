//
//  MetaCommand.c
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/06.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "MetaCommand.h"

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table) {
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
        close_input_buffer(input_buffer);
        free_table(table);
        exit(EXIT_SUCCESS);
    }
    else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}
