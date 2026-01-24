import subprocess
import shutil
from pathlib import Path

DIR_A = Path("./KSFrontEnd/src/Shared").resolve()
DIR_B = Path("./KSAudioEngine/src/Shared").resolve()

def git_timestamp(path: Path) -> int:
    try:
        return int(subprocess.check_output(
            ["git", "log", "-1", "--format=%ct", "--", str(path)],
            stderr=subprocess.DEVNULL
        ))
    except subprocess.CalledProcessError:
        print(f"[git] no history: {path}")
        return 0

def collect_files(base: Path):
    files = {
        p.relative_to(base)
        for p in base.rglob("*")
        if p.is_file()
    }
    print(f"[scan] {base} -> {len(files)} files")
    return files

print("=== Shared sync start ===")
print(f"DIR_A: {DIR_A}")
print(f"DIR_B: {DIR_B}")

files_a = collect_files(DIR_A)
files_b = collect_files(DIR_B)
all_files = files_a | files_b

print(f"[scan] total unique files: {len(all_files)}")

for rel in sorted(all_files):
    a = DIR_A / rel
    b = DIR_B / rel

    if a.exists() and b.exists():
        if a.read_bytes() == b.read_bytes():
            print(f"[skip] {rel}")
            continue

        ts_a = git_timestamp(a)
        ts_b = git_timestamp(b)

        if ts_a >= ts_b:
            print(f"[update] {rel} -> DIR_B (newer in DIR_A)")
            b.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(a, b)
        else:
            print(f"[update] {rel} -> DIR_A (newer in DIR_B)")
            a.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(b, a)

    else:
        src = a if a.exists() else b
        dst = b if src is a else a
        print(f"[copy] {rel} -> {'DIR_B' if src is a else 'DIR_A'}")
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)

print("=== Shared sync done ===")