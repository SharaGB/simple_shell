# <a href="url"><img src="https://user-images.githubusercontent.com/90220978/145126989-7e3c2c83-88fc-477c-ad07-6294086651c2.jpg" align="middle" width="100" height="100"></a> simple_shell

![bashshell](https://user-images.githubusercontent.com/90220978/145126786-e6ada7f9-5a6e-4b41-b577-c3ec4a3ae756.png)


**Table of Contents**
- [Simple Shell](#simple-shell)
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Requeriments](#requeriments)
- [Man](#man)
- [Flowchart](#flowchart)

## Simple Shell
The shell is a program that allows users to interact with the system by processing the commands given to it. The commands that can be invoked from the shell can be classified as internal (they actually correspond to commands interpreted by the shell itself) and external (they correspond to executable files external to the shell). In addition to commands, shells offer other elements to enhance their functionality, such as variables, functions or control structures. The set of internal commands and elements available, as well as their syntax, will depend on the particular shell used.  This shell is intentionally minimalistic, but includes the basic functionality of a traditional Unix-like command line user interface.
Standard functions and system calls used in simple_shell include:

   - acces: *([man 2 access](https://man7.org/linux/man-pages/man2/access.2.html))*
   - close: *([man 2 close](https://man7.org/linux/man-pages/man2/close.2.html))*
   - execve: *([man 2 execve](https://man7.org/linux/man-pages/man2/execve.2.html))*
   - exit: *([man 3 exit](https://man7.org/linux/man-pages/man3/exit.3.html))*
   - fflush: *([man 3 fflush](https://man7.org/linux/man-pages/man3/fflush.3.html))*
   - fork: *([man 2 fork](https://man7.org/linux/man-pages/man2/fork.2.html))*
   - free: *([man 3 free](https://linux.die.net/man/3/free))*
   - getline: *([man 3 getline](https://man7.org/linux/man-pages/man3/getline.3.html)*)
   - getpid: *([man 2 getpid](https://man7.org/linux/man-pages/man2/getpid.2.html))*
   - isatty: *([man 3 isatty](https://man7.org/linux/man-pages/man3/isatty.3.html))*
   - malloc: *([man 3 malloc](https://man7.org/linux/man-pages/man3/free.3.html))*
   - open: *([man 2 open](https://man7.org/linux/man-pages/man2/open.2.html))*
   - perror: *([man 3 perror](https://man7.org/linux/man-pages/man3/perror.3.html))*
   - read: *([man 2 read](https://man7.org/linux/man-pages/man2/read.2.html))*
   - signal: *([man 2 signal](https://man7.org/linux/man-pages/man2/signal.2.html))*
   - stat: *([man 2 stat](https://linux.die.net/man/2/stat))*
   - strtok: *([man 3 strtok](https://man7.org/linux/man-pages/man3/strtok_r.3.html))*
   - waitpid: *([man 2 waitpid](https://linux.die.net/man/2/waitpid))*
   - write: *([man 2 write](https://man7.org/linux/man-pages/man2/write.2.html))*


## Installation

Use [git](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository) to clone this repository in your local machine

```bash
git clone https://github.com/SharaGB/simple_shell.git
```

## Compilation

All files were created and compiled on Ubuntu 14.04.4 LTS using GCC 4.8.4 with the command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Usage
You can use the shell in two different modes:

Your shell should work like this in interactive mode:

```bash
$ ./hsh
🧿$ /bin/ls
hsh main.c shell.c
🧿$
```
To exit the program type command 'exit' or 'ctrl + D'

```bash
shara@DESKTOP-MHDLLP0:~/simple_shell$ ./hsh
🧿$ ls
AUTHORS    Test        execute.c    function_aux.c    help_cd   help_exit  hsh                 main.h              non_built_in.c          token.c
README.md  built_in.c  free_args.c  function_aux_2.c  help_env  help_help  interactive_mode.c  man_1_simple_shell  non_interactive_mode.c
🧿$ ps
  PID TTY          TIME CMD
 2635 pts/2    00:00:00 bash
30217 pts/2    00:00:00 hsh
30285 pts/2    00:00:00 ps
🧿$ exit
shara@DESKTOP-MHDLLP0:~/simple_shell$
```

But also in non-interactive mode:

```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
```

 ### ***Now you can execute the program ✨***

## Requeriments
### Tasks ✔️

- [x] Write a README
- [x] Write a man for your shell.
- [x] An AUTHORS file at the root of your repository
- [x] Handle the “end of file” condition (***Ctrl+D***)
- [x] Handle command lines with arguments
- [x] Handle the PATH
- [x] Implement the exit built-in
- [x] Implement the env built-in
- [x] Uses exit status
- [x] Shell continues upon ***Crtl+C***
- [x] Implement the help [built-in]


## Man
**Man Page** 📑
To see the *man page* of our **simple_shell** function use:

```bash
man ./man_1_simple_shell
```

## Flowchart


## Authors 🖋

Carlos Rincón | [GitHub](https://github.com/CarlosRinconsofdev) | [Gmail](3901@holbertonschool.com)

Shara García | [GitHub](https://github.com/SharaGB) | [Gmail](3779@holbertonschool.com)
