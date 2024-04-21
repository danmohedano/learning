---
date: 2024-04-21
type: note
focus: "beamer"
description: "Creating presentations in LaTeX using beamer"
tags: presentations, beamer, latex
---

# Example

```latex
\documentclass{beamer}
\usetheme{metropolis}

\title{My Presentation}
\subtitle{Using Beamer}
\author{John Smith}
\institute{University of the World}
\date{\today}

\begin{document}

\begin{frame}
\titlepage
\end{frame}

\begin{frame}
\frametitle{Outline}
\tableofcontents
\end{frame}

\section{Lists}
\subsection{Itemize}

\begin{frame}
\frametitle{Itemize}
\begin{itemize}
    \item Point A
    \item Point B
    \begin{itemize}
        \item Point C
        \item Point D
    \end{itemize}
\end{itemize}
\end{frame}

\subsection{Enumerate}

\begin{frame}
\frametitle{Enumerate}
\begin{enumerate}[I]
    \item Point A
    \item Point B
    \begin{enumerate}[i]
        \item Point C
        \item Point D
    \end{enumerate}
    \begin{enumerate}[(i)]
        \item Point C
        \item Point D
    \end{enumerate}
\end{enumerate}
\end{frame}

\section{Columns}
\begin{frame}
\frametitle{Columns}
    \begin{columns}
        \column{0.5\textwidth}
        Hello there!
        \column{0.5\textwidth}
        Second column!
    \end{columns}
\end{frame}

\section{Figures}

\begin{frame}
\frametitle{Figures}
\begin{figure}
    \centering
    \includegraphics[scale=0.5]{lion.png}
    \caption{A lion}
\end{figure}

Some text below the picture.

\end{frame}

\section{Description}

\begin{frame}
\frametitle{Description}
\begin{description}
    \item[API] Application Programming Interface
\end{description}
\end{frame}

\section{Tables}

\begin{frame}
\frametitle{Table}
\begin{table}
    \begin{tabular}{l | c | c | c | c }
    Competitor Name & Swim & Cycle & Run & Total \\
    \hline \hline
    John T & 13:04 & 24:15 & 18:34 & 55:53 \\ 
    Norman P & 8:00 & 22:45 & 23:02 & 53:47\\
    Alex K & 14:00 & 28:00 & n/a & n/a\\
    Sarah H & 9:22 & 21:10 & 24:03 & 54:35 
    \end{tabular}
    \caption{Triathlon results}
\end{table}
\end{frame}

\section{Blocks}

\begin{frame}
\begin{block}{Block Title}
Lorem ipsum dolor sit amet, consectetur adipisicing elit, 
sed do eiusmod tempor incididunt ut labore et 
dolore magna aliqua.
\end{block}
\begin{definition}
A prime number is a number that...
\end{definition}
\begin{example}
Lorem ipsum dolor sit amet, consectetur adipisicing elit, 
sed do eiusmod tempor incididunt ut labore et
dolore magna aliqua.
\end{example}
\begin{theorem}[Pythagoras] 
$ a^2 + b^2 = c^2$
\end{theorem}
\end{frame}

\section{Animation/Pause}

\begin{frame}
\frametitle{Pause}
\begin{itemize}
\pause
\item Point A
\pause
\item Point B
\begin{itemize}
\pause
\item part 1
\pause
\item part 2
\end{itemize}
\pause
\item Point C
\pause
\item Point D
\end{itemize}
\end{frame}

\begin{frame}
\frametitle{Overlay Specifications}
\begin{enumerate}[(I)]
\item<1-> Point A
\item<2-> Point B
\begin{itemize}
\item<3-> part 1
\item<4-> part 2
\end{itemize}
\item<5-> Point C
\item<6-> Point D
\end{enumerate}
\end{frame}

\begin{frame}
\frametitle{Overlay Specifications II}
\onslide<1->{First Line of Text}

\onslide<2->{Second Line of Text}

\onslide<3->{Third Line of Text}
\end{frame}

\setbeamercovered{transparent}
\begin{frame}
\frametitle{Overlay Specifications III}
\onslide<1->{First Line of Text}

\onslide<2->{Second Line of Text}

\onslide<3->{Third Line of Text}
\end{frame}

\end{document}
```

# Themes

## Metropolis

![[687474703a2f2f692e696d6775722e636f6d2f4278753532667a2e706e67.png]]
