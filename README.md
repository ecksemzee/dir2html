# dir2html
Export contents of directory into HTML file.

##  Installation
Install G++ compiler then hit `make` in directory, where the soruce is

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
