#include <iostream>
#include <filesystem>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;
namespace fs = std::filesystem;

// variables to build html file
vector<string> contents;
vector<string> contentFN;
vector<string> HTMLhead = {
    "<!DOCTYPE html><html><head><title>Contents</title>",
    "<script>function switchf(target){document.getElementById(\"viewer\").src=`file://${target}`;}</script><style>",
    "html,body{margin: 0px;height: 100%;}.w{height: 100%;}*{box-sizing: border-box;}.column{overflow: auto;border:1px outset grey;float: left;width: 50%;padding: 10px;}body:after{content: "";display: table;clear: both;height: 100%;}"
    "</style></head><body>",
    "<div class=\"w\"><div class=\"column w\" style=\"background-color:#aaa;\"><div><h2>Contents of"
};
vector<string> HTMLmiddle;
string HTMLfoot = "​</div><iframe id=\"viewer\" class=\"column w\" src=\"data:text/html;charset=utf-8,%3Chtml%3E%3Cbody%3ESelect%20file%20on%20left%20list%3C/body%3E%3C/html%3E\"></iframe></div></body></html>";

// docs
string usageargs = "[directory] [filename]";
string docs = "Without arguments, program will generate output file with current working directory with filename 'out.html'.\n\n[directory] - Set specific directory to iterate through and insert contents in generated file\n[filename] - Specify filename to output file. Note that '.html' extension is optional";

// functions

// make output file
void makefile(string target, string output) {
    for (const auto& entry : fs::directory_iterator(target)) { // iterate through contents in specified dir
        if (fs::is_regular_file(entry)) { // if it's file
            contents.push_back(entry.path().string());
            contentFN.push_back(entry.path().filename().string());
        } else { // if it's dir
            continue;
        }
    }
    for (auto entry : contentFN) { // loop through vector full of filenames to make file list on output
        HTMLmiddle.push_back("<a href=\"#\" onclick=\"switchf('" +
            target +
            "/" +
            entry +
            "')\">" +
            entry +
            "</a><br>"
        );
    }
    try { // start building the file
        string outname;
        if (output.find(".html") == std::string::npos) { // if there is no '.html' in second argrument
            outname = output + ".html";
        } else {
            outname = output;
        }
        ofstream output(outname);
        // actually building output
        for (auto entry : HTMLhead) {
            output << entry << endl;
        }
        output << target << "​</h2><span>Select file to read contents on the right. Only files are shown</span><br><hr><span>File name</span><br></div>";
        for (auto entry : HTMLmiddle) {
            output << entry << endl;
        }
        output << HTMLfoot;
        output.close();
    } catch(...) {
        cout << "Can't make output file!" << endl;
        return;
    }
    return;
}

int main(int argc, char **argv) {
    // argv[1] = directory name
    // argv[2] = output name
    if (argc > 3) { // fun docs
        cout << "Too many arguments, here is the usage:\n" << endl;
        cout << argv[0] << " " << usageargs << endl;
        cout << endl << docs << endl;
        return 0;
    }
    // now checking args
    if (argv[1]) {
        if (fs::exists(argv[1])) {
            if (fs::is_directory(argv[1])) {
                if (argv[2]) {
                    makefile(argv[1], argv[2]);
                } else {
                    makefile(argv[1], "out.html");
                }
            } else {
                cout << "'" << argv[1] << "'" << " is not a directory" << endl;
                return 0;
            }
        } else {
            cout << "No such directory '" << argv[1] << "'" << endl;
            return 0;
        }
    } else {
        try {
            makefile(fs::current_path().string(), "out.html");
        } catch(...) {
            cout << "Something went wrong!" << endl;
            return 0;
        }
    }
    return 0;
}
