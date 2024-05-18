## How To Run
First compile the program using `make` (or `make pristine` to clear previous files in the process).

Run: `./main`

## Files
    - `image.c`: manages image file.
    - `block.c`: read and write from a block.
    - `testfs.c`: Tests _block.c_ and _image.c_.

## Functions

### Block.c
    - `bread`: Finds the block offset based on a block number and reads from the image file.
    - `bwrite`: Finds the block offset based on a block number and writes to the image file.
### image.c
    - `image_open`: Opens a image file given a file name.
    - `image_close`: Closes the file image.
### testfs.c
    - _test_image_open_: tests _image.c_ image_open function.
    - _test_image_open_: tests _image.c_ image_close function.
    - _test_block_bread_: tests bread.
    - _test_block_bwrite_: tests bwrite.
    
