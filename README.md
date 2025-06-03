<h1 align="center">MSHELL</h1>

<p align="center"><em>A handcrafted POSIX-compliant shell for mastering process control, I/O redirection, and job management.</em></p>

<p align="center">
  <img src="https://img.shields.io/github/last-commit/SaKagiRi/MSHELL" />
  <img src="https://img.shields.io/github/languages/top/SaKagiRi/MSHELL" />
  <img src="https://img.shields.io/github/languages/count/SaKagiRi/MSHELL" />
</p>

<p align="center"><strong><em>Built with the tools and technologies:</em></strong></p>

<p align="center">
  <img src="https://img.shields.io/badge/Nix-5277C3?logo=nixos&logoColor=white" />
  <img src="https://img.shields.io/badge/Makefile-000000?logo=gnu&logoColor=white" />
  <img src="https://img.shields.io/badge/C-00599C?logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/Markdown-000000?logo=markdown&logoColor=white" />
</p>

---

## 🚀 Features

- **Interactive Shell**: Supports command execution with arguments.
- **Built-in Commands**: Implements `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Redirections**: Handles input (`<`), output (`>`), append (`>>`), and heredoc (`<<`) redirections.
- **Pipelines**: Supports command chaining using pipes (`|`).
- **Environment Variables**: Expands variables like `$HOME` and `$PATH`.
- **Signal Handling**: Manages `SIGINT`, `SIGQUIT`, and `SIGTERM` signals gracefully.
- **Error Handling**: Provides informative error messages for invalid commands and syntax errors.

---

## 🛠️ Build & Run

To build and run the shell:

```bash
git clone https://github.com/SaKagiRi/MSHELL.git
cd MSHELL
make
./minishell
