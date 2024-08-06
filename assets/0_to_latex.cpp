#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // 包含算法库
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    const std::string output_filename = "0output_latex_sections.tex";
    std::ofstream outfile(output_filename);

    if (!outfile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
            std::string filename = entry.path().filename().string();
            std::string basename = filename.substr(0, filename.size() - 4);
            if(filename=="0_to_latex.cpp") continue;
            // 转换为大写
            std::transform(basename.begin(), basename.end(), basename.begin(),
                           [](unsigned char c){ return std::toupper(c); });

            std::string subsection_title = basename;
            // 将文件名中的短横线替换为空白
            std::replace(subsection_title.begin(), subsection_title.end(), '-', ' ');

            outfile << "\\subsection{" << subsection_title << "}\n";
            outfile << "\\raggedbottom\\lstinputlisting[style=cpp]{assets/" << basename << ".cpp}\n";
            outfile << "\\hrulefill\n\n";
        }
    }

    outfile.close();
    std::cout << "LaTeX sections generated in " << output_filename << std::endl;
    return 0;
}