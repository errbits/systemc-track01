# ErrBits · SystemC Track 01 — Graded Labs

Your workspace for the graded tasks in [ErrBits SystemC Studio](https://errbits.com/systemc-studio.html),
Track 01 Basics. You write code here, push it, and the ErrBits grader tests it with hidden tests
and reports your score on GitHub and in the studio.

## 1 · Set up (once)

1. **Use this template** (green button, top right) → **Create a new repository**
   - Owner: your GitHub account · Name: `track01` · **Private** (recommended, so nobody copies your answers)
2. Connect the **same GitHub account** in your [ErrBits profile](https://errbits.com/profile.html#github).
3. Install the **ErrBits Grader** app on your new repository *(link coming soon)*.

## 2 · Open your workspace

**Codespace (easiest):** in your repo, **Code → Codespaces → Create codespace on main**.
SystemC 2.3.3 is already installed and the project builds automatically.
Codespaces are free for personal accounts up to GitHub's monthly limit.

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

Each file has the task in its header comment; the full task is in the **Graded Task** tab of the studio.

```bash
make build            # compile everything
make play             # try steps 01 and 04
make play STEP=05     # try step 05 (also 06, 07)
```

The playground (`play/main.cpp`) is for you — edit it freely. It is **not** the grader.

## 4 · Submit

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
