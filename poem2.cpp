#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Запросить слова у пользователя
string ReadLinePoem() {
    string input;
    cout << "Введите слова через пробел: ";
    getline(cin, input);
    return input;
}

// Расставить слова в стихе
vector<string> ArrangeWordsPoem() {
    vector<string> words;
    bool enoughWords = false; // флаг, указывающий, достаточно ли слов для составления стиха

    while (!enoughWords) {
        string word = ReadLinePoem();
        size_t start = 0;
        size_t end = word.find(' ');

        // Разделяем строку на слова и добавляем их в вектор
        while (end != string::npos) {
            string subword = word.substr(start, end - start);
            if (!subword.empty()) {
                words.push_back(subword);
            }
            start = end + 1;
            end = word.find(' ', start);
        }

        string subword = word.substr(start);
        if (!subword.empty()) {
            words.push_back(subword);
        }

        // Проверка наличия хотя бы трех слов для составления стиха
        if (words.size() >= 3) {
            enoughWords = true;
        }
        else {
            cout << "Недостаточно слов для составления стиха." << endl;
            words.clear(); // очистить вектор слов и запросить слова заново
        }
    }

    return words;
}

void ReadPoem() {
    cout << "Poem: " << endl;
    vector<string> poem = ArrangeWordsPoem();
    for (const string& word : poem) {
        cout << word << ' ';
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    ReadPoem();
    return 0;
}