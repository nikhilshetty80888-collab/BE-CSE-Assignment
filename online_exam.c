#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 5
#define MAX_STUDENTS 50

// Structure for storing question details
struct Question
{
    int id;
    char question[200];
    char options[4][100];
    char correctAnswer;
    int marks;
};

// Structure for storing student result
struct Student
{
    char name[50];
    int rollNo;
    int score;
    int totalMarks;
    float percentage;
    char grade;
    int attempted;
    int correct;
    int incorrect;
    int unanswered;
};

// Function to calculate grade
char calculateGrade(float percentage)
{
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 70)
        return 'C';
    else if (percentage >= 60)
        return 'D';
    else if (percentage >= 50)
        return 'E';
    else
        return 'F';
}

// Function to conduct examination
void conductExam(struct Question questions[], struct Student *student)
{
    int i;
    char answer;

    student->score = 0;
    student->attempted = 0;
    student->correct = 0;
    student->incorrect = 0;
    student->unanswered = 0;

    printf("\n============================================\n");
    printf("           ONLINE EXAMINATION\n");
    printf("============================================\n");

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("\nQuestion %d: %s\n",
               questions[i].id, questions[i].question);

        printf("A. %s\n", questions[i].options[0]);
        printf("B. %s\n", questions[i].options[1]);
        printf("C. %s\n", questions[i].options[2]);
        printf("D. %s\n", questions[i].options[3]);

        printf("Enter your answer (A/B/C/D) or X for unanswered: ");
        scanf(" %c", &answer);

        answer = toupper(answer);

        if (answer == 'X')
        {
            student->unanswered++;
            printf("Question unanswered.\n");
        }
        else if (answer == 'A' || answer == 'B' ||
                 answer == 'C' || answer == 'D')
        {
            student->attempted++;

            if (answer == questions[i].correctAnswer)
            {
                student->score += questions[i].marks;
                student->correct++;
                printf("Correct answer!\n");
            }
            else
            {
                student->incorrect++;
                printf("Incorrect answer.\n");
            }
        }
        else
        {
            printf("Invalid answer. Question considered unanswered.\n");
            student->unanswered++;
        }
    }

    student->totalMarks = 0;

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        student->totalMarks += questions[i].marks;
    }

    student->percentage =
        ((float)student->score / student->totalMarks) * 100;

    student->grade = calculateGrade(student->percentage);
}

// Function to display answer review
void displayAnswers(struct Question questions[])
{
    int i;

    printf("\n============================================\n");
    printf("          CORRECT ANSWERS\n");
    printf("============================================\n");

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Q%d. %s\n",
               questions[i].id,
               questions[i].correctAnswer == 'A' ?
               questions[i].options[0] :
               questions[i].correctAnswer == 'B' ?
               questions[i].options[1] :
               questions[i].correctAnswer == 'C' ?
               questions[i].options[2] :
               questions[i].options[3]);

        printf("Correct Option: %c\n\n",
               questions[i].correctAnswer);
    }
}

// Function to display individual result
void displayResult(struct Student student)
{
    printf("\n============================================\n");
    printf("             EXAM RESULT\n");
    printf("============================================\n");

    printf("Student Name : %s\n", student.name);
    printf("Roll Number  : %d\n", student.rollNo);
    printf("Score        : %d / %d\n",
           student.score, student.totalMarks);
    printf("Percentage   : %.2f%%\n", student.percentage);
    printf("Grade        : %c\n", student.grade);
    printf("Attempted    : %d\n", student.attempted);
    printf("Correct      : %d\n", student.correct);
    printf("Incorrect    : %d\n", student.incorrect);
    printf("Unanswered   : %d\n", student.unanswered);

    printf("============================================\n");
}

// Function to generate performance report
void performanceReport(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo student results available.\n");
        return;
    }

    printf("\n============================================================\n");
    printf("                 PERFORMANCE REPORT\n");
    printf("============================================================\n");

    printf("%-5s %-20s %-10s %-12s %-8s\n",
           "Roll", "Name", "Score", "Percentage", "Grade");

    printf("------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-5d %-20s %-10d %-11.2f %-8c\n",
               students[i].rollNo,
               students[i].name,
               students[i].score,
               students[i].percentage,
               students[i].grade);
    }

    printf("============================================================\n");
}

// Main function
int main()
{
    struct Question questions[MAX_QUESTIONS] =
    {
        {
            1,
            "Which language is mainly used for system programming?",
            {"HTML", "C", "CSS", "SQL"},
            'B',
            2
        },

        {
            2,
            "Which symbol is used to end a statement in C?",
            {".", ",", ";", ":"},
            'C',
            2
        },

        {
            3,
            "Which keyword is used to declare an integer variable?",
            {"float", "int", "char", "double"},
            'B',
            2
        },

        {
            4,
            "Which loop executes at least once?",
            {"for", "while", "do-while", "nested"},
            'C',
            2
        },

        {
            5,
            "Which function is the starting point of a C program?",
            {"start()", "main()", "begin()", "run()"},
            'B',
            2
        }
    };

    struct Student students[MAX_STUDENTS];

    int studentCount = 0;
    int choice;
    int rollNo;
    int i;
    int found;

    while (1)
    {
        printf("\n\n============================================\n");
        printf("      ONLINE EXAMINATION MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf("1. Start Examination\n");
        printf("2. Display Student Result\n");
        printf("3. Display Correct Answers\n");
        printf("4. Generate Performance Report\n");
        printf("5. Exit\n");
        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                if (studentCount >= MAX_STUDENTS)
                {
                    printf("\nStudent storage is full!\n");
                    break;
                }

                printf("\nEnter Student Name: ");
                scanf(" %[^\n]", students[studentCount].name);

                printf("Enter Roll Number: ");
                scanf("%d", &students[studentCount].rollNo);

                conductExam(questions, &students[studentCount]);

                printf("\nExam completed successfully!\n");

                displayResult(students[studentCount]);

                studentCount++;

                break;

            case 2:

                if (studentCount == 0)
                {
                    printf("\nNo student has completed the examination.\n");
                    break;
                }

                printf("\nEnter Roll Number: ");
                scanf("%d", &rollNo);

                found = 0;

                for (i = 0; i < studentCount; i++)
                {
                    if (students[i].rollNo == rollNo)
                    {
                        displayResult(students[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("\nStudent result not found.\n");
                }

                break;

            case 3:

                displayAnswers(questions);

                break;

            case 4:

                performanceReport(students, studentCount);

                break;

            case 5:

                printf("\nThank you for using the Online Examination System!\n");
                return 0;

            default:

                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}