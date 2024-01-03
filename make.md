---
date: 2024-01-03
type: note/language
language: make
focus: "notes"
sourceType: docs
source: "[https://www.gnu.org/software/make/manual/html_node/index.html](https://www.gnu.org/software/make/manual/html_node/index.html)"
tags: make
---

## Phony Targets

One that is not really the name of a file; rather, it is just a name for a recipe to be executed when you make an explicit request. For example:

```make
.PHONY: clean
clean: 
    rm *.o temp
```

## Automatic Variables

- `$@`: file name of the target of the rule.
- `$%`: target member name, when the target is an archive member.
- `$<`: name of the first prerequisite.
- `$?`: the names of all the prerequisites that are newer than the target, with spaces between them.
- `$^`: the names of all the prerequisites, with spaces between them.

## Functions for String Substitution and Analysis

> `$(subst from,to,text)`

Performs a textual replacement on the text `text`: each occurrence of `from` is replaced to `to`.

> `$(patsubst pattern,replacement,text)`

Finds whitespace-separated words in `text` that match `pattern` and replaces them with `replacement`. `pattern` may contain a `%` acting as a wildcard, matching any number of any characters within a word. If `replacement` also contains the wildcard `%`, then it is replaced by the text that matched it in `pattern`. 

Substitution references are a simpler way to get the effect of the function. 

```make
$(var:pattern=replacement)
# is equivalent to
$(patsubst pattern,replacement,$(var))
```

The second shorthand simplifies one of the most common uses: replacing the suffix at the end of file names:

```make
$(var:suffix=replacement)
# is equivalent to
$(patsubst %suffix,%replacement,$(var))
```