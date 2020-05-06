//
//  Statement.h
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/06.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#ifndef Statement_h
#define Statement_h

#include <stdio.h>

#include "Row.h"
#include "InputBuffer.h"
#include "Table.h"

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct {
    StatementType type;
    Row row_to_insert; // only used by insert statement
} Statement;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum {
    EXECUTE_SUCCESS,
    EXECUTE_TABLE_FULL
} ExecuteResult;

PrepareResult prepare_statement(InputBuffer* input_buffer,Statement* statement);
ExecuteResult execute_statement(Statement* statement, Table* table);

#endif /* Statement_h */
