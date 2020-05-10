//
//  Node.h
//  SimpleDatabase
//
//  Created by 顾超 on 2020/05/09.
//  Copyright © 2020 Chao Gu. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>

typedef struct Cursor Cursor;
typedef struct Row Row;

uint32_t LEAF_NODE_MAX_CELLS(void);

uint32_t* leaf_node_num_cells(void* node);
void* leaf_node_value(void* node, uint32_t cell_num);
void initialize_leaf_node(void* node);
void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value);
void print_constants(void);
void print_leaf_node(void* node);

#endif /* Node_h */
