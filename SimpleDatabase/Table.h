//
//  Table.h
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/06.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#ifndef Table_h
#define Table_h

#include <stdio.h>

extern const uint32_t PAGE_SIZE;
#define TABLE_MAX_PAGES 100
extern uint32_t TABLE_MAX_ROWS(void);

typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
} Table;

Table* new_table(void);
void free_table(Table* table);

void* row_slot(Table* table, uint32_t row_num);

#endif /* Table_h */
