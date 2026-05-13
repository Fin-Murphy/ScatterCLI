# ScatterCLI

ScatterCLI is a simple CLI (Command Line Interface) written in C++ for interacting with
[Obsidian.md](https://obsidian.md/) Kanban files from the terminal while programming,
without having to have Obsidian open.

When programming, I find it very distracting to have to switch back and forth between
applications, and it slows down my workflow — so I built ScatterCLI to allow myself to
have a live interface between my to-do list for any project directly in the terminal,
without having to constantly toggle back and forth between Obsidian (the notes app that
I use) and Visual Studio. ScatterCLI is built to accept a filepath from the user to a
Kanban file in Obsidian, but it can be used freestanding if the user generates their
own file to build from.

ScatterCLI streamlines moving task cards between to-do list columns and the completed
column, but is also meant to grow into a foundation for automation and completion
tracking — for example, a points system to keep track of progress on a given
assignment.

Only thing I haven't done yet is make it runnable as a command and not from the repo itself,
but I usually run fish+tmux so this hasn't affected my workflow. 

Here is a quick demo of the application running: 



<img width="720" height="436" alt="demo" src="https://github.com/user-attachments/assets/91c23341-65b9-4c46-b0d0-7c2ecbaed057" />




## How it works

ScatterCLI reads an Obsidian Kanban markdown file directly. Obsidian Kanban boards are
just plain markdown under the hood, with columns as `##` headings and cards as
checkbox list items:

```markdown
---
kanban-plugin: board
---

## TODO

- [ ] Write README
- [ ] Refactor file I/O

## COMPLETED

- [ ] Set up project
```

ScatterCLI parses these columns and cards in place, edits the file when you add,
delete, or strike a task, and writes it back so your changes show up the next time
Obsidian opens the board.

## Building

This is a small two-file C++ program — no build system required:

```sh
g++ main.cpp -o scattercli
```

## Usage

Pass the path to a Kanban `.md` file as the only argument:

```sh
./scattercli /path/to/your/Kanban.md
```

You'll be dropped into a prompt (`| >`) that accepts the following commands:

| Command  | What it does                                            |
| -------- | ------------------------------------------------------- |
| `list`   | Print all tasks grouped by column                       |
| `add`    | Add a new task to the first column                      |
| `strike` | Move a task by name into the `## COMPLETED` column      |
| `delete` | Remove a task by name                                   |
| `kill`   | Exit ScatterCLI                                         |

## Project status

ScatterCLI is a personal tool, and there's still a list of improvements I want to make
(better error handling on bad filepaths, due-date syntax parsing, card duplication,
input validation, and the points/completion-tracking system mentioned above). See
`Temp.txt` for the running to-do list this tool was eating its own dog food on while
being built.

## Links and media

<!-- Add GitHub link and screenshots / demo media here -->
