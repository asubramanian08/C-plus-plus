enum ArgPara { call, inF, outF, fld, st, argCt };
std::string_view readCSVLine(std::istream &in, bool peek);
int REGEX_sortType(std::string_view field);