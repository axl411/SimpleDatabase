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
#include "Table.h"
#include "InputBuffer.h"
#include "Node.h"
#include "Pager.h"

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table) {
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
        close_input_buffer(input_buffer);
        db_close(table);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(input_buffer->buffer, ".constants") == 0) {
        printf("Constants:\n");
        print_constants();
        return META_COMMAND_SUCCESS;
    }
    else if (strcmp(input_buffer->buffer, ".btree") == 0) {
        printf("Tree:\n");
        print_leaf_node(get_page(table->pager, 0));
        return META_COMMAND_SUCCESS;
    }
    else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}
