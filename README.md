# dir2html
Export contents of directory into HTML file.

##  Installation
It's quite simple to set up the program, because all you need is compiler. First download the source code and compile the program. Make sure you set complier to target C++17 or newer. G++ CLI option for that is `-std=c++17`. OS doesn't matter, it will work on most OSes.

## Arguments
After compiling the program, there are two argruments. Usage is:
```sh
$ ./dir2html [directory] [filename]
```
`[directory]` - Target specific directory. 

`[filename]` - Output file name. If unspecified, program will output `output.html`

Note that these options are optional, without them, program will grab current working directory and generate `out.html`

## To do...
* Make it list subdirectories like tree as a CLI argument
* Fix bugs I haven't discovered yet.
