# include "yal_parser.h"
# include <bits/stdc++.h>
using namespace std;

void PARSER::GetFilename(const int& argc, char *argv[])
{
    if(argc == 4)
    {
        this->yal_filename = argv[1];
        this->out_filename = argv[2];
        this->output_filename = argv[3];
    }
    else
    {
        cerr << "Error: Parser should be executed with input file and output file. \n";
        exit(-1);
    }
}
void PARSER::ReadYalFile()
{
    fin.open(yal_filename);
    if(!fin)
    {
        cerr << "Error: Input .yal file failed. \n";
        exit(1);
    }
    string line;
    while(getline(fin, line))
    {
        if(line.size() < 10)
            continue;
        else if(line.substr(0, 6) == "MODULE")
            CreatModule(line);
        else if(line.substr(1, 10) == "DIMENSIONS")
            SetModuleWH(line);
    }
    cout << "READ " << yal_filename << " COMPLETE" << "\n"; // debug
    fin.close();
}
void PARSER::CreatModule(string line)
{
    new_ptr = new module;
    new_ptr->name = line.substr(7, line.size() - 8);
    cout << "MODULE " << new_ptr->name << " CREATED\n"; // debug
}
void PARSER::SetModuleWH(string line)
{
    vector<int> dimensions;
    stringstream ss(line);
    string s;
    while(ss >> s)
    {
        if(s != "DIMENSIONS")
            dimensions.push_back(stoi(s));
    }
    new_ptr->width = dimensions[2] - dimensions[6];
    new_ptr->height = dimensions[3] - dimensions[7];
    module_vec.push_back(*new_ptr);
    cout << "MODULE " << new_ptr->name << " WH SET\n\n"; // debug
}
void PARSER::ReadOutFile()
{
    fin.open(out_filename);
    if(!fin)
    {
        cerr << "Error: Input .out file failed. \n";
        exit(1);
    }
    string line;
    while(getline(fin, line))
    {
        SetModuleXY(line);
    }
    cout << "READ " << out_filename << " COMPLETE" << "\n"; // debug
    fin.close();
}
void PARSER::SetModuleXY(string line)
{
    vector<int> dimensions;
    stringstream ss(line);
    string s;
    string module_name;
    int module_width;
    while(ss >> s)
    {
        if(s[0] == 'M')
            module_name = s;
        else
            dimensions.push_back(stoi(s));
    }
    for(int i = 0; i < module_vec.size(); ++i)
    {
        if(module_vec[i].name == module_name)
        {
            module_vec[i].x = dimensions[0];
            module_vec[i].y = dimensions[1];
            if(dimensions[2] == 1)
            {
                module_width = module_vec[i].width;
                module_vec[i].width = module_vec[i].height;
                module_vec[i].height = module_width;
            }
        }
    }
    cout << "MODULE " << module_name << " XY SET\n\n"; // debug
}
void PARSER::WriteFile()
{
    fout.open(output_filename);
    if(!fout)
    {
        cerr << "Error : Output file failed. \n";
        exit(1);
    }
    fout << "axis equal;\n" << "hold on\n" << "grid on\n";
    for(int i = 0; i < module_vec.size(); ++i)
    {
        fout << "block_x=[";
        fout << " " << module_vec[i].x;
        fout << " " << module_vec[i].x;
        fout << " " << module_vec[i].x + module_vec[i].width;
        fout << " " << module_vec[i].x + module_vec[i].width;
        fout << " " << module_vec[i].x;
        fout << "];\n";
        fout << "block_y=[";
        fout << " " << module_vec[i].y;
        fout << " " << module_vec[i].y + module_vec[i].height;
        fout << " " << module_vec[i].y + module_vec[i].height;
        fout << " " << module_vec[i].y;
        fout << " " << module_vec[i].y;
        fout << "];\n";
        fout << "fill(block_x,block_y,'c');\n";
        fout << "text(" << module_vec[i].x + module_vec[i].width / 2 << "," << module_vec[i].y + module_vec[i].height / 2 << ",";
        fout << "'" << module_vec[i].name << "');\n";
    }
}