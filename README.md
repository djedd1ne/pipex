# pipex
#### Bash Pipes
A bash pipe, symbolized by '|' , is a powerful tool used to pass the output of one command as input to another, with the syntax ```[command1] | [command2]``` 
#### What is pipex?
pipex is a small program to handle pipes. The program is equivalent to this command line <br>
```bash
< infile cmd1 | cmd2 > outfile
```

#### Clone and make
```bash
git clone https://github.com/djedd1ne/pipex
```
```
make
```
The infile file must be created before runing the program, pipex will create outfile<br>
#### Usage
```bash
./pipex infile cmd1 cmd2 outfile
```
#### Test:
&nbsp;Create infile file using "touch"
```bash
touch infile
```
&nbsp;Run 
```bash
./pipex infile "ls -l" "wc -l" outfile
```
