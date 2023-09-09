
#pragma once

#include <iostream>

class Form {

private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    class GradeTooHighException;
    class GradeTooLowException;

    Form();
    Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
    ~Form();
    Form(const Form &form);
    Form &operator= (const Form &form);

    const std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
};

std::ostream& operator<<(std::ostream& out, const Form& form);
