#include <algorithm>
#include <iterator>

std::vector<std::string> split_string(const std::string& str) {
    std::istringstream iss(str);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    return words;
}

void Book::build_index(const std::set<std::string>& words) {
    index_.clear();
    size_t page_number = 1;

    for (const Page& page : book_) {
        for (size_t line_num = 0; line_num < page.get_num_lines(); ++line_num) {
            std::string line = page.get_line(line_num);
            std::vector<std::string> line_words = split_string(line);

            for (const std::string& word : line_words) {
                if (words.find(word) != words.end()) {
                    index_[word].insert(page_number);
                }
            }
        }

        ++page_number;
    }
}