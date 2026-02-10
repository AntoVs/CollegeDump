class Question:
    def __init__(self, q_no, text, answers, options=None):
        self.q_no = q_no
        self.text = text
        self.options = options
        self.answers = answers
        
class Quiz:
    def __init__(self):
        self.questions = []

    def add_question(self, question):
        self.questions.append(question)

    def create_quiz(self):
        n = int(input("Enter number of questions: "))

        for i in range(1, n + 1):
            print(f"\nEnter the details for question {i}")
            text = input("Question: ")
            qtype = input("Enter question type (MCQ/SA): ").upper()

            if qtype == "MCQ":
                options = []
                op_count = int(input("Enter number of options: "))
                for j in range(op_count):
                    options.append(input(f"Option {j + 1}: "))
                answer = input("Correct option (exact text): ")
                self.add_question(Question(i, text, answer, options))
            else:
                answer = input("Correct answer: ")
                self.add_question(Question(i, text, answer))

    def conduct(self):
        score = 0
        total = len(self.questions)

        for q in self.questions:
            print(f"\nQ{q.q_no}: {q.text}")

            if q.options:  # MCQ
                for i, opt in enumerate(q.options, start=1):
                    print(i, ".", opt)

                user = int(input("Enter option number: "))
                if q.options[user - 1] == q.answers:
                    score += 1
            else:  # Short Answer
                user = input("Enter answer: ")
                if user == q.answers:
                    score += 1
        return score, total

class Student:
    def __init__(self, name):
        self.name = name

    def display_score(self, score, total):
        print("\nStudent:", self.name)
        print("Score:", score, "/", total)


quiz = Quiz()
quiz.create_quiz()
s = Student("Antony")
result, total = quiz.conduct()
s.display_score(result, total)
