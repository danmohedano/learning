---
date: 2024-01-25
type: note
focus: "tmux"
description: "tmux information"
tags: tmux, workflow
---

# Cheat Sheet

## Sessions

|               Command               | Action                            |
|:-----------------------------------:|:--------------------------------- |
|          `tmux`  or `:new`          | New session                       |
|       `tmux new -s mysession`       | New session with name `mysession` |
|    `tmux kill-ses -t mysession`     | Kill session `mysession`          |
|       `tmux kill-session -a`        | Kill all sessions but current     |
| `tmux kill-session -a -t mysession` | Kill all sessions but `mysession` |
|            `[leader] $`             | Rename session                    |
|            `[leader] d`             | Detach from session               |
|      `tmux ls` or `[leader] s`      | Show all sessions                 |
|              `tmux a`               | Attach to last session            |
|        `tmux a -t mysession`        | Attach to `mysession`             |
|            `[leader] w`             | Session and window preview        |
|            `[leader] (`             | Move to previous session          |
|            `[leader] )`             | Move to next session              |

## Windows

|               Command               | Action                                                              |
|:-----------------------------------:|:------------------------------------------------------------------- |
| `tmux new -s mysession -n mywindow` | Start a new session with the name `mysession` and window `mywindow` |
|            `[leader] c`             | Create window                                                       |
|            `[leader] ,`             | Rename current window                                               |
|            `[leader] &`             | Close current window                                                |
|            `[leader] w`             | List windows                                                        |
|            `[leader] p`             | Previous window                                                     |
|            `[leader] n`             | Next window                                                         |
|          `[leader] 0...9`           | Switch window by number                                             |
|            `[leader] l`             | Toggle last active window                                           |                                    |                                                                     |

## Panes

|           Command            | Action                          |
|:----------------------------:|:------------------------------- |
|         `[leader] ;`         | Toggle last active pane         |
|         `[leader] %`         | Split vertically                |
|         `[leader] "`         | Split horizontally              |
|    `[leader] arrow_keys`     | Switch to pane to the direction |
|     `[leader] spacebar`      | Toggle between pane layouts     |
|         `[leader] o`         | Switch to next pane             |
|         `[leader] q`         | Show pane numbers               |
|         `[leader] z`         | Toggle pane zoom                |
|         `[leader] !`         | Convert pane into a window      |
| `[leader] [ctrl] arrow_keys` | Resize current pane             |
|         `[leader] x`         | Close current pane              |

## Misc

|   Command    | Action             |
|:------------:|:------------------ |
| `[leader] :` | Enter command mode |
| `[leader] ?` | List key bindings  | 
