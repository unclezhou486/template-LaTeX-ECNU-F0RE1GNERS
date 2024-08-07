#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

// 仅在下划线前面添加反斜杠进行转义
std::string escape_filename(const std::string& filename) {
    std::string safe_filename = filename;
    size_t pos = 0;
    while ((pos = safe_filename.find('_', pos)) != std::string::npos) {
        safe_filename.insert(pos, "\\"); // 在下划线前面插入反斜杠
        pos += 2; // 更新位置，跳过新插入的字符
    }
    return safe_filename;
}

int main() {
    const std::string output_filename = "listings.tex";
    std::ofstream outfile(output_filename);

    if (!outfile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    outfile << "% Generated LaTeX code for C++ file listings" << std::endl;
    outfile << "\\section{All}\n";
    for (const auto& entry : fs::directory_iterator(".")) {
        const auto& path = entry.path();
        if (entry.is_regular_file() && path.extension() == ".cpp") {
            std::string filename = path.filename().string();
            std::string basename = escape_filename(filename); // 转义文件名

            // 构造子章节标题，这里简单地使用转义后的文件名
            std::string subsection_title = basename.substr(0, basename.size() - 4);

            // 输出到LaTeX文件

            outfile << "\\subsection{" << subsection_title << "}\n";
            outfile << "\\raggedbottom\\lstinputlisting[style=cpp]{assets/" << basename << "}\n"; // 假设.cpp文件在assets目录下
            outfile << "\\hrulefill\n\n";
        }
    }

    outfile.close();
    std::cout << "LaTeX listings generated in " << output_filename << std::endl;
    return 0;
}
