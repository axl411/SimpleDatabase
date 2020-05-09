//
//  MetaCommand.h
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/06.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#ifndef MetaCommand_h
#define MetaCommand_h

#include <stdio.h>

typedef struct InputBuffer InputBuffer;
typedef struct Table Table;

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);

#endif /* MetaCommand_h */
