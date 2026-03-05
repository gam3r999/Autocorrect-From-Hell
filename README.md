<div align="center">

```
░█████╗░██╗░░░██╗████████╗░█████╗░░█████╗░██████╗░██████╗░███████╗░█████╗░████████╗
██╔══██╗██║░░░██║╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗╚══██╔══╝
███████║██║░░░██║░░░██║░░░██║░░██║██║░░╚═╝██████╔╝██████╔╝█████╗░░██║░░╚═╝░░░██║░░░
██╔══██║██║░░░██║░░░██║░░░██║░░██║██║░░██╗██╔══██╗██╔══██╗██╔══╝░░██║░░██╗░░░██║░░░
██║░░██║╚██████╔╝░░░██║░░░╚█████╔╝╚█████╔╝██║░░██║██║░░██║███████╗╚█████╔╝░░░██║░░░
╚═╝░░╚═╝░╚═════╝░░░╚═╝░░░░╚════╝░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝░╚════╝░░░░╚═╝░░░
```

```
███████╗██████╗░░█████╗░███╗░░░███╗  ██╗░░██╗███████╗██╗░░░░░██╗░░░░░
██╔════╝██╔══██╗██╔══██╗████╗░████║  ██║░░██║██╔════╝██║░░░░░██║░░░░░
█████╗░░██████╔╝██║░░██║██╔████╔██║  ███████║█████╗░░██║░░░░░██║░░░░░
██╔══╝░░██╔══██╗██║░░██║██║╚██╔╝██║  ██╔══██║██╔══╝░░██║░░░░░██║░░░░░
██║░░░░░██║░░██║╚█████╔╝██║░╚═╝░██║  ██║░░██║███████╗███████╗███████╗
╚═╝░░░░░╚═╝░░╚═╝░╚════╝░╚═╝░░░░░╚═╝  ╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝
```

<br>

**A low-level Windows keyboard hook that turns your typing into absolute chaos.**

<br>

![Windows](https://img.shields.io/badge/Windows-10%20%2F%2011-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-red?style=for-the-badge)
![Chaos Level](https://img.shields.io/badge/Chaos%20Level-MAXIMUM-FF0000?style=for-the-badge)
![Made In](https://img.shields.io/badge/Made%20In-St.%20Petersburg%2C%20FL-orange?style=for-the-badge)

<br>

> *Type normally. Watch everything burn.* 🔥

<br>

---

</div>

<br>

## ⚡ What Is This

Every time you type a trigger word — `the`, `coffee`, `boss`, `meeting` — it **instantly** replaces it with something cursed. No popup. No warning. No mercy. Works in **every application** on your machine.

```
INPUT  →  the meeting with boss is on coffee break

OUTPUT →  the forbidden ritual coven gathering with dungeon master is on the bean juice break
```

> **⚠️ Warning:** Prank tool. Do not deploy on systems without consent, at work, at school, or anywhere you value your employment / enrollment / freedom. The author accepts zero responsibility for your chaos. Use hilariously.

<br>

---

<br>

## 🧬 Features

<br>

| | Feature | Description |
|:---:|:---|:---|
| 🎯 | **Global Hook** | Low-level `WH_KEYBOARD_LL` — intercepts keystrokes in *any* application |
| ⚡ | **Instant Replace** | Triggers the moment you finish a word — no spacebar needed |
| 💀 | **37 Trigger Words** | Each with multiple random cursed replacements |
| 🔢 | **Roman Numerals** | Type `42` → get `XLII`. Every time. |
| 🔐 | **XOR Obfuscation** | Funny phrases are encrypted in the binary to dodge AV heuristics |
| 👻 | **Silent Mode** | No UI, no tray icon, no persistence — completely invisible |
| 🧹 | **Clean Uninstaller** | `cleanup.exe` — kills process, removes files, no admin required |
| 🎭 | **Disguise Support** | Custom icon + fake version info — ship it as `RuntimeBroker.exe` |

<br>

---

<br>

## 🛠️ Build

### Requirements

- **OS:** Windows 10 or 11 (x64)
- **Compiler:** Visual Studio (Community edition) with **C++ Desktop Development** workload

<br>

### Basic Compile

Open **Developer Command Prompt for VS** *(standard — not elevated)*:

```bat
cd path\to\your\project

cl /EHsc /O2 /std:c++17 /Fe:autocorrect.exe autocorrect.cpp ^
   /link /SUBSYSTEM:WINDOWS user32.lib advapi32.lib
```

<br>

### Full Build — With Icon & Fake Version Info

<details>
<summary><b>🎭 Click to expand full disguise build instructions</b></summary>

<br>

**Step 1 — Create `uninstall.rc`:**

```rc
1 ICON "your_icon.ico"
```

**Step 2 — Create `version.rc`:**

```rc
1 VERSIONINFO
FILEVERSION 10,0,22631,1
PRODUCTVERSION 10,0,22631,1
FILEOS 0x40004L
FILETYPE 0x1L
BEGIN
  BLOCK "StringFileInfo"
  BEGIN
    BLOCK "040904b0"
    BEGIN
      VALUE "CompanyName",      "Microsoft Corporation"
      VALUE "FileDescription",  "Runtime Broker"
      VALUE "FileVersion",      "10.0.22631.1"
      VALUE "InternalName",     "RuntimeBroker"
      VALUE "OriginalFilename", "RuntimeBroker.exe"
      VALUE "ProductName",      "Microsoft Windows Operating System"
      VALUE "ProductVersion",   "10.0.22631.1"
    END
  END
  BLOCK "VarFileInfo"
  BEGIN
    VALUE "Translation", 0x409, 1200
  END
END
```

**Step 3 — Compile everything:**

```bat
rc /fo u.res uninstall.rc
rc /fo v.res version.rc
cl /EHsc /O2 /std:c++17 /Fe:autocorrect.exe autocorrect.cpp ^
   /link /SUBSYSTEM:WINDOWS user32.lib advapi32.lib u.res v.res
```

</details>

<br>

---

<br>

## 🚀 Run

```
1.  Right-click autocorrect.exe  →  "Run as administrator"
    └─ First time only — required for the global keyboard hook

2.  Windows Defender flags it?  →  Add a manual exclusion
    └─ Expected. Keyboard hooks + injection = AV heuristic bait.

3.  Open Notepad. Start typing. Embrace the chaos.
```

<br>

---

<br>

## 💬 Trigger Words

<div align="center">

`the` &nbsp; `a` &nbsp; `is` &nbsp; `and` &nbsp; `of` &nbsp; `coffee` &nbsp; `hello` &nbsp; `boss` &nbsp; `meeting` &nbsp; `work`

`deadline` &nbsp; `update` &nbsp; `client` &nbsp; `office` &nbsp; `friend` &nbsp; `mom` &nbsp; `dad` &nbsp; `guy` &nbsp; `thanks`

`pookie` &nbsp; `computer` &nbsp; `phone` &nbsp; `google` &nbsp; `search` &nbsp; `amazon` &nbsp; `video` &nbsp; `internet`

`water` &nbsp; `eat` &nbsp; `sleep` &nbsp; `game` &nbsp; `home` &nbsp; `scream` &nbsp; `help` &nbsp; `ok` &nbsp; `okay`

</div>

<br>

### Example Replacements

| You type | You might get |
|:---|:---|
| `the` | `the industrial revolution` · `the forbidden ritual` |
| `boss` | `dungeon master` · `supreme overlord` |
| `coffee` | `the bean juice` · `hot brown thinking water` |
| `meeting` | `coven gathering` · `mandatory suffering session` |
| `deadline` | `the reaping` · `inevitable doom timestamp` |
| `42` | `XLII` |
| `1999` | `MCMXCIX` |

<br>

---

<br>

## 🧹 Uninstall

**Option A — Included uninstaller:**

```bat
cleanup.exe
```

**Option B — Manual removal:**

```
Ctrl+Shift+Esc  →  Task Manager  →  End process
Delete autocorrect.exe
Win+R  →  shell:startup  →  delete any suspicious shortcuts
```

<br>

---

<br>

## ⚖️ Disclaimer

```
THIS SOFTWARE IS PROVIDED FOR EDUCATIONAL AND ENTERTAINMENT PURPOSES ONLY.

  ✗  Do not deploy on any system without explicit owner consent
  ✗  Do not use in professional, academic, or institutional environments
  ✗  Do not use to harass, spy on, or cause harm to any person
  ✗  AV software WILL flag this (expected — keyboard hook heuristics)

THE AUTHOR ACCEPTS ZERO LIABILITY FOR ANY CONSEQUENCES OF MISUSE.
```

<br>

---

<br>

## 📄 License

Released under **[CC BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)**

| You can | You cannot |
|:---|:---|
| ✅ Share & redistribute | ❌ Use commercially |
| ✅ Remix & adapt | ❌ Remove attribution |
| ✅ Build upon it | ❌ Re-license under different terms |

<br>

---

<br>

<div align="center">

**Made with chaos and bad decisions**

`St. Petersburg, FL  ·  2026`

**[@gam3r999](https://github.com/gam3r999)**

<br>

*"In a world of autocorrect, be the autocorrect."*

</div>
