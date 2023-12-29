---
type: index
description: "All notes taken"
tags: 0-index
---

# Languages

```dataview
TABLE date AS "date"
WHERE type = "note/language/index" AND file.folder != "templates"
SORT date DESC
```

# Literature

```dataview
TABLE WITHOUT ID
file.link AS "title", authors AS "authors", year AS "year", itemType AS "type", summary AS "summary"
WHERE type = "note/literature" AND file.folder != "templates"
```

# Others

```dataview
TABLE focus AS "focus", description AS "description", date AS "date"
WHERE type = "note" AND file.folder != "templates" AND !language
SORT date DESC
```

# TODO
- [ ] NixOS
- [ ] tmux
- [ ] terminal auto-complete