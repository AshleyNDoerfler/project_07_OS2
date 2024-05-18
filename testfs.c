#include "image.h"
#include "block.h"
#include "free.h"
#include "inode.h"
#include "testfs.h"
#include <stdio.h>
#include <string.h>

#ifdef CTEST_ENABLE

void test_image_open(){
    CTEST_ASSERT(image_open("filesystem.img", 1) != -1, "checking image open return value");
}

void test_image_close(){
    CTEST_ASSERT(image_close() != -1, "checking image close return value");
}

void test_block_bwrite_and_read(){
    unsigned char block[BLOCK_SIZE];
    unsigned char data[BLOCK_SIZE] = "Hello, World!";
    
    bwrite(0, block);

    unsigned char *read_block = bread(0, block);
    CTEST_ASSERT(memcmp(read_block, data, BLOCK_SIZE), "checking memory block after using bwrite and bread");
}

void test_set_free(){
    unsigned char block[BLOCK_SIZE];
    int num = 10;
    int set = 1;
    set_free(block, num, set);
    CTEST_ASSERT((block[num / 8] & (1 << (num % 8))) == (set << (num % 8)), "checking set_free block value");
}

void test_find_free(){
    unsigned char block[BLOCK_SIZE];
    CTEST_ASSERT(find_free(block) != -1, "checking find_free return value");
}

void test_ialloc(){
    CTEST_ASSERT(ialloc() != -1, "checking ialloc return value");
}

void test_alloc(){
    CTEST_ASSERT(alloc() != -1, "checking alloc return value");
}

int main(){
    CTEST_VERBOSE(1);
    
    test_image_open();
    test_image_close();
    test_block_bwrite_and_read();
    test_set_free();
    test_find_free();
    test_ialloc();
    test_alloc();

    CTEST_RESULTS();
    CTEST_EXIT();
}

#else

int main(){
    
    // Test image open
    image_open("filesystem.img", 1);
    // Test image close
    image_close();
    
    unsigned char buffer[BLOCK_SIZE];
    // Test block bread
    bread(0, buffer);

    // Test block bwrite
    bwrite(0, buffer);

    // Test set_free
    unsigned char block[BLOCK_SIZE];
    set_free(block, 0, 1);

    // Test find_free
    find_free(block);

    // Test iaalloc
    ialloc();

    // Print success message
    printf("Testfs is working\n");
    return 0;
}

#endif