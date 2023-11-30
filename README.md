# Simple Shell

This simple shell is a basic command-line interpreter written in C that emulates some functionalities of a Unix-like shell.

## How It Works

The simple shell operates by following these main steps:

1. **Displaying the Prompt:** Upon running the shell, it displays a prompt (e.g., `shell$`), indicating it's ready to receive user commands.

2. **Reading User Input:** It reads user input from the command line.

3. **Parsing User Input:** The shell parses the input to separate the command and its arguments.

4. **Executing Commands:** Based on the parsed input, the shell executes the specified command. It handles both built-in commands (like `cd`, `exit`) and external programs.

5. **Handling Piped Commands:** If a command contains a pipe (`|`), the shell handles executing multiple commands in a pipeline.

6. **Exiting the Shell:** Upon entering the `exit` command, the shell terminates.

## Features

- **Command Execution:** Executes commands entered by the user.
- **Basic Built-in Commands:** Supports some built-in commands like `cd` (change directory) and `exit` (terminate the shell).
- **Piped Commands:** Can handle commands separated by pipes (`|`).

## How to Use

To use the simple shell:

1. **Compile:** Compile the shell program using a C compiler (e.g., `gcc shell.c -o shell`).
2. **Run:** Execute the compiled program (e.g., `./shell`).
3. **Enter Commands:** Enter commands at the prompt and press Enter to execute them.
4. **Exit:** To exit the shell, type `exit` and press Enter.

## Limitations

This simple shell has limitations compared to full-fledged shells:

- Limited built-in commands
- Basic error handling
- Lack of advanced features like environment variable handling, scripting, and job control
