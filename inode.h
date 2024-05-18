#ifndef INODE_H
#define INODE_H

int ialloc(void);
struct inode *incore_find_free(void);
struct inode *incore_find(unsigned int inode_num);
void incore_free_all(void);

#endif