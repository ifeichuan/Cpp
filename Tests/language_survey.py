from survey import AnonymousSurvey
# 定义一个问题，并创建一个调查

question = "What language did you first learn to speak"
my_survey = AnonymousSurvey(question)

my_survey.show_question()

print("Enter 'q' to any time quit.\n" )

while True:
    response = input("Language:")
    if response == 'q':
        break
    my_survey.store_response(response)

print("\nThank you to everyone who participated in the sur_vey!")
my_survey.show_results()