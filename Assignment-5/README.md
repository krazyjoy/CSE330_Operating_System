# Assignment-5-1229960136


## world of file handling
- I found a website extremely helpful to me: `https://www.guru99.com/cpp-file-read-write-open.html`
- fstream library

| ofstream | ifstream | fstream |
|---------|----------|---------|
| create, | read     | create, |
| write   | N/A      | read,   |
| N/A     | N/A      | write   |

### write data to a new file

`open(filename, mode)`
    - modes: (I made a small mistake here only use `ios::out` without including `std` library)
        - `std::ios::out`: write
        - `std::ios::app`: append
        - `std::ios::in`: read

    
- stream operators:
    - stream insertion operator: `<<`, left side is the fstream to write to, right side is your text input
    - stream extraction operator: `>>`, left side is the file stream to read from, right side is your data structure to save text into
`fstream/ofstream/ifstream.close()`:
    - all closing file operation operates the same
    - close file is a necessary step to keep reading and writing content safely.
  
### read/open previously written file

`std::ifstream fin(filename)`: the `fin` assumes fstream an object
    - `std::getline(object, line)`: reads fstream object by deliminator newline to a string (`line`)
    - coninuous string: use `fileContent` large string to store line, and since newline to eliminated during `getline` operation, I add it back for each read out `line`

### replace string
- string has a `find()` function that searches for the matching string starting position
- maintain a while loop that only stops when content is finished reading, given by `std::string::npos`
- string has another `replace()` functions that takes the (position to replace, length, targeted_string) as arguments that will fulfill the replacement string goal
- once a matched string is replaced in the large string, read contents after that also matches, and keeps go on until while loop is terminated by no more match strings can be found

### rename file
- `std::rename(old_filename, new_filename)`
  - convert string to c_str() to pass in **pointer** of where the string allocates

- interesting finding
  - I got different results when I execute the cpp code, latter I found it's due to my generated
    assignment5_renamed.txt. The existence of this file will disturb the content output to either print out the modified contents/renamed file
    messages.
