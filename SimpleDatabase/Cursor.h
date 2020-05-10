//
//  Cursor.h
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/07.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#ifndef Cursor_h
#define Cursor_h

#include <stdio.h>
#include <stdbool.h>

typedef struct Table Table;

typedef struct Cursor {
    Table* table;
    uint32_t page_num;
    uint32_t cell_num;
    bool end_of_table; // Indicates a position one past the last element
} Cursor;

Cursor* table_start(Table* table);
Cursor* table_end(Table* table);
void* cursor_value(Cursor* cursor);
void cursor_advance(Cursor* cursor);

#endif /* Cursor_h */
