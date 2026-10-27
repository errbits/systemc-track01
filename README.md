# ErrBits · SystemC Track 01 — Graded Labs

Your workspace for the graded tasks in [ErrBits SystemC Studio](https://errbits.com/systemc-studio.html),
Track 01 Basics. You write code here, push it, and the ErrBits grader tests it with hidden tests
and reports your score on GitHub and in the studio.

## 1 · Set up (once)

1. **Use this template** (green button, top right) → **Create a new repository**
   - Owner: **your own** GitHub account (not an organisation) · Name: anything, e.g. `track01` ·
     **Private** (required: see [LICENSE](LICENSE))
2. Connect the **same GitHub account** in your [ErrBits profile](https://errbits.com/profile.html#github).
3. Install the **ErrBits Grader** app: [github.com/apps/errbits-grader](https://github.com/apps/errbits-grader/installations/new)
   → your account → **Only select repositories** → your new repo. It can only read your code
   and post ✓/✗ on your commits; it never writes to your repo.

Keep the file names (`src/stepNN.cpp`) and the function names as they are; the repo name doesn't matter.

## 2 · Open your workspace

**Codespace (easiest):** in your repo, **Code → Codespaces → Create codespace on main**.
SystemC 2.3.3 is already installed and the project builds automatically. Open a terminal with
**Terminal → New Terminal** (or <kbd>Ctrl</kbd>+<kbd>`</kbd>): `make play` runs your code, and the
`git` commands below submit it. You can also commit from the **Source Control** panel.
Codespaces are free for personal accounts up to GitHub's monthly limit.

**Create one Codespace and keep reusing it.** Next time, open the same one from
**Code → Codespaces** (pick the existing name) or [github.com/codespaces](https://github.com/codespaces);
don't click *Create* again. Each new Codespace uses more of your free storage and hours, and
work you haven't pushed stays only in the one you wrote it in. It stops by itself after 30 minutes
idle and keeps your files. Delete it only after everything is pushed.

**Local with Docker:**
```bash
docker run -it --rm -v "$PWD":/workspace ghcr.io/errbits/systemc:2.3.3 bash
make play
```

**Local with your own SystemC 2.3.3** (built with C++17):
```bash
make play SYSTEMC_HOME=/path/to/systemc-2.3.3
```

## 3 · Do a task

| Step | File | You write |
|---|---|---|
| 01 · Set Up Your Environment | `src/step01.cpp` | `lab_systemc_version()` |
| 04 · Data Types | `src/step04.cpp` | `high_nibble`, `low_nibble`, `saturating_add` |
| 05 · SC_MODULE, Ports, Processes | `src/step05.cpp` | `Counter` constructor + `on_clk()` |
| 06 · SC_THREAD vs SC_METHOD | `src/step06.cpp` | `AndGate`, `ResetSeq` |
| 07 · Signals, Events & Timing | `src/step07.cpp` | `ClockGen::run()` |

For each step, work in this loop from the terminal:

1. **Read the problem statement first:** the header comment in `src/stepNN.cpp`, and the full task
   in the studio's **Graded Task** tab. Know what each function must return before you write it.
2. **Solve only the problem:** fill in the function bodies in `src/stepNN.cpp`. Don't change
   `include/lab.h`, the `Makefile` or other steps' files; the grader ignores them anyway.
3. **Build and run, often:**
   ```bash
   make                  # compile everything (same as make build)
   make play             # run steps 01 and 04
   make play STEP=05     # run step 05 (also 06, 07)
   make clean && make    # fresh rebuild if errors look stale or odd
   ```
   Fix every compiler error and warning, then check the printed output against the task.
4. **Submit** (section 4) once `make play` looks right. Read the ✓/✗ test names, fix, push again.

The playground (`play/main.cpp`) is for you — edit it freely. It is **not** the grader: hidden
tests check more cases, so think about edge cases the statement mentions.

## 4 · Submit

In the Codespace (or your local) terminal:

```bash
git add src/step05.cpp
git commit -m "step 05: counter"
git push
```

Every push to your **main** branch is graded — only the steps whose files changed.
Within about a minute you'll see ✓ or ✗ next to your commit on GitHub, and your score in the studio.
Your best score counts. Push again as often as you like (rate-limited to keep the grader fair).

## Rules

- Only `src/stepNN.cpp` files are graded. Changes to `include/lab.h`, the `Makefile` or
  anything else are ignored — the grader uses its own copies.
- Keep the function and class signatures exactly as declared in `include/lab.h`.
- The hidden tests use values personal to you, so copying someone else's answers won't pass.
- Work only in your own repository, from the GitHub account connected to your ErrBits profile.
- Keep the repository private and don't share your solutions.

## License

© 2025–2026 ErrBits. All rights reserved. This is proprietary course material, not open source.
You may use it only to complete the ErrBits graded labs in your own private repository.
Redistribution, publishing or reuse without written permission is not allowed. See [LICENSE](LICENSE).
