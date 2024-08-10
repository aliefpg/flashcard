#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <vector>
#include <string>
#include <utility>

struct SingleAnswerQuestion {
    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    char correctAnswer;
};

struct MultipleAnswerQuestion {
    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    std::string optionE;
    std::vector<std::string> correctAnswers;
};

std::vector<SingleAnswerQuestion> getSingleAnswerQuestions();


std::vector<MultipleAnswerQuestion> getMultipleAnswerQuestions();

#endif
