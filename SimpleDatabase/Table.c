//
//  Table.c
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/06.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#include <stdlib.h>

#include "Table.h"
#include "Row.h"

const uint32_t PAGE_SIZE = 4096;
uint32_t ROWS_PER_PAGE() { return PAGE_SIZE / ROW_SIZE; };
uint32_t TABLE_MAX_ROWS() { return ROWS_PER_PAGE() * TABLE_MAX_PAGES; }

Table* new_table() {
    Table* table = malloc(sizeof(Table));
    table->num_rows = 0;
    for (uint32_t i = 0; i < TABLE_MAX_PAGES; i++) {
        table->pages[i] = NULL;
    }
    return table;
}

void free_table(Table* table) {
    for (int i = 0; table->pages[i]; i++) {
        free(table->pages[i]);
    }
    free(table);
}

void* row_slot(Table* table, uint32_t row_num) {
    uint32_t page_num = row_num / ROWS_PER_PAGE();
    void* page = table->pages[page_num];
    if (page == NULL) {
        // Allocate memory only when we try to access page
        page = table->pages[page_num] = malloc(PAGE_SIZE);
    }
    uint32_t row_offset = row_num % ROWS_PER_PAGE();
    uint32_t byte_offset = row_offset * ROW_SIZE;
    return page + byte_offset;
}
