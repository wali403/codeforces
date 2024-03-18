import os

def count_cpp_lines(dir):
    return sum(sum(1 for line in open(os.path.join(root, f), encoding='utf-8')) for root, _, files in os.walk(dir) for f in files if f.endswith(".cpp"))

print(count_cpp_lines(os.getcwd()))
