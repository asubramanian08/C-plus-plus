enum ArgPara { call, inF, outF, fld, st, argCt };
std::string_view getField(std::string_view ln, int col);
std::string_view getCSVLine(std::istream &in, bool peek);