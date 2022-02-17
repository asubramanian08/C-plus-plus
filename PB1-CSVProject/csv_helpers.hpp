enum ArgPara { call, inF, outF, fld, st, argCt };
std::string_view readCSVLine(std::string_view &csv_view, std::string_view &line, bool advance);
int REGEX_sortType(std::string_view field);