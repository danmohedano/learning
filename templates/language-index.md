---
date: <% tp.date.now("YYYY-MM-DD") %>
type: note/language/index
language: <% tp.file.title %>
tags: index/language
---

# Resources

# Notes

```dataview
TABLE focus, sourceType AS "type", source, date
WHERE type = "note/language" AND file.folder != "templates" AND language = "<% tp.file.title %>"
SORT date DESC
```