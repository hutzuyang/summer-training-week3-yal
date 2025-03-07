# ifndef YAL_PARSER_H
# define YAL_PARSER_H

# include <bits/stdc++.h>
using namespace std;

struct module
{
    string name;
    int x = 0, y = 0, width, height;
};
class PARSER
{
    public:
    string yal_filename, out_filename, output_filename;
    void GetFilename(const int& argc, char *argv[]);
    void ReadYalFile();
    void ReadOutFile();
    void WriteFile();
    private:
    ifstream fin;
    ofstream fout;
    module *new_ptr;
    vector <module> module_vec;
    void CreatModule(string);
    void SetModuleWH(string);
    void SetModuleXY(string);
};

# endif