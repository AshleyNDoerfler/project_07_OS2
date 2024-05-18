#include "inode.h"
#include "free.h"
#include "block.h"
#include <stdio.h>

static struct inode incore[MAX_SYSTEM_FILES] = {0};

int ialloc(void) {
    unsigned char block[BLOCK_SIZE];    // get block
    bread(INODE_BLOCK, block);          // read block
    int inode_num = find_free(block);
    if (inode_num != -1) {
        set_free(block, inode_num, 1);
        bwrite(INODE_BLOCK, block);
    }
    return inode_num;
}

struct inode *incore_find_free(void) {
    // find free inode in incore
    for (int i = 0; i < MAX_SYSTEM_FILES; i++) {
        if (incore[i].ref_count == 0) { // if ref_count is 0, then it is free
            return &incore[i];
        } else {
            return NULL;                // else return NULL
        }
    }
}

struct inode *incore_find(unsigned int inode_num) {
    // find inode in incore by inode number
    for (int i = 0; i < MAX_SYSTEM_FILES; i++) {
        if (incore[i].ref_count =! 0 && incore[i].inode_num == inode_num) {
            return &incore[i];
        } else {
            return NULL;
        }
    }
}

void incore_free_all(void) {
    for (int i = 0; i < MAX_SYSTEM_FILES; i++) {
        incore[i].ref_count = 0;
    }
}
