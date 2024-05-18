#include "inode.h"
#include "free.h"
#include "block.h"
#include "pack.h"
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
        }
    }
    return NULL; // return NULL if not found
}

struct inode *incore_find(unsigned int inode_num) {
    // find inode in incore by inode number
    for (int i = 0; i < MAX_SYSTEM_FILES; i++) {
        if ((incore[i].ref_count =! 0) && (incore[i].inode_num == inode_num)) {
            return &incore[i];
        }
    }
    return NULL; // return NULL if not found
}

void incore_free_all(void) {
    for (int i = 0; i < MAX_SYSTEM_FILES; i++) {
        incore[i].ref_count = 0;
    }
}

int block_offest(int inode_num){
    int block_num = inode_num / INODES_PER_BLOCK + INODE_FIRST_BLOCK;
    int block_offset = inode_num % INODES_PER_BLOCK;
    int block_offset_bytes = block_offset * INODE_SIZE;

    return block_num, block_offset_bytes;
}

void read_inode(struct inode *in, int inode_num){
    unsigned char block[BLOCK_SIZE];
    int block_num, block_offset_bytes;
    block_num, block_offset_bytes = block_offset(inode_num);
    
    bread(block_num, block);

    struct inode *inode = read_u32(block + block_offset_bytes);
}

void write_inode(struct inode *in){
    unsigned char block[BLOCK_SIZE];
    int block_num, block_offset_bytes;
    block_num, block_offset_bytes = block_offset(in->inode_num);
    
    bread(block_num, block);

    write_u8(block + block_offset_bytes, in);
    bwrite(block_num, block);
}