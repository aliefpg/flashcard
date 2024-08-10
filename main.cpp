#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "questions.h"

using namespace std;

// Function to ask a single-answer question
// Fungsi untuk menanyakan pertanyaan dengan satu jawaban
void askQuestion(const SingleAnswerQuestion& q) {
    char userAnswer;

    // Display the question and answer options
    // Tampilkan pertanyaan dan opsi jawaban
    cout << q.question << "\n";
    cout << "A. " << q.optionA << "\n";
    cout << "B. " << q.optionB << "\n";
    cout << "C. " << q.optionC << "\n";
    cout << "D. " << q.optionD << "\n";

    // Get the user's answer
    // Terima jawaban dari pengguna
    cout << "Masukkan pilihan jawaban (A/B/C/D): ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);

    // Check the answer
    // Periksa jawaban
    if (userAnswer == q.correctAnswer) {
        cout << "Jawaban benar!\n";
    } else {
        cout << "Jawaban salah. Jawaban yang benar adalah: " << q.correctAnswer << "\n";
    }
}

// Function to ask a multiple-answer question
// Fungsi untuk menanyakan pertanyaan dengan beberapa jawaban
void askMultipleAnswerQuestion(const MultipleAnswerQuestion& q) {
    vector<string> userAnswers;
    int numCorrectAnswers = q.correctAnswers.size();

    while (true) {
        cout << q.question << "\n";
        cout << "A. " << q.optionA << "\n";
        cout << "B. " << q.optionB << "\n";
        cout << "C. " << q.optionC << "\n";
        cout << "D. " << q.optionD << "\n";
        cout << "E. " << q.optionE << "\n";

        cout << "Masukkan jawaban pertama: ";
        string answer1;
        cin >> answer1;
        answer1 = toupper(answer1[0]);

        cout << "Masukkan jawaban kedua: ";
        string answer2;
        cin >> answer2;
        answer2 = toupper(answer2[0]);

        // Check if the answers are valid
        // Periksa apakah jawaban valid
        if ((answer1 != "A" && answer1 != "B" && answer1 != "C" && answer1 != "D" && answer1 != "E") ||
            (answer2 != "A" && answer2 != "B" && answer2 != "C" && answer2 != "D" && answer2 != "E")) {
            cout << "Jawaban tidak valid. Coba lagi.\n";
            continue;
        }

        // Store answers and ensure they are unique
        // Simpan jawaban dan pastikan unik
        userAnswers.clear();
        userAnswers.push_back(answer1);
        if (answer1 != answer2) {
            userAnswers.push_back(answer2);
        } else {
            cout << "Jawaban kedua tidak boleh sama dengan jawaban pertama. Coba lagi.\n";
            continue;
        }

        // Check if the number of answers is correct
        // Periksa apakah jumlah jawaban sudah benar
        if (userAnswers.size() != numCorrectAnswers) {
            cout << "Jumlah jawaban yang Anda berikan tidak sesuai. Anda perlu memberikan " << numCorrectAnswers << " jawaban.\n";
            continue;
        }

        // Sort and compare answers
        // Urutkan dan bandingkan jawaban
        sort(userAnswers.begin(), userAnswers.end());
        vector<string> sortedCorrectAnswers = q.correctAnswers;
        sort(sortedCorrectAnswers.begin(), sortedCorrectAnswers.end());

        if (userAnswers == sortedCorrectAnswers) {
            cout << "Jawaban Anda benar!\n";
        } else {
            cout << "Jawaban salah.\n";
            cout << "Jawaban yang benar adalah: ";
            for (const auto& answer : q.correctAnswers) {
                cout << answer << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    srand(time(0));

    char userResponse;

    // Get questions
    // Ambil pertanyaan
    auto singleAnswerQuestions = getSingleAnswerQuestions();
    auto multipleAnswerQuestions = getMultipleAnswerQuestions();

    do {
        // random question
        // acak pertanyaan
        int questionIndex = rand() % (singleAnswerQuestions.size() + multipleAnswerQuestions.size());

        // Call the function to ask the selected question
        // Panggil fungsi untuk menanyakan pertanyaan yang dipilih
        if (questionIndex < singleAnswerQuestions.size()) {
            askQuestion(singleAnswerQuestions[questionIndex]);
        } else {
            questionIndex -= singleAnswerQuestions.size();
            askMultipleAnswerQuestion(multipleAnswerQuestions[questionIndex]);
        }

        cout << "Ingin mencoba pertanyaan lain? (y/n): ";
        cin >> userResponse;

        system("cls");

        if (userResponse == 'n' || userResponse == 'N') {
            break;
        }

    } while (userResponse == 'y' || userResponse == 'Y');

    return 0;
}
