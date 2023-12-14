---
type: note/literature
authors: "{{authors}}"
title: "{{title}}"
year: {{date | format("YYYY")}}
citeKey: "@{{citekey}}"
{% if itemType %}itemType: "{{itemType}}" {% endif %}
{% if itemType == "journalArticle" %}journal: "{{publicationTitle}}" {% endif %}
{% if volume %}volume: "{{volume}}" {% endif %}
{% if issue %}issue: "{{issue}}" {% endif %}
{% if itemType == "bookSection" %}book: "{{publicationTitle}}" {% endif %}
{% if publisher %}publisher: "{{publisher}}" {% endif %}
{% if place %}location: "{{place}}" {% endif %}
{% if numPages %}pages: "{{numPages}}" {% endif %}
{% if DOI %}doi: "{{DOI}}" {% endif %}
{% if ISBN %}isbn: "{{ISBN}}" {% endif %}
tags: 
summary:
---

> [!cite]
> {{bibliography}}

> [!info]
> Zotero Link: {{pdfZoteroLink}}

# Annotations

{% persist "annotations" %}

{% set newAnnotations = annotations | filterby("date", "dateafter", lastImportDate) %}

{% if newAnnotations.length > 0 %}

{% for annotation in newAnnotations %}

{% if annotation.type == "image" %}

![[{{annotation.imageRelativePath}}]]

[p.{{annotation.page}}]({{annotation.desktopURI}})

{% elif annotation.type == "highlight" %}

{% if annotation.colorCategory == "Yellow" %}

> [!warning]
> {% elif annotation.colorCategory == "Blue" %}
> [!info]
> {% elif annotation.colorCategory == "Green" %}
> [!success]
> {% elif annotation.colorCategory == "Red" %}
> [!danger]
> {% elif annotation.colorCategory == "Purple" %}
> [!example]
> {% endif %}
> {{annotation.annotatedText}} - [p.{{annotation.page}}]({{annotation.desktopURI}})
{% endif %}

{% if annotation.comment %}

> {{annotation.comment}}
{% endif %}
{% endfor %}
{% endif %}
{% endpersist %}

# Notes

{% persist "notes" %}

{% endpersist %}