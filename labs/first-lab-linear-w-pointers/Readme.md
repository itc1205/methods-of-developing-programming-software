# First Labaratory-work (Linear w pointers type) - variant 3

## Usage of the program

1. Inserting records

    Firstly choose the 1.INSERT option.

    Then fill in all the data that program will ask you.

    And then program will automatically save it for you.

2. List all of the records

    Firstly choose the 2.LIST option.

    Then the program will display the copy-friendly table

3. Searching by attributes

    Firstly choose the 3.LOOKUP option.

    Then choose the lookup attribute.

    Then enter the string to search/number/range to search for

4. Exiting from program

    Choose the 4.EXIT option.

    The program will close.

## Table format

    Table will contain information about music

    The record will have those fields

    1. Music title

    2. Artist name

    3. Release year

    4. Sold count

## Building process

```bash
mkdir build
cd build
cmake ../
make
./app
```

## For generating your LSP-config for clangd
```bash
cd build
cmake ../ -DCMAKE_EXPORT_COMPILE_COMMANDS=1
ln -s compile_commands.json ../
```
