import shutil


def clear_file_content(filename):
    with open(filename, mode="w") as f:
        pass

def copy_file_content(source_file, destination_file):
    shutil.copyfile(source_file, destination_file)