# Lab 1 (modular-type)

Variant 3 (music)

## API Defenition

API Consists of several header-level files

* Database class

    Abstracts reading and writing from and into the file

* Repository and music-data class

    Abstracts working with records into struct

More on them

### Database

Should have:

* Read method 

    To strings from file

* Write method

    To write strings into file

### Repository

Should have:

* Retrieve method

    To retrieve records as music-class structs


* Add method

    To write records from music-class struct

### Music class

Should have:

* Special *magic* methods to cin, cout them

* Destructors and constructors


### TUI class

Should have:

* Simple menu


* Section for:
    
    1. Adding records
    2. Listing all records
    3. Finding records by attribute
    4. Exiting and cleaning up