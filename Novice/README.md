<h1>Custom Shell Project</h1><\n>
<h3>Introduction</h3>
Welcome to the Custom Shell project! In this project, we will delve into the world of shell programming by creating our own custom Unix-like shell. This readme will shed light on various aspects of shell programming and help you answer important questions related to the history of Unix, shell operation, process management, and more.

<h3>Key Questions</h3>
Before we dive into the project, let's answer some fundamental questions to set the context:

1. Who designed and implemented the original Unix operating system?

The original Unix operating system was designed and implemented by Ken Thompson, Dennis Ritchie, and other members of the Bell Labs research team in the late 1960s.

2. Who wrote the first version of the UNIX shell?

The first version of the UNIX shell, known as the Thompson shell or sh, was also developed by Ken Thompson in 1971.

3. Who invented the B programming language (the direct predecessor to the C programming language)?

Ken Thompson and Dennis Ritchie developed the B programming language, which served as a precursor to the C programming language. They created C by extending and improving upon the ideas of B.

4. Who is Ken Thompson?

Ken Thompson is a computer scientist and one of the key figures in the development of the Unix operating system and the C programming language. He received the Turing Award in 1984 for his contributions to computer science.

<h3>Understanding Shells</h3>
<h4>How does a shell work?</h4>
A shell is a command-line interface that interacts with the operating system's kernel. It reads commands from the user, interprets them, and executes the corresponding programs or system commands. It acts as an intermediary between the user and the operating system.

<h4>What is a pid and a ppid?</h4>
PID (Process ID): A PID is a unique numeric identifier assigned to each running process on a Unix-like operating system. It helps in tracking and managing processes.

PPID (Parent Process ID): PPID is the PID of the parent process that spawned the current process. It's used to establish parent-child relationships between processes.

<h4>How to manipulate the environment of the current process?</h4>
The environment of a process can be manipulated using environment variables. You can set, modify, or remove environment variables within a shell using commands like export, unset, and export VARNAME=value.

<h4>What is the difference between a function and a system call?</h4>
Function: A function is a block of code within a program that can be called or invoked to perform a specific task. Functions are part of the program and execute in user space.

System Call: A system call is a request for a service or operation provided by the operating system kernel. System calls are used to interact with the kernel and perform privileged operations like file I/O, process creation, and networking.

<h4>How to create processes?</h4>
Processes can be created in Unix-like systems using the fork() system call. The new process is a copy of the parent process, and both continue executing code from the point of the fork() call.

<h4>What are the three prototypes of main?</h4>
In C programming, there are three standard prototypes for the main function:

int main(void): Represents a program with no command-line arguments.
int main(int argc, char *argv[]): Accepts command-line arguments as an array of strings.
int main(int argc, char *argv[], char *envp[]): Accepts command-line arguments and the environment variables as an array of strings.
Shell Operations
<h4>How does the shell use the PATH to find the programs?</h4>
The shell uses the PATH environment variable to locate executable programs. It searches directories listed in PATH from left to right until it finds the desired program's executable file. The directories are separated by colons (':' on Unix-like systems).

<h4>How to execute another program with the execve system call?</h4>
The execve() system call is used to replace the current process with a new process. It loads a new program into the current process's memory and starts executing it. execve() requires the path to the program, command-line arguments, and the environment variables.

<h4>How to suspend the execution of a process until one of its children terminates?</h4>
You can use the wait() or waitpid() system calls to suspend the execution of a parent process until one of its child processes terminates. These calls allow the parent process to collect information about the terminated child, including its exit status.

<h4>What is EOF (End-of-File)?</h4>
EOF, or "End-of-File," is a condition that indicates the end of data in a file or stream. In C programming and many other programming languages, EOF is represented as a special value (typically -1) and is used to signal the end of input when reading from files or other input sources.

<h3>Conclusion</h3>
With this knowledge, you're well-equipped to embark on the journey of creating your custom shell. Remember to explore the Unix philosophy, understand process management, and implement the core features of a shell, such as command parsing, execution, and managing environment variables. Happy shell programming!
