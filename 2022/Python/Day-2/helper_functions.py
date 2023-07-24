import os

def get_relative_path(file_name):
    # Get the path of the currently running script
    current_script_path = os.path.abspath(__file__)

    # Get the parent directory of the script
    script_directory = os.path.dirname(current_script_path)

    return os.path.join(script_directory, file_name)
