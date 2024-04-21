---
date: 2024-04-21
type: note
focus: "tikz"
description: "Using Tikz to create diagrams in LaTeX"
tags: diagrams, tikz, latex
---

# Example

```latex
\documentclass[tikz,convert={outext=.svg,command=\unexpanded{pdf2svg \infile\space\outfile}},multi=false]{standalone}
\usepackage{amsmath}
\usepackage{xcolor}
\usetikzlibrary{shapes, arrows, positioning, calc, fit}

\begin{document}

% Color definitions
\definecolor{darkpastelgreen}{rgb}{0.01, 0.75, 0.24}
\definecolor{cadetgrey}{rgb}{0.57, 0.64, 0.69}

% Tikz definitions
\tikzset{
    block/.style = {rectangle, draw, fill=white, minimum height=3em, minimum width=3em, align=center},
    special_block/.style = {rectangle, draw=red, fill=white, minimum height=3em, minimum width=3em, align=center},
    tag/.style = {rectangle, draw, fill=cyan, minimum height=1em, minimum width=1em, align=center},
    dotted_block/.style = {rectangle, thick, dashed},
    box/.style = {rectangle, thick, dashed, draw=darkpastelgreen, label={[rotate=90, anchor=south, text=darkpastelgreen]west:box}},
    arrow/.style = {->, thick},
}

\begin{tikzpicture}[auto, node distance=1cm,>=latex']
    % Blocks
    \node [block] (a) {a};
    \node [block, right=of a] (b) {b};
    \node [block, right=of b] (c) {c};
    \node [block, right=of c] (d) {d};
    \node [block, right=of d] (e) {e};
    \node [block, right=of e] (f) {f};

    % Arrows
    \draw [arrow] (a) -- (b) node[midway] (Aarrow) {};
    \draw [arrow] (b) -- (c);
    \draw [arrow] (c) -- (d);
    \draw [arrow] (d) -- (e);

    % Colored box
    \node[box, fit=(a) (b) (c) (d) (e) (f)] (greenbox) {};
\end{tikzpicture}

\end{document}
```

# Creation of `.svg` Files

Using the `standalone` document class and the `pdf2svg` package in Linux, you can automate the creation of individual diagrams and their conversion to `svg`, by using the `tikz` option in the document class and using the following options to automate the conversion:

```latex
convert={outext=.svg,command=\unexpanded{pdf2svg \infile\space\outfile}},multi=false
```

# Tikz Structures

## Style Definitions

You can use `\tikzset{}` to set style options and give them an "id" so they can be used anywhere in the code. Useful for organization and avoiding repetition.

## Nodes

As far as I know, the general structure for a node definition is:

```latex
\node [options] (id) {text/label};
```

For the positioning, it is useful to use relative coordinates to other nodes, with `above`, `right`, `below` or `left`. You can also specifiy the gap size:

```latex
    \node [block] (a) {a};
    \node [block, right=of a] (b) {b};
    \node [block, above=4cm of b] (c) {c};
    \node [block, above right=4cm and 2cm of c.north east] (d) {d};
```

The nodes can also be labeled with the `label` option.

```latex
label={[rotate=90, anchor=south, text=darkpastelgreen]west:box}
```

To specify the size of the node, the `fit` option is perfect. With it, the node can be forced to fit inside a series of nodes or provide the `north west` and `south east` corners coordinates.

For mult-line text inside nodes, use the option `align` and then `\\` inside the node label to create a line jump.

## Arrows

Very useful to define several points in the path if the arrow should have multiple orthogonal turns. Nodes can also be defined in the path to later be used in other relative coordinate systems or to apply a label to the arrow.

```latex
    \draw [arrow] (a) -- (b) node[midway] (Aarrow) {};
    \draw [arrow] (b.east) -- ([xshift=1cm]b.east) |- (c.west);
```