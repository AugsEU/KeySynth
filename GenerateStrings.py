import sys
import csv
import argparse

def parse_tsv(path):
	tsv_file = open(path)
	
	key_map = {}
	table_rows = []
	for line in tsv_file.readlines():
		entries = line.split("\t")

		if len(key_map) == 0: # First non-empty line is keys
			for i, entry in enumerate(entries):
				key_map[i] = entry.strip()
		else:
			table_row = {}
			for i, entry in enumerate(entries):
				entry_key = key_map[i]
				table_row[entry_key] = entry.strip()

			table_rows.append(table_row)
	
	return table_rows

def generate_cpp_file(tsv_file):
	cpp_lines = ["// This file was automatically generated"]

	define_list = []
	amalgam_str = ""

	# First generate amalgam string
	write_head = 0
	for row in tsv_file:
		full_id = f"LC_{row["Section"]}_{row["ID"]}"
		loc_str = row["Value"]
		str_len = len(loc_str)

		amalgam_str += row["Value"]

		define_list.append(f"#define {full_id} {write_head}, {str_len}")
		
		write_head += str_len

	cpp_lines.append("")
	cpp_lines.append(f"static constexpr char* const AMALGAM_STR = \"{amalgam_str}\";")
	cpp_lines.append("")
	for define in define_list:
		cpp_lines.append(define)

	return cpp_lines



# SCRIPT
g_parser = argparse.ArgumentParser()
g_parser.add_argument("input")
g_parser.add_argument("output")
g_args = g_parser.parse_args()

g_tsv_file = parse_tsv(g_args.input)
g_cpp_lines = generate_cpp_file(g_tsv_file)

for line in g_cpp_lines:
	print(line)


