import re

already_unfolded = set()
def unfold(include, position):
    file_path = re.match(r'#include "(.+)".*', include).group(1)
    with open(file_path, 'r') as f:
        del vim.current.buffer[position]
        if not file_path in already_unfolded:
            vim.current.buffer.append(f.readlines(), position)
            already_unfolded.add(file_path)

stopped = False
while not stopped:
    stopped = True
    for line_number, line in enumerate(vim.current.buffer):
        if line.startswith('#include "algos'):
            unfold(line, line_number)
            stopped = False
            break

