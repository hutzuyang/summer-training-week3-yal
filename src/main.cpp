# include "yal_parser.h"
# include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    PARSER PARSER_obj;
    PARSER_obj.GetFilename(argc, argv);
    PARSER_obj.ReadYalFile();
    cout << "ReadYalFile done\n"; // debug
    PARSER_obj.ReadOutFile();
    PARSER_obj.WriteFile();
    cout << "WRITE " << PARSER_obj.output_filename << " COMPLETE\n";
    return 0;
}