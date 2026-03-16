Import("env")
import os
import subprocess

def generate_disasm(source, target, env):
    build_dir = env.subst("$BUILD_DIR")
    elf_path = os.path.join(build_dir, "firmware.elf")
    lss_path = os.path.join(build_dir, "firmware.lss")

    cc = env.subst("$CC")
    objdump = cc.replace("gcc", "objdump")

    result = subprocess.run(
        [objdump, "-d", "-S", "-C", elf_path],
        capture_output=True,
        text=True
    )

    with open(lss_path, "w", encoding="utf-8") as f:
        f.write(result.stdout)

    print(f"Disassembly written to: {lss_path}")

env.AddPostAction("$BUILD_DIR/firmware.hex", generate_disasm)