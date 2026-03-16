#!/usr/bin/env python3
"""
Converts an 8-pixel-tall bitmap image to a C++ uint8_t array.
Each column is encoded as a single byte, MSB = top pixel. Slop coded script.
"""

import sys
import os
from PIL import Image


def load_image(path: str) -> Image.Image:
    img = Image.open(path).convert("RGB")
    if img.height != 8:
        raise ValueError(f"Image must be exactly 8 pixels tall, got {img.height}")
    return img


def encode_columns(img: Image.Image) -> list[int]:
    """Encode each column as a uint8_t, top pixel = MSB."""
    bytes_out = []
    for x in range(img.width):
        byte = 0
        for y in range(8):
            r, g, b = img.getpixel((x, y))
            # Treat dark pixels as 1, light pixels as 0
            is_set = 1 if (r + g + b) < 384 else 0
            byte |= is_set << y
        bytes_out.append(byte)
    return bytes_out


def format_cpp_array(data: list[int], columns_per_line: int = 5) -> str:
    hex_values = [f"0x{b:02X}" for b in data]
    lines = []
    for i in range(0, len(hex_values), columns_per_line):
        chunk = hex_values[i : i + columns_per_line]
        lines.append("    " + ", ".join(chunk))
    inner = ",\n".join(lines)
    return f"static constexpr uint8_t gArray[] = {{\n{inner}\n}};"


def main():
    if len(sys.argv) > 1:
        image_path = sys.argv[1]
    else:
        script_dir = os.path.dirname(os.path.abspath(__file__))
        image_path = os.path.join(script_dir, "AsciiBitfont.png")
        if not os.path.exists(image_path):
            sys.exit(
                f"Error: No argument given and default image not found at:\n  {image_path}"
            )

    img = load_image(image_path)
    data = encode_columns(img)
    print(format_cpp_array(data))


if __name__ == "__main__":
    main()