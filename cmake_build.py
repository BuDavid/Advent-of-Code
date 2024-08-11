from typing import List
import os
import glob

CURRENT_DIR = os.getcwd()
SOLUTION_PATH = CURRENT_DIR + "/Solutions"
ALL_SOLUTIONS_FILE = CURRENT_DIR + "/SolutionManager/include/all_solutions.hpp"
FACTORY_SOURCE_FILE = CURRENT_DIR + "/SolutionManager/src/solution_factory.cpp"

def changed(hpp_files: List[str]) -> bool:
    if not os.path.exists(ALL_SOLUTIONS_FILE):
        return True

    lines = []
    with open(ALL_SOLUTIONS_FILE, 'r') as file:
        lines = file.readlines()

    del lines[0:4]
    del lines[-2:]
    lines = [line.split('"')[1] for line in lines]   

    return set(lines) != set(hpp_files)

def create_all_solutions(hpp_files: List[str]):
    with open(ALL_SOLUTIONS_FILE, 'w') as file:
        file.write("// This is an automatically generated file. Do not modify.\n")
        file.write("#ifndef ALL_SOLUTIONS_H_\n")
        file.write("#define ALL_SOLUTIONS_H_\n\n")

        for hpp_file in hpp_files:
            file.write('#include "' + hpp_file + '"\n')

        file.write("\n#endif  // ALL_SOLUTIONS_H_")

def create_factory_cpp(hpp_files: List[str]):
    with open(FACTORY_SOURCE_FILE, 'w') as file:
        file.write("// This is an automatically generated file. Do not modify.\n")
        file.write('#include "solution_factory.hpp"\n\n')
        file.write("std::unique_ptr<Solution> SolutionFactory::create_solution(int day, int year) {\n")
        file.write("\tswitch(year) {\n");

        old_year = ""
        for hpp_file in hpp_files:
            parts = hpp_file.split("/")
            day = (parts[-2].split("day"))[1]
            year = parts[-3]

            if not old_year:
                file.write(f"\t\tcase {year}:\n");
                file.write("\t\t\tswitch(day) {\n");
                old_year = year

            if year != old_year and old_year:
                file.write("\t\t\t\tdefault:\n");
                file.write('\t\t\t\t\tthrow std::invalid_argument("invalid argument");\n');
                file.write("\t\t\t}\n");
                file.write(f"\t\tcase {year}:\n");
                file.write("\t\t\tswitch(day) {\n");
                old_year = year

            file.write(f"\t\t\t\tcase {day}:\n");
            file.write(f"\t\t\t\t\treturn std::make_unique<Y{year}Day{day}>();\n");

        file.write("\t\t\t\tdefault:\n");
        file.write('\t\t\t\t\tthrow std::invalid_argument("invalid argument");\n');
        file.write("\t\t\t}\n");
        file.write("\t\tdefault:\n");
        file.write('\t\t\tthrow std::invalid_argument("invalid argument");\n');
        file.write("\t}\n");
        file.write("}")

def main():
    hpp_files = glob.glob(os.path.join(SOLUTION_PATH, '**/*.hpp'), recursive=True)

    if not changed(hpp_files):
        return
        
    create_all_solutions(hpp_files)
    create_factory_cpp(hpp_files)

if __name__ == "__main__":
    main()

