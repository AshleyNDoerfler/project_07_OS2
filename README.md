## How To Run
First compile the program using `make` (or `make pristine` to clear previous files in the process).

Run: `./main`

## Files
    - `image.c`: Manages image file.
    - `block.c`: Read and write from a block.
    - `testfs.c`: Tests _block.c_ and _image.c_.
    - `free.c`: Frees bits.
    - `inode.c`: Allocates space for the inode.
    - `pack.c`: Reads and Writes unsigned numbers of different numbers of bits/bytes.

## Functions

### Block.c
    - `bread`: Finds the block offset based on a block number and reads from the image file.
    - `bwrite`: Finds the block offset based on a block number and writes to the image file.
    - `alloc`: Allocates a block of data.
### image.c
    - `image_open`: Opens a image file given a file name.
    - `image_close`: Closes the file image.
### testfs.c
    - _test_image_open_: tests _image.c_ image_open function.
    - _test_image_open_: tests _image.c_ image_close function.
    - _test_block_bread_: tests bread.
    - _test_block_bwrite_: tests bwrite.
### free.c
    - _set_free_: Sets a bit to free (0).
    - _find_free_: Finds the first free fit.
### inode.c
    - _ialloc_: Allocates space for the inode block.
    - _incore_find_free_: Finds the first free in-core  inode in the incore array and returns a pointer to it.
    - _incore_find_: Finds an in-core inode recod in the incore aaray by the inode number.
    - _incore_free_all_:Sets the ref_count to all in-core nodes to 0.
### pack.c
    - _read_u_32_: Reads an unsigned 32-bit integer from a buffer.p
    - _read_u16_: Reads an unsigned 16-bit integer from a buffer.
    - _read_u8_:  Reads an unsigned 8-bit integer from a buffer.
    - _write_u32_: Writes an unsigned 32-bit integer to a buffer.
    - _write_u16_: Writes an unsigned 16-bit integer to a buffer.
    - _write_u8_: Writes an unsigned 8-bit integer to a buffer.
    
