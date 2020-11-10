#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

//https://stackoverflow.com/questions/5607589/right-way-to-split-an-stdstring-into-a-vectorstring
std::vector<std::string> split(std::string str, std::string token){
    std::vector<std::string>result;
    while(str.size()){
        unsigned int index = str.find(token);
        if(index!=std::string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
std::string join(std::vector<std::string> vec, std::string token){
    std::string ret = "";
    for(std::string str : vec)
        ret += str + token;
    return ret.substr(0, ret.size() - 1 - token.size());
}


class Char{
public:
    std::vector<std::string> rows;
    Char(){}
    Char(const std::vector<std::string>& rows){
        this->rows = rows;
    }
    void append(std::vector<std::string>& arr){
        for(unsigned int i = 0; i < this->rows.size(); i++){
            if(i >= arr.size()) arr.push_back("");
            arr[i] += this->rows[i];
        }
    }
};

class Font{
public:
    std::map<char, Char> charMap;
    Font(){}
    Font(const std::map<char, Char>& charMap){
        this->charMap = charMap;
    }
    std::string gen(const std::string& string){
        std::vector<std::string> ret;
        for(char c : string){
            this->charMap[c].append(ret);
        }
        return join(ret, "\n");
    }
};

class FontGenerator{
public:
    Font font;
    FontGenerator(const std::string& font){
        std::vector<std::string> chrs = split(font, "\n\n");
        std::map<char, Char> charMap;
        for(std::string chr : chrs){
            std::vector<std::string> lines = split(chr, "\n");
            std::vector<std::string> lines2;
            lines2.assign(&lines[1], &lines[lines.size()]);
            charMap[lines[0][0]] = Char(lines2);
        }
        this->font = Font(charMap);
    }
    std::string gen(const std::string& args){
        return this->font.gen(args);
    }
};

int main(int argc, char* argv[]){
    std::string filename = argv[1];
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string font = buffer.str();

    FontGenerator generator(font);
    std::string input = "";
    while(true){
        std::cout << "text: ";
        std::cin >> input;
        std::cout << generator.gen(input) << std::endl;
    }
    return 0;
}
