#include "inode.h"
#include "free.h"
#include "block.h"

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