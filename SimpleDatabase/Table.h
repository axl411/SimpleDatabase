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

typedef struct Pager Pager;

extern const uint32_t PAGE_SIZE;
#define TABLE_MAX_PAGES 100
extern uint32_t ROWS_PER_PAGE(void);
extern uint32_t TABLE_MAX_ROWS(void);

typedef struct Table {
    uint32_t num_rows;
    Pager* pager;
} Table;

Table* db_open(const char* filename);
void db_close(Table* table);

#endif /* Table_h */
