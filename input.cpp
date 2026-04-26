#include <fstream>
#include <iostream>
using namespace std;

bool FileExits(string filename) {
    ifstream f(filename);
    if (f.is_open())
        return true;
    else
        return false;
}

bool compile(string filename) {
    size_t pos = filename.find_last_of('.');
    string str = filename.substr(0, pos);

    string command = "g++ " + filename + " -o " + str + " && ./" + str;
    int result = system(command.c_str());

    if (result != 0) return false;

    string run_cmd = "./" + str + " < input.txt > output.txt";
    system(run_cmd.c_str());

    return true;
}

bool compare(string f1, string f2) {
    ifstream a(f1), b(f2);
    string s1, s2;

    while (true) {
        bool r1 = (bool)(a >> s1);
        bool r2 = (bool)(b >> s2);

        if (r1 != r2) return false;
        if (!r1) break;

        if (s1 != s2) return false;
    }
    return true;
}

int main() {
    string filename;
    cin >> filename;
    if (FileExits(filename))
        cout << "FILE FOUND\n";
    else
        cout << "FILE NOT FOUND\n";

    if (compile(filename))
        cout << "Compilation Successful\n";
    else
        cout << "Compilation Error\n";

    if (compare("output.txt", "expected.txt"))
        cout << "OK PASSED\n";
    else
        cout << "WRONG ANSWER\n";

    return 0;
}
